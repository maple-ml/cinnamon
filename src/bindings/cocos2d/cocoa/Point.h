#pragma once

#include "cocos2d.h"
#include "pybind11.h"
#include <pybind11/operators.h>
#include "macros.h"

namespace py = pybind11;
USING_NS_CC;

void CCPoint_init(py::module &m) {
    auto c = py::class_<CCPoint>(m, "CCPoint");
        c.def(py::init<float, float>());
        c.def_readwrite("x", &CCPoint::x);
        c.def_readwrite("y", &CCPoint::y);
        // operators
        c.def("__repr__", [](CCPoint self) { return std::to_string(self.x) + ", " + std::to_string(self.y); });
        /*
        c.def(py::self + py::self);
        c.def(py::self += py::self);
        c.def(py::self * py::self);
        c.def(py::self *= py::self);
        c.def(py::self / py::self);
        c.def(py::self /= py::self);
        c.def("__eq__", [](CCPoint &self, CCPoint &other) { return self.equals(other); });
        c.def("__ne__", [](CCPoint &self, CCPoint &other) { return !self.equals(other); });
        */
}