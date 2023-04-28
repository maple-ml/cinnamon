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
#include "bindings/geometry_dash_bindings.h"
#include "bindings/cocos2d_bindings.h"
#include "bindings/manual_bindings.h"

// hooks
#include "core/hooks/ModdedMenuLayer.h"

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

    cinnamon::logger::log("Generating stubgen", "INFO");

    try {
        pybind::exec(
            "from distutils.sysconfig import get_python_lib\n"
            "import pybind11_stubgen\n"
            "import logging\n"

            "logging.getLogger(\"pybind11_stubgen\").disabled = True\n"
            "pybind11_stubgen.main([\"cinnamon\", \"--ignore-invalid=all\", \"--output-dir\", get_python_lib(), \"--root-module-suffix\", \"\"])\n" 
            "pybind11_stubgen.main([\"cocos2d\", \"--ignore-invalid=all\", \"--output-dir\", get_python_lib(), \"--root-module-suffix\", \"\"])\n"
            "pybind11_stubgen.main([\"geometry_dash\", \"--ignore-invalid=all\", \"--output-dir\", get_python_lib(), \"--root-module-suffix\", \"\"])\n"
        );
    }
    catch (pybind::error_already_set& e) {
        cinnamon::logger::log("Failed to run stubgen: " + std::string(e.what()), "ERROR");
    }

    cinnamon::logger::log("Stubgen generation complete", "DEBUG");

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

    // call on_modules_loaded
    for (auto const& [key, val] : cinnamon::module::modules) {
        if (pybind::hasattr(val, "on_modules_loaded")) {
            val.attr("on_modules_loaded")();
        }
    }

    pybind::gil_scoped_release release;


    // enable hooks
    ModdedMenuLayer::enable();

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
