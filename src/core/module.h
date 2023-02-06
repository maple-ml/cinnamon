#pragma once
#include "pybind11.h"
#include "pybind11/embed.h"
#include <cocos2d.h>
#include "MinHook.h"
#include "core/hooks.h"

namespace pybind = pybind11;

namespace cinnamon {
    namespace module {
        std::map<std::string, pybind::object> modules = std::map<std::string, pybind::object>();

        // turn into metaclass
        void register_mod(pybind::object mod) {
            using namespace pybind11::literals;
            pybind::module_ threading = pybind::module_::import("threading");
            
            threading.attr("Thread")("target"_a=mod.attr("_init"), "args"_a=pybind::make_tuple(mod)).attr("start")();
        }

        class Mod {
        public:
            Mod() {

            }

            void loop() {
                pybind::exec("while True: pass"); // keep interpreter alive
            }

            static void _init(pybind::object mod_cls) { // PRIVATE TO PY, called on thread, runs __init__ and starts loop
                pybind::object mod;
                try {
                    mod = mod_cls();
                }
                catch (const pybind::error_already_set& e) {
                    //globals::startupErrorOccured = true;
                    pybind::print("Exception has occured while initializing mod class: " + mod_cls.attr("__name__").cast<std::string>());
                    pybind::print(e.what());
                    return;
                }
                cinnamon::module::modules.insert<std::pair<std::string, pybind::object>>(std::pair<std::string, pybind::object>(mod.attr("name").cast<std::string>(), mod));

                cinnamon::logger::log("Starting loop", "DEBUG");
                mod.attr("loop")();
            }

            void on_enable() {

            }

            void on_disable() {
                
            }
        };
    }
}

PYBIND11_EMBEDDED_MODULE(cinnamon, m) {
    cinnamon::logger::log("Binding cinnamon", "DEBUG");

    auto mod = pybind::class_<cinnamon::module::Mod>(m, "Mod", pybind::dynamic_attr());
        mod.def(pybind::init<>());
        mod.def("_init", &cinnamon::module::Mod::_init);
        mod.def("loop", &cinnamon::module::Mod::loop);

    
    auto pyhook = pybind::class_<cinnamon::hooks::PythonHook>(m, "Hook");
        pyhook.def(pybind::init<>());
        pyhook.def(pybind::init<std::string, size_t, pybind::function>());
        pyhook.def(pybind::init<pybind::function, pybind::function>());
        pyhook.def_readwrite("functionname", &cinnamon::hooks::PythonHook::m_functionname);
        pyhook.def_readwrite("address", &cinnamon::hooks::PythonHook::m_address);
        pyhook.def_readwrite("detour", &cinnamon::hooks::PythonHook::m_detour);
    
    m.def("register_mod", &cinnamon::module::register_mod);

    cinnamon::logger::log("Binded cinnamon", "DEBUG");
}
