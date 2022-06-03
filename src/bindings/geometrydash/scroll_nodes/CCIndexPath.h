#pragma once

// no hooks

#include "utilities.h"
#include "globals.h"

class CCIndexPath : public cocos2d::CCObject {
    public:
        int m_nPosition;
        int m_nUnknown2;

    public:
        static CCIndexPath* create(unsigned int idk1, int idk2) {
            return reinterpret_cast<CCIndexPath* (__fastcall*)(int, int)>(utilities::getBase() + 0x30E40)(idk1, idk2);
        }
    };