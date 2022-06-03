#pragma once

#include "utilities.h"
#include "globals.h"
#include "BoomListView.h"

// no hooks

class CustomListView : public BoomListView {
protected:
    CustomListView() {
        reinterpret_cast<void(__thiscall*)(CustomListView*)>(utilities::getBase() + 0x57E60)(this);
    }

public:
    static CustomListView* create(CCArray* entries, BoomListType type, float width, float height) {
        __asm {
            movss xmm1, width
            movss xmm2, height
        }

        auto pRet = reinterpret_cast<CustomListView*(__thiscall*)(CCArray*, BoomListType)>(utilities::getBase() + 0x57f90)(entries, type);

        __asm add esp, 0x4

        return pRet;
    }

    virtual void setupList() {
        return reinterpret_cast<void(__thiscall*)(BoomListView*)>(utilities::getBase() + 0x58870)(this);
    }
    virtual TableViewCell* getListCell(const char* key) {
        return reinterpret_cast<TableViewCell * (__thiscall*)(BoomListView*, const char*)>(utilities::getBase() + 0x58050)(this, key);
    }
    virtual void loadCell(TableViewCell* cell, unsigned int index) {
        return reinterpret_cast<void(__thiscall*)(BoomListView*, TableViewCell*, unsigned int)>(utilities::getBase() + 0x585C0)(this, cell, index);
    }
};