#pragma once

#include "cocos2d.h"
#include "pybind11.h"
#include "macros.h"

namespace py = pybind11;
USING_NS_CC;

void CCDirector_init(py::module &m) {
    auto c = py::class_<CCDirector, CCObject>(m, "CCDirector");
        c.def(py::init(&CCDirector::sharedDirector));
        c.def("init", &CCDirector::init);
        c.def("getClassTypeInfo", &CCDirector::getClassTypeInfo);
        c.def("getRunningScene", &CCDirector::getRunningScene);
        CINNAMON_BIND_GETSET(CCDirector, AnimationInterval);
        c.def("isDisplayStats", &CCDirector::isDisplayStats);
        CINNAMON_BIND_SET(CCDirector, DisplayStats);
        CINNAMON_BIND_GET(CCDirector, SecondsPerFrame);
        c.def("isNextDeltaTimeZero", &CCDirector::isNextDeltaTimeZero);
        CINNAMON_BIND_SET(CCDirector, NextDeltaTimeZero);
        c.def("isPaused", &CCDirector::isPaused);
        CINNAMON_BIND_GET(CCDirector, TotalFrames);
        CINNAMON_BIND_GETSET(CCDirector, Projection);
        c.def("reshapeProjection", &CCDirector::reshapeProjection);
        CINNAMON_BIND_SET(CCDirector, Viewport);
        c.def("isSendCleanupToScene", &CCDirector::isSendCleanupToScene);
        CINNAMON_BIND_GETSET(CCDirector, NotificationNode);
        CINNAMON_BIND_GETSET(CCDirector, Delegate);
        CINNAMON_BIND_GET(CCDirector, WinSize);
        CINNAMON_BIND_GET(CCDirector, WinSizeInPixels);
        CINNAMON_BIND_GET(CCDirector, VisibleSize);
        c.def("convertToGL", &CCDirector::convertToGL);
        c.def("convertToUI", &CCDirector::convertToUI);
        c.def("getZEye", &CCDirector::getZEye);
        c.def("runWithScene", &CCDirector::runWithScene);
        c.def("pushScene", &CCDirector::pushScene);
        c.def("popScene", &CCDirector::popScene);
        c.def("popToRootScene", &CCDirector::popToRootScene);
        c.def("popToSceneStackLevel", &CCDirector::popToSceneStackLevel);
        c.def("replaceScene", &CCDirector::replaceScene);
        c.def("end", &CCDirector::end);
        c.def("pause", &CCDirector::pause);
        c.def("resume", &CCDirector::resume);
        c.def("stopAnimation", &CCDirector::stopAnimation);
        c.def("startAnimation", &CCDirector::startAnimation);
        c.def("drawScene", &CCDirector::drawScene);
        c.def("purgeCachedData", &CCDirector::purgeCachedData);
        CINNAMON_BIND_SET(CCDirector, DefaultValues);
        CINNAMON_BIND_SET(CCDirector, GLDefaultValues);
        CINNAMON_BIND_SET(CCDirector, AlphaBlending);
        CINNAMON_BIND_SET(CCDirector, DepthTest);
        c.def("mainLoop", &CCDirector::mainLoop);
        CINNAMON_BIND_GETSET(CCDirector, ContentScaleFactor);
        c.def("checkSceneReference", &CCDirector::checkSceneReference);
        c.def("getNextScene", &CCDirector::getNextScene);
        c.def("levelForSceneInStack", &CCDirector::levelForSceneInStack);
        c.def("popSceneWithTransition", &CCDirector::popSceneWithTransition);
        c.def("popToSceneInStack", &CCDirector::popToSceneInStack);
        c.def("sceneCount", &CCDirector::sceneCount);
        c.def("willSwitchToScene", &CCDirector::willSwitchToScene);
        c.def("removeStatsLabel", &CCDirector::removeStatsLabel);
        c.def("resetSmoothFixCounter", &CCDirector::resetSmoothFixCounter);
        CINNAMON_BIND_SET(CCDirector, DeltaTime);
        c.def("setupScreenScale", &CCDirector::setupScreenScale);
        c.def("updateContentScale", &CCDirector::updateContentScale);
        c.def("updateScreenScale", &CCDirector::updateScreenScale);
        c.def("getLoadedTextureQuality", &CCDirector::getLoadedTextureQuality);
        c.def("sharedDirector", &CCDirector::sharedDirector);
}