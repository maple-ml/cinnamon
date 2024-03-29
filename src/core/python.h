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
            pybind::function m_function;

        public:
            static CallPyOnMainNode* create(pybind::function func) {
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
                pybind::gil_scoped_acquire acquire;

                m_function();

                pybind::gil_scoped_release release;
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
        void CINNAMON_API printPythonException(pybind::error_already_set& e);
        CINNAMON_API std::string getPythonFileFromObject(pybind::object obj);
    }
}
