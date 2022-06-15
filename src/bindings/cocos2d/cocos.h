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


// TODO: bind
template<class T = cocos2d::CCNode*>
static T getChild(cocos2d::CCNode* x, int i) {
    // start from end for negative index
    if (i < 0) i = x->getChildrenCount() + i;
    // check if backwards index is out of bounds
    if (i < 0) return nullptr;
    // check if forwards index is out of bounds
    if (static_cast<int>(x->getChildrenCount()) <= i) return nullptr;
    return reinterpret_cast<T>(x->getChildren()->objectAtIndex(i));
}


PYBIND11_EMBEDDED_MODULE(cocos2d, m) { // the suffering begins
    utilities::log("Binding cocos2d", "DEBUG");

    //m.def("menu_selector", [](void* selector) { (SEL_MenuHandler)(&selector); });
    m.def("ccp", [](float x, float y) { return CCPoint(x, y); } );

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