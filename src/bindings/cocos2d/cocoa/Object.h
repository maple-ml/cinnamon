#pragma once

#include "cocos2d.h"
#include "pybind11.h"
#include "macros.h"

namespace py = pybind11;
USING_NS_CC;

void CCObject_init(py::module &m) {
    auto c = py::class_<CCObject, CCCopying>(m, "CCObject");
        c.def("release", &CCObject::release);
        c.def("retain", &CCObject::retain);
        c.def("autorelease", &CCObject::autorelease);
        c.def("copy", &CCObject::copy);
        c.def("isSingleReference", &CCObject::isSingleReference);
        c.def("retainCount", &CCObject::retainCount);
        c.def("isEqual", &CCObject::isEqual);
        c.def("update", &CCObject::update);
        CINNAMON_BIND_GETSET(CCObject, Tag);
        c.def("setObjType", &CCObject::setObjType);
}