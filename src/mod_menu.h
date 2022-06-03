#pragma once
#include "geometrydash.h"

// FIXME: circular dependency
class ModMenu {
public:
    static bool MenuLayer_init(MenuLayer* self) {
        return MenuLayer::initO(self);
    }
};