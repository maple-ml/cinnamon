#pragma once

// no hooks

#include "utilities.h"
#include "globals.h"

#include "CCIndexPath.h"
#include "level_nodes/GJGameLevel.h"
#include "CCContentLayer.h"

class CCContentLayer;
class TableView;
class CCScrollLayerExtDelegate;

class TableViewCell : public CCLayer {
    public:
        bool m_bUnknown;
        PAD(3)
        TableView* m_pTableView;
        CCIndexPath m_iIndexPath;
        std::string m_sUnknownString;
        PAD(4)
        float m_fWidth;
        float m_fHeight;
        CCLayerColor* m_pBGLayer;
        CCLayer* m_pLayer;
        PAD(4)

        TableViewCell(const char* name, float width, float height) {
            __asm {
                movss xmm2, width
                movss xmm3, height
            }
            reinterpret_cast<void(__thiscall*)(TableViewCell*, const char*)>(
                utilities::getBase() + 0x32E70
            )(this, name);
        }

        static TableViewCell* create(const char* name, float width, float height) {
            auto pRet = new TableViewCell(name, width, height);

            if (pRet) {
                pRet->autorelease();
                return pRet;
            }

            CC_SAFE_DELETE(pRet);
            return nullptr;
        }
};

class StatsCell : public TableViewCell {
    public:
        void updateBGColor(unsigned int index) {
            reinterpret_cast<void(__thiscall*)(StatsCell*, unsigned int)>(
                utilities::getBase() + 0x59cf0
            )(this, index);
        }
};

class LevelCell : public TableViewCell {
    public:
        GJGameLevel* m_pLevel;
        PAD(4)
};

class CCScrollLayerExt : public CCLayer {
    public:
        CCTouch* m_pTouch;
        CCPoint m_obTouchPosition;
        CCPoint m_obTouchStartPosition;
        PAD(8)
        bool m_bTouchDown;
        bool m_bNotAtEndOfScroll;
        PAD(2)
        CCLayerColor* m_pVerticalScrollbar;
        CCLayerColor* m_pHorizontalScrollbar;
        CCScrollLayerExtDelegate* m_pDelete;
        CCContentLayer* m_pContentLayer;
        bool m_bCutContent;
        bool m_bVScrollbarVisible;
        bool m_bHScrollbarVisible;
        bool m_bDisableHorizontal;
        bool m_bDisableVertical;
        bool m_bDisableMovement;
        PAD(2)
        float m_fScrollLimitTop;
        float m_fScrollLimitBottom;
        float m_fPeekLimitTop;
        float m_fPeekLimitBottom;

        CCScrollLayerExt(CCRect rect) {
            reinterpret_cast<void(__thiscall*)(CCScrollLayerExt*, CCRect)>(
                utilities::getBase() + 0x1B020
            )(this, rect);
        }

        virtual void registerWithTouchDispatcher() override {
            return reinterpret_cast<void(__thiscall*)(CCScrollLayerExt*)>(
                utilities::getBase() + 0x1b980
            )(this);
        }

        virtual void preVisitWithClippingRect(CCRect rect) {
            return reinterpret_cast<void(__thiscall*)(CCScrollLayerExt*, CCRect)>(
                utilities::getBase() + 0x1C000
            )(this, rect);
        }
        virtual void postVisit() {
            return reinterpret_cast<void(__thiscall*)(CCScrollLayerExt*)>(
                utilities::getBase() + 0x1C090
            )(this);
        }

        static CCScrollLayerExt* create(CCRect rect, bool vertical = true) {
            auto pRet = new CCScrollLayerExt(rect);

            if (pRet) {
                pRet->autorelease();
                pRet->m_bDisableVertical = !vertical;
                pRet->m_bDisableHorizontal = vertical;
                pRet->m_bCutContent = true;
                return pRet;
            }

            CC_SAFE_DELETE(pRet);
            return nullptr;
        }

        void scrollLayer(float scroll) {
            __asm movss xmm1, scroll

            reinterpret_cast<void(__thiscall*)(CCScrollLayerExt*)>(
                utilities::getBase() + 0x1be20
            )(this);
        }

        void moveToTop() {
            reinterpret_cast<void(__thiscall*)(CCScrollLayerExt*)>(
                utilities::getBase() + 0x1b4a0
            )(this);
        }

        void moveToTopWithOffset(float fOffset) {
            __asm { movss xmm1, fOffset }

            reinterpret_cast<void(__thiscall*)(CCScrollLayerExt*)>(
                utilities::getBase() + 0x1b420
            )(this);
        }

        float getMinY() {
            return this->getContentSize().height - this->m_pContentLayer->getContentSize().height - this->m_fScrollLimitTop;
        }

        float getMaxY() {
            return this->m_fScrollLimitBottom;
        }

        void addItem(CCNode* cell, bool addToTop = false) {
            float height = 0.0f;
            CCObject* obj;
            CCARRAY_FOREACH(this->m_pContentLayer->getChildren(), obj) {
                auto node = reinterpret_cast<CCNode*>(obj);

                height += node->getScaledContentSize().height;

                if (!addToTop)
                node->setPositionY(node->getPositionY() + cell->getScaledContentSize().height);
            }

            cell->setPosition(
                this->getScaledContentSize().width / 2,
                addToTop ? 
                height + cell->getScaledContentSize().height / 2 :
                cell->getScaledContentSize().height / 2
            );

            height += cell->getScaledContentSize().height;

            this->m_pContentLayer->addChild(cell);

            this->m_pContentLayer->setContentSize({
                cell->getScaledContentSize().width, height
            });
        }
};

class CCScrollLayerExtDelegate {
    public:
        // robs typo not mine
        virtual void scrllViewWillBeginDecelerating(CCScrollLayerExt*) {}
        virtual void scrollViewDidEndDecelerating(CCScrollLayerExt*) {}
        virtual void scrollViewTouchMoving(CCScrollLayerExt*) {}
        virtual void scrollViewDidEndMoving(CCScrollLayerExt*) {}
        virtual void scrollViewTouchBegin(CCScrollLayerExt*) {}
        virtual void scrollViewTouchEnd(CCScrollLayerExt*) {}
};