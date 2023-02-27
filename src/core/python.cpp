#include "pybind11.h"
#include "pybind11/embed.h"
#include <cocos2d.h>
#include "MinHook.h"
#include "core/module.h"
#include "core/python.h"


namespace cinnamon {
    namespace python {
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
    }
}