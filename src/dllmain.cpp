#define WIN32_LEAN_AND_MEAN
#undef ERROR
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <filesystem>
#include <thread>

#include <cocos2d.h>
#include <pybind11.h>
#include <pybind11/embed.h>

namespace py = pybind11;
USING_NS_CC;

#include "macros.h"
#include "utilities.h"
#include "mod_menu.h"

// bindings
#include "bindings/cinnamon.h"
#include "bindings/geometrydash/geometrydash.h"

DWORD WINAPI dll_thread(void* hModule) {
    utilities::initialize();
    utilities::enableDebugMode();

    py::scoped_interpreter python;

    std::string mod_path = utilities::getGDPath();
    mod_path.append("cinnamon\\mods\\");
    py::module_::import("sys").attr("path").attr("append")(mod_path);

    utilities::log("Cinnamon Initialized!", "INFO");

    ModMenu::enable_hooks();
    
    utilities::log("ModMenu hooks enabled", "DEBUG");

    py::gil_scoped_acquire acquire;

    for (const auto& dirEntry : std::filesystem::directory_iterator(mod_path.c_str())) {
        if (utilities::hasEnding(dirEntry.path().string(), ".py") && !dirEntry.is_directory()) {
            std::string file = dirEntry.path().string().c_str();

            utilities::log("Running Python file: " + file, "INFO");

            py::object mod = py::eval_file(file); // non cocos thread

            utilities::log("Python file started: " + file, "INFO");
        }
    }

    py::gil_scoped_release release;

    utilities::log("Main thread exiting...", "DEBUG");
    return 0;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0x1000, dll_thread, hModule, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

