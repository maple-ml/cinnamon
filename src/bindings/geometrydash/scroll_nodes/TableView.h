#pragma once

// no hooks

#include "CCScrollLayerExt.h"
#include "utilities.h"
#include "globals.h"

class CCScrollLayerExt;
class CCScrollLayerExtDelegate;
class CCIndexPath;
class TableView;

typedef enum {

} TableViewCellEditingStyle;

class TableViewDelegate {
public:
    virtual void willTweenToIndexPath(CCIndexPath&, TableViewCell*, TableView*) {}
    virtual void didEndTweenToIndexPath(CCIndexPath&, TableView*) {}
    virtual void TableViewWillDisplayCellForRowAtIndexPath(CCIndexPath&, TableViewCell*, TableView*) {}
    virtual void TableViewDidDisplayCellForRowAtIndexPath(CCIndexPath&, TableViewCell*, TableView*) {}
    virtual void TableViewWillReloadCellForRowAtIndexPath(CCIndexPath&, TableViewCell*, TableView*) {}
    virtual float cellHeightForRowAtIndexPath(CCIndexPath&, TableView*) = 0;
    virtual void didSelectRowAtIndexPath(CCIndexPath&, TableView*) = 0;
};

class TableViewDataSource {
public:
    virtual unsigned int numberOfRowsInSection(unsigned int, TableView*) = 0;
    virtual unsigned int numberOfSectionsInTableView(TableView*) { return 1; }
    virtual void TableViewCommitCellEditingStyleForRowAtIndexPath(TableView*, TableViewCellEditingStyle, CCIndexPath&) {}
    virtual TableViewCell* cellForRowAtIndexPath(CCIndexPath&, TableView*) = 0;
};

class TableView : public CCScrollLayerExt, public CCScrollLayerExtDelegate {
    public:
        bool m_bTouchDown2;
        PAD(4)
        CCPoint m_obTouchStartPosition2;
        CCPoint m_obUnknown2;
        CCPoint m_obTouchPosition2;
        PAD(4)
        bool m_bTouchMoved;
        PAD(3)
        CCArray* m_pCellArray;
        CCArray* m_pArray2;
        CCArray* m_pArray3;
        TableViewDelegate* m_pDelegate;
        TableViewDataSource* m_pDataSource;
        PAD(16)
        float m_fTouchLastY;
        PAD(4)

        TableView(CCRect rect) : CCScrollLayerExt(rect) {
            reinterpret_cast<TableView*(__thiscall*)(TableView*, CCRect)>(utilities::getBase() + 0x30fb0)(this, rect);
        }

        void reloadData() {
            reinterpret_cast<void(__thiscall*)(TableView*)>(utilities::getBase() + 0x317e0)(this);
        }

        static TableView* create(TableViewDelegate* delegate, TableViewDataSource* dataSource, CCRect rect) {
            auto pRet = reinterpret_cast<TableView*(__fastcall*)(TableViewDelegate*, TableViewDataSource*, CCRect)>(utilities::getBase() + 0x30ed0)(delegate, dataSource, rect);

            __asm add esp, 0x10

            return pRet;
        }
};