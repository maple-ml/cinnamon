#pragma once

#include "utilities.h"
#include "globals.h"

class CCContentLayer : public cocos2d::CCLayerColor {
public:
    static CCContentLayer* create(const cocos2d::ccColor4B& color, float width, float height) {
        __asm {
            movss xmm1, width
            movss xmm2, height
        }
        return reinterpret_cast<CCContentLayer* (__fastcall*)(const cocos2d::ccColor4B&)>(utilities::getBase() + 0x172A0)(color);
    }
};