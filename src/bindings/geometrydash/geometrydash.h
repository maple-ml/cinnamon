#pragma once

#include "macros.h"
#include "utilities.h"
#include "hooks.h"

// layers_scenes_transitions_nodes
#include "layers_scenes_transitions_nodes/FLAlertLayer.h"
#include "layers_scenes_transitions_nodes/MenuLayer.h"

// menu_nodes
#include "menu_nodes/CCMenuItemSpriteExtra.h" // no bindings yet

// scroll_nodes
#include "scroll_nodes/BoomListView.h" // no bindings yet
#include "scroll_nodes/CCContentLayer.h" // no bindings yet
#include "scroll_nodes/CCIndexPath.h" // no bindings yet
#include "scroll_nodes/CCScrollLayerExt.h" // no bindings yet
#include "scroll_nodes/CustomListView.h" // no bindings yet
#include "scroll_nodes/TableView.h" // no bindings yet

// sprite_nodes
#include "sprite_nodes/PlayerObject.h"

PYBIND11_EMBEDDED_MODULE(geometrydash, m) {

    FLAlertLayer_init(m);
    MenuLayer_init(m);

    PlayerObject_init(m);
}