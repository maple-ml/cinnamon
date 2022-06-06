#pragma once

#include "cocos2d.h"
#include "pybind11.h"
#include "macros.h"

namespace py = pybind11;
USING_NS_CC;

void CCLayer_init(py::module &m) {
    // more base classes: CCTouchDelegate, CCAccelerometerDelegate, CCKeypadDelegate, CCKeyboardDelegate, CCMouseDelegate
    auto c = py::class_<CCLayer, CCNode>(m, "CCLayer");
        c.def(py::init(&CCLayer::create));
        c.def("create", &CCLayer::create);
        c.def("init", &CCLayer::init);
        c.def("onEnter", &CCLayer::onEnter);
        c.def("onExit", &CCLayer::onExit);
        c.def("onEnterTransitionDidFinish", &CCLayer::onEnterTransitionDidFinish);
        c.def("ccTouchBegan", &CCLayer::ccTouchBegan);
        c.def("ccTouchMoved", &CCLayer::ccTouchMoved);
        c.def("ccTouchEnded", &CCLayer::ccTouchEnded);
        c.def("ccTouchCancelled", &CCLayer::ccTouchCancelled);
        c.def("ccTouchesBegan", &CCLayer::ccTouchesBegan);
        c.def("ccTouchesMoved", &CCLayer::ccTouchesMoved);
        c.def("ccTouchesEnded", &CCLayer::ccTouchesEnded);
        c.def("ccTouchesCancelled", &CCLayer::ccTouchesCancelled);
        c.def("didAccelerate", &CCLayer::didAccelerate);
        c.def("registerScriptAccelerateHandler", &CCLayer::registerScriptAccelerateHandler);
        c.def("unregisterScriptAccelerateHandler", &CCLayer::unregisterScriptAccelerateHandler);
        c.def("registerWithTouchDispatcher", &CCLayer::registerWithTouchDispatcher);
        c.def("registerScriptTouchHandler", &CCLayer::registerScriptTouchHandler);
        c.def("unregisterScriptTouchHandler", &CCLayer::unregisterScriptTouchHandler);
        c.def("isTouchEnabled", &CCLayer::isTouchEnabled);
        CINNAMON_BIND_SET(CCLayer, TouchEnabled);
        CINNAMON_BIND_GETSET(CCLayer, TouchMode);
        CINNAMON_BIND_GETSET(CCLayer, TouchPriority);
        c.def("isAccelerometerEnabled", &CCLayer::isAccelerometerEnabled);
        CINNAMON_BIND_SET(CCLayer, AccelerometerEnabled);
        CINNAMON_BIND_SET(CCLayer, AccelerometerInterval);
        c.def("isKeypadEnabled", &CCLayer::isKeypadEnabled);
        CINNAMON_BIND_SET(CCLayer, KeypadEnabled);
        c.def("isKeyboardEnabled", &CCLayer::isKeyboardEnabled);
        CINNAMON_BIND_SET(CCLayer, KeyboardEnabled);
        c.def("isMouseEnabled", &CCLayer::isMouseEnabled);
        CINNAMON_BIND_SET(CCLayer, MouseEnabled);
        c.def("registerScriptKeypadHandler", &CCLayer::registerScriptKeypadHandler);
        c.def("unregisterScriptKeypadHandler", &CCLayer::unregisterScriptKeypadHandler);
        c.def("keyBackClicked", &CCLayer::keyBackClicked);
        c.def("keyMenuClicked", &CCLayer::keyMenuClicked);
        c.def("keyDown", &CCLayer::keyDown);
}