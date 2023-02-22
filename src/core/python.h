#pragma once
#include "pybind11.h"
#include "pybind11/embed.h"
#include <cocos2d.h>
#include "core/utilities/game.h"
#include "MinHook.h"

namespace pybind = pybind11;
using namespace cocos2d;

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

        class CallPyOnMainNode : public CCNode {
        protected:
            pybind::object m_function;

        public:
            static CallPyOnMainNode* create(pybind::object func) {
                auto ret = new CallPyOnMainNode;
                if (ret) {
                    ret->m_function = func;
                    ret->autorelease();
                    return ret;
                }
                CC_SAFE_DELETE(ret);
                return nullptr;
            }

            void onInvoke() {
                pybind::scoped_interpreter guard{};

                PyObject_CallNoArgs(m_function.ptr());
            }
        };

        class CallOnMainNode : public CCNode {
        protected:
            std::function<void()> m_function;

        public:
            static CallOnMainNode* create(std::function<void()> func) {
                auto ret = new CallOnMainNode;
                if (ret) {
                    ret->m_function = func;
                    ret->autorelease();
                    return ret;
                }
                CC_SAFE_DELETE(ret);
                return nullptr;
            }

            void onInvoke() {
                m_function();
            }
        };

        void runPyOnMain(pybind::function func) {
            auto node = CallPyOnMainNode::create(func);
            CCDirector::sharedDirector()->getRunningScene()->runAction(
                CCSequence::create(
                    CCDelayTime::create(0),
                    CCCallFunc::create(node, callfunc_selector(CallPyOnMainNode::onInvoke)),
                    nullptr
                )
            );
        }
    }
}