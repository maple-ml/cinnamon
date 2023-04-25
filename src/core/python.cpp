#include "pybind11.h"
#include "pybind11/embed.h"
#include <cocos2d.h>
#include "MinHook.h"
#include "core/module.h"
#include "core/python.h"

namespace cinnamon {
    namespace python {
        using namespace pybind11::literals;

        bool runPythonFile(std::string file) {
            try {
                pybind::object mod = pybind::eval_file(file); // non cocos thread
            }
            catch (pybind::error_already_set& e) {
                cinnamon::module::startupErrorOccurred = true;
                pybind::print("Exception has occured while running python file: " + file);
                pybind::print(e.what());
                return false;
            }
            return true;
        }

        void runPyOnMain(pybind::function func) {
            auto node = cinnamon::python::CallPyOnMainNode::create(func);
            CCDirector::sharedDirector()->getRunningScene()->runAction(
                CCSequence::create(
                    CCDelayTime::create(0),
                    CCCallFunc::create(node, callfunc_selector(cinnamon::python::CallPyOnMainNode::onInvoke)),
                    nullptr
                )
            );
        }

        void printPythonException(pybind::error_already_set& e) {
            pybind::gil_scoped_acquire acquire;
            pybind::object traceback = pybind::module_::import("traceback");
            pybind::object format_exception = traceback.attr("format_exception");
            pybind::object formatted = format_exception(e.type(), e.value(), e.trace());
            pybind::object formatted_str = pybind::str("").attr("join")(formatted);
            pybind::print(std::string(pybind::str(formatted_str)), "end"_a="");
            pybind::gil_scoped_release release;
        }
    }
}