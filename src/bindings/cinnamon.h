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
        threading.attr("Thread")("target"_a=mod).attr("start")();
    }

    class Mod {
    public:
        std::string name;
        std::string version;
        std::string author;
        std::string description;

        void loop() {
            // keep interpreter alive
            py::exec("while True: pass");
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

    auto c = py::class_<cinnamon_py::Mod>(m, "Mod");
        c.def("loop", &cinnamon_py::Mod::loop);
}