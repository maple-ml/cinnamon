#pragma once

#include "utilities.h"
#include "globals.h"
#include "mod_menu.h"

class MenuLayer : public CCLayer {
public:
    static MenuLayer* create() { CINNAMON_FUNC(__stdcall, MenuLayer*, 0x190550, CINNAMON_ARGS(), CINNAMON_ARGS()) }
	CINNAMON_HOOK(createH, createO, MenuLayer*, CINNAMON_ARGS(), CINNAMON_ARGS());
	CINNAMON_ORIGINAL(createO, MenuLayer*, CINNAMON_ARGS());
	CINNAMON_ADDRESS(createA, 0x190550);
	CINNAMON_NAME(createN, "MenuLayer::createH");

    bool init() { CINNAMON_FUNC(__thiscall, bool, 0x1907b0, CINNAMON_ARGS(MenuLayer*), CINNAMON_ARGS(this)) }
	CINNAMON_HOOK_PLUS(initH, initO, bool, ModMenu::MenuLayer_init, CINNAMON_ARGS(self), CINNAMON_ARGS(MenuLayer* self));
	CINNAMON_ORIGINAL(initO, bool, CINNAMON_ARGS(MenuLayer*));
	CINNAMON_ADDRESS(initA, 0x1907b0);
	CINNAMON_NAME(initN, "MenuLayer::initH");
};

void MenuLayer_init(py::module &m) {
	auto c = py::class_<MenuLayer>(m, "MenuLayer");
        c.def("create", &MenuLayer::create);
		c.def("createO", []() { return MenuLayer::createO(); });
        c.attr("createA") = MenuLayer::createA;
        c.attr("createN") = MenuLayer::createN;
        utilities::hookCinnamon((PVOID)MenuLayer::createA, MenuLayer::createH, (LPVOID*)&MenuLayer::createO);

        c.def("init", &MenuLayer::init);
		c.def("initO", [](MenuLayer* self) { return MenuLayer::initO(self); });
        c.attr("initA") = MenuLayer::initA;
        c.attr("initN") = MenuLayer::initN;
        utilities::hookCinnamon((PVOID)MenuLayer::initA, MenuLayer::initH, (LPVOID*)&MenuLayer::initO);
}