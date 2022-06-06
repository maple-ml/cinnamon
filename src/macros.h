#pragma once

#define USING_NS_CINNAMON using namespace cinnamon;

#define CINNAMON_NS_BEGIN namespace {
#define CINNAMON_NS_END }

#define CINNAMON_ARGS(...) __VA_ARGS__

// bindings

#define CINNAMON_BIND_GET(cls, name) c.def("get" #name, &cls ## ::get ## name);
#define CINNAMON_BIND_SET(cls, name) c.def("set" #name, &cls ## ::set ## name);

#define CINNAMON_BIND_SET_CAST(cls, name, types) c.def("set" #name, py::overload_cast<types>(&cls ## ::set ## name));


#define CINNAMON_BIND_GETSET(cls, name) CINNAMON_BIND_GET(cls, name); CINNAMON_BIND_SET(cls, name);

#define CINNAMON_BIND_GETSET_CAST(cls, name, types) CINNAMON_BIND_GET(cls, name); CINNAMON_BIND_SET_CAST(cls, name, types);

// codegen

#define CINNAMON_NAME(name, value) static inline const char* name = value;

#define CINNAMON_ADDRESS(name, addr) static inline size_t name = utilities::getBase() + addr;

#define CINNAMON_ORIGINAL(name, ret, args) static inline ret(__thiscall* name)(args);

#define CINNAMON_FUNC(call, ret, addr, types, args) return reinterpret_cast<ret(call*)(types)>(utilities::getBase() + addr)(args);
#define CINNAMON_FUNC_STACK_FIX(stack, call, ret, addr, types, args) ret pRet = reinterpret_cast<ret(call*)(types)>(utilities::getBase() + addr)(args); __asm add esp, stack; return pRet;

#define CINNAMON_HOOK(name, original, ret, args, types) static ret __fastcall name(types) { \
    std::multimap<std::string, py::function>::iterator itr; \
    for (itr = globals::pyHookmap.begin(); itr != globals::pyHookmap.end(); ++itr) { \
        if (itr->first == __FUNCTION__) { \
            py::gil_scoped_acquire acquire; \
            ret pRet = itr->second(args).cast<ret>(); \
            py::gil_scoped_release release; \
            return pRet; \
        } \
    } \
    return original(args); \
}

#define CINNAMON_HOOK_VOID(name, original, args, types) static void __fastcall name(types) { \
    std::multimap<std::string, py::function>::iterator itr; \
    for (itr = globals::pyHookmap.begin(); itr != globals::pyHookmap.end(); ++itr) { \
        if (itr->first == __FUNCTION__) { \
            py::gil_scoped_acquire acquire; \
            itr->second(args); \
            py::gil_scoped_release release; \
            return; \
        } \
    } \
}

// this is used when we want to hook this in cinnmaon as well, (instead of just hooking python functions, i want to hook a function for cinnamon as well)
// ex. hooking menulayer in cinnamon to create mod list but also allowing python to do it
// i couldn't come up with a better name other than "plus", June 2, 2022 14:22:11
#define CINNAMON_HOOK_PLUS(name, original, ret, hook, args, types) static ret __fastcall name(types) { \
    std::multimap<std::string, py::function>::iterator itr; \
    for (itr = globals::pyHookmap.begin(); itr != globals::pyHookmap.end(); ++itr) { \
        if (itr->first == __FUNCTION__) { \
            py::gil_scoped_acquire acquire; \
            itr->second(args); \
            py::gil_scoped_release release; \
            break; \
        } \
    } \
    ret pRet = hook(args); \
    return pRet; \
}

#define CINNAMON_HOOK_PLUS_VOID(name, original, hook, args, types) static void __fastcall name(types) { \
    std::multimap<std::string, py::function>::iterator itr; \
    for (itr = globals::pyHookmap.begin(); itr != globals::pyHookmap.end(); ++itr) { \
        if (itr->first == __FUNCTION__) { \
            py::gil_scoped_acquire acquire; \
            itr->second(args); \
            py::gil_scoped_release release; \
            break; \
        } \
    } \
    hook(args); \
}

#define CINNAMON_ORIGINAL_HOOK(hookname, name, name2, original, ret, args, types) static inline int name2 = 1; \
static ret __fastcall name(types) { \
    std::multimap<std::string, py::function>::iterator itr; \
    int itr2 = 0; \
    for (itr = globals::pyHookmap.begin(); itr != globals::pyHookmap.end(); ++itr) { \
        if (globals::pyHookmap.count(hookname) == name2) { \
            ret pRet = original(args); \
            name2 = 1; \
            return pRet; \
        } \
        if (itr->first == hookname) { \
            if (itr2 == name2) { \
                name2++; \
                py::gil_scoped_acquire acquire; \
                itr->second(args); \
                py::gil_scoped_release release; \
            } \
            itr2++; \
        } \
    } \
    if (globals::pyHookmap.count(hookname) == name2) { \
        ret pRet = original(args); \
        name2 = 1; \
        return pRet; \
    } \
    return original(args); \
}

#define CINNAMON_ORIGINAL_HOOK_VOID(hookname, name, name2, original, args, types) static inline int name2 = 1; \
static void __fastcall name(types) { \
    std::multimap<std::string, py::function>::iterator itr; \
    int itr2 = 0; \
    for (itr = globals::pyHookmap.begin(); itr != globals::pyHookmap.end(); ++itr) { \
        if (globals::pyHookmap.count(hookname) == name2) { \
            original(args); \
            name2 = 1; \
            return; \
        } \
        if (itr->first == hookname) { \
            if (itr2 == name2) { \
                name2++; \
                py::gil_scoped_acquire acquire; \
                itr->second(args); \
                py::gil_scoped_release release; \
            } \
            itr2++; \
        } \
    } \
    if (globals::pyHookmap.count(hookname) == name2) { \
        original(args); \
        name2 = 1; \
        return; \
    } \
}