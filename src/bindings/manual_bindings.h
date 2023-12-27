
#pragma once
#include <cocos2d.h>
#include "core/utilities/game.h"
#include "core/hooks.h"
#include "core/python.h"
#include "pybind11.h"
#include "pybind11/embed.h"

#ifndef PAD
#define PAD(size) char __STR_CAT__(__, __STR_CAT__(pad, __LINE__))[size] = {};
#endif

USING_NS_CC;
namespace pybind = pybind11;

class CCMenuItemSpriteExtra : public CCMenuItemSprite {
private:
	float m_sizeMult = 1.25;
	float m_origScale = 1.f;
    pybind::function m_pythonCallback;
	bool m_usePythonCallback = false;
public:
	virtual void selected() override {
		CCMenuItemSprite::selected();
		auto resize = CCScaleTo::create(0.3f, m_sizeMult * m_origScale);
		auto bounce = CCEaseBounceOut::create(resize);
		this->runAction(bounce);
	};
	virtual void unselected() override {
		CCMenuItemSprite::unselected();
		auto resize = CCScaleTo::create(0.3f, m_origScale);
		auto bounce = CCEaseBounceOut::create(resize);
		this->runAction(bounce);
	}
	virtual void activate() override {
        if (m_usePythonCallback) {
			try {
				pybind::gil_scoped_acquire acquire;
				m_pythonCallback(m_pListener, this);
				pybind::gil_scoped_release release;
			}
			catch (pybind::error_already_set& e) {
				cinnamon::logger::log("An exception occurred while calling a python callback:", cinnamon::logger::LoggingLevel::ERROR);
				// traceback exception
				cinnamon::python::printPythonException(e);
			}
        }
        else {
			CCMenuItemSprite::activate();
        }
		this->stopAllActions();
		this->setScale(m_origScale);
	}
	virtual void setScale(float scale) override {
		CCMenuItemSprite::setScale(scale);	
		m_origScale = scale;
	}
	static CCMenuItemSpriteExtra* create(CCNode* normalSprite, CCNode* selectedSprite, CCObject* target, SEL_MenuHandler selector) {
		auto spriteItem = new CCMenuItemSpriteExtra;
		if (spriteItem && spriteItem->initWithNormalSprite(normalSprite, selectedSprite, nullptr, target, selector)) 
			spriteItem->autorelease();
		else {
			delete spriteItem;
			spriteItem = nullptr;
		}
		return spriteItem;
	}

    // custom cinammon stuff to allow for python callbacks
	static CCMenuItemSpriteExtra* create(CCNode* normalSprite, CCNode* selectedSprite, CCObject* target, pybind::function callback) {
		auto spriteItem = new CCMenuItemSpriteExtra;

        spriteItem->m_pythonCallback = callback;
		spriteItem->m_usePythonCallback = true;

		if (spriteItem && spriteItem->initWithNormalSprite(normalSprite, selectedSprite, nullptr, target, nullptr)) 
			spriteItem->autorelease();
		else {
			delete spriteItem;
			spriteItem = nullptr;
		}
		return spriteItem;
	}

	static CCMenuItemSpriteExtra* create(CCNode* normalSprite, CCObject* target, pybind::function callback) {
		auto spriteItem = new CCMenuItemSpriteExtra;

        spriteItem->m_pythonCallback = callback;
		spriteItem->m_usePythonCallback = true;

		if (spriteItem && spriteItem->initWithNormalSprite(normalSprite, nullptr, nullptr, target, nullptr))
			spriteItem->autorelease();
		else {
			delete spriteItem;
			spriteItem = nullptr;
		}

		return spriteItem;
	}

	void setSizeMult(float multiplier) { m_sizeMult = multiplier; }
};

namespace manualbindings {
    void cocos2d_init(pybind::module_ &m) {
        cinnamon::logger::log("Initializing manual cocos2d bindings", cinnamon::logger::LoggingLevel::INFO);

		pybind::class_<CCMenuItem, CCNodeRGBA>(m, "CCMenuItem")
			.def_static("create", pybind::overload_cast<>(&CCMenuItem::create))
			.def_static("create", pybind::overload_cast<CCObject*, SEL_MenuHandler>(&CCMenuItem::create))
			.def("initWithTarget", &CCMenuItem::initWithTarget)
			.def("activate", &CCMenuItem::activate, pybind::return_value_policy::automatic_reference)
			.def("selected", &CCMenuItem::selected, pybind::return_value_policy::automatic_reference)
			.def("unselected", &CCMenuItem::unselected, pybind::return_value_policy::automatic_reference)
			.def("setEnabled", &CCMenuItem::setEnabled, pybind::return_value_policy::automatic_reference)
			.def("isEnabled", &CCMenuItem::isEnabled, pybind::return_value_policy::automatic_reference);

        pybind::class_<CCMenuItemImage, CCMenuItem>(m, "CCMenuItemImage")
            .def_static("create", pybind::overload_cast<const char*, const char*>(&CCMenuItemImage::create))
            .def_static("create", pybind::overload_cast<const char*, const char*, const char*>(&CCMenuItemImage::create))
            .def_static("create", pybind::overload_cast<const char*, const char*, CCObject*, SEL_MenuHandler>(&CCMenuItemImage::create))
            .def_static("create", pybind::overload_cast<const char*, const char*, const char*, CCObject*, SEL_MenuHandler>(&CCMenuItemImage::create))
            .def("init", &CCMenuItemImage::init)
            .def("initWithNormalImage", &CCMenuItemImage::initWithNormalImage)
            .def("setNormalSpriteFrame", &CCMenuItemImage::setNormalSpriteFrame)
            .def("setSelectedSpriteFrame", &CCMenuItemImage::setSelectedSpriteFrame)
            .def("setDisabledSpriteFrame", &CCMenuItemImage::setDisabledSpriteFrame)
            .def_static("create", pybind::overload_cast<>(&CCMenuItemImage::create));

		pybind::class_<CCMenuItemSprite, CCMenuItem>(m, "CCMenuItemSprite")
			.def("initWithNormalSprite", &CCMenuItemSprite::initWithNormalSprite, pybind::return_value_policy::automatic_reference)
			.def("selected", &CCMenuItemSprite::selected, pybind::return_value_policy::automatic_reference)
			.def("unselected", &CCMenuItemSprite::unselected, pybind::return_value_policy::automatic_reference)
			.def("setEnabled", &CCMenuItemSprite::setEnabled, pybind::return_value_policy::automatic_reference);
	}

    void geometry_dash_init(pybind::module_ &m) {
        cinnamon::logger::log("Initializing manual geometry dash bindings", cinnamon::logger::LoggingLevel::INFO);
		pybind::class_<CCMenuItemSpriteExtra, CCMenuItemSprite>(m, "CCMenuItemSpriteExtra")
            .def("setSizeMult", &CCMenuItemSpriteExtra::setSizeMult, pybind::return_value_policy::automatic_reference)
            .def("setScale", &CCMenuItemSpriteExtra::setScale, pybind::return_value_policy::automatic_reference)
            .def("activate", &CCMenuItemSpriteExtra::activate, pybind::return_value_policy::automatic_reference)
            .def("unselected", &CCMenuItemSpriteExtra::unselected, pybind::return_value_policy::automatic_reference)
            .def("selected", &CCMenuItemSpriteExtra::selected, pybind::return_value_policy::automatic_reference)
            .def_static("create", pybind::overload_cast<CCNode*, CCNode*, CCObject*, SEL_MenuHandler>(&CCMenuItemSpriteExtra::create), pybind::return_value_policy::automatic_reference)
			.def_static("create", pybind::overload_cast<CCNode*, CCNode*, CCObject*, pybind::function>(&CCMenuItemSpriteExtra::create), pybind::return_value_policy::automatic_reference)
			.def_static("create", pybind::overload_cast<CCNode*, CCObject*, pybind::function>(&CCMenuItemSpriteExtra::create), pybind::return_value_policy::automatic_reference);
    }
}