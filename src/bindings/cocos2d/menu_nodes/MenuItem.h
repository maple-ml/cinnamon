#pragma once

#include "cocos2d.h"
#include "pybind11.h"
#include "macros.h"

namespace py = pybind11;
USING_NS_CC;

void CCMenuItem_init(py::module &m) {
    auto c = py::class_<CCMenuItem, CCNode>(m, "CCMenuItem"); // base class = CCNodeRGBA
        c.def(py::init([]() { return CCMenuItem::create(); }));
        c.def(py::init([](CCObject* rec, SEL_MenuHandler selector) { return CCMenuItem::create(rec, selector); }));
        c.def("create", py::overload_cast<>(&CCMenuItem::create));
        c.def("create", py::overload_cast<CCObject*, SEL_MenuHandler>(&CCMenuItem::create));
        c.def("initWithTarget", &CCMenuItem::initWithTarget);
        c.def("rect", &CCMenuItem::rect);
        c.def("activate", &CCMenuItem::activate);
        c.def("selected", &CCMenuItem::selected);
        c.def("unselected", &CCMenuItem::unselected);
        c.def("registerScriptTapHandler", &CCMenuItem::registerScriptTapHandler);
        c.def("unregisterScriptTapHandler", &CCMenuItem::unregisterScriptTapHandler);
        CINNAMON_BIND_GET(CCMenuItem, ScriptTapHandler);
        c.def("isEnabled", &CCMenuItem::isEnabled);
        CINNAMON_BIND_SET(CCMenuItem, Enabled);
        c.def("isSelected", &CCMenuItem::isSelected);
        CINNAMON_BIND_SET(CCMenuItem, Target);
}