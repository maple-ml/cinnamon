#include "pybind11.h"
#include "pybind11/embed.h"
#include "pybind11/functional.h"
#include <cocos2d.h>
#include "core/module.h"
#include "core/hooks.h"
#include <functional>
#include <filesystem>

namespace cinnamon {
    namespace module {
        std::map<std::string, pybind::object> modules = std::map<std::string, pybind::object>();
        std::map<std::string, PythonMod*> modInstances = std::map<std::string, PythonMod*>();
        bool startupErrorOccurred = false;

        void register_python_mod(pybind::object mod) {
            using namespace pybind11::literals;
            pybind::module_ threading = pybind::module_::import("threading");
            
            threading.attr("Thread")("target"_a=mod.attr("_init"), "args"_a=pybind::make_tuple(mod)).attr("start")();
        }

        void PythonMod::start_file_watcher() {
            // seperate thread to watch
            std::thread([this]() {
                while (true) {
                    DWORD dwWaitResult = WaitForSingleObject(m_fileChangeHandle, INFINITE);

                    if (dwWaitResult == WAIT_OBJECT_0) {
                        std::stringstream streamstream;
                        streamstream << "File \"" << m_modPath << "\" changed, reloading";

                        std::string str = streamstream.str();

                        cinnamon::logger::log(str, "INFO");

                        pybind::gil_scoped_acquire acquire;

                        try {
                            // remove old hook handlers by itering over hooks::pythonHooks
                            std::multimap<std::string, pybind::function>::iterator pyitr;
                            for (pyitr = cinnamon::hooks::pythonHooks.begin(); pyitr != cinnamon::hooks::pythonHooks.end(); pyitr++) {
                                cinnamon::logger::log("Removing hook handler: " + pyitr->second.attr("__name__").cast<std::string>(), "DEBUG");
                                cinnamon::hooks::pythonHooks.erase(pyitr);
                            }

                            // run updated file

                            for (const auto& modDirEntry : std::filesystem::directory_iterator(m_modPath)) {
                                std::string dirFile = modDirEntry.path().string();
                                if (modDirEntry.path().filename() == "main.py"
                                    | modDirEntry.path().filename() == "__main__.py"
                                    | modDirEntry.path().filename().string() == modDirEntry.path().parent_path().filename().string() + ".py") {

                                    cinnamon::python::runPythonFile(dirFile);
                                }
                            }
                        }
                        catch (pybind::error_already_set& e) {
                            cinnamon::logger::log("Failed to reload module: " + std::string(e.what()), "ERROR");
                        }

                        pybind::gil_scoped_release release;

                        cinnamon::logger::log("Reloaded module " + m_name, "INFO");

                        break;
                    } else {
                        cinnamon::logger::log("Failed while watching file for changes", "ERROR");
                        break;
                    }
                    Sleep(2000);
                }
            }).detach();
        }
    }
}

PYBIND11_EMBEDDED_MODULE(cinnamon, m) {
    cinnamon::logger::log("Binding cinnamon", "DEBUG");

    auto mod = pybind::class_<cinnamon::module::PythonMod>(m, "Mod", pybind::dynamic_attr());
        mod.def(pybind::init<>());
        mod.def("_init", &cinnamon::module::PythonMod::_init);
        mod.def("loop", &cinnamon::module::PythonMod::loop);
        mod.def_readwrite("name", &cinnamon::module::PythonMod::m_name);
        mod.def_readwrite("version", &cinnamon::module::PythonMod::m_version);
        mod.def_readwrite("author", &cinnamon::module::PythonMod::m_author);
        mod.def_readwrite("description", &cinnamon::module::PythonMod::m_description);
        mod.def_readwrite("enabled", &cinnamon::module::PythonMod::m_enabled);
        mod.def_readwrite("mod_path", &cinnamon::module::PythonMod::m_modPath);
        mod.def_readwrite("hooks", &cinnamon::module::PythonMod::m_hooks);
        mod.def("enable", &cinnamon::module::PythonMod::enable);
        mod.def("disable", &cinnamon::module::PythonMod::disable);
        mod.def("is_enabled", &cinnamon::module::PythonMod::isEnabled);
        mod.def("on_enable", &cinnamon::module::PythonMod::on_enable);
        mod.def("on_disable", &cinnamon::module::PythonMod::on_disable);

    
    auto pyhook = pybind::class_<cinnamon::hooks::PythonHook>(m, "Hook");
        pyhook.def(pybind::init<>());
        pyhook.def(pybind::init<std::string, size_t, pybind::function>());
        pyhook.def(pybind::init<pybind::function, pybind::function>());
        pyhook.def_readwrite("functionname", &cinnamon::hooks::PythonHook::m_functionname);
        pyhook.def_readwrite("address", &cinnamon::hooks::PythonHook::m_address);
        pyhook.def_readwrite("detour", &cinnamon::hooks::PythonHook::m_detour);
        pyhook.def_readwrite("enabled", &cinnamon::hooks::PythonHook::m_enabled);
        pyhook.def("enable", &cinnamon::hooks::PythonHook::enable);
        pyhook.def("disable", &cinnamon::hooks::PythonHook::disable);

    // hook decorator
    m.def("hook", [](pybind::function to_hook) {
        return pybind::cpp_function([to_hook](pybind::function func) {
            cinnamon::hooks::PythonHook(to_hook, func);
            return pybind::cpp_function([func](pybind::args args, pybind::kwargs kwargs) {
                return func(*args, **kwargs);
            });
        });
    });

    // logging
    m.def("set_logging_level", pybind::overload_cast<cinnamon::logger::LoggingLevel>(&cinnamon::logger::setLoggingLevel));
    m.def("set_logging_level", pybind::overload_cast<std::string>(&cinnamon::logger::setLoggingLevel));
    pybind::enum_<cinnamon::logger::LoggingLevel>(m, "LoggingLevel")
        .value("DEBUG", cinnamon::logger::LoggingLevel::DEBUG)
        .value("INFO", cinnamon::logger::LoggingLevel::INFO)
        .value("WARNING", cinnamon::logger::LoggingLevel::WARNING)
        .value("ERROR", cinnamon::logger::LoggingLevel::ERROR)
        .value("CRITICAL", cinnamon::logger::LoggingLevel::CRITICAL)
        .export_values();
    
    m.def("register_mod", &cinnamon::module::register_python_mod);
    m.def("run", &cinnamon::python::runPyOnMain);

    cinnamon::logger::log("Binded cinnamon", "DEBUG");
}