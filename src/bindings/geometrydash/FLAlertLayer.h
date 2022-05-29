#pragma once

#include "hooks.h"
#include "globals.h"
#include "utilities.h"

class FLAlertLayer : public CCNode {
public:
    static FLAlertLayer* create(FLAlertLayer* target, const char* title,
        const char* btn1, const char* btn2, std::string caption) {
        FLAlertLayer* pRet = reinterpret_cast<FLAlertLayer* (__fastcall*)(FLAlertLayer*, const char*, const char*, const char*, std::string)>(utilities::getBase() + 0x22680)(target, title, btn1, btn2, caption);
        
        __asm add esp, 0x20
        return pRet;
    }

    void show() {
        return reinterpret_cast<void(__thiscall*)(FLAlertLayer*)>(utilities::getBase() + 0x23560)(this);
    }
};


void FLAlertLayer_init(py::module &m) {
	py::class_<FLAlertLayer>(m, "FLAlertLayer");
}
