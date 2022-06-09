#pragma once

#include "cocos2d.h"
#include "pybind11.h"
#include <pybind11/operators.h>
#include "macros.h"

namespace py = pybind11;
USING_NS_CC;

void CCSize_init(py::module &m) {
    auto c = py::class_<CCSize>(m, "CCSize");
        c.def(py::init<float, float>());
        c.def_readwrite("width", &CCSize::width);
        c.def_readwrite("height", &CCSize::height);
        // operators
        c.def("__repr__", [](CCSize self) { return std::to_string(self.width) + ", " + std::to_string(self.height); });
        /*
        c.def(py::self + py::self);
        c.def(py::self += py::self);
        c.def(py::self * py::self);
        c.def(py::self *= py::self);
        c.def(py::self / py::self);
        c.def(py::self /= py::self);
        c.def("__eq__", [](CCSize &self, CCSize &other) { return self.equals(other); });
        c.def("__ne__", [](CCSize &self, CCSize &other) { return !self.equals(other); });
        */
}