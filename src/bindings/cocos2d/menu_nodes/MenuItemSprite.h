#pragma once

#include "cocos2d.h"
#include "pybind11.h"
#include "macros.h"

namespace py = pybind11;
USING_NS_CC;

void CCMenuItemSprite_init(py::module &m) {
    auto c = py::class_<CCMenuItemSprite, CCMenuItem>(m, "CCMenuItemSprite");
        /* // no one even uses this class
        c.def(py::init([](CCNode* normalSprite, CCNode* selectedSprite, CCNode* disabledSprite) {
            return CCMenuItemSprite::create(normalSprite, selectedSprite, disabledSprite);
        }));
        c.def(py::init([](CCNode* normalSprite, CCNode* selectedSprite, CCObject* disabledSprite, SEL_MenuHandler selector) {
            return CCMenuItemSprite::create(normalSprite, selectedSprite, disabledSprite, selector);
        }));
        c.def(py::init([](CCNode* normalSprite, CCNode* selectedSprite, CCNode* disabledSprite, CCObject* target, SEL_MenuHandler selector) {
            return CCMenuItemSprite::create(normalSprite, selectedSprite, disabledSprite, target, selector);
        }));
        c.def("create", py::overload_cast<CCNode*, CCNode*, CCNode*>(&CCMenuItemSprite::create));
        c.def("create", py::overload_cast<CCNode*, CCNode*, CCObject*, SEL_MenuHandler>(&CCMenuItemSprite::create));
        c.def("create", py::overload_cast<CCNode*, CCNode*, CCNode*, CCObject*, SEL_MenuHandler>(&CCMenuItemSprite::create));
        */
        c.def("initWithNormalSprite", &CCMenuItemSprite::initWithNormalSprite);
        c.def("selected", &CCMenuItemSprite::selected);
        c.def("unselected", &CCMenuItemSprite::unselected);
        CINNAMON_BIND_SET(CCMenuItemSprite, Enabled);
}