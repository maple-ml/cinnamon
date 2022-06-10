#pragma once

#include "cocos2d.h"
#include "pybind11.h"
#include "macros.h"

namespace py = pybind11;
USING_NS_CC;

void CCNode_init(py::module &m) {
    auto c = py::class_<CCNode, CCObject>(m, "CCNode");
        // members
        c.def_property("position", py::overload_cast<>(&CCNode::getPosition), py::overload_cast<const CCPoint&>(&CCNode::setPosition));
        // functions
        c.def("__init__", &CCNode::create);
        c.def("create", &CCNode::create);
        c.def("init", &CCNode::init);
        c.def("description", &CCNode::description);
        c.def("setZOrder_", &CCNode::_setZOrder);
        CINNAMON_BIND_GETSET(CCNode, ZOrder);
        CINNAMON_BIND_GETSET(CCNode, VertexZ);
        CINNAMON_BIND_GETSET(CCNode, ScaleX);
        CINNAMON_BIND_GETSET(CCNode, ScaleY);
        c.def("getScale", py::overload_cast<>(&CCNode::getScale));
        c.def("setScale", py::overload_cast<float>(&CCNode::setScale));
        c.def("setScale", py::overload_cast<float, float>(&CCNode::setScale));
        c.def("getPosition", py::overload_cast<>(&CCNode::getPosition));
        c.def("setPosition", py::overload_cast<const CCPoint&>(&CCNode::setPosition));
        c.def("setPosition", py::overload_cast<float, float>(&CCNode::setPosition));
        CINNAMON_BIND_GETSET(CCNode, PositionX);
        CINNAMON_BIND_GETSET(CCNode, PositionY);
        CINNAMON_BIND_GETSET(CCNode, SkewX);
        CINNAMON_BIND_GETSET(CCNode, SkewY);
        CINNAMON_BIND_GETSET(CCNode, AnchorPoint);
        CINNAMON_BIND_GET(CCNode, AnchorPointInPoints);
        CINNAMON_BIND_GETSET(CCNode, ContentSize);
        CINNAMON_BIND_GET(CCNode, ScaledContentSize);
        CINNAMON_BIND_SET(CCNode, Visible);
        c.def("isVisible", &CCNode::isVisible);
        CINNAMON_BIND_GETSET(CCNode, Rotation);
        CINNAMON_BIND_GETSET(CCNode, RotationX);
        CINNAMON_BIND_GETSET(CCNode, RotationY);
        CINNAMON_BIND_GETSET(CCNode, OrderOfArrival);
        CINNAMON_BIND_GETSET(CCNode, GLServerState);
        c.def("ignoreAnchorPointForPosition", &CCNode::ignoreAnchorPointForPosition);
        c.def("isIgnoreAnchorPointForPosition", &CCNode::isIgnoreAnchorPointForPosition);
        c.def("addChild", py::overload_cast<CCNode*>(&CCNode::addChild));
        c.def("addChild", py::overload_cast<CCNode*, int>(&CCNode::addChild));
        c.def("addChild", py::overload_cast<CCNode*, int, int>(&CCNode::addChild));
        c.def("getChildByTag", &CCNode::getChildByTag);
        c.def("getChildren", &CCNode::getChildren);
        c.def("getChildrenCount", &CCNode::getChildrenCount);
        CINNAMON_BIND_GETSET(CCNode, Parent);
        c.def("removeFromParent", &CCNode::removeFromParent);
        c.def("removeFromParentAndCleanup", &CCNode::removeFromParentAndCleanup);
        c.def("removeChild", py::overload_cast<CCNode*>(&CCNode::removeChild));
        c.def("removeChild", py::overload_cast<CCNode*, bool>(&CCNode::removeChild));
        c.def("removeChildByTag", py::overload_cast<int, bool>(&CCNode::removeChildByTag));
        c.def("removeChildByTag", py::overload_cast<int, bool>(&CCNode::removeChildByTag));
        c.def("reorderChild", &CCNode::reorderChild);
        c.def("sortAllChildren", &CCNode::sortAllChildren);
        CINNAMON_BIND_GETSET(CCNode, Grid);
        CINNAMON_BIND_GETSET(CCNode, Tag);
        CINNAMON_BIND_GETSET(CCNode, UserData);
        CINNAMON_BIND_GETSET(CCNode, UserObject);
        CINNAMON_BIND_GETSET(CCNode, ShaderProgram);
        CINNAMON_BIND_GET(CCNode, Camera);
        c.def("isRunning", &CCNode::isRunning);
        c.def("registerScriptHandler", &CCNode::registerScriptHandler);
        c.def("unregisterScriptHandler", &CCNode::unregisterScriptHandler);
        c.def("onEnter", &CCNode::onEnter);
        c.def("onEnterTransitionDidFinish", &CCNode::onEnterTransitionDidFinish);
        c.def("onExit", &CCNode::onExit);
        c.def("onExitTransitionDidStart", &CCNode::onExitTransitionDidStart);
        c.def("cleanup", &CCNode::cleanup);
        c.def("draw", &CCNode::draw);
        c.def("visit", &CCNode::visit);
        c.def("boundingBox", &CCNode::boundingBox);
        CINNAMON_BIND_GETSET(CCNode, ActionManager);
        c.def("runAction", &CCNode::runAction);
        c.def("stopAllActions", &CCNode::stopAllActions);
        c.def("stopAction", &CCNode::stopAction);
        c.def("stopActionByTag", &CCNode::stopActionByTag);
        CINNAMON_BIND_GET(CCNode, ActionByTag);
        c.def("numberOfRunningActions", &CCNode::numberOfRunningActions);
        CINNAMON_BIND_GETSET(CCNode, Scheduler);
        c.def("scheduleUpdate", &CCNode::scheduleUpdate);
        c.def("scheduleUpdateWithPriority", &CCNode::scheduleUpdateWithPriority);
        c.def("unscheduleUpdate", &CCNode::unscheduleUpdate);
        c.def("schedule", static_cast<void(CCNode::*)(SEL_SCHEDULE, float, unsigned int, float)>(&CCNode::schedule));
        c.def("schedule", static_cast<void(CCNode::*)(SEL_SCHEDULE, float)>(&CCNode::schedule));
        c.def("schedule", static_cast<void(CCNode::*)(SEL_SCHEDULE)>(&CCNode::schedule));
        c.def("scheduleOnce", &CCNode::scheduleOnce);
        c.def("unschedule", &CCNode::unschedule);
        c.def("unscheduleAllSelectors", &CCNode::unscheduleAllSelectors);
        c.def("resumeSchedulerAndActions", &CCNode::resumeSchedulerAndActions);
        c.def("pauseSchedulerAndActions", &CCNode::pauseSchedulerAndActions);
        c.def("update", &CCNode::update);
        c.def("transform", &CCNode::transform);
        c.def("transformAncestors", &CCNode::transformAncestors);
        c.def("convertToNodeSpace", &CCNode::convertToNodeSpace);
        c.def("convertToWorldSpace", &CCNode::convertToWorldSpace);
        c.def("convertToNodeSpaceAR", &CCNode::convertToNodeSpaceAR);
        c.def("convertToWorldSpaceAR", &CCNode::convertToWorldSpaceAR);
        c.def("convertTouchToNodeSpace", &CCNode::convertTouchToNodeSpace);
        c.def("convertTouchToNodeSpaceAR", &CCNode::convertTouchToNodeSpaceAR);
}