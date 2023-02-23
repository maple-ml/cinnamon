#pragma once
#include "pybind11.h"
#include "pybind11/embed.h"
#include <cocos2d.h>
#include "MinHook.h"

USING_NS_CC;
namespace pybind = pybind11;

namespace cinnamon {
    namespace hooks {
        std::multimap<std::string, pybind::function> pythonHooks = std::multimap<std::string, pybind::function>();
        std::multimap<std::string, void*> hooks = std::multimap<std::string, void*>();

        class PythonHook {
        public:
            std::string m_functionname;
            size_t m_address;
            pybind::function m_detour;

            PythonHook() {}

            PythonHook(std::string functionname, size_t address, pybind::function detour) {
                m_functionname = functionname;
                m_address = address;
                m_detour = detour;
                
                cinnamon::hooks::pythonHooks.insert(std::pair<std::string, pybind::function>(functionname, detour));

                MH_EnableHook((LPVOID)address);
            }

            PythonHook(pybind::function toHook, pybind::function detour) {
                std::pair<std::string, size_t> ret = toHook(detour).cast<std::pair<std::string, size_t>>();

                m_functionname = ret.first;
                m_address = ret.second;
                m_detour = detour;

                cinnamon::hooks::pythonHooks.insert(std::pair<std::string, pybind::function>(ret.first, detour));

                MH_EnableHook((LPVOID)ret.second);
            }

            // don't use this
            void disable() {
                MH_DisableHook((LPVOID)m_address);
            }
        };

        // C++ hook
        class Hook {
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

        PythonHook hookPython(std::string functionname, size_t address, pybind::function detour) {
            return PythonHook(functionname, address, detour);;
        }

        PythonHook hookPython(pybind::function toHook, pybind::function detour) {
            std::pair<std::string, size_t> ret = toHook(detour).cast<std::pair<std::string, size_t>>();

            std::string functionname = ret.first;
            size_t address = ret.second;

            return PythonHook(functionname, address, detour);
        }

        MH_STATUS hookCinnamon(PVOID address, PVOID hook, LPVOID* original) {
            std::stringstream addr_stream;
            addr_stream << std::hex << address;
            std::string addr( addr_stream.str() );

            cinnamon::logger::log("Hooking " + addr + ": " + std::to_string((unsigned int)(address)), "DEBUG");
            MH_STATUS status = MH_CreateHook(address, hook, original);
            cinnamon::logger::log(std::string("Hooked ") + addr + std::string(" with status ") + std::string(MH_StatusToString(status)), "DEBUG");
            return status;
        }

        MH_STATUS init() {
            MH_STATUS status = MH_Initialize();
            return status;
        }
    }
}