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
                m_enabled = true;
                
                cinnamon::hooks::pythonHooks.insert(std::pair<std::string, pybind::function>(functionname, detour));

                MH_EnableHook((LPVOID)address);
            }

            PythonHook(pybind::function toHook, pybind::function detour) {
                std::pair<std::string, size_t> ret = toHook(detour).cast<std::pair<std::string, size_t>>();

                m_functionname = ret.first;
                m_address = ret.second;
                m_detour = detour;
                m_modFilePath = cinnamon::python::getPythonFileFromObject(m_detour);
                m_enabled = true;

                cinnamon::hooks::pythonHooks.insert(std::pair<std::string, pybind::function>(ret.first, detour));

                MH_EnableHook((LPVOID)ret.second);
            }

            void disable() {
                m_enabled = false;
            }

            bool remove() {
                // remove this pair from map
                auto range = cinnamon::hooks::pythonHooks.equal_range(m_functionname);
                for (auto it = range.first; it != range.second; ++it) {
                    if (it->second == m_detour) {
                        pythonHooks.erase(it);
                        return true;
                    }
                }
                return false;
            }

            void enable() {
                m_enabled = true;

                // iterate of modInstances
                for (const auto& [key, value] : cinnamon::module::modInstances) {
                    std::cout << value->getName() << std::endl;
                }

                //check if already saved in hooks
                for (auto& hook : cinnamon::module::modInstances[m_modFilePath]->m_hooks) {
                    if (
                        hook->m_detour.attr("__name__").cast<std::string>() == m_detour.attr("__name__").cast<std::string>() &&
                        hook->m_functionname == m_functionname &&
                        hook->m_modFilePath == m_modFilePath
                    ) {
                        return;
                    }
                }
                // save this hook to the mod
                cinnamon::module::modInstances[m_modFilePath]->m_hooks.push_back(this);
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