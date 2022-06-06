#pragma once

#include "cocos2d.h"
#include "pybind11.h"
#include "macros.h"

namespace py = pybind11;
USING_NS_CC;

void CCScene_init(py::module &m) {
    auto c = py::class_<CCScene, CCNode>(m, "CCScene");
        c.def(py::init(&CCScene::create));
        c.def("create", &CCScene::create);
}