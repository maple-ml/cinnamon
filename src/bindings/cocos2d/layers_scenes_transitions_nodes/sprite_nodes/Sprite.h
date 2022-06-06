#pragma once

#include "cocos2d.h"
#include "pybind11.h"
#include "macros.h"

namespace py = pybind11;
USING_NS_CC;

void CCSprite_init(py::module &m) {
    auto c = py::class_<CCSprite, CCNode>(m, "CCSprite"); // CCNodeRGBA, CCTextureProtocol
        c.def(py::init([]() { return CCSprite::create(); }));
        c.def(py::init([](const char* pszFileName) { return CCSprite::create(pszFileName); }));
        c.def(py::init([](const char* pszFileName, const CCRect& rect) { return CCSprite::create(pszFileName, rect); }));
        c.def("create", py::overload_cast<>(&CCSprite::create));
        c.def("create", py::overload_cast<const char*>(&CCSprite::create));
        c.def("create", py::overload_cast<const char*, const CCRect&>(&CCSprite::create));
        c.def("createWithTexture", py::overload_cast<CCTexture2D*>(&CCSprite::createWithTexture));
        c.def("createWithTexture", py::overload_cast<CCTexture2D*, const CCRect&>(&CCSprite::createWithTexture));
        c.def("createWithSpriteFrame", &CCSprite::createWithSpriteFrame);
        c.def("createWithSpriteFrameName", &CCSprite::createWithSpriteFrameName);
        c.def("init", &CCSprite::init);
        c.def("initWithTexture", py::overload_cast<CCTexture2D*>(&CCSprite::initWithTexture));
        c.def("initWithTexture", py::overload_cast<CCTexture2D*, const CCRect&>(&CCSprite::initWithTexture));
        c.def("initWithTexture", py::overload_cast<CCTexture2D*, const CCRect&, bool>(&CCSprite::initWithTexture));
        c.def("initWithSpriteFrame", &CCSprite::initWithSpriteFrame);
        c.def("initWithSpriteFrameName", &CCSprite::initWithSpriteFrameName);
        c.def("initWithFile", py::overload_cast<const char*>(&CCSprite::initWithFile));
        c.def("initWithFile", py::overload_cast<const char*, const CCRect&>(&CCSprite::initWithFile));
        c.def("setChildColor", &CCSprite::setChildColor);
        c.def("setChildOpacity", &CCSprite::setChildOpacity);
}