#pragma once
#include <iostream>
#include <stdio.h>

namespace cinnamon {
    namespace utilities {
        uintptr_t base = reinterpret_cast<uintptr_t>(GetModuleHandle(0));

        bool startup_error_occurred = false;
    }
}