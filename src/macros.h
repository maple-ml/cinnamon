#pragma once

#define USING_NS_CINNAMON using namespace cinnamon;

#define CINNAMON_NS_BEGIN namespace {
#define CINNAMON_NS_END }

// codegen

#define CINNAMON_ARGS(...) __VA_ARGS__

#define CINNAMON_NAME(name, value) static inline const char* name = value;

#define CINNAMON_ADDRESS(name, addr) static inline size_t name = utilities::getBase() + addr;

#define CINNAMON_ORIGINAL(name, ret, args) static inline void(__thiscall* name)(args);

#define CINNAMON_FUNC(ret, addr, types, args) return reinterpret_cast<ret(__thiscall*)(types)>(utilities::getBase() + addr)(args);

#define CINNAMON_HOOK(name, original, args, types) static void __fastcall name(types) { \
if (globals::hookmap.find(__FUNCTION__) != globals::hookmap.end()) { \
    py::gil_scoped_acquire acquire; \
    globals::hookmap[__FUNCTION__](args); \
    py::gil_scoped_release release; \
} \
}