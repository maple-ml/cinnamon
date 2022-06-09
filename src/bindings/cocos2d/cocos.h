#pragma once

#include "macros.h"
#include "utilities.h"
#include "hooks.h"
#include "globals.h"

// CC is omitted because cocos will wrongfully find our version of it

// base dir

#include "Director.h"

// base nodes
#include "base_nodes/Node.h"

// cocoa
#include "cocoa/Object.h"
#include "cocoa/Copying.h"
#include "cocoa/Point.h"
#include "cocoa/Size.h"

// layers_scenes_transitions_nodes
#include "layers_scenes_transitions_nodes/Scene.h"
#include "layers_scenes_transitions_nodes/Layer.h"

// menu_nodes

#include "menu_nodes/MenuItem.h"
#include "menu_nodes/MenuItemSprite.h"

// sprite_nodes
#include "sprite_nodes/Sprite.h"

PYBIND11_EMBEDDED_MODULE(cocos2d, m) { // the suffering begins
    utilities::log("Binding cocos2d", "DEBUG");

    //m.def("menu_selector", [](void* selector) { (SEL_MenuHandler)(&selector); });

    CCCopying_init(m);
    CCObject_init(m);

    CCSize_init(m);
    CCPoint_init(m);

    CCNode_init(m);

    CCMenuItem_init(m);
    CCMenuItemSprite_init(m);

    CCScene_init(m);
    CCLayer_init(m);

    CCSprite_init(m);

    CCDirector_init(m);

    utilities::log("Binded cocos2d", "DEBUG");
}