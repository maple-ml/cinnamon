#pragma once
#include <iostream>
#include <stdio.h>
#include <windows.h>

namespace cinnamon {
    namespace utilities {
        uintptr_t base = reinterpret_cast<uintptr_t>(GetModuleHandle(0));
    }
}