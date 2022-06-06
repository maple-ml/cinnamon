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

PYBIND11_EMBEDDED_MODULE(cocos2d, m) { // the suffering begins
    // base nodes
    CCNode_init(m);
    // cocoa
    CCObject_init(m);
    CCCopying_init(m);
    // layers_scenes_transitions_nodes
    CCScene_init(m);
    CCLayer_init(m);
}