#pragma once

#include "cocos2d.h"
#include "pybind11.h"
#include "macros.h"

namespace py = pybind11;
USING_NS_CC;

void CCCopying_init(py::module &m) {
    auto c = py::class_<CCCopying>(m, "CCCopying");
        c.def("copyWithZone", &CCCopying::copyWithZone);
}