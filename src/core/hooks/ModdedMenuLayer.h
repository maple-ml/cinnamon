#include <cocos2d.h>
#include "bindings/geometrydash_bindings.h"
#include "core/hooks.h"
#include "core/macros.h"

// todo: bind this
class CCMenuItemSpriteExtra : public CCMenuItemSprite {
private:
	float m_sizeMult = 1.25;
	float m_origScale = 1.f;
public:
	virtual void selected() override {
		CCMenuItemSprite::selected();
		auto resize = cocos2d::CCScaleTo::create(0.3f, m_sizeMult * m_origScale);
		auto bounce = cocos2d::CCEaseBounceOut::create(resize);
		this->runAction(bounce);
	};
	virtual void unselected() override {
		CCMenuItemSprite::unselected();
		auto resize = cocos2d::CCScaleTo::create(0.3f, m_origScale);
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

class ModMenuLayer : public CCLayer {
private:
    //GJListLayer* m_list;
    //CCArray* m_mods;

public:
    static ModMenuLayer* create() {
        auto ret = new ModMenuLayer();
        if (ret && ret->init()) {
            ret->autorelease();
        } else {
            delete ret;
            ret = nullptr;
        }
        return ret;
    }

    bool init() {
        CCSprite* bg = CCSprite::create("GJ_gradientBG.png"); // blue bg

        CCSize winSize = CCDirector::sharedDirector()->getWinSize();
        CCSize size = bg->getContentSize();
        
        bg->setScaleX(winSize.width / size.width);
        bg->setScaleY(winSize.height / size.height);

        bg->setAnchorPoint({0, 0});

        bg->setColor({0, 102, 255});

        bg->setZOrder(-1);

        addChild(bg);

        CCMenuItemSpriteExtra* button = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("GJ_arrow_01_001.png"),
            nullptr,
            this,
            menu_selector(ModMenuLayer::backButtonCallback)
        );

        CCMenu* menu = CCMenu::create();
        menu->addChild(button);

        menu->setPosition({25, winSize.height - 25});

        addChild(menu);
            
        setKeypadEnabled(true);

        return true;
    }

    void keyBackClicked() {
        CCDirector::sharedDirector()->popSceneWithTransition(0.5f, PopTransition::kPopTransitionFade);
    }

    void backButtonCallback(CCObject* object) {
        keyBackClicked();
    }

};

class ModdedMenuLayer : public MenuLayer {
public:
    static bool init(MenuLayer* self) {
        bool ret = MenuLayer::initO(self);

        std::cout << "init from cinnamon internals" << std::endl;

        CCSprite* spr = CCSprite::create("GJ_button_01.png");

        CCDirector* director = CCDirector::sharedDirector();

        spr->setPosition(ccp(director->getWinSize().width / 2, director->getWinSize().height / 2));

        self->addChild(spr, 9999);

        //CCMenu* bottomMenu = getChild<CCMenu>(self, 13);

        //CCMenuItemSpriteExtra* btn = CCMenuItemSpriteExtra::create(CCSprite::create("GJ_button_01.png"), nullptr, self, menu_selector(onButtonPress));

        //bottomMenu->addChild(btn);
        //bottomMenu->alignItemsHorizontallyWithPadding(5.0f);

        return ret;
    }

    void onButtonPress(CCObject* sender) {
        ModMenuLayer* modmenu = ModMenuLayer::create();
        CCScene* scene = CCScene::create();
        scene->addChild(modmenu);

        CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5, scene));
    }

    static void enable() {
        cinnamon::hooks::Hook(MenuLayer::init, &ModdedMenuLayer::init);
    }
};