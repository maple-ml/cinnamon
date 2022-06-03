#pragma once

#include "utilities.h"
#include "globals.h"
#include "TableView.h"

// no hooks

class TableViewDelegate;
class TableViewDataSource;
class TableView;
class TableViewCell;

enum BoomListType {
    kBoomListTypeDefault 		= 0x0,
    kBoomListTypeUser 			= 0x2,
    kBoomListTypeStats 			= 0x3,
    kBoomListTypeAchievement    = 0x4,
    kBoomListTypeLevel 		    = 0x5,
    kBoomListTypeLevel2 	    = 0x6,
    kBoomListTypeComment 	    = 0x7,
    kBoomListTypeComment2 	    = 0x8,
    kBoomListTypeSong 		    = 0xb,
    kBoomListTypeScore 		    = 0xc,
    kBoomListTypeMapPack 	    = 0xd,
    kBoomListTypeCustomSong     = 0xe,
    kBoomListTypeComment3 	    = 0xf,
    kBoomListTypeUser2 		    = 0x10,
    kBoomListTypeRequest 	    = 0x11,
    kBoomListTypeMessage 	    = 0x12,
    kBoomListTypeLevelScore     = 0x13,
    kBoomListTypeArtist		    = 0x14,
};

class BoomListView : public CCLayer, public TableViewDelegate, public TableViewDataSource {
public:
    TableView* m_pTableView;
    CCArray* m_pEntries;
    BoomListType m_eType;
    float m_fHeight;
    float m_fWidth;
    float m_fItemSeparation;
    PAD(4)

public:
    virtual float cellHeightForRowAtIndexPath(CCIndexPath& path, TableView* view) {
        return reinterpret_cast<float(__thiscall*)(char*, CCIndexPath&, TableView*)>(utilities::getBase() + 0x10E50)(reinterpret_cast<char*>(this) + 0x11C, path, view);
    }

    virtual unsigned int numberOfRowsInSection(unsigned int section, TableView* view) {
        return reinterpret_cast<unsigned int(__thiscall*)(char*, unsigned int, TableView*)>(utilities::getBase() + 0x10E60)(reinterpret_cast<char*>(this) + 0x120, section, view);
    }

    virtual TableViewCell* cellForRowAtIndexPath(CCIndexPath& path, TableView* view) {
        return reinterpret_cast<TableViewCell* (__thiscall*)(char*, CCIndexPath&, TableView*)>(utilities::getBase() + 0x10E70)(reinterpret_cast<char*>(this) + 0x120, path, view);
    }

    virtual ~BoomListView() {
        CC_SAFE_RELEASE(m_pEntries);
    }
    
    bool init(CCArray* entries, BoomListType btype, float width, float height) {
        __asm {
            movss xmm2, height
            movss xmm3, width
        }
        return reinterpret_cast<bool(__thiscall*)(BoomListView*, CCArray*, int, BoomListType)>(utilities::getBase() + 0x10c20)(this, entries, 0, btype);
    }

    virtual void setupList() {
        return reinterpret_cast<void(__thiscall*)(BoomListView*)>(utilities::getBase() + 0x10DC0)(this);
    }

    virtual TableViewCell* getListCell(const char* key) {
        return reinterpret_cast<TableViewCell* (__thiscall*)(BoomListView*, const char*)>(utilities::getBase() + 0x10ED0)(this, key);
    }

    virtual void loadCell(TableViewCell* cell, unsigned int index) {
        return reinterpret_cast<void(__thiscall*)(BoomListView*, TableViewCell*, unsigned int)>(utilities::getBase() + 0x10FF0)(this, cell, index);
    }

    virtual void didSelectRowAtIndexPath(CCIndexPath&, TableView*) {}
};