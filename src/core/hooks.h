#pragma once
#include "pybind11.h"
#include "pybind11/embed.h"
#include <cocos2d.h>
#include "MinHook.h"
#include "core/logger.h"
#include "core/macros.h"
#include "core/python.h"
#include "core/module.h"

USING_NS_CC;
namespace pybind = pybind11;

namespace cinnamon {
    namespace hooks {
        CINNAMON_API extern std::multimap<std::string, pybind::function> pythonHooks;
        CINNAMON_API extern std::multimap<std::string, void*> hooks;

        class CINNAMON_API PythonHook {
        public:
            std::string m_functionname;
            size_t m_address;
            pybind::function m_detour;
            std::string m_modFilePath;
            bool m_enabled;

            PythonHook() {}

            PythonHook(std::string functionname, size_t address, pybind::function detour) {
                m_functionname = functionname;
                m_address = address;
                m_detour = detour;
                m_modFilePath = cinnamon::python::getPythonFileFromObject(m_detour);

                enable();

                cinnamon::hooks::pythonHooks.insert(std::pair<std::string, pybind::function>(functionname, detour));
            }

            PythonHook(pybind::function toHook, pybind::function detour) {
                pybind::print(toHook, detour);

                std::pair<std::string, size_t> ret = toHook(detour).cast<std::pair<std::string, size_t>>();

                m_functionname = ret.first;
                m_address = ret.second;
                m_detour = detour;
                m_modFilePath = cinnamon::python::getPythonFileFromObject(m_detour);

                enable();

                cinnamon::hooks::pythonHooks.insert(std::pair<std::string, pybind::function>(ret.first, detour));

                // loop through pythonHooks

                std::multimap<std::string, pybind::function>::iterator itr;
                for (itr = cinnamon::hooks::pythonHooks.begin(); itr != cinnamon::hooks::pythonHooks.end(); ++itr) {
                    // need to cast second to string
                    std::cout << itr->first << std::endl;
                }
            }

            void enable() {
                if (!m_enabled) {
                    m_enabled = true;
                    cinnamon::hooks::pythonHooks.insert(std::pair<std::string, pybind::function>(m_functionname, m_detour));
                    MH_EnableHook((LPVOID)m_address);
                }
            }

            void disable() {
                if (m_enabled) {
                    m_enabled = false;
                    cinnamon::hooks::pythonHooks.erase(m_functionname);
                    MH_DisableHook((LPVOID)m_address);
                }
            }

        };

        // C++ hook
        class CINNAMON_API Hook {
        public:
            std::string m_functionname;
            size_t m_address;
            void* m_detour;

            Hook() {}

            Hook(std::string functionname, size_t address, void* detour) {
                m_functionname = functionname;
                m_address = address;
                m_detour = detour;

                cinnamon::hooks::hooks.insert(std::pair<std::string, void*>(functionname, detour));

                MH_EnableHook((LPVOID)address);
            }

            Hook(std::pair<std::string, size_t>(*toHook)(pybind::function), void* detour) {
                std::pair<std::string, size_t> ret = toHook(pybind::function());

                m_functionname = ret.first;
                m_address = ret.second;
                m_detour = detour;

                cinnamon::hooks::hooks.insert(std::pair<std::string, void*>(ret.first, detour));

                MH_EnableHook((LPVOID)ret.second);
            }

            // don't use this
            void disable() {
                MH_DisableHook((LPVOID)m_address);
            }
        };

        CINNAMON_API PythonHook hookPython(std::string functionname, size_t address, pybind::function detour);

        CINNAMON_API PythonHook hookPython(pybind::function toHook, pybind::function detour);

        CINNAMON_API MH_STATUS hookCinnamon(PVOID address, PVOID hook, LPVOID* original);

        CINNAMON_API MH_STATUS init();
    }
}