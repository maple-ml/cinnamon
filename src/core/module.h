#pragma once
#include "pybind11.h"
#include "pybind11/embed.h"
#include <cocos2d.h>
#include "MinHook.h"
#include "core/hooks.h"
#include "core/macros.h"
#include "core/python.h"

namespace pybind = pybind11;

namespace cinnamon {
    namespace module {
        CINNAMON_API extern std::map<std::string, pybind::object> modules;
        CINNAMON_API extern bool startupErrorOccurred;

        // turn into metaclass
        CINNAMON_API void register_python_mod(pybind::object mod);

        class CINNAMON_API PythonMod {
        public:
            bool m_enabled;
            std::string m_name;
            std::string m_version;
            std::string m_author;
            std::string m_description;

            bool isEnabled() {
                return m_enabled;
            }

            void enable() {
                m_enabled = true;
                on_enable();
            }

            void disable() {
                m_enabled = false;
                on_disable();
            }

            std::string getName() {
                return m_name;
            }

            std::string getVersion() {
                return m_version;
            }

            std::string getAuthor() {
                return m_author;
            }

            std::string getDescription() {
                return m_description;
            }

            // events and stuff

            PythonMod() {

            }

            void loop() {
                pybind::exec("while True: pass"); // keep interpreter alive
            }

            static void _init(pybind::object mod_cls) { // PRIVATE TO PY, called on thread, runs __init__ and starts loop
                pybind::object mod;
                try {
                    mod = mod_cls();
                }
                catch (const pybind::error_already_set& e) {
                    // TODO: use logger
                    cinnamon::module::startupErrorOccurred = true;
                    pybind::print("Exception has occured while initializing mod class: " + mod_cls.attr("__name__").cast<std::string>());
                    pybind::print(e.what());
                    return;
                }
                cinnamon::module::modules.insert<std::pair<std::string, pybind::object>>(std::pair<std::string, pybind::object>(mod.attr("name").cast<std::string>(), mod));

                cinnamon::logger::log("Starting loop", "DEBUG");
                mod.attr("loop")();
            }

            void on_enable() {

            }

            void on_disable() {
                
            }
        };

        // c++ mod
        class CINNAMON_API Mod {
        private:
            std::string m_name;
            std::string m_version;
            std::string m_author;
            std::string m_description;
            bool m_enabled;
        
        public:
            std::string getName() {
                return m_name;
            }

            std::string getVersion() {
                return m_version;
            }

            std::string getAuthor() {
                return m_author;
            }

            std::string getDescription() {
                return m_description;
            }

            bool isEnabled() {
                return m_enabled;
            }

            void enable() {
                m_enabled = true;
                on_enable();
            }

            void disable() {
                m_enabled = false;
                on_disable();
            }

            // events and stuff

            Mod() {

            }

            void on_enable() {

            }

            void on_disable() {
                
            }
        };
    }
}

extern "C" PyObject* _pybind11_init_impl_cinnamon();