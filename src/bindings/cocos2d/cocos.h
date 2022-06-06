#pragma once

#include "macros.h"
#include "utilities.h"
#include "hooks.h"

// CC is omitted because cocos will wrongfully find our version of it

// base nodes
#include "base_nodes/Node.h"

// cocoa
#include "cocoa/Object.h"
#include "cocoa/Copying.h"

// layers_scenes_transitions_nodes
#include "layers_scenes_transitions_nodes/Scene.h"
#include "layers_scenes_transitions_nodes/Layer.h"

// sprite_nodes
#include "sprite_nodes/Sprite.h"

PYBIND11_EMBEDDED_MODULE(cocos2d, m) { // the suffering begins
    CCCopying_init(m);
    CCObject_init(m);

    CCNode_init(m);

    CCScene_init(m);
    CCLayer_init(m);

    CCSprite_init(m);
}