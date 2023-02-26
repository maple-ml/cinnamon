#pragma once
#include <iostream>
#include <stdio.h>
#include "core/macros.h"

namespace cinnamon {
    namespace utilities {
        CINNAMON_API bool hasEnding(std::string const& fullString, std::string const& ending);

        CINNAMON_API std::string getGDPath();

        CINNAMON_API std::string getCinnamonPath();

        CINNAMON_API std::string getModsPath();
    }
}