#pragma once

#include "macros.h"
#include "utilities.h"
#include "hooks.h"


#include "./PlayerObject.h"
#include "./FLAlertLayer.h"

PYBIND11_EMBEDDED_MODULE(geometrydash, m) {
    PlayerObject_init(m);
}