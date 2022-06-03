#pragma once
#include "cocos2d.h"
#include "cocos-ext.h"
#include "macros.h"

USING_NS_CC;
using namespace extension;

class ModMenuLayer : public CCLayer {
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
        std::cout << "layer init\n";

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

        addChild(CCScrollView::create(CCSize(winSize.width, winSize.height)));

        return true;
    }

    void keyBackClicked() {
    CCDirector::sharedDirector()->popSceneWithTransition(0.5f, PopTransition::kPopTransitionFade);
    }

    void backButtonCallback(CCObject* object) {
        keyBackClicked();
    }

};

class ModMenu : public CCNode {
public:
    static void enable_hooks() {
        MH_EnableHook((PVOID)0x1907b0); // MenuLayer::init
    }

    static bool MenuLayer_init(CCLayer* self) {
        std::cout << "menulayer\n";

        CCSize window = CCDirector::sharedDirector()->getWinSize();

        CCMenu* bottomMenu = (CCMenu*)self->getChildren()->objectAtIndex(3);
        CCMenuItemSpriteExtra* btn = CCMenuItemSpriteExtra::create(CCSprite::create("GJ_button_01.png"), nullptr, self, menu_selector(onButtonPress));

        CCMenuItem* chestBtn = (CCMenuItem*)(bottomMenu->getChildren()->objectAtIndex(4));
        bottomMenu->removeChild(chestBtn, false); // so it doesn't get in the way of the bottom menu, no cleanup so it doens't move

        bottomMenu->addChild(btn);
        bottomMenu->alignItemsHorizontallyWithPadding(5.0f);

        return true;
    }

    void onButtonPress(CCObject* sender) {
        std::cout << "button pressed\n";

        ModMenuLayer* modmenu = ModMenuLayer::create();
        CCScene* scene = CCScene::create();
        scene->addChild(modmenu);

        CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5, scene));
    }
};