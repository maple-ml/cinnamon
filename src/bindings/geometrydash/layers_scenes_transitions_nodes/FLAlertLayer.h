#pragma once

#include "globals.h"
#include "utilities.h"
#include "hooks.h"
#include "macros.h"

class FLAlertLayer : public CCLayerColor {
public:
    static FLAlertLayer* create(FLAlertLayer* target, const char* title, const char* btn1, const char* btn2, std::string caption) {
        FLAlertLayer* pRet = reinterpret_cast<FLAlertLayer* (__fastcall*)(FLAlertLayer*, const char*, const char*, const char*, std::string)>(utilities::getBase() + 0x22680)(target, title, btn1, btn2, caption);
        __asm add esp, 0x20
        return pRet;
    }
    static FLAlertLayer* create(FLAlertLayer* target, const char* title, const char* btn1, const char* btn2, float width, std::string caption) {
        FLAlertLayer* pRet = reinterpret_cast<FLAlertLayer* (__fastcall*)(FLAlertLayer*, const char*, const char*, const char*, float, std::string)>(utilities::getBase() + 0x22730)(target, title, btn1, btn2, width, caption);
        __asm add esp, 0x24
        return pRet;
    }

    //static FLAlertLayer* create(FLAlertLayer* target, const char* title, const char* btn1, const char* btn2, std::string caption) { CINNAMON_FUNC_STACK_FIX(0x20, __fastcall, FLAlertLayer*, 0x22680, CINNAMON_ARGS(FLAlertLayer*, const char*, const char*, const char*, std::string), CINNAMON_ARGS(target, title, btn1, btn2, caption)) };

    void show() { CINNAMON_FUNC(__thiscall, void, 0x23560, CINNAMON_ARGS(FLAlertLayer*), CINNAMON_ARGS(this)) }
    CINNAMON_HOOK_OVERLOAD(show, "FLAlertLayer::showH", 0x23560);
	CINNAMON_HOOK_VOID(showH, showO, CINNAMON_ARGS(self), CINNAMON_ARGS(FLAlertLayer* self));
	CINNAMON_ORIGINAL(showO_, void, CINNAMON_ARGS(FLAlertLayer*));
    CINNAMON_ORIGINAL_HOOK_VOID("FLAlertLayer::showH", showO, showC, showO_, CINNAMON_ARGS(self), CINNAMON_ARGS(FLAlertLayer* self));
	CINNAMON_ADDRESS(showA, 0x23560);
	CINNAMON_NAME(showN, "FLAlertLayer::showH");
};

void FLAlertLayer_init(py::module &m) {
    auto c = py::class_<FLAlertLayer>(m, "FLAlertLayer"); // use CCLayerColor as a base when possible (when the bindings exist)
        c.def("create", py::overload_cast<FLAlertLayer*, const char*, const char*, const char*, std::string>(&FLAlertLayer::create));
        c.def("create", py::overload_cast<FLAlertLayer*, const char*, const char*, const char*, float, std::string>(&FLAlertLayer::create));

        c.def("show", py::overload_cast<>(&FLAlertLayer::show));
        c.def("show", py::overload_cast<py::function>(&FLAlertLayer::show));
        c.def("showO", [](FLAlertLayer* self) { return FLAlertLayer::showO(self); });
        c.attr("showA") = FLAlertLayer::showA;
        c.attr("showN") = FLAlertLayer::showN;
        utilities::hookCinnamon((PVOID)FLAlertLayer::showA, FLAlertLayer::showH, (LPVOID*)&FLAlertLayer::showO_);
}