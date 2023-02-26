#pragma once
#include "pybind11.h"
#include "pybind11/embed.h"
#include <cocos2d.h>
#include "MinHook.h"
#include "core/macros.h"

namespace pybind = pybind11;
using namespace cocos2d;

namespace cinnamon {
    namespace python {
        CINNAMON_API bool runPythonFile(std::string file);

        class CINNAMON_API CallPyOnMainNode : public CCNode {
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

        class CINNAMON_API CallOnMainNode : public CCNode {
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

        void CINNAMON_API runPyOnMain(pybind::function func);
    }
}
