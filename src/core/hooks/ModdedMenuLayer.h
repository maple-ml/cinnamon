#include <cocos2d.h>
#include "bindings/geometry_dash_bindings.h"
#include "bindings/cocos2d_bindings.h"
#include "bindings/manual_bindings.h"
#include "core/hooks.h"
#include "core/macros.h"
#include "core/module.h"

/*class ModListCell : public TableViewCell {
protected:
    float m_width;
    float m_height;
    CCMenu* m_menu;
    CCLabelBMFont* m_description;
    CCMenuItemToggler* m_enableToggle = nullptr;
    cocos2d::CCLayerColor* m_backgroundLayer;
    cinnamon::module::PythonMod* m_mod;

public:
    void draw() {
        reinterpret_cast<StatsCell*>(this)->StatsCell::draw(reinterpret_cast<StatsCell*>(this));
    }

    ModListCell* ModListCell::create(char const* key, CCSize size) {
        auto pRet = new ModListCell(key, size);
        if (pRet) {
            return pRet;
        }
        CC_SAFE_DELETE(pRet);
        return nullptr;
    }

    ModListCell(char const* name, CCSize size) {
        
    }

    void updateBGColor(int index) {
        if (index & 1) m_backgroundLayer->setColor(ccc3(0xc2, 0x72, 0x3e));
        else m_backgroundLayer->setColor(ccc3(0xa1, 0x58, 0x2c));
        m_backgroundLayer->setOpacity(0xff);
    }
};

class ModListLayer : public CustomListView {
    static CustomListView* create(
        cocos2d::CCArray* items, float itemHeight = 40.f, float width = 358.f,
        float height = 220.f
    );

    void setupList() {
        if (!m_entries->count()) return;
        m_tableView->reloadData();

        // fix content layer content size so the
        // list is properly aligned to the top
        auto coverage = calculateChildCoverage(m_tableView->m_contentLayer);
        m_tableView->m_contentLayer->setContentSize({ -coverage.origin.x + coverage.size.width,
                                                    -coverage.origin.y + coverage.size.height });

        if (m_entries->count() == 1) {
            m_tableView->moveToTopWithOffset(m_itemSeparation * 2);
        } else if (m_entries->count() == 2) {
            m_tableView->moveToTopWithOffset(-m_itemSeparation);
        } else {
            m_tableView->moveToTop();
        }
    }

    ModListCell* getListCell(char const* key) {
        return ModListCell::create(key, { m_width, m_itemSeparation });
    }

    void loadCell(TableViewCell* cell, int index) {
        auto node = dynamic_cast<CCNode*>(m_entries->objectAtIndex(index));
        if (node) {
            auto lcell = (ModListCell*)(cell);
            node->setContentSize(lcell->getScaledContentSize());
            node->setPosition(0, 0);
            lcell->addChild(node);
            lcell->updateBGColor(index);
        }
    }
};*/

class ModMenuLayer : public CCLayer {
private:
    GJListLayer* m_list;
    CCArray* m_mods;

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

        // for now we're going to use cclabelbmfont to display the mod list

        // iterate through cinnamon::module::modInstances and add them to the list

        float height = 80;
        
        std::map<std::string, cinnamon::module::PythonMod*>::iterator it;
        for (it = cinnamon::module::modInstances.begin(); it != cinnamon::module::modInstances.end(); ++it) {
            CCLabelBMFont* label = CCLabelBMFont::create((it->second->getName() + " by " + it->second->getAuthor()).c_str(), "bigFont.fnt");
            label->setAlignment(kCCTextAlignmentCenter);
            label->setAnchorPoint({0.5, 0.5});
            label->setPosition(winSize.width / 2, winSize.height - height);
            label->setScale(0.5);

            addChild(label);

            height += 30;
        }

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
        CCMenu* menu = CCMenu::create();

        CCDirector* director = CCDirector::sharedDirector();

        CCMenuItemSpriteExtra* btn = CCMenuItemSpriteExtra::create(spr, nullptr, self, menu_selector(onButtonPress));

        menu->addChild(btn);

        menu->setPosition(ccp(director->getWinSize().width - 25, director->getWinSize().height - 25));

        self->addChild(menu, 10);

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