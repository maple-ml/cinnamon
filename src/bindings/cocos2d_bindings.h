// AUTOMATICALLY GENERATED PURE BINDING for "cocos2d" module
#pragma once
#include <cocos2d.h>
#include "core/utilities/game.h"
#include "core/hooks.h"
#include "pybind11.h"
#include "pybind11/embed.h"
#include "bindings/manual_bindings.h"
#include "bindings/enums.h"

USING_NS_CC;
namespace pybind = pybind11;

#define uint unsigned int
#define constchar const char
#define longlong long long
#define ulonglong ulong long
#define CONSTCCPoint const CCPoint
#define CONSTCCSize const CCSize
#define CONSTCCRect const CCRect
#define CONSTccBezierConfig const ccBezierConfig
#define CONSTccColor3B const ccColor3B
#define CONSTCCAffineTransform const CCAffineTransform
#define CONSTCCBool const CCBool
#define CONSTCCInteger const CCInteger
#define CONSTCCFloat const CCFloat
#define CONSTCCDouble const CCDouble
#define CONSTCCString const CCString
#define CONSTCCArray const CCArray
#define CONSTCCDictionary const CCDictionary
#define CONSTCCSet const CCSet
#define CONSTstdstring const std::string
#define CONSTCCColor4F const ccColor4F
#define CONSTCCColor4B const ccColor4B

PYBIND11_EMBEDDED_MODULE(cocos2d, m) {

    auto cccopying = pybind::class_<CCCopying>(m, "CCCopying");
    cccopying.def("copyWithZone", &CCCopying::copyWithZone, pybind::return_value_policy::automatic_reference);

    auto ccobject = pybind::class_<CCObject, CCCopying>(m, "CCObject");
    ccobject.def("release", &CCObject::release, pybind::return_value_policy::automatic_reference);
    ccobject.def("retain", &CCObject::retain, pybind::return_value_policy::automatic_reference);
    ccobject.def("autorelease", &CCObject::autorelease, pybind::return_value_policy::automatic_reference);
    ccobject.def("copy", &CCObject::copy, pybind::return_value_policy::automatic_reference);
    ccobject.def("isSingleReference", &CCObject::isSingleReference, pybind::return_value_policy::automatic_reference);
    ccobject.def("retainCount", &CCObject::retainCount, pybind::return_value_policy::automatic_reference);
    ccobject.def("isEqual", &CCObject::isEqual, pybind::return_value_policy::automatic_reference);
    ccobject.def("acceptVisitor", &CCObject::acceptVisitor, pybind::return_value_policy::automatic_reference);
    ccobject.def("update", &CCObject::update, pybind::return_value_policy::automatic_reference);
    ccobject.def("getTag", &CCObject::getTag, pybind::return_value_policy::automatic_reference);
    ccobject.def("setTag", &CCObject::setTag, pybind::return_value_policy::automatic_reference);
    ccobject.def("setObjType", &CCObject::setObjType, pybind::return_value_policy::automatic_reference);

    auto ccnode = pybind::class_<CCNode, CCObject>(m, "CCNode");
    ccnode.def("init", &CCNode::init, pybind::return_value_policy::automatic_reference);
    ccnode.def_static("create", &CCNode::create, pybind::return_value_policy::automatic_reference);
    ccnode.def("description", &CCNode::description, pybind::return_value_policy::automatic_reference);
    ccnode.def("setZOrder", &CCNode::setZOrder, pybind::return_value_policy::automatic_reference);
    ccnode.def("_setZOrder", &CCNode::_setZOrder, pybind::return_value_policy::automatic_reference);
    ccnode.def("getZOrder", &CCNode::getZOrder, pybind::return_value_policy::automatic_reference);
    ccnode.def("setVertexZ", &CCNode::setVertexZ, pybind::return_value_policy::automatic_reference);
    ccnode.def("getVertexZ", &CCNode::getVertexZ, pybind::return_value_policy::automatic_reference);
    ccnode.def("setScaleX", &CCNode::setScaleX, pybind::return_value_policy::automatic_reference);
    ccnode.def("getScaleX", &CCNode::getScaleX, pybind::return_value_policy::automatic_reference);
    ccnode.def("setScaleY", &CCNode::setScaleY, pybind::return_value_policy::automatic_reference);
    ccnode.def("getScaleY", &CCNode::getScaleY, pybind::return_value_policy::automatic_reference);
    ccnode.def("setScale", pybind::overload_cast<float>(&CCNode::setScale), pybind::return_value_policy::automatic_reference);
    ccnode.def("getScale", &CCNode::getScale, pybind::return_value_policy::automatic_reference);
    ccnode.def("setScale", pybind::overload_cast<float, float>(&CCNode::setScale), pybind::return_value_policy::automatic_reference);
    ccnode.def("setPosition", pybind::overload_cast<CONSTCCPoint&>(&CCNode::setPosition), pybind::return_value_policy::automatic_reference);
    ccnode.def("getPosition", pybind::overload_cast<>(&CCNode::getPosition), pybind::return_value_policy::automatic_reference);
    ccnode.def("setPosition", pybind::overload_cast<float, float>(&CCNode::setPosition), pybind::return_value_policy::automatic_reference);
    ccnode.def("setPositionX", &CCNode::setPositionX, pybind::return_value_policy::automatic_reference);
    ccnode.def("getPositionX", &CCNode::getPositionX, pybind::return_value_policy::automatic_reference);
    ccnode.def("setPositionY", &CCNode::setPositionY, pybind::return_value_policy::automatic_reference);
    ccnode.def("getPositionY", &CCNode::getPositionY, pybind::return_value_policy::automatic_reference);
    ccnode.def("setSkewX", &CCNode::setSkewX, pybind::return_value_policy::automatic_reference);
    ccnode.def("getSkewX", &CCNode::getSkewX, pybind::return_value_policy::automatic_reference);
    ccnode.def("setSkewY", &CCNode::setSkewY, pybind::return_value_policy::automatic_reference);
    ccnode.def("getSkewY", &CCNode::getSkewY, pybind::return_value_policy::automatic_reference);
    ccnode.def("setAnchorPoint", &CCNode::setAnchorPoint, pybind::return_value_policy::automatic_reference);
    ccnode.def("getAnchorPoint", &CCNode::getAnchorPoint, pybind::return_value_policy::automatic_reference);
    ccnode.def("getAnchorPointInPoints", &CCNode::getAnchorPointInPoints, pybind::return_value_policy::automatic_reference);
    ccnode.def("setContentSize", &CCNode::setContentSize, pybind::return_value_policy::automatic_reference);
    ccnode.def("getContentSize", &CCNode::getContentSize, pybind::return_value_policy::automatic_reference);
    ccnode.def("setVisible", &CCNode::setVisible, pybind::return_value_policy::automatic_reference);
    ccnode.def("isVisible", &CCNode::isVisible, pybind::return_value_policy::automatic_reference);
    ccnode.def("setRotation", &CCNode::setRotation, pybind::return_value_policy::automatic_reference);
    ccnode.def("getRotation", &CCNode::getRotation, pybind::return_value_policy::automatic_reference);
    ccnode.def("setRotationX", &CCNode::setRotationX, pybind::return_value_policy::automatic_reference);
    ccnode.def("getRotationX", &CCNode::getRotationX, pybind::return_value_policy::automatic_reference);
    ccnode.def("setRotationY", &CCNode::setRotationY, pybind::return_value_policy::automatic_reference);
    ccnode.def("getRotationY", &CCNode::getRotationY, pybind::return_value_policy::automatic_reference);
    ccnode.def("setOrderOfArrival", &CCNode::setOrderOfArrival, pybind::return_value_policy::automatic_reference);
    ccnode.def("getOrderOfArrival", &CCNode::getOrderOfArrival, pybind::return_value_policy::automatic_reference);
    ccnode.def("setGLServerState", &CCNode::setGLServerState, pybind::return_value_policy::automatic_reference);
    ccnode.def("getGLServerState", &CCNode::getGLServerState, pybind::return_value_policy::automatic_reference);
    ccnode.def("ignoreAnchorPointForPosition", &CCNode::ignoreAnchorPointForPosition, pybind::return_value_policy::automatic_reference);
    ccnode.def("isIgnoreAnchorPointForPosition", &CCNode::isIgnoreAnchorPointForPosition, pybind::return_value_policy::automatic_reference);
    ccnode.def("addChild", pybind::overload_cast<CCNode*>(&CCNode::addChild), pybind::return_value_policy::automatic_reference);
    ccnode.def("addChild", pybind::overload_cast<CCNode*, int>(&CCNode::addChild), pybind::return_value_policy::automatic_reference);
    ccnode.def("addChild", pybind::overload_cast<CCNode*, int, int>(&CCNode::addChild), pybind::return_value_policy::automatic_reference);
    ccnode.def("getChildByTag", &CCNode::getChildByTag, pybind::return_value_policy::automatic_reference);
    ccnode.def("getChildren", &CCNode::getChildren, pybind::return_value_policy::automatic_reference);
    ccnode.def("getChildrenCount", &CCNode::getChildrenCount, pybind::return_value_policy::automatic_reference);
    ccnode.def("setParent", &CCNode::setParent, pybind::return_value_policy::automatic_reference);
    ccnode.def("getParent", &CCNode::getParent, pybind::return_value_policy::automatic_reference);
    ccnode.def("removeFromParent", &CCNode::removeFromParent, pybind::return_value_policy::automatic_reference);
    ccnode.def("removeFromParentAndCleanup", &CCNode::removeFromParentAndCleanup, pybind::return_value_policy::automatic_reference);
    ccnode.def("removeChild", pybind::overload_cast<CCNode*>(&CCNode::removeChild), pybind::return_value_policy::automatic_reference);
    ccnode.def("removeChild", pybind::overload_cast<CCNode*, bool>(&CCNode::removeChild), pybind::return_value_policy::automatic_reference);
    ccnode.def("removeChildByTag", pybind::overload_cast<int>(&CCNode::removeChildByTag), pybind::return_value_policy::automatic_reference);
    ccnode.def("removeChildByTag", pybind::overload_cast<int, bool>(&CCNode::removeChildByTag), pybind::return_value_policy::automatic_reference);
    ccnode.def("removeAllChildren", &CCNode::removeAllChildren, pybind::return_value_policy::automatic_reference);
    ccnode.def("removeAllChildrenWithCleanup", &CCNode::removeAllChildrenWithCleanup, pybind::return_value_policy::automatic_reference);
    ccnode.def("reorderChild", &CCNode::reorderChild, pybind::return_value_policy::automatic_reference);
    ccnode.def("sortAllChildren", &CCNode::sortAllChildren, pybind::return_value_policy::automatic_reference);
    ccnode.def("getGrid", &CCNode::getGrid, pybind::return_value_policy::automatic_reference);
    ccnode.def("setGrid", &CCNode::setGrid, pybind::return_value_policy::automatic_reference);
    ccnode.def("getTag", &CCNode::getTag, pybind::return_value_policy::automatic_reference);
    ccnode.def("setTag", &CCNode::setTag, pybind::return_value_policy::automatic_reference);
    ccnode.def("getUserData", &CCNode::getUserData, pybind::return_value_policy::automatic_reference);
    ccnode.def("setUserData", &CCNode::setUserData, pybind::return_value_policy::automatic_reference);
    ccnode.def("getUserObject", &CCNode::getUserObject, pybind::return_value_policy::automatic_reference);
    ccnode.def("setUserObject", &CCNode::setUserObject, pybind::return_value_policy::automatic_reference);
    ccnode.def("getShaderProgram", &CCNode::getShaderProgram, pybind::return_value_policy::automatic_reference);
    ccnode.def("setShaderProgram", &CCNode::setShaderProgram, pybind::return_value_policy::automatic_reference);
    ccnode.def("getCamera", &CCNode::getCamera, pybind::return_value_policy::automatic_reference);
    ccnode.def("isRunning", &CCNode::isRunning, pybind::return_value_policy::automatic_reference);
    ccnode.def("onEnter", &CCNode::onEnter, pybind::return_value_policy::automatic_reference);
    ccnode.def("onEnterTransitionDidFinish", &CCNode::onEnterTransitionDidFinish, pybind::return_value_policy::automatic_reference);
    ccnode.def("onExitTransitionDidStart", &CCNode::onExitTransitionDidStart, pybind::return_value_policy::automatic_reference);
    ccnode.def("onExit", &CCNode::onExit, pybind::return_value_policy::automatic_reference);
    ccnode.def("cleanup", &CCNode::cleanup, pybind::return_value_policy::automatic_reference);
    ccnode.def("draw", &CCNode::draw, pybind::return_value_policy::automatic_reference);
    ccnode.def("visit", &CCNode::visit, pybind::return_value_policy::automatic_reference);
    ccnode.def("boundingBox", &CCNode::boundingBox, pybind::return_value_policy::automatic_reference);
    ccnode.def("setActionManager", &CCNode::setActionManager, pybind::return_value_policy::automatic_reference);
    ccnode.def("getActionManager", &CCNode::getActionManager, pybind::return_value_policy::automatic_reference);
    ccnode.def("runAction", &CCNode::runAction, pybind::return_value_policy::automatic_reference);
    ccnode.def("stopAllActions", &CCNode::stopAllActions, pybind::return_value_policy::automatic_reference);
    ccnode.def("stopAction", &CCNode::stopAction, pybind::return_value_policy::automatic_reference);
    ccnode.def("stopActionByTag", &CCNode::stopActionByTag, pybind::return_value_policy::automatic_reference);
    ccnode.def("getActionByTag", &CCNode::getActionByTag, pybind::return_value_policy::automatic_reference);
    ccnode.def("numberOfRunningActions", &CCNode::numberOfRunningActions, pybind::return_value_policy::automatic_reference);
    ccnode.def("setScheduler", &CCNode::setScheduler, pybind::return_value_policy::automatic_reference);
    ccnode.def("getScheduler", &CCNode::getScheduler, pybind::return_value_policy::automatic_reference);
    ccnode.def("scheduleUpdate", &CCNode::scheduleUpdate, pybind::return_value_policy::automatic_reference);
    ccnode.def("scheduleUpdateWithPriority", &CCNode::scheduleUpdateWithPriority, pybind::return_value_policy::automatic_reference);
    ccnode.def("unscheduleUpdate", &CCNode::unscheduleUpdate, pybind::return_value_policy::automatic_reference);
    ccnode.def("schedule", pybind::overload_cast<SEL_SCHEDULE, float, uint, float>(&CCNode::schedule), pybind::return_value_policy::automatic_reference);
    ccnode.def("schedule", pybind::overload_cast<SEL_SCHEDULE, float>(&CCNode::schedule), pybind::return_value_policy::automatic_reference);
    ccnode.def("scheduleOnce", &CCNode::scheduleOnce, pybind::return_value_policy::automatic_reference);
    ccnode.def("schedule", pybind::overload_cast<SEL_SCHEDULE>(&CCNode::schedule), pybind::return_value_policy::automatic_reference);
    ccnode.def("unschedule", &CCNode::unschedule, pybind::return_value_policy::automatic_reference);
    ccnode.def("unscheduleAllSelectors", &CCNode::unscheduleAllSelectors, pybind::return_value_policy::automatic_reference);
    ccnode.def("resumeSchedulerAndActions", &CCNode::resumeSchedulerAndActions, pybind::return_value_policy::automatic_reference);
    ccnode.def("pauseSchedulerAndActions", &CCNode::pauseSchedulerAndActions, pybind::return_value_policy::automatic_reference);
    ccnode.def("update", &CCNode::update, pybind::return_value_policy::automatic_reference);
    ccnode.def("transform", &CCNode::transform, pybind::return_value_policy::automatic_reference);
    ccnode.def("transformAncestors", &CCNode::transformAncestors, pybind::return_value_policy::automatic_reference);
    ccnode.def("updateTransform", &CCNode::updateTransform, pybind::return_value_policy::automatic_reference);
    ccnode.def("nodeToParentTransform", &CCNode::nodeToParentTransform, pybind::return_value_policy::automatic_reference);
    ccnode.def("parentToNodeTransform", &CCNode::parentToNodeTransform, pybind::return_value_policy::automatic_reference);
    ccnode.def("nodeToWorldTransform", &CCNode::nodeToWorldTransform, pybind::return_value_policy::automatic_reference);
    ccnode.def("worldToNodeTransform", &CCNode::worldToNodeTransform, pybind::return_value_policy::automatic_reference);
    ccnode.def("convertToNodeSpace", &CCNode::convertToNodeSpace, pybind::return_value_policy::automatic_reference);
    ccnode.def("convertToWorldSpace", &CCNode::convertToWorldSpace, pybind::return_value_policy::automatic_reference);
    ccnode.def("convertToNodeSpaceAR", &CCNode::convertToNodeSpaceAR, pybind::return_value_policy::automatic_reference);
    ccnode.def("convertToWorldSpaceAR", &CCNode::convertToWorldSpaceAR, pybind::return_value_policy::automatic_reference);
    ccnode.def("convertTouchToNodeSpace", &CCNode::convertTouchToNodeSpace, pybind::return_value_policy::automatic_reference);
    ccnode.def("convertTouchToNodeSpaceAR", &CCNode::convertTouchToNodeSpaceAR, pybind::return_value_policy::automatic_reference);
    ccnode.def("setAdditionalTransform", &CCNode::setAdditionalTransform, pybind::return_value_policy::automatic_reference);
    ccnode.def("getComponent", &CCNode::getComponent, pybind::return_value_policy::automatic_reference);
    ccnode.def("addComponent", &CCNode::addComponent, pybind::return_value_policy::automatic_reference);
    ccnode.def("removeComponent", pybind::overload_cast<constchar*>(&CCNode::removeComponent), pybind::return_value_policy::automatic_reference);
    ccnode.def("removeComponent", pybind::overload_cast<CCComponent*>(&CCNode::removeComponent), pybind::return_value_policy::automatic_reference);
    ccnode.def("removeAllComponents", &CCNode::removeAllComponents, pybind::return_value_policy::automatic_reference);

    auto ccrgbaprotocol = pybind::class_<CCRGBAProtocol>(m, "CCRGBAProtocol");
    ccrgbaprotocol.def("setOpacity", &CCRGBAProtocol::setOpacity, pybind::return_value_policy::automatic_reference);
    ccrgbaprotocol.def("getOpacity", &CCRGBAProtocol::getOpacity, pybind::return_value_policy::automatic_reference);
    ccrgbaprotocol.def("setColor", &CCRGBAProtocol::setColor, pybind::return_value_policy::automatic_reference);
    ccrgbaprotocol.def("getColor", &CCRGBAProtocol::getColor, pybind::return_value_policy::automatic_reference);
    ccrgbaprotocol.def("isCascadeColorEnabled", &CCRGBAProtocol::isCascadeColorEnabled, pybind::return_value_policy::automatic_reference);
    ccrgbaprotocol.def("setCascadeColorEnabled", &CCRGBAProtocol::setCascadeColorEnabled, pybind::return_value_policy::automatic_reference);
    ccrgbaprotocol.def("isCascadeOpacityEnabled", &CCRGBAProtocol::isCascadeOpacityEnabled, pybind::return_value_policy::automatic_reference);
    ccrgbaprotocol.def("setCascadeOpacityEnabled", &CCRGBAProtocol::setCascadeOpacityEnabled, pybind::return_value_policy::automatic_reference);

    auto ccnodergba = pybind::class_<CCNodeRGBA, CCNode, CCRGBAProtocol>(m, "CCNodeRGBA");
    ccnodergba.def("init", &CCNodeRGBA::init, pybind::return_value_policy::automatic_reference);
    ccnodergba.def_static("create", &CCNodeRGBA::create, pybind::return_value_policy::automatic_reference);
    ccnodergba.def("getOpacity", &CCNodeRGBA::getOpacity, pybind::return_value_policy::automatic_reference);
    ccnodergba.def("setOpacity", &CCNodeRGBA::setOpacity, pybind::return_value_policy::automatic_reference);
    ccnodergba.def("getColor", &CCNodeRGBA::getColor, pybind::return_value_policy::automatic_reference);
    ccnodergba.def("setColor", &CCNodeRGBA::setColor, pybind::return_value_policy::automatic_reference);
    ccnodergba.def("isCascadeColorEnabled", &CCNodeRGBA::isCascadeColorEnabled, pybind::return_value_policy::automatic_reference);
    ccnodergba.def("setCascadeColorEnabled", &CCNodeRGBA::setCascadeColorEnabled, pybind::return_value_policy::automatic_reference);
    ccnodergba.def("isCascadeOpacityEnabled", &CCNodeRGBA::isCascadeOpacityEnabled, pybind::return_value_policy::automatic_reference);
    ccnodergba.def("setCascadeOpacityEnabled", &CCNodeRGBA::setCascadeOpacityEnabled, pybind::return_value_policy::automatic_reference);
    ccnodergba.def("updateDisplayedColor", &CCNodeRGBA::updateDisplayedColor, pybind::return_value_policy::automatic_reference);
    ccnodergba.def("updateDisplayedOpacity", &CCNodeRGBA::updateDisplayedOpacity, pybind::return_value_policy::automatic_reference);
    ccnodergba.def("getDisplayedColor", &CCNodeRGBA::getDisplayedColor, pybind::return_value_policy::automatic_reference);
    ccnodergba.def("getDisplayedOpacity", &CCNodeRGBA::getDisplayedOpacity, pybind::return_value_policy::automatic_reference);
    ccnodergba.def("setOpacityModifyRGB", &CCNodeRGBA::setOpacityModifyRGB, pybind::return_value_policy::automatic_reference);
    ccnodergba.def("isOpacityModifyRGB", &CCNodeRGBA::isOpacityModifyRGB, pybind::return_value_policy::automatic_reference);

    auto cctextureprotocol = pybind::class_<CCTextureProtocol>(m, "CCTextureProtocol");
    cctextureprotocol.def("setTexture", &CCTextureProtocol::setTexture, pybind::return_value_policy::automatic_reference);
    cctextureprotocol.def("getTexture", &CCTextureProtocol::getTexture, pybind::return_value_policy::automatic_reference);

    auto ccatlasnode = pybind::class_<CCAtlasNode, CCNodeRGBA, CCTextureProtocol>(m, "CCAtlasNode");
    ccatlasnode.def_static("create", &CCAtlasNode::create, pybind::return_value_policy::automatic_reference);
    ccatlasnode.def("initWithTileFile", &CCAtlasNode::initWithTileFile, pybind::return_value_policy::automatic_reference);
    ccatlasnode.def("initWithTexture", &CCAtlasNode::initWithTexture, pybind::return_value_policy::automatic_reference);
    ccatlasnode.def("updateAtlasValues", &CCAtlasNode::updateAtlasValues, pybind::return_value_policy::automatic_reference);
    ccatlasnode.def("draw", &CCAtlasNode::draw, pybind::return_value_policy::automatic_reference);
    ccatlasnode.def("setTexture", &CCAtlasNode::setTexture, pybind::return_value_policy::automatic_reference);
    ccatlasnode.def("getTexture", &CCAtlasNode::getTexture, pybind::return_value_policy::automatic_reference);
    ccatlasnode.def("isOpacityModifyRGB", &CCAtlasNode::isOpacityModifyRGB, pybind::return_value_policy::automatic_reference);
    ccatlasnode.def("setOpacityModifyRGB", &CCAtlasNode::setOpacityModifyRGB, pybind::return_value_policy::automatic_reference);
    ccatlasnode.def("getColor", &CCAtlasNode::getColor, pybind::return_value_policy::automatic_reference);
    ccatlasnode.def("setColor", &CCAtlasNode::setColor, pybind::return_value_policy::automatic_reference);
    ccatlasnode.def("setOpacity", &CCAtlasNode::setOpacity, pybind::return_value_policy::automatic_reference);

    auto cccamera = pybind::class_<CCCamera, CCObject>(m, "CCCamera");
    cccamera.def("init", &CCCamera::init, pybind::return_value_policy::automatic_reference);
    cccamera.def("description", &CCCamera::description, pybind::return_value_policy::automatic_reference);
    cccamera.def("restore", &CCCamera::restore, pybind::return_value_policy::automatic_reference);
    cccamera.def("setDirty", &CCCamera::setDirty, pybind::return_value_policy::automatic_reference);
    cccamera.def("isDirty", &CCCamera::isDirty, pybind::return_value_policy::automatic_reference);
    cccamera.def("locate", &CCCamera::locate, pybind::return_value_policy::automatic_reference);
    cccamera.def("setEyeXYZ", &CCCamera::setEyeXYZ, pybind::return_value_policy::automatic_reference);
    cccamera.def("setCenterXYZ", &CCCamera::setCenterXYZ, pybind::return_value_policy::automatic_reference);
    cccamera.def("setUpXYZ", &CCCamera::setUpXYZ, pybind::return_value_policy::automatic_reference);
    cccamera.def("getEyeXYZ", &CCCamera::getEyeXYZ, pybind::return_value_policy::automatic_reference);
    cccamera.def("getCenterXYZ", &CCCamera::getCenterXYZ, pybind::return_value_policy::automatic_reference);
    cccamera.def("getUpXYZ", &CCCamera::getUpXYZ, pybind::return_value_policy::automatic_reference);

    auto ccconfiguration = pybind::class_<CCConfiguration, CCObject>(m, "CCConfiguration");

    auto typeinfo = pybind::class_<TypeInfo>(m, "TypeInfo");

    auto ccdirector = pybind::class_<CCDirector, CCObject, TypeInfo>(m, "CCDirector");
    ccdirector.def("init", &CCDirector::init, pybind::return_value_policy::automatic_reference);
    ccdirector.def_static("sharedDirector", &CCDirector::sharedDirector, pybind::return_value_policy::automatic_reference);
    ccdirector.def("getRunningScene", &CCDirector::getRunningScene, pybind::return_value_policy::automatic_reference);
    ccdirector.def("getAnimationInterval", &CCDirector::getAnimationInterval, pybind::return_value_policy::automatic_reference);
    ccdirector.def("setAnimationInterval", &CCDirector::setAnimationInterval, pybind::return_value_policy::automatic_reference);
    ccdirector.def("isDisplayStats", &CCDirector::isDisplayStats, pybind::return_value_policy::automatic_reference);
    ccdirector.def("setDisplayStats", &CCDirector::setDisplayStats, pybind::return_value_policy::automatic_reference);
    ccdirector.def("getSecondsPerFrame", &CCDirector::getSecondsPerFrame, pybind::return_value_policy::automatic_reference);
    ccdirector.def("setOpenGLView", &CCDirector::setOpenGLView, pybind::return_value_policy::automatic_reference);
    ccdirector.def("isNextDeltaTimeZero", &CCDirector::isNextDeltaTimeZero, pybind::return_value_policy::automatic_reference);
    ccdirector.def("setNextDeltaTimeZero", &CCDirector::setNextDeltaTimeZero, pybind::return_value_policy::automatic_reference);
    ccdirector.def("isPaused", &CCDirector::isPaused, pybind::return_value_policy::automatic_reference);
    ccdirector.def("getTotalFrames", &CCDirector::getTotalFrames, pybind::return_value_policy::automatic_reference);
    ccdirector.def("getProjection", &CCDirector::getProjection, pybind::return_value_policy::automatic_reference);
    ccdirector.def("setProjection", &CCDirector::setProjection, pybind::return_value_policy::automatic_reference);
    ccdirector.def("reshapeProjection", &CCDirector::reshapeProjection, pybind::return_value_policy::automatic_reference);
    ccdirector.def("setViewport", &CCDirector::setViewport, pybind::return_value_policy::automatic_reference);
    ccdirector.def("isSendCleanupToScene", &CCDirector::isSendCleanupToScene, pybind::return_value_policy::automatic_reference);
    ccdirector.def("getNotificationNode", &CCDirector::getNotificationNode, pybind::return_value_policy::automatic_reference);
    ccdirector.def("setNotificationNode", &CCDirector::setNotificationNode, pybind::return_value_policy::automatic_reference);
    ccdirector.def("getDelegate", &CCDirector::getDelegate, pybind::return_value_policy::automatic_reference);
    ccdirector.def("setDelegate", &CCDirector::setDelegate, pybind::return_value_policy::automatic_reference);
    ccdirector.def("getWinSize", &CCDirector::getWinSize, pybind::return_value_policy::automatic_reference);
    ccdirector.def("getWinSizeInPixels", &CCDirector::getWinSizeInPixels, pybind::return_value_policy::automatic_reference);
    ccdirector.def("getVisibleSize", &CCDirector::getVisibleSize, pybind::return_value_policy::automatic_reference);
    ccdirector.def("getVisibleOrigin", &CCDirector::getVisibleOrigin, pybind::return_value_policy::automatic_reference);
    ccdirector.def("convertToGL", &CCDirector::convertToGL, pybind::return_value_policy::automatic_reference);
    ccdirector.def("convertToUI", &CCDirector::convertToUI, pybind::return_value_policy::automatic_reference);
    ccdirector.def("getZEye", &CCDirector::getZEye, pybind::return_value_policy::automatic_reference);
    ccdirector.def("runWithScene", &CCDirector::runWithScene, pybind::return_value_policy::automatic_reference);
    ccdirector.def("pushScene", &CCDirector::pushScene, pybind::return_value_policy::automatic_reference);
    ccdirector.def("popScene", &CCDirector::popScene, pybind::return_value_policy::automatic_reference);
    ccdirector.def("popToRootScene", &CCDirector::popToRootScene, pybind::return_value_policy::automatic_reference);
    ccdirector.def("popToSceneStackLevel", &CCDirector::popToSceneStackLevel, pybind::return_value_policy::automatic_reference);
    ccdirector.def("replaceScene", &CCDirector::replaceScene, pybind::return_value_policy::automatic_reference);
    ccdirector.def("end", &CCDirector::end, pybind::return_value_policy::automatic_reference);
    ccdirector.def("pause", &CCDirector::pause, pybind::return_value_policy::automatic_reference);
    ccdirector.def("resume", &CCDirector::resume, pybind::return_value_policy::automatic_reference);
    ccdirector.def("drawScene", &CCDirector::drawScene, pybind::return_value_policy::automatic_reference);
    ccdirector.def("purgeCachedData", &CCDirector::purgeCachedData, pybind::return_value_policy::automatic_reference);
    ccdirector.def("setDefaultValues", &CCDirector::setDefaultValues, pybind::return_value_policy::automatic_reference);
    ccdirector.def("setGLDefaultValues", &CCDirector::setGLDefaultValues, pybind::return_value_policy::automatic_reference);
    ccdirector.def("setAlphaBlending", &CCDirector::setAlphaBlending, pybind::return_value_policy::automatic_reference);
    ccdirector.def("setDepthTest", &CCDirector::setDepthTest, pybind::return_value_policy::automatic_reference);
    ccdirector.def("setContentScaleFactor", &CCDirector::setContentScaleFactor, pybind::return_value_policy::automatic_reference);
    ccdirector.def("getContentScaleFactor", &CCDirector::getContentScaleFactor, pybind::return_value_policy::automatic_reference);
    ccdirector.def("checkSceneReference", &CCDirector::checkSceneReference, pybind::return_value_policy::automatic_reference);
    ccdirector.def("getNextScene", &CCDirector::getNextScene, pybind::return_value_policy::automatic_reference);
    ccdirector.def("levelForSceneInStack", &CCDirector::levelForSceneInStack, pybind::return_value_policy::automatic_reference);
    ccdirector.def("popSceneWithTransition", &CCDirector::popSceneWithTransition, pybind::return_value_policy::automatic_reference);
    ccdirector.def("popToSceneInStack", &CCDirector::popToSceneInStack, pybind::return_value_policy::automatic_reference);
    ccdirector.def("sceneCount", &CCDirector::sceneCount, pybind::return_value_policy::automatic_reference);
    ccdirector.def("willSwitchToScene", &CCDirector::willSwitchToScene, pybind::return_value_policy::automatic_reference);
    ccdirector.def("removeStatsLabel", &CCDirector::removeStatsLabel, pybind::return_value_policy::automatic_reference);
    ccdirector.def("resetSmoothFixCounter", &CCDirector::resetSmoothFixCounter, pybind::return_value_policy::automatic_reference);
    ccdirector.def("setDeltaTime", &CCDirector::setDeltaTime, pybind::return_value_policy::automatic_reference);
    ccdirector.def("setupScreenScale", &CCDirector::setupScreenScale, pybind::return_value_policy::automatic_reference);
    ccdirector.def("updateContentScale", &CCDirector::updateContentScale, pybind::return_value_policy::automatic_reference);
    ccdirector.def("updateScreenScale", &CCDirector::updateScreenScale, pybind::return_value_policy::automatic_reference);
    ccdirector.def("getLoadedTextureQuality", &CCDirector::getLoadedTextureQuality, pybind::return_value_policy::automatic_reference);

    auto ccdisplaylinkdirector = pybind::class_<CCDisplayLinkDirector, CCDirector>(m, "CCDisplayLinkDirector");
    ccdisplaylinkdirector.def("mainLoop", &CCDisplayLinkDirector::mainLoop, pybind::return_value_policy::automatic_reference);
    ccdisplaylinkdirector.def("setAnimationInterval", &CCDisplayLinkDirector::setAnimationInterval, pybind::return_value_policy::automatic_reference);
    ccdisplaylinkdirector.def("startAnimation", &CCDisplayLinkDirector::startAnimation, pybind::return_value_policy::automatic_reference);
    ccdisplaylinkdirector.def("stopAnimation", &CCDisplayLinkDirector::stopAnimation, pybind::return_value_policy::automatic_reference);

    auto cctimer = pybind::class_<CCTimer, CCObject>(m, "CCTimer");
    cctimer.def("getInterval", &CCTimer::getInterval, pybind::return_value_policy::automatic_reference);
    cctimer.def("setInterval", &CCTimer::setInterval, pybind::return_value_policy::automatic_reference);
    cctimer.def("getSelector", &CCTimer::getSelector, pybind::return_value_policy::automatic_reference);
    cctimer.def("initWithTarget", pybind::overload_cast<CCObject*, SEL_SCHEDULE>(&CCTimer::initWithTarget), pybind::return_value_policy::automatic_reference);
    cctimer.def("initWithTarget", pybind::overload_cast<CCObject*, SEL_SCHEDULE, float, uint, float>(&CCTimer::initWithTarget), pybind::return_value_policy::automatic_reference);
    cctimer.def("update", &CCTimer::update, pybind::return_value_policy::automatic_reference);

    auto ccscheduler = pybind::class_<CCScheduler, CCObject>(m, "CCScheduler");
    ccscheduler.def("getTimeScale", &CCScheduler::getTimeScale, pybind::return_value_policy::automatic_reference);
    ccscheduler.def("setTimeScale", &CCScheduler::setTimeScale, pybind::return_value_policy::automatic_reference);
    ccscheduler.def("update", &CCScheduler::update, pybind::return_value_policy::automatic_reference);
    ccscheduler.def("scheduleSelector", pybind::overload_cast<SEL_SCHEDULE, CCObject*, float, uint, float, bool>(&CCScheduler::scheduleSelector), pybind::return_value_policy::automatic_reference);
    ccscheduler.def("scheduleSelector", pybind::overload_cast<SEL_SCHEDULE, CCObject*, float, bool>(&CCScheduler::scheduleSelector), pybind::return_value_policy::automatic_reference);
    ccscheduler.def("scheduleUpdateForTarget", &CCScheduler::scheduleUpdateForTarget, pybind::return_value_policy::automatic_reference);
    ccscheduler.def("unscheduleSelector", &CCScheduler::unscheduleSelector, pybind::return_value_policy::automatic_reference);
    ccscheduler.def("unscheduleUpdateForTarget", &CCScheduler::unscheduleUpdateForTarget, pybind::return_value_policy::automatic_reference);
    ccscheduler.def("unscheduleAllForTarget", &CCScheduler::unscheduleAllForTarget, pybind::return_value_policy::automatic_reference);
    ccscheduler.def("unscheduleAll", &CCScheduler::unscheduleAll, pybind::return_value_policy::automatic_reference);
    ccscheduler.def("unscheduleAllWithMinPriority", &CCScheduler::unscheduleAllWithMinPriority, pybind::return_value_policy::automatic_reference);
    ccscheduler.def("pauseTarget", &CCScheduler::pauseTarget, pybind::return_value_policy::automatic_reference);
    ccscheduler.def("resumeTarget", &CCScheduler::resumeTarget, pybind::return_value_policy::automatic_reference);
    ccscheduler.def("isTargetPaused", &CCScheduler::isTargetPaused, pybind::return_value_policy::automatic_reference);
    ccscheduler.def("pauseAllTargets", &CCScheduler::pauseAllTargets, pybind::return_value_policy::automatic_reference);
    ccscheduler.def("pauseAllTargetsWithMinPriority", &CCScheduler::pauseAllTargetsWithMinPriority, pybind::return_value_policy::automatic_reference);
    ccscheduler.def("resumeTargets", &CCScheduler::resumeTargets, pybind::return_value_policy::automatic_reference);

    auto ccaffinetransform = pybind::class_<CCAffineTransform>(m, "CCAffineTransform");

    auto ccarray = pybind::class_<CCArray, CCObject>(m, "CCArray");
    ccarray.def_static("create", pybind::overload_cast<>(&CCArray::create), pybind::return_value_policy::automatic_reference);
    ccarray.def_static("createWithObject", &CCArray::createWithObject, pybind::return_value_policy::automatic_reference);
    ccarray.def_static("createWithCapacity", &CCArray::createWithCapacity, pybind::return_value_policy::automatic_reference);
    ccarray.def_static("createWithArray", &CCArray::createWithArray, pybind::return_value_policy::automatic_reference);
    ccarray.def_static("createWithContentsOfFile", &CCArray::createWithContentsOfFile, pybind::return_value_policy::automatic_reference);
    ccarray.def_static("createWithContentsOfFileThreadSafe", &CCArray::createWithContentsOfFileThreadSafe, pybind::return_value_policy::automatic_reference);
    ccarray.def("init", &CCArray::init, pybind::return_value_policy::automatic_reference);
    ccarray.def("initWithObject", &CCArray::initWithObject, pybind::return_value_policy::automatic_reference);
    ccarray.def("initWithCapacity", &CCArray::initWithCapacity, pybind::return_value_policy::automatic_reference);
    ccarray.def("initWithArray", &CCArray::initWithArray, pybind::return_value_policy::automatic_reference);
    ccarray.def("count", &CCArray::count, pybind::return_value_policy::automatic_reference);
    ccarray.def("capacity", &CCArray::capacity, pybind::return_value_policy::automatic_reference);
    ccarray.def("indexOfObject", &CCArray::indexOfObject, pybind::return_value_policy::automatic_reference);
    ccarray.def("objectAtIndex", &CCArray::objectAtIndex, pybind::return_value_policy::automatic_reference);
    ccarray.def("lastObject", &CCArray::lastObject, pybind::return_value_policy::automatic_reference);
    ccarray.def("randomObject", &CCArray::randomObject, pybind::return_value_policy::automatic_reference);
    ccarray.def("containsObject", &CCArray::containsObject, pybind::return_value_policy::automatic_reference);
    ccarray.def("addObject", &CCArray::addObject, pybind::return_value_policy::automatic_reference);
    ccarray.def("addObjectsFromArray", &CCArray::addObjectsFromArray, pybind::return_value_policy::automatic_reference);
    ccarray.def("insertObject", &CCArray::insertObject, pybind::return_value_policy::automatic_reference);
    ccarray.def("removeObject", &CCArray::removeObject, pybind::return_value_policy::automatic_reference);
    ccarray.def("removeObjectAtIndex", &CCArray::removeObjectAtIndex, pybind::return_value_policy::automatic_reference);
    ccarray.def("removeLastObject", &CCArray::removeLastObject, pybind::return_value_policy::automatic_reference);
    ccarray.def("removeObjectsInArray", &CCArray::removeObjectsInArray, pybind::return_value_policy::automatic_reference);
    ccarray.def("removeAllObjects", &CCArray::removeAllObjects, pybind::return_value_policy::automatic_reference);
    ccarray.def("fastRemoveObject", &CCArray::fastRemoveObject, pybind::return_value_policy::automatic_reference);
    ccarray.def("fastRemoveObjectAtIndex", &CCArray::fastRemoveObjectAtIndex, pybind::return_value_policy::automatic_reference);
    ccarray.def("exchangeObject", &CCArray::exchangeObject, pybind::return_value_policy::automatic_reference);
    ccarray.def("exchangeObjectAtIndex", &CCArray::exchangeObjectAtIndex, pybind::return_value_policy::automatic_reference);
    ccarray.def("replaceObjectAtIndex", &CCArray::replaceObjectAtIndex, pybind::return_value_policy::automatic_reference);
    ccarray.def("reverseObjects", &CCArray::reverseObjects, pybind::return_value_policy::automatic_reference);
    ccarray.def("reduceMemoryFootprint", &CCArray::reduceMemoryFootprint, pybind::return_value_policy::automatic_reference);
    ccarray.def("copyWithZone", &CCArray::copyWithZone, pybind::return_value_policy::automatic_reference);
    ccarray.def("acceptVisitor", &CCArray::acceptVisitor, pybind::return_value_policy::automatic_reference);

    auto ccautoreleasepool = pybind::class_<CCAutoreleasePool, CCObject>(m, "CCAutoreleasePool");
    ccautoreleasepool.def("addObject", &CCAutoreleasePool::addObject, pybind::return_value_policy::automatic_reference);
    ccautoreleasepool.def("removeObject", &CCAutoreleasePool::removeObject, pybind::return_value_policy::automatic_reference);
    ccautoreleasepool.def("clear", &CCAutoreleasePool::clear, pybind::return_value_policy::automatic_reference);

    auto ccpoolmanager = pybind::class_<CCPoolManager>(m, "CCPoolManager");
    ccpoolmanager.def("push", &CCPoolManager::push, pybind::return_value_policy::automatic_reference);
    ccpoolmanager.def("pop", &CCPoolManager::pop, pybind::return_value_policy::automatic_reference);
    ccpoolmanager.def("pop", &CCPoolManager::pop, pybind::return_value_policy::automatic_reference);
    ccpoolmanager.def("removeObject", &CCPoolManager::removeObject, pybind::return_value_policy::automatic_reference);

    auto ccdatavisitor = pybind::class_<CCDataVisitor>(m, "CCDataVisitor");
    ccdatavisitor.def("visit", pybind::overload_cast<CONSTCCBool*>(&CCDataVisitor::visit), pybind::return_value_policy::automatic_reference);
    ccdatavisitor.def("visit", pybind::overload_cast<CONSTCCInteger*>(&CCDataVisitor::visit), pybind::return_value_policy::automatic_reference);
    ccdatavisitor.def("visit", pybind::overload_cast<CONSTCCFloat*>(&CCDataVisitor::visit), pybind::return_value_policy::automatic_reference);
    ccdatavisitor.def("visit", pybind::overload_cast<CONSTCCDouble*>(&CCDataVisitor::visit), pybind::return_value_policy::automatic_reference);
    ccdatavisitor.def("visit", pybind::overload_cast<CONSTCCString*>(&CCDataVisitor::visit), pybind::return_value_policy::automatic_reference);
    ccdatavisitor.def("visit", pybind::overload_cast<CONSTCCArray*>(&CCDataVisitor::visit), pybind::return_value_policy::automatic_reference);
    ccdatavisitor.def("visit", pybind::overload_cast<CONSTCCDictionary*>(&CCDataVisitor::visit), pybind::return_value_policy::automatic_reference);
    ccdatavisitor.def("visit", pybind::overload_cast<CONSTCCSet*>(&CCDataVisitor::visit), pybind::return_value_policy::automatic_reference);

    auto ccprettyprinter = pybind::class_<CCPrettyPrinter, CCDataVisitor>(m, "CCPrettyPrinter");
    ccprettyprinter.def("clear", &CCPrettyPrinter::clear, pybind::return_value_policy::automatic_reference);
    ccprettyprinter.def("getResult", &CCPrettyPrinter::getResult, pybind::return_value_policy::automatic_reference);
    ccprettyprinter.def("visitObject", &CCPrettyPrinter::visitObject, pybind::return_value_policy::automatic_reference);
    ccprettyprinter.def("visit", pybind::overload_cast<CONSTCCBool*>(&CCPrettyPrinter::visit), pybind::return_value_policy::automatic_reference);
    ccprettyprinter.def("visit", pybind::overload_cast<CONSTCCInteger*>(&CCPrettyPrinter::visit), pybind::return_value_policy::automatic_reference);
    ccprettyprinter.def("visit", pybind::overload_cast<CONSTCCFloat*>(&CCPrettyPrinter::visit), pybind::return_value_policy::automatic_reference);
    ccprettyprinter.def("visit", pybind::overload_cast<CONSTCCDouble*>(&CCPrettyPrinter::visit), pybind::return_value_policy::automatic_reference);
    ccprettyprinter.def("visit", pybind::overload_cast<CONSTCCString*>(&CCPrettyPrinter::visit), pybind::return_value_policy::automatic_reference);
    ccprettyprinter.def("visit", pybind::overload_cast<CONSTCCArray*>(&CCPrettyPrinter::visit), pybind::return_value_policy::automatic_reference);
    ccprettyprinter.def("visit", pybind::overload_cast<CONSTCCDictionary*>(&CCPrettyPrinter::visit), pybind::return_value_policy::automatic_reference);
    ccprettyprinter.def("visit", pybind::overload_cast<CONSTCCSet*>(&CCPrettyPrinter::visit), pybind::return_value_policy::automatic_reference);

    auto ccdictelement = pybind::class_<CCDictElement>(m, "CCDictElement");
    ccdictelement.def("getObject", &CCDictElement::getObject, pybind::return_value_policy::automatic_reference);
    ccdictelement.def("getStrKey", &CCDictElement::getStrKey, pybind::return_value_policy::automatic_reference);
    ccdictelement.def("getIntKey", &CCDictElement::getIntKey, pybind::return_value_policy::automatic_reference);

    auto ccdictionary = pybind::class_<CCDictionary, CCObject>(m, "CCDictionary");
    ccdictionary.def_static("create", &CCDictionary::create, pybind::return_value_policy::automatic_reference);
    ccdictionary.def_static("createWithDictionary", &CCDictionary::createWithDictionary, pybind::return_value_policy::automatic_reference);
    ccdictionary.def_static("createWithContentsOfFile", &CCDictionary::createWithContentsOfFile, pybind::return_value_policy::automatic_reference);
    ccdictionary.def_static("createWithContentsOfFileThreadSafe", &CCDictionary::createWithContentsOfFileThreadSafe, pybind::return_value_policy::automatic_reference);
    ccdictionary.def("count", &CCDictionary::count, pybind::return_value_policy::automatic_reference);
    ccdictionary.def("objectForKey", pybind::overload_cast<CONSTstdstring&>(&CCDictionary::objectForKey), pybind::return_value_policy::automatic_reference);
    ccdictionary.def("setObject", pybind::overload_cast<CCObject*, CONSTstdstring&>(&CCDictionary::setObject), pybind::return_value_policy::automatic_reference);
    ccdictionary.def("removeObjectForKey", pybind::overload_cast<CONSTstdstring&>(&CCDictionary::removeObjectForKey), pybind::return_value_policy::automatic_reference);
    ccdictionary.def("removeAllObjects", &CCDictionary::removeAllObjects, pybind::return_value_policy::automatic_reference);
    ccdictionary.def("allKeys", &CCDictionary::allKeys, pybind::return_value_policy::automatic_reference);
    ccdictionary.def("allKeysForObject", &CCDictionary::allKeysForObject, pybind::return_value_policy::automatic_reference);
    ccdictionary.def("copyWithZone", &CCDictionary::copyWithZone, pybind::return_value_policy::automatic_reference);
    ccdictionary.def("acceptVisitor", &CCDictionary::acceptVisitor, pybind::return_value_policy::automatic_reference);

    auto ccpoint = pybind::class_<CCPoint>(m, "CCPoint");
    ccpoint.def(pybind::init<>());
    ccpoint.def(pybind::init<float, float>());
    ccpoint.def_readwrite("x", &CCPoint::x);
    ccpoint.def_readwrite("y", &CCPoint::y);

    auto ccsize = pybind::class_<CCSize>(m, "CCSize");
    ccsize.def_readwrite("width", &CCSize::width);
    ccsize.def_readwrite("height", &CCSize::height);

    auto ccrect = pybind::class_<CCRect>(m, "CCRect");
    ccrect.def_readwrite("origin", &CCRect::origin);
    ccrect.def_readwrite("size", &CCRect::size);

    auto ccinteger = pybind::class_<CCInteger, CCObject>(m, "CCInteger");
    ccinteger.def("getValue", &CCInteger::getValue, pybind::return_value_policy::automatic_reference);
    ccinteger.def("acceptVisitor", &CCInteger::acceptVisitor, pybind::return_value_policy::automatic_reference);

    auto ccset = pybind::class_<CCSet, CCObject>(m, "CCSet");
    ccset.def_static("create", &CCSet::create, pybind::return_value_policy::automatic_reference);
    ccset.def("count", &CCSet::count, pybind::return_value_policy::automatic_reference);
    ccset.def("anyObject", &CCSet::anyObject, pybind::return_value_policy::automatic_reference);
    ccset.def("containsObject", &CCSet::containsObject, pybind::return_value_policy::automatic_reference);
    ccset.def("addObject", &CCSet::addObject, pybind::return_value_policy::automatic_reference);
    ccset.def("removeObject", &CCSet::removeObject, pybind::return_value_policy::automatic_reference);
    ccset.def("removeAllObjects", &CCSet::removeAllObjects, pybind::return_value_policy::automatic_reference);
    ccset.def("copyWithZone", &CCSet::copyWithZone, pybind::return_value_policy::automatic_reference);
    ccset.def("acceptVisitor", &CCSet::acceptVisitor, pybind::return_value_policy::automatic_reference);

    auto ccstring = pybind::class_<CCString, CCObject>(m, "CCString");
    ccstring.def("getCString", &CCString::getCString, pybind::return_value_policy::automatic_reference);
    ccstring.def("length", &CCString::length, pybind::return_value_policy::automatic_reference);
    ccstring.def_static("create", &CCString::create, pybind::return_value_policy::automatic_reference);
    ccstring.def_static("createWithData", &CCString::createWithData, pybind::return_value_policy::automatic_reference);
    ccstring.def("compare", &CCString::compare, pybind::return_value_policy::automatic_reference);
    ccstring.def("intValue", &CCString::intValue, pybind::return_value_policy::automatic_reference);
    ccstring.def("boolValue", &CCString::boolValue, pybind::return_value_policy::automatic_reference);
    ccstring.def("copyWithZone", &CCString::copyWithZone, pybind::return_value_policy::automatic_reference);
    ccstring.def("acceptVisitor", &CCString::acceptVisitor, pybind::return_value_policy::automatic_reference);

    auto cczone = pybind::class_<CCZone>(m, "CCZone");

    auto ccdrawnode = pybind::class_<CCDrawNode, CCNode>(m, "CCDrawNode");
    ccdrawnode.def("init", &CCDrawNode::init, pybind::return_value_policy::automatic_reference);
    ccdrawnode.def("draw", &CCDrawNode::draw, pybind::return_value_policy::automatic_reference);
    ccdrawnode.def("drawDot", &CCDrawNode::drawDot, pybind::return_value_policy::automatic_reference);
    ccdrawnode.def("drawSegment", &CCDrawNode::drawSegment, pybind::return_value_policy::automatic_reference);
    ccdrawnode.def("drawPolygon", &CCDrawNode::drawPolygon, pybind::return_value_policy::automatic_reference);
    ccdrawnode.def("clear", &CCDrawNode::clear, pybind::return_value_policy::automatic_reference);
    ccdrawnode.def("listenBackToForeground", &CCDrawNode::listenBackToForeground, pybind::return_value_policy::automatic_reference);

    auto ccgridbase = pybind::class_<CCGridBase, CCObject>(m, "CCGridBase");
    ccgridbase.def("initWithSize", pybind::overload_cast<CONSTCCSize&, CCTexture2D*, bool>(&CCGridBase::initWithSize), pybind::return_value_policy::automatic_reference);
    ccgridbase.def("initWithSize", pybind::overload_cast<CONSTCCSize&>(&CCGridBase::initWithSize), pybind::return_value_policy::automatic_reference);
    ccgridbase.def("set2DProjection", &CCGridBase::set2DProjection, pybind::return_value_policy::automatic_reference);
    ccgridbase.def("blit", &CCGridBase::blit, pybind::return_value_policy::automatic_reference);
    ccgridbase.def("reuse", &CCGridBase::reuse, pybind::return_value_policy::automatic_reference);
    ccgridbase.def("calculateVertexPoints", &CCGridBase::calculateVertexPoints, pybind::return_value_policy::automatic_reference);

    auto ccgrid3d = pybind::class_<CCGrid3D, CCGridBase>(m, "CCGrid3D");
    ccgrid3d.def("initWithSize", pybind::overload_cast<CONSTCCSize&, CCTexture2D*, bool>(&CCGrid3D::initWithSize), pybind::return_value_policy::automatic_reference);
    ccgrid3d.def("initWithSize", pybind::overload_cast<CONSTCCSize&>(&CCGrid3D::initWithSize), pybind::return_value_policy::automatic_reference);
    ccgrid3d.def("originalVertex", &CCGrid3D::originalVertex, pybind::return_value_policy::automatic_reference);
    ccgrid3d.def("vertex", &CCGrid3D::vertex, pybind::return_value_policy::automatic_reference);
    ccgrid3d.def("setVertex", &CCGrid3D::setVertex, pybind::return_value_policy::automatic_reference);
    ccgrid3d.def("blit", &CCGrid3D::blit, pybind::return_value_policy::automatic_reference);
    ccgrid3d.def("reuse", &CCGrid3D::reuse, pybind::return_value_policy::automatic_reference);
    ccgrid3d.def("calculateVertexPoints", &CCGrid3D::calculateVertexPoints, pybind::return_value_policy::automatic_reference);

    auto cctiledgrid3d = pybind::class_<CCTiledGrid3D, CCGridBase>(m, "CCTiledGrid3D");
    cctiledgrid3d.def("initWithSize", pybind::overload_cast<CONSTCCSize&, CCTexture2D*, bool>(&CCTiledGrid3D::initWithSize), pybind::return_value_policy::automatic_reference);
    cctiledgrid3d.def("initWithSize", pybind::overload_cast<CONSTCCSize&>(&CCTiledGrid3D::initWithSize), pybind::return_value_policy::automatic_reference);
    cctiledgrid3d.def("originalTile", &CCTiledGrid3D::originalTile, pybind::return_value_policy::automatic_reference);
    cctiledgrid3d.def("tile", &CCTiledGrid3D::tile, pybind::return_value_policy::automatic_reference);
    cctiledgrid3d.def("setTile", &CCTiledGrid3D::setTile, pybind::return_value_policy::automatic_reference);
    cctiledgrid3d.def("blit", &CCTiledGrid3D::blit, pybind::return_value_policy::automatic_reference);
    cctiledgrid3d.def("reuse", &CCTiledGrid3D::reuse, pybind::return_value_policy::automatic_reference);
    cctiledgrid3d.def("calculateVertexPoints", &CCTiledGrid3D::calculateVertexPoints, pybind::return_value_policy::automatic_reference);

    auto ccblendprotocol = pybind::class_<CCBlendProtocol>(m, "CCBlendProtocol");
    ccblendprotocol.def("setBlendFunc", &CCBlendProtocol::setBlendFunc, pybind::return_value_policy::automatic_reference);
    ccblendprotocol.def("getBlendFunc", &CCBlendProtocol::getBlendFunc, pybind::return_value_policy::automatic_reference);

    auto cclabelprotocol = pybind::class_<CCLabelProtocol>(m, "CCLabelProtocol");
    cclabelprotocol.def("setString", &CCLabelProtocol::setString, pybind::return_value_policy::automatic_reference);
    cclabelprotocol.def("getString", &CCLabelProtocol::getString, pybind::return_value_policy::automatic_reference);

    auto ccdirectordelegate = pybind::class_<CCDirectorDelegate>(m, "CCDirectorDelegate");
    ccdirectordelegate.def("updateProjection", &CCDirectorDelegate::updateProjection, pybind::return_value_policy::automatic_reference);

    auto cclabelatlas = pybind::class_<CCLabelAtlas, CCAtlasNode, CCLabelProtocol>(m, "CCLabelAtlas");
    cclabelatlas.def("create", pybind::overload_cast<constchar*, constchar*, uint, uint, uint>(&CCLabelAtlas::create), pybind::return_value_policy::automatic_reference);
    cclabelatlas.def("create", pybind::overload_cast<constchar*, constchar*>(&CCLabelAtlas::create), pybind::return_value_policy::automatic_reference);
    cclabelatlas.def("initWithString", pybind::overload_cast<constchar*, constchar*, uint, uint, uint>(&CCLabelAtlas::initWithString), pybind::return_value_policy::automatic_reference);
    cclabelatlas.def("initWithString", pybind::overload_cast<constchar*, constchar*>(&CCLabelAtlas::initWithString), pybind::return_value_policy::automatic_reference);
    cclabelatlas.def("initWithString", pybind::overload_cast<constchar*, CCTexture2D*, uint, uint, uint>(&CCLabelAtlas::initWithString), pybind::return_value_policy::automatic_reference);
    cclabelatlas.def("setString", &CCLabelAtlas::setString, pybind::return_value_policy::automatic_reference);
    cclabelatlas.def("getString", &CCLabelAtlas::getString, pybind::return_value_policy::automatic_reference);
    cclabelatlas.def("updateAtlasValues", &CCLabelAtlas::updateAtlasValues, pybind::return_value_policy::automatic_reference);
    cclabelatlas.def("setOpacityModifyRGB", &CCLabelAtlas::setOpacityModifyRGB, pybind::return_value_policy::automatic_reference);
    cclabelatlas.def("isOpacityModifyRGB", &CCLabelAtlas::isOpacityModifyRGB, pybind::return_value_policy::automatic_reference);
    cclabelatlas.def("setOpacity", &CCLabelAtlas::setOpacity, pybind::return_value_policy::automatic_reference);
    cclabelatlas.def("getOpacity", &CCLabelAtlas::getOpacity, pybind::return_value_policy::automatic_reference);
    cclabelatlas.def("setColor", &CCLabelAtlas::setColor, pybind::return_value_policy::automatic_reference);
    cclabelatlas.def("getColor", &CCLabelAtlas::getColor, pybind::return_value_policy::automatic_reference);
    cclabelatlas.def("setBlendFunc", &CCLabelAtlas::setBlendFunc, pybind::return_value_policy::automatic_reference);
    cclabelatlas.def("getBlendFunc", &CCLabelAtlas::getBlendFunc, pybind::return_value_policy::automatic_reference);

    auto ccbmfontconfiguration = pybind::class_<CCBMFontConfiguration, CCObject>(m, "CCBMFontConfiguration");
    ccbmfontconfiguration.def("description", &CCBMFontConfiguration::description, pybind::return_value_policy::automatic_reference);
    ccbmfontconfiguration.def("initWithFNTfile", &CCBMFontConfiguration::initWithFNTfile, pybind::return_value_policy::automatic_reference);
    ccbmfontconfiguration.def("getAtlasName", &CCBMFontConfiguration::getAtlasName, pybind::return_value_policy::automatic_reference);
    ccbmfontconfiguration.def("setAtlasName", &CCBMFontConfiguration::setAtlasName, pybind::return_value_policy::automatic_reference);
    ccbmfontconfiguration.def("release", &CCBMFontConfiguration::release, pybind::return_value_policy::automatic_reference);
    ccbmfontconfiguration.def("retain", &CCBMFontConfiguration::retain, pybind::return_value_policy::automatic_reference);
    ccbmfontconfiguration.def("autorelease", &CCBMFontConfiguration::autorelease, pybind::return_value_policy::automatic_reference);
    ccbmfontconfiguration.def("copy", &CCBMFontConfiguration::copy, pybind::return_value_policy::automatic_reference);
    ccbmfontconfiguration.def("isSingleReference", &CCBMFontConfiguration::isSingleReference, pybind::return_value_policy::automatic_reference);
    ccbmfontconfiguration.def("retainCount", &CCBMFontConfiguration::retainCount, pybind::return_value_policy::automatic_reference);
    ccbmfontconfiguration.def("isEqual", &CCBMFontConfiguration::isEqual, pybind::return_value_policy::automatic_reference);
    ccbmfontconfiguration.def("acceptVisitor", &CCBMFontConfiguration::acceptVisitor, pybind::return_value_policy::automatic_reference);
    ccbmfontconfiguration.def("update", &CCBMFontConfiguration::update, pybind::return_value_policy::automatic_reference);

    auto ccspritebatchnode = pybind::class_<CCSpriteBatchNode, CCNode, CCTextureProtocol>(m, "CCSpriteBatchNode");
    ccspritebatchnode.def("getTextureAtlas", &CCSpriteBatchNode::getTextureAtlas, pybind::return_value_policy::automatic_reference);
    ccspritebatchnode.def("setTextureAtlas", &CCSpriteBatchNode::setTextureAtlas, pybind::return_value_policy::automatic_reference);
    ccspritebatchnode.def("getDescendants", &CCSpriteBatchNode::getDescendants, pybind::return_value_policy::automatic_reference);
    ccspritebatchnode.def_static("createWithTexture", pybind::overload_cast<CCTexture2D*, uint>(&CCSpriteBatchNode::createWithTexture), pybind::return_value_policy::automatic_reference);
    ccspritebatchnode.def_static("createWithTexture", pybind::overload_cast<CCTexture2D*>(&CCSpriteBatchNode::createWithTexture), pybind::return_value_policy::automatic_reference);
    ccspritebatchnode.def_static("create", pybind::overload_cast<constchar*, uint>(&CCSpriteBatchNode::create), pybind::return_value_policy::automatic_reference);
    ccspritebatchnode.def_static("create", pybind::overload_cast<constchar*>(&CCSpriteBatchNode::create), pybind::return_value_policy::automatic_reference);
    ccspritebatchnode.def("initWithTexture", &CCSpriteBatchNode::initWithTexture, pybind::return_value_policy::automatic_reference);
    ccspritebatchnode.def("initWithFile", &CCSpriteBatchNode::initWithFile, pybind::return_value_policy::automatic_reference);
    ccspritebatchnode.def("init", &CCSpriteBatchNode::init, pybind::return_value_policy::automatic_reference);
    ccspritebatchnode.def("increaseAtlasCapacity", &CCSpriteBatchNode::increaseAtlasCapacity, pybind::return_value_policy::automatic_reference);
    ccspritebatchnode.def("removeChildAtIndex", &CCSpriteBatchNode::removeChildAtIndex, pybind::return_value_policy::automatic_reference);
    ccspritebatchnode.def("insertChild", &CCSpriteBatchNode::insertChild, pybind::return_value_policy::automatic_reference);
    ccspritebatchnode.def("appendChild", &CCSpriteBatchNode::appendChild, pybind::return_value_policy::automatic_reference);
    ccspritebatchnode.def("removeSpriteFromAtlas", &CCSpriteBatchNode::removeSpriteFromAtlas, pybind::return_value_policy::automatic_reference);
    ccspritebatchnode.def("rebuildIndexInOrder", &CCSpriteBatchNode::rebuildIndexInOrder, pybind::return_value_policy::automatic_reference);
    ccspritebatchnode.def("highestAtlasIndexInChild", &CCSpriteBatchNode::highestAtlasIndexInChild, pybind::return_value_policy::automatic_reference);
    ccspritebatchnode.def("lowestAtlasIndexInChild", &CCSpriteBatchNode::lowestAtlasIndexInChild, pybind::return_value_policy::automatic_reference);
    ccspritebatchnode.def("atlasIndexForChild", &CCSpriteBatchNode::atlasIndexForChild, pybind::return_value_policy::automatic_reference);
    ccspritebatchnode.def("reorderBatch", &CCSpriteBatchNode::reorderBatch, pybind::return_value_policy::automatic_reference);
    ccspritebatchnode.def("getTexture", &CCSpriteBatchNode::getTexture, pybind::return_value_policy::automatic_reference);
    ccspritebatchnode.def("setTexture", &CCSpriteBatchNode::setTexture, pybind::return_value_policy::automatic_reference);
    ccspritebatchnode.def("setBlendFunc", &CCSpriteBatchNode::setBlendFunc, pybind::return_value_policy::automatic_reference);
    ccspritebatchnode.def("getBlendFunc", &CCSpriteBatchNode::getBlendFunc, pybind::return_value_policy::automatic_reference);
    ccspritebatchnode.def("visit", &CCSpriteBatchNode::visit, pybind::return_value_policy::automatic_reference);
    ccspritebatchnode.def("addChild", pybind::overload_cast<CCNode*>(&CCSpriteBatchNode::addChild), pybind::return_value_policy::automatic_reference);
    ccspritebatchnode.def("addChild", pybind::overload_cast<CCNode*, int>(&CCSpriteBatchNode::addChild), pybind::return_value_policy::automatic_reference);
    ccspritebatchnode.def("addChild", pybind::overload_cast<CCNode*, int, int>(&CCSpriteBatchNode::addChild), pybind::return_value_policy::automatic_reference);
    ccspritebatchnode.def("reorderChild", &CCSpriteBatchNode::reorderChild, pybind::return_value_policy::automatic_reference);
    ccspritebatchnode.def("removeChild", &CCSpriteBatchNode::removeChild, pybind::return_value_policy::automatic_reference);
    ccspritebatchnode.def("removeAllChildrenWithCleanup", &CCSpriteBatchNode::removeAllChildrenWithCleanup, pybind::return_value_policy::automatic_reference);
    ccspritebatchnode.def("sortAllChildren", &CCSpriteBatchNode::sortAllChildren, pybind::return_value_policy::automatic_reference);
    ccspritebatchnode.def("draw", &CCSpriteBatchNode::draw, pybind::return_value_policy::automatic_reference);

    auto cclabelbmfont = pybind::class_<CCLabelBMFont, CCSpriteBatchNode, CCLabelProtocol, CCRGBAProtocol>(m, "CCLabelBMFont");
    cclabelbmfont.def_static("create", pybind::overload_cast<constchar*, constchar*, float, CCTextAlignment, CCPoint>(&CCLabelBMFont::create), pybind::return_value_policy::automatic_reference);
    cclabelbmfont.def_static("create", pybind::overload_cast<constchar*, constchar*, float, CCTextAlignment>(&CCLabelBMFont::create), pybind::return_value_policy::automatic_reference);
    cclabelbmfont.def_static("create", pybind::overload_cast<constchar*, constchar*, float>(&CCLabelBMFont::create), pybind::return_value_policy::automatic_reference);
    cclabelbmfont.def_static("create", pybind::overload_cast<constchar*, constchar*>(&CCLabelBMFont::create), pybind::return_value_policy::automatic_reference);
    cclabelbmfont.def_static("create", pybind::overload_cast<>(&CCLabelBMFont::create), pybind::return_value_policy::automatic_reference);
    cclabelbmfont.def("init", &CCLabelBMFont::init, pybind::return_value_policy::automatic_reference);
    cclabelbmfont.def("createFontChars", &CCLabelBMFont::createFontChars, pybind::return_value_policy::automatic_reference);
    cclabelbmfont.def("setString", pybind::overload_cast<constchar*>(&CCLabelBMFont::setString), pybind::return_value_policy::automatic_reference);
    cclabelbmfont.def("setString", pybind::overload_cast<constchar*, bool>(&CCLabelBMFont::setString), pybind::return_value_policy::automatic_reference);
    cclabelbmfont.def("getString", &CCLabelBMFont::getString, pybind::return_value_policy::automatic_reference);
    cclabelbmfont.def("setCString", &CCLabelBMFont::setCString, pybind::return_value_policy::automatic_reference);
    cclabelbmfont.def("setAnchorPoint", &CCLabelBMFont::setAnchorPoint, pybind::return_value_policy::automatic_reference);
    cclabelbmfont.def("updateLabel", &CCLabelBMFont::updateLabel, pybind::return_value_policy::automatic_reference);
    cclabelbmfont.def("setAlignment", &CCLabelBMFont::setAlignment, pybind::return_value_policy::automatic_reference);
    cclabelbmfont.def("setWidth", &CCLabelBMFont::setWidth, pybind::return_value_policy::automatic_reference);
    cclabelbmfont.def("setLineBreakWithoutSpace", &CCLabelBMFont::setLineBreakWithoutSpace, pybind::return_value_policy::automatic_reference);
    cclabelbmfont.def("setScale", &CCLabelBMFont::setScale, pybind::return_value_policy::automatic_reference);
    cclabelbmfont.def("setScaleX", &CCLabelBMFont::setScaleX, pybind::return_value_policy::automatic_reference);
    cclabelbmfont.def("setScaleY", &CCLabelBMFont::setScaleY, pybind::return_value_policy::automatic_reference);
    cclabelbmfont.def("isOpacityModifyRGB", &CCLabelBMFont::isOpacityModifyRGB, pybind::return_value_policy::automatic_reference);
    cclabelbmfont.def("setOpacityModifyRGB", &CCLabelBMFont::setOpacityModifyRGB, pybind::return_value_policy::automatic_reference);
    cclabelbmfont.def("getDisplayedOpacity", &CCLabelBMFont::getDisplayedOpacity, pybind::return_value_policy::automatic_reference);
    cclabelbmfont.def("setOpacity", &CCLabelBMFont::setOpacity, pybind::return_value_policy::automatic_reference);
    cclabelbmfont.def("updateDisplayedOpacity", &CCLabelBMFont::updateDisplayedOpacity, pybind::return_value_policy::automatic_reference);
    cclabelbmfont.def("isCascadeOpacityEnabled", &CCLabelBMFont::isCascadeOpacityEnabled, pybind::return_value_policy::automatic_reference);
    cclabelbmfont.def("setCascadeOpacityEnabled", &CCLabelBMFont::setCascadeOpacityEnabled, pybind::return_value_policy::automatic_reference);
    cclabelbmfont.def("getColor", &CCLabelBMFont::getColor, pybind::return_value_policy::automatic_reference);
    cclabelbmfont.def("getDisplayedColor", &CCLabelBMFont::getDisplayedColor, pybind::return_value_policy::automatic_reference);
    cclabelbmfont.def("setColor", &CCLabelBMFont::setColor, pybind::return_value_policy::automatic_reference);
    cclabelbmfont.def("updateDisplayedColor", &CCLabelBMFont::updateDisplayedColor, pybind::return_value_policy::automatic_reference);
    cclabelbmfont.def("isCascadeColorEnabled", &CCLabelBMFont::isCascadeColorEnabled, pybind::return_value_policy::automatic_reference);
    cclabelbmfont.def("setCascadeColorEnabled", &CCLabelBMFont::setCascadeColorEnabled, pybind::return_value_policy::automatic_reference);
    cclabelbmfont.def("setFntFile", &CCLabelBMFont::setFntFile, pybind::return_value_policy::automatic_reference);
    cclabelbmfont.def("getFntFile", &CCLabelBMFont::getFntFile, pybind::return_value_policy::automatic_reference);
    cclabelbmfont.def("getConfiguration", &CCLabelBMFont::getConfiguration, pybind::return_value_policy::automatic_reference);

    auto ccsprite = pybind::class_<CCSprite, CCNodeRGBA, CCTextureProtocol>(m, "CCSprite");
    ccsprite.def_static("create", pybind::overload_cast<>(&CCSprite::create), pybind::return_value_policy::automatic_reference);
    ccsprite.def_static("create", pybind::overload_cast<constchar*>(&CCSprite::create), pybind::return_value_policy::automatic_reference);
    ccsprite.def_static("create", pybind::overload_cast<constchar*, CONSTCCRect&>(&CCSprite::create), pybind::return_value_policy::automatic_reference);
    ccsprite.def_static("createWithTexture", pybind::overload_cast<CCTexture2D*>(&CCSprite::createWithTexture), pybind::return_value_policy::automatic_reference);
    ccsprite.def_static("createWithTexture", pybind::overload_cast<CCTexture2D*, CONSTCCRect&>(&CCSprite::createWithTexture), pybind::return_value_policy::automatic_reference);
    ccsprite.def_static("createWithSpriteFrame", &CCSprite::createWithSpriteFrame, pybind::return_value_policy::automatic_reference);
    ccsprite.def_static("createWithSpriteFrameName", &CCSprite::createWithSpriteFrameName, pybind::return_value_policy::automatic_reference);
    ccsprite.def("init", &CCSprite::init, pybind::return_value_policy::automatic_reference);
    ccsprite.def("initWithTexture", pybind::overload_cast<CCTexture2D*>(&CCSprite::initWithTexture), pybind::return_value_policy::automatic_reference);
    ccsprite.def("initWithTexture", pybind::overload_cast<CCTexture2D*, CONSTCCRect&>(&CCSprite::initWithTexture), pybind::return_value_policy::automatic_reference);
    ccsprite.def("initWithTexture", pybind::overload_cast<CCTexture2D*, CONSTCCRect&, bool>(&CCSprite::initWithTexture), pybind::return_value_policy::automatic_reference);
    ccsprite.def("initWithSpriteFrame", &CCSprite::initWithSpriteFrame, pybind::return_value_policy::automatic_reference);
    ccsprite.def("initWithSpriteFrameName", &CCSprite::initWithSpriteFrameName, pybind::return_value_policy::automatic_reference);
    ccsprite.def("initWithFile", pybind::overload_cast<constchar*>(&CCSprite::initWithFile), pybind::return_value_policy::automatic_reference);
    ccsprite.def("initWithFile", pybind::overload_cast<constchar*, CONSTCCRect&>(&CCSprite::initWithFile), pybind::return_value_policy::automatic_reference);
    ccsprite.def("setTexture", &CCSprite::setTexture, pybind::return_value_policy::automatic_reference);
    ccsprite.def("getTexture", &CCSprite::getTexture, pybind::return_value_policy::automatic_reference);

    auto cclabelttf = pybind::class_<CCLabelTTF, CCSprite, CCLabelProtocol>(m, "CCLabelTTF");
    cclabelttf.def("description", &CCLabelTTF::description, pybind::return_value_policy::automatic_reference);
    cclabelttf.def_static("create", pybind::overload_cast<constchar*, constchar*, float>(&CCLabelTTF::create), pybind::return_value_policy::automatic_reference);
    cclabelttf.def_static("create", pybind::overload_cast<constchar*, constchar*, float, CONSTCCSize&, CCTextAlignment>(&CCLabelTTF::create), pybind::return_value_policy::automatic_reference);
    cclabelttf.def_static("create", pybind::overload_cast<constchar*, constchar*, float, CONSTCCSize&, CCTextAlignment, CCVerticalTextAlignment>(&CCLabelTTF::create), pybind::return_value_policy::automatic_reference);
    cclabelttf.def("initWithString", pybind::overload_cast<constchar*, constchar*, float>(&CCLabelTTF::initWithString), pybind::return_value_policy::automatic_reference);
    cclabelttf.def("initWithString", pybind::overload_cast<constchar*, constchar*, float, CONSTCCSize&, CCTextAlignment>(&CCLabelTTF::initWithString), pybind::return_value_policy::automatic_reference);
    cclabelttf.def("initWithString", pybind::overload_cast<constchar*, constchar*, float, CONSTCCSize&, CCTextAlignment, CCVerticalTextAlignment>(&CCLabelTTF::initWithString), pybind::return_value_policy::automatic_reference);
    cclabelttf.def("setTextDefinition", &CCLabelTTF::setTextDefinition, pybind::return_value_policy::automatic_reference);
    cclabelttf.def("getTextDefinition", &CCLabelTTF::getTextDefinition, pybind::return_value_policy::automatic_reference);
    cclabelttf.def("enableShadow", &CCLabelTTF::enableShadow, pybind::return_value_policy::automatic_reference);
    cclabelttf.def("disableShadow", &CCLabelTTF::disableShadow, pybind::return_value_policy::automatic_reference);
    cclabelttf.def("enableStroke", &CCLabelTTF::enableStroke, pybind::return_value_policy::automatic_reference);
    cclabelttf.def("disableStroke", &CCLabelTTF::disableStroke, pybind::return_value_policy::automatic_reference);
    cclabelttf.def("setFontFillColor", &CCLabelTTF::setFontFillColor, pybind::return_value_policy::automatic_reference);
    cclabelttf.def("init", &CCLabelTTF::init, pybind::return_value_policy::automatic_reference);
    cclabelttf.def("setString", &CCLabelTTF::setString, pybind::return_value_policy::automatic_reference);
    cclabelttf.def("getString", &CCLabelTTF::getString, pybind::return_value_policy::automatic_reference);
    cclabelttf.def("getHorizontalAlignment", &CCLabelTTF::getHorizontalAlignment, pybind::return_value_policy::automatic_reference);
    cclabelttf.def("setHorizontalAlignment", &CCLabelTTF::setHorizontalAlignment, pybind::return_value_policy::automatic_reference);
    cclabelttf.def("getVerticalAlignment", &CCLabelTTF::getVerticalAlignment, pybind::return_value_policy::automatic_reference);
    cclabelttf.def("setVerticalAlignment", &CCLabelTTF::setVerticalAlignment, pybind::return_value_policy::automatic_reference);
    cclabelttf.def("setDimensions", &CCLabelTTF::setDimensions, pybind::return_value_policy::automatic_reference);
    cclabelttf.def("getDimensions", &CCLabelTTF::getDimensions, pybind::return_value_policy::automatic_reference);
    cclabelttf.def("setFontSize", &CCLabelTTF::setFontSize, pybind::return_value_policy::automatic_reference);
    cclabelttf.def("getFontSize", &CCLabelTTF::getFontSize, pybind::return_value_policy::automatic_reference);
    cclabelttf.def("setFontName", &CCLabelTTF::setFontName, pybind::return_value_policy::automatic_reference);
    cclabelttf.def("getFontName", &CCLabelTTF::getFontName, pybind::return_value_policy::automatic_reference);

    auto cctouchdelegate = pybind::class_<CCTouchDelegate>(m, "CCTouchDelegate");

    auto ccaccelerometerdelegate = pybind::class_<CCAccelerometerDelegate>(m, "CCAccelerometerDelegate");

    auto cckeypaddelegate = pybind::class_<CCKeypadDelegate>(m, "CCKeypadDelegate");

    auto cclayer = pybind::class_<CCLayer, CCNode, CCTouchDelegate, CCAccelerometerDelegate, CCKeypadDelegate>(m, "CCLayer");
    cclayer.def_static("create", []() { return CCLayer::create(); }, pybind::return_value_policy::automatic_reference);
    cclayer.def("init", &CCLayer::init, pybind::return_value_policy::automatic_reference);
    cclayer.def("onEnter", &CCLayer::onEnter, pybind::return_value_policy::automatic_reference);
    cclayer.def("onExit", &CCLayer::onExit, pybind::return_value_policy::automatic_reference);
    cclayer.def("onEnterTransitionDidFinish", &CCLayer::onEnterTransitionDidFinish, pybind::return_value_policy::automatic_reference);
    cclayer.def("ccTouchesBegan", &CCLayer::ccTouchesBegan, pybind::return_value_policy::automatic_reference);
    cclayer.def("ccTouchesMoved", &CCLayer::ccTouchesMoved, pybind::return_value_policy::automatic_reference);
    cclayer.def("ccTouchesEnded", &CCLayer::ccTouchesEnded, pybind::return_value_policy::automatic_reference);
    cclayer.def("ccTouchesCancelled", &CCLayer::ccTouchesCancelled, pybind::return_value_policy::automatic_reference);
    cclayer.def("ccTouchBegan", &CCLayer::ccTouchBegan, pybind::return_value_policy::automatic_reference);
    cclayer.def("ccTouchMoved", &CCLayer::ccTouchMoved, pybind::return_value_policy::automatic_reference);
    cclayer.def("ccTouchEnded", &CCLayer::ccTouchEnded, pybind::return_value_policy::automatic_reference);
    cclayer.def("ccTouchesCancelled", &CCLayer::ccTouchesCancelled, pybind::return_value_policy::automatic_reference);
    cclayer.def("didAccelerate", &CCLayer::didAccelerate, pybind::return_value_policy::automatic_reference);
    cclayer.def("isTouchEnabled", &CCLayer::isTouchEnabled, pybind::return_value_policy::automatic_reference);
    cclayer.def("setTouchEnabled", &CCLayer::setTouchEnabled, pybind::return_value_policy::automatic_reference);
    cclayer.def("setTouchMode", &CCLayer::setTouchMode, pybind::return_value_policy::automatic_reference);
    cclayer.def("getTouchMode", &CCLayer::getTouchMode, pybind::return_value_policy::automatic_reference);
    cclayer.def("setTouchPriority", &CCLayer::setTouchPriority, pybind::return_value_policy::automatic_reference);
    cclayer.def("getTouchPriority", &CCLayer::getTouchPriority, pybind::return_value_policy::automatic_reference);
    cclayer.def("isAccelerometerEnabled", &CCLayer::isAccelerometerEnabled, pybind::return_value_policy::automatic_reference);
    cclayer.def("setKeypadEnabled", &CCLayer::setKeypadEnabled, pybind::return_value_policy::automatic_reference);

    auto cclayerrgba = pybind::class_<CCLayerRGBA, CCLayer, CCRGBAProtocol>(m, "CCLayerRGBA");
    cclayerrgba.def("init", &CCLayerRGBA::init, pybind::return_value_policy::automatic_reference);
    cclayerrgba.def("isOpacityModifyRGB", &CCLayerRGBA::isOpacityModifyRGB, pybind::return_value_policy::automatic_reference);
    cclayerrgba.def("setOpacityModifyRGB", &CCLayerRGBA::setOpacityModifyRGB, pybind::return_value_policy::automatic_reference);
    cclayerrgba.def("getOpacity", &CCLayerRGBA::getOpacity, pybind::return_value_policy::automatic_reference);
    cclayerrgba.def("setOpacity", &CCLayerRGBA::setOpacity, pybind::return_value_policy::automatic_reference);
    cclayerrgba.def("getColor", &CCLayerRGBA::getColor, pybind::return_value_policy::automatic_reference);
    cclayerrgba.def("setColor", &CCLayerRGBA::setColor, pybind::return_value_policy::automatic_reference);

    auto cclayercolor = pybind::class_<CCLayerColor, CCLayerRGBA, CCBlendProtocol>(m, "CCLayerColor");
    cclayercolor.def_static("create", pybind::overload_cast<CONSTCCColor4B&, float, float>(&CCLayerColor::create), pybind::return_value_policy::automatic_reference);
    cclayercolor.def_static("create", pybind::overload_cast<CONSTCCColor4B&>(&CCLayerColor::create), pybind::return_value_policy::automatic_reference);
    cclayercolor.def_static("create", pybind::overload_cast<>(&CCLayerColor::create), pybind::return_value_policy::automatic_reference);
    cclayercolor.def("init", &CCLayerColor::init, pybind::return_value_policy::automatic_reference);
    cclayercolor.def("changeWidthAndHeight", &CCLayerColor::changeWidthAndHeight, pybind::return_value_policy::automatic_reference);
    cclayercolor.def("changeWidth", &CCLayerColor::changeWidth, pybind::return_value_policy::automatic_reference);
    cclayercolor.def("changeHeight", &CCLayerColor::changeHeight, pybind::return_value_policy::automatic_reference);
    cclayercolor.def("setBlendFunc", &CCLayerColor::setBlendFunc, pybind::return_value_policy::automatic_reference);
    cclayercolor.def("getBlendFunc", &CCLayerColor::getBlendFunc, pybind::return_value_policy::automatic_reference);
    cclayercolor.def("setOpacity", &CCLayerColor::setOpacity, pybind::return_value_policy::automatic_reference);
    cclayercolor.def("setColor", &CCLayerColor::setColor, pybind::return_value_policy::automatic_reference);
    cclayercolor.def("setOpacityModifyRGB", &CCLayerColor::setOpacityModifyRGB, pybind::return_value_policy::automatic_reference);
    cclayercolor.def("isOpacityModifyRGB", &CCLayerColor::isOpacityModifyRGB, pybind::return_value_policy::automatic_reference);

    auto ccscene = pybind::class_<CCScene, CCNode>(m, "CCScene");
    ccscene.def("create", &CCScene::create, pybind::return_value_policy::automatic_reference);

    auto ccmenu = pybind::class_<CCMenu, CCLayerRGBA>(m, "CCMenu");
    ccmenu.def_static("create", pybind::overload_cast<>(&CCMenu::create), pybind::return_value_policy::automatic_reference);
    ccmenu.def_static("createWithArray", pybind::overload_cast<CCArray*>(&CCMenu::createWithArray), pybind::return_value_policy::automatic_reference);
    ccmenu.def_static("createWithItem", pybind::overload_cast<CCMenuItem*>(&CCMenu::createWithItem), pybind::return_value_policy::automatic_reference);
    ccmenu.def("init", &CCMenu::init, pybind::return_value_policy::automatic_reference);
    ccmenu.def("initWithArray", &CCMenu::initWithArray, pybind::return_value_policy::automatic_reference);
    ccmenu.def("alignItemsVertically", &CCMenu::alignItemsVertically, pybind::return_value_policy::automatic_reference);
    ccmenu.def("alignItemsVerticallyWithPadding", &CCMenu::alignItemsVerticallyWithPadding, pybind::return_value_policy::automatic_reference);
    ccmenu.def("alignItemsHorizontally", &CCMenu::alignItemsHorizontally, pybind::return_value_policy::automatic_reference);
    ccmenu.def("alignItemsHorizontallyWithPadding", &CCMenu::alignItemsHorizontallyWithPadding, pybind::return_value_policy::automatic_reference);
    ccmenu.def("setHandlerPriority", &CCMenu::setHandlerPriority, pybind::return_value_policy::automatic_reference);

    auto ccapplication = pybind::class_<CCApplication>(m, "CCApplication");

    // r, g, b
    auto cccolor3b = pybind::class_<ccColor3B>(m, "CCColor3B");
    cccolor3b.def(pybind::init<>());
    cccolor3b.def_readwrite("r", &ccColor3B::r);
    cccolor3b.def_readwrite("g", &ccColor3B::g);
    cccolor3b.def_readwrite("b", &ccColor3B::b);


    manualbindings::cocos2d_init(m);

    std::cout << "cocos2d bindings generated" << std::endl;
}