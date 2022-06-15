#pragma once

#include "macros.h"
#include "utilities.h"

#include "layers_scenes_transitions_nodes/FLAlertLayer.h"
#include "hooks.h"

namespace cinnamon {

void alert(const char* title, std::string caption, const char* btn1, const char* btn2, float width) {
    FLAlertLayer::create(nullptr, title, btn1, btn2, width, caption)->show();
}

void alert(const char* title, std::string caption, const char* btn1, const char* btn2) {
    FLAlertLayer::create(nullptr, title, btn1, btn2, caption)->show();
}

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
        py::object mod;
        try {
            mod = mod_cls();
        }
        catch (const py::error_already_set& e) {
            globals::startupErrorOccured = true;
            py::print("Exception has occured while initializing mod class: " + mod_cls.attr("__name__").cast<std::string>());
            py::print(e.what());
            return;
        }
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
    utilities::log("Binding cinnamon", "DEBUG");

    m.def("run", &utilities::runPyOnMain); // broken atm
    m.def("enable_debug", &utilities::enableDebugMode);
    m.def("hook", py::overload_cast<std::string, size_t, py::function>(&cinnamon::hookPython)); // old method
    m.def("hook", py::overload_cast<py::function, py::function>(&cinnamon::hookPython)); // new method
    m.def("alert", py::overload_cast<std::string>(&cinnamon::alert));
    m.def("alert", py::overload_cast<std::string, const char*>(&cinnamon::alert));
    m.def("alert", py::overload_cast<std::string, const char*, const char*>(&cinnamon::alert));
    m.def("log", py::overload_cast<std::string, LoggingLevel>(&utilities::log));
    m.def("log", py::overload_cast<std::string, std::string>(&utilities::log));
    m.def("register_mod", &cinnamon::register_mod);
    m.attr("base") = utilities::getBase();
    m.attr("gd_path") = utilities::getGDPath();

    auto c = py::class_<cinnamon::Mod>(m, "Mod", py::dynamic_attr());
        c.def(py::init<>());
        c.def("_init", &cinnamon::Mod::_init);
        c.def("loop", &cinnamon::Mod::loop);

    auto c2 = py::class_<cinnamon::PythonHook>(m, "Hook");
        c2.def(py::init<>());
        c2.def_readwrite("functionname", &cinnamon::PythonHook::m_functionname);
        c2.def_readwrite("address", &cinnamon::PythonHook::m_address);
        c2.def_readwrite("detour", &cinnamon::PythonHook::m_detour);
        c2.def_readwrite("enabled", &cinnamon::PythonHook::m_enabled);

    utilities::log("Binded cinnamon", "DEBUG");
}