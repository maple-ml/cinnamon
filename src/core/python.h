#pragma once
#include "pybind11.h"
#include "pybind11/embed.h"
#include <cocos2d.h>
#include "core/utilities/game.h"
#include "MinHook.h"

namespace pybind = pybind11;

namespace cinnamon {
    namespace python {
        bool runPythonFile(std::string file) {
            try {
                pybind::object mod = pybind::eval_file(file); // non cocos thread
            }
            catch (pybind::error_already_set& e) {
                utilities::startup_error_occurred = true;
                pybind::print("Exception has occured while running python file: " + file);
                pybind::print(e.what());
                return false;
            }
            return true;
        }
    }
}