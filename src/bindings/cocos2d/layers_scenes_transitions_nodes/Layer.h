#pragma once

#include "cocos2d.h"
#include "pybind11.h"
#include "macros.h"

namespace py = pybind11;
USING_NS_CC;

void CCLayer_init(py::module &m) {
    auto c = py::class_<CCLayer>(m, "CCLayer");
        c.def("__init__", &CCLayer::create);
        c.def("create", &CCLayer::create);
        c.def("init", &CCLayer::init);
        c.def("onEnter", &CCLayer::onEnter);
        c.def("onExit", &CCLayer::onExit);
        c.def("onEnterTransitionDidFinish", &CCLayer::onEnterTransitionDidFinish);
        c.def("CCTouchBegan", &CCLayer::CCTouchBegan);
        c.def("CCTouchMoved", &CCLayer::CCTouchMoved);
        c.def("CCTouchEnded", &CCLayer::CCTouchEnded);
        c.def("CCTouchCancelled", &CCLayer::CCTouchCancelled);
        c.def("CCTouchesBegan", &CCLayer::CCTouchesBegan);
        c.def("CCTouchesMoved", &CCLayer::CCTouchesMoved);
        c.def("CCTouchesEnded", &CCLayer::CCTouchesEnded);
        c.def("CCTouchesCancelled", &CCLayer::CCTouchesCancelled);
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
        CINNAMON_BIND_SET(CCLayer, isMouseEnabled);
        c.def("registerScriptKeypadHandler", &CCLayer::registerScriptKeypadHandler);
        c.def("unregisterScriptKeypadHandler", &CCLayer::unregisterScriptKeypadHandler);
        c.def("keyBackClicked", &CCLayer::keyBackClicked);
        c.def("keyMenuClicked", &CCLayer::keyMenuClicked);
        c.def("keyDown", &CCLayer::keyDown);
        c.def("getScriptTouchHandlerEntry", &CCLayer::getScriptTouchHandlerEntry);
        c.def("getScriptKeypadHandlerEntry", &CCLayer::getScriptKeypadHandlerEntry);
        c.def("getScriptAccelerateHandlerEntry", &CCLayer::getScriptAccelerateHandlerEntry);
}