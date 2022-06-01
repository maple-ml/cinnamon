#pragma once

#include "macros.h"
#include "utilities.h"
#include "hooks.h"

#include "bindings/geometrydash/geometrydash.h"

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

    void loop() {
        // keep interpreter alive
        py::exec("while True: pass");
    }
}

PYBIND11_EMBEDDED_MODULE(cinnamon, m) {
    m.def("run", &utilities::runPyOnMain); // broken atm
    m.def("loop", &cinnamon_py::loop);
    m.def("enable_debug", &utilities::enableDebugMode);
    m.def("hook", &hooks::hookPython); // hooks a direct address
    m.def("alert", py::overload_cast<std::string>(&cinnamon_py::alert));
    m.def("alert", py::overload_cast<std::string, const char*>(&cinnamon_py::alert));
    m.def("alert", py::overload_cast<std::string, const char*, const char*>(&cinnamon_py::alert));
    m.def("log", &utilities::log);
    m.attr("base") = utilities::getBase();
    m.attr("gd_path") = utilities::getGDPath();
}