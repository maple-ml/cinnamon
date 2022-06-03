#pragma once

#include "macros.h"
#include "utilities.h"
#include "hooks.h"

#include "sprite_nodes/PlayerObject.h"
#include "layers_scenes_transitions_nodes/FLAlertLayer.h"
#include "layers_scenes_transitions_nodes/MenuLayer.h"

PYBIND11_EMBEDDED_MODULE(geometrydash, m) {
    PlayerObject_init(m);
    FLAlertLayer_init(m);
    MenuLayer_init(m);
}