#pragma once
#include "cocos2d.h"
#include "cocos-ext.h"
#include "macros.h"
#include "menu_nodes/CCMenuItemSpriteExtra.h"
#include "scroll_nodes/CustomListView.h"
#include "layers_scenes_transitions_nodes/GJListLayer.h"
#include "scroll_nodes/CCScrollLayerExt.h"
#include "layers_scenes_transitions_nodes/FLAlertLayer.h"
#include "cinnamon.h"

USING_NS_CC;
using namespace extension;

#define CCARRAY_FOREACH_B_BASE(__array__, __obj__, __type__, __index__) \
    if ((__array__) && (__array__)->count()) \
    for (auto [__index__, __obj__] = std::tuple<unsigned int, __type__> { 0u, nullptr }; \
        (__index__ < (__array__)->count() && (__obj__ = reinterpret_cast<__type__>((__array__)->objectAtIndex(__index__)))); \
        __index__++)

#define CCARRAY_FOREACH_B_TYPE(__array__, __obj__, __type__) \
    CCARRAY_FOREACH_B_BASE(__array__, __obj__, __type__*, ccArray_forEach_b_base_index)

#define CCARRAY_FOREACH_B(__array__, __obj__) \
    CCARRAY_FOREACH_B_BASE(__array__, __obj__, CCObject*, ccArray_forEach_b_index)

CCRect calculateNodeCoverage(CCArray* nodes) {
    CCRect coverage;
    CCARRAY_FOREACH_B_TYPE(nodes, child, CCNode) {
        auto pos = (CCPoint)child->getPosition() - (CCPoint)child->getScaledContentSize() * (CCPoint)child->getAnchorPoint();
        auto csize = (CCPoint)child->getPosition() + (CCPoint)child->getScaledContentSize() * (CCPoint { 1.f, 1.f } - (CCPoint)child->getAnchorPoint());
        if (pos.x < coverage.origin.x) {
            coverage.origin.x = pos.x;
        }
        if (pos.y < coverage.origin.y) {
            coverage.origin.y = pos.y;
        }
        if (csize.x > coverage.size.width) {
            coverage.size.width = csize.x;
        }
        if (csize.y > coverage.size.height) {
            coverage.size.height = csize.y;
        }
    }
    return coverage;
}

CCRect calculateChildCoverage(CCNode* parent) {
    return calculateNodeCoverage(parent->getChildren());
}

class ModObject : public TableViewCell {
private:
    py::object m_module;
public:
};

class ModMenuView : public CustomListView {
public:
    TableView* m_pTableView;
    CCArray* m_pEntries;
    BoomListType m_eType;
    float m_fHeight;
    float m_fWidth;
    float m_fItemSeparation;

    void setupList() {
        m_fItemSeparation = 40.0f;

        if (!m_pEntries->count()) return;

        m_pTableView->reloadData();

        auto coverage = calculateChildCoverage(m_pTableView->m_pContentLayer);
        m_pTableView->m_pContentLayer->setContentSize({
            -coverage.origin.x + coverage.size.width,
            -coverage.origin.y + coverage.size.height
        });

        if (m_pEntries->count() == 1) {
            m_pTableView->moveToTopWithOffset(m_fItemSeparation);
        } else {
            m_pTableView->moveToTop();
        }
    }

    TableViewCell* getListCell(const char* key) {
        return ModObject::create(key, this->m_fWidth, this->m_fHeight);
    }

    bool init(CCArray* mods, BoomListType type, float width, float height) {
        return CustomListView::init(mods, type, width, height);
    }

    static ModMenuView* create(CCArray* mods, BoomListType type, float width, float height) {
        auto pRet = new ModMenuView;
        if (pRet) {
            if (pRet->init(mods, type, width, height)) {
                pRet->autorelease();
                return pRet;
            }
        }
        CC_SAFE_DELETE(pRet);
        return nullptr;
    }
};

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

        this->m_mods = CCArray::create();

        std::multimap<std::string, py::object>::iterator itr;
        for (itr = globals::modules.begin(); itr != globals::modules.end(); ++itr) {
            utilities::log(std::string("Mod menu: ") + itr->first, "DEBUG");
            this->m_mods->addObject(ModObject::create(itr->first.c_str(), 358.f, 220.f));
        }

        CustomListView* listv = CustomListView::create(this->m_mods, kBoomListTypeDefault, 358.f, 190.f);
        this->m_list = GJListLayer::create(listv, "Mods", {0, 0, 0, 180}, 358.f, 220.f);

        this->m_list->setZOrder(2);
        this->m_list->setPosition(winSize / 2 - this->m_list->getScaledContentSize() / 2);

        addChild(this->m_list);

        CCLabelBMFont* label = CCLabelBMFont::create("Mod list is not avaliable yet.", "bigFont.fnt");

        label->setPosition(winSize.width / 2, (winSize.height / 2) + (winSize.height / 4));
        label->setScale(0.5f);

        addChild(label, 5);

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
    void showStartupError(CCNode* sender) {
        cinnamon::alert("Cinnamon", "An <cr>exception</c> occured while loading a mod.\nEnable <cy>debug</c> mode and check the console for more information.", "Ok", nullptr, 300.0f);
    }

    static void enable_hooks() {
        MH_EnableHook((PVOID)0x1907b0); // MenuLayer::init
    }

    static bool MenuLayer_init(CCLayer* self) {
        if (globals::startupErrorOccured)
            CCDirector::sharedDirector()->getScheduler()->scheduleSelector(schedule_selector(ModMenu::showStartupError), self, 0.1f, false, 0, 0.1f);

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
        ModMenuLayer* modmenu = ModMenuLayer::create();
        CCScene* scene = CCScene::create();
        scene->addChild(modmenu);

        CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5, scene));
    }
};