#pragma once

#define USING_NS_CINNAMON using namespace cinnamon;

#define CINNAMON_NS_BEGIN namespace {;
#define CINNAMON_NS_END };

// codegen

#define CINNAMON_MODULE_DEF(mname) PYBIND11_EMBEDED_MODULE(mname, m)
#define CINNAMON_PY_DEF(name, func) m.def(name, func)
#define CINNAMON_PY_ATTR(name, att) m.attr(name) = attr
#define CINNAMON_PY_CLASS(name, class) py::class_<class>(m, name)
#define CINNAMON_PY_MEMBER(name, func) def(name, func)