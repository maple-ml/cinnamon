#pragma once

#include "cocos2d.h"
#include "pybind11.h"
#include "macros.h"

namespace py = pybind11;
USING_NS_CC;

void CCScene_init(py::module &m) {
    auto c = py::class_<CCScene>(m, "CCScene");
        c.def("__init__", &CCScene::create);
        c.def("create", &CCScene::create);
}