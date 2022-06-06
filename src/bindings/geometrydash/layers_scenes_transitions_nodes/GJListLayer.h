#pragma once

// no hooks

#include "utilities.h"
#include "globals.h"
#include "scroll_nodes/BoomListView.h"

class GJListLayer : public CCLayerColor {
public:
    BoomListView* m_pListView;

public:
    static GJListLayer* create(BoomListView* list, const char* title, ccColor4B color, float width, float height) {
        __asm movss xmm3, width

        auto pRet = reinterpret_cast<GJListLayer * (__fastcall*)(BoomListView*, const char*, ccColor4B, float)>(utilities::getBase() + 0x12E000)(list, title, color, height);

        __asm add esp, 0x8

        return pRet;
    }
};