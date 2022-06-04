#pragma once

#include "macros.h"
#include "utilities.h"

#include "layers_scenes_transitions_nodes/FLAlertLayer.h"
#include "hooks.h"

namespace cinnamon_py {
    void alert(std::string caption, const char* btn1, const char* btn2) {
        FLAlertLayer::create(nullptr, "Alert", btn1, btn2, caption)->show();
    }

    void alert(std::string caption, const char* btn1) {
        FLAlertLayer::create(nullptr, "Alert", btn1, nullptr, caption)->show();
    }

    void alert(std::string caption) {
        FLAlertLayer::create(nullptr, "Alert", "Ok", nullptr, caption)->show();
    }

    void register_mod(py::object mod) {
        using namespace pybind11::literals;
        py::module_ threading = py::module_::import("threading");
        
        threading.attr("Thread")("target"_a=mod.attr("_init"), "args"_a=py::make_tuple(mod)).attr("start")();
    }

    class Mod {
    public:
        Mod() {

        }

        void loop() {
            py::exec("while True: pass"); // keep interpreter alive
        }

        static void _init(py::object mod_cls) { // PRIVATE TO PY, called on thread, runs __init__ and starts loop
            py::object mod = mod_cls();

            globals::modules.insert<std::pair<std::string, py::object>>(std::pair<std::string, py::object>(mod.attr("name").cast<std::string>(), mod));

            utilities::log("Starting loop", "DEBUG");
            mod.attr("loop")();
        }

        void on_enable() {

        }

        void on_disable() {
            
        }
    };
}

PYBIND11_EMBEDDED_MODULE(cinnamon, m) {
    m.def("run", &utilities::runPyOnMain); // broken atm
    m.def("enable_debug", &utilities::enableDebugMode);
    m.def("hook", &hooks::hookPython); // hooks a direct address
    m.def("alert", py::overload_cast<std::string>(&cinnamon_py::alert));
    m.def("alert", py::overload_cast<std::string, const char*>(&cinnamon_py::alert));
    m.def("alert", py::overload_cast<std::string, const char*, const char*>(&cinnamon_py::alert));
    m.def("log", &utilities::log);
    m.def("register_mod", &cinnamon_py::register_mod);
    m.attr("base") = utilities::getBase();
    m.attr("gd_path") = utilities::getGDPath();

    auto c = py::class_<cinnamon_py::Mod>(m, "Mod", py::dynamic_attr());
        c.def(py::init<>());
        c.def("_init", &cinnamon_py::Mod::_init);
        c.def("loop", &cinnamon_py::Mod::loop);
}