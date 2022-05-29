#pragma once

#include "macros.h"
#include "utilities.h"
#include "hooks.h"

#include "bindings/geometrydash/geometrydash.h"

void alert(const char* title, std::string caption, const char* btn1, const char* btn2) {
    std::cout << title << caption << btn1 << btn2 << std::endl;
    FLAlertLayer::create(nullptr, title, btn1, btn2, caption)->show();
}

PYBIND11_EMBEDDED_MODULE(cinnamon, m) {
    m.def("run", &utilities::runPyOnMain); // broken atm
    m.def("get_gd_path", &utilities::getGDPath);
    m.def("enable_debug", &utilities::enableDebugMode);
    m.def("hook_address", &hooks::hookAddressPython); // hooks a direct address
    m.def("alert", &alert);
    m.attr("base") = utilities::getBase();
}