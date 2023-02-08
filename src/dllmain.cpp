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

#include "core/utilities/path.h"
#include "core/python.h"
#include "core/logger.h"
#include "core/module.h"

// bindings (autogen)
#include "bindings/geometrydash_bindings.h"
#include "bindings/cocos2d_bindings.h"

namespace pybind = pybind11;
USING_NS_CC;

DWORD WINAPI dll_thread(void* hModule) {
    AllocConsole();
    FILE* fDummy;
    freopen_s(&fDummy, "CONIN$", "r", stdin);
    freopen_s(&fDummy, "CONOUT$", "w", stderr);
    freopen_s(&fDummy, "CONOUT$", "w", stdout);
    cinnamon::logger::setLoggingLevel(cinnamon::logger::LoggingLevel::DEBUG);

    cinnamon::hooks::init();

    pybind::scoped_interpreter python;

    std::string mod_path = cinnamon::utilities::getModsPath();
    pybind::module_::import("sys").attr("path").attr("append")(mod_path);

    pybind::gil_scoped_acquire acquire;

    for (const auto& dirEntry : std::filesystem::directory_iterator(mod_path.c_str())) {
        std::string file = dirEntry.path().string();

        if (dirEntry.is_directory()) {
            cinnamon::logger::log("Found directory: " + file, "INFO");
            for (const auto& modDirEntry : std::filesystem::directory_iterator(dirEntry.path().string().c_str())) {
                std::string dirFile = modDirEntry.path().string();
                if (modDirEntry.path().filename() == "main.py"
                    | modDirEntry.path().filename() == "__main__.py"
                    | modDirEntry.path().filename().string() == modDirEntry.path().parent_path().filename().string() + ".py") {
                    cinnamon::logger::log("Found Python file: " + dirFile, "INFO");

                    if (cinnamon::python::runPythonFile(dirFile)) {
                        cinnamon::logger::log("Python file started: " + dirFile, "INFO");
                    }
                }
            }
        }

        else if (cinnamon::utilities::hasEnding(file, ".py")) {
            cinnamon::logger::log("Found Python file: " + file, "INFO");

            if (cinnamon::python::runPythonFile(file)) {
                cinnamon::logger::log("Python file started: " + file, "INFO");
            }
        }
    }

    cinnamon::logger::log("All modules loaded!", "INFO");

    // call on_all_modules_loaded
    for (auto const& [key, val] : cinnamon::module::modules) {
        if (val.attr("on_modules_loaded")) {
            val.attr("on_modules_loaded")();
        }
    }

    pybind::gil_scoped_release release;
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

