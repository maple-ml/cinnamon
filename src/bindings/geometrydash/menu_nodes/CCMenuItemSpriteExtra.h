#pragma once
#include "cocos2d.h"

#include "hooks.h"
#include "globals.h"
#include "utilities.h"
#include "macros.h"

class CCMenuItemSpriteExtra : public CCMenuItemSprite {
private:
	float m_sizeMult = 1.25;
	float m_origScale = 1.f;
public:
	virtual void selected() override {
		CCMenuItemSprite::selected();
		auto resize = cocos2d::CCScaleTo::create(0.3, m_sizeMult * m_origScale);
		auto bounce = cocos2d::CCEaseBounceOut::create(resize);
		this->runAction(bounce);
	};
	virtual void unselected() override {
		CCMenuItemSprite::unselected();
		auto resize = cocos2d::CCScaleTo::create(0.3, m_origScale);
		auto bounce = cocos2d::CCEaseBounceOut::create(resize);
		this->runAction(bounce);
	}
	virtual void activate() override {
		CCMenuItemSprite::activate();
		this->stopAllActions();
		this->setScale(m_origScale);
	}
	virtual void setScale(float scale) override {
		CCMenuItemSprite::setScale(scale);	
		m_origScale = scale;
	}
	static CCMenuItemSpriteExtra* create(CCNode *normalSprite, CCNode *selectedSprite, CCObject *target, cocos2d::SEL_MenuHandler selector) {
		auto spriteItem = new CCMenuItemSpriteExtra;
		if (spriteItem && spriteItem->initWithNormalSprite(normalSprite, selectedSprite, nullptr, target, selector)) 
			spriteItem->autorelease();
		else {
			delete spriteItem;
			spriteItem = nullptr;
		}
		return spriteItem;
	}
	void setSizeMult(float multiplier) { m_sizeMult = multiplier; }
};

void CCMenuItemSpriteExtra_init(py::module &m) {
	auto c = py::class_<CCMenuItemSpriteExtra, CCMenuItemSprite>(m, "CCMenuItemSpriteExtra");
		c.def("selected", &CCMenuItemSpriteExtra::selected);
		c.def("unselected", &CCMenuItemSpriteExtra::unselected);
		c.def("activate", &CCMenuItemSpriteExtra::activate);
		c.def("setScale", &CCMenuItemSpriteExtra::setScale);
		c.def("create", &CCMenuItemSpriteExtra::create);
		c.def("setSizeMult", &CCMenuItemSpriteExtra::setSizeMult);
}