#pragma once
#include <stdio.h>
#include <iostream>
#include "core/macros.h"
#undef ERROR

namespace cinnamon {
    namespace logger {
        enum class LoggingLevel {
            DEBUG,
            INFO,
            WARNING,
            ERROR,
            CRITICAL
        };

        CINNAMON_API extern LoggingLevel loggingLevel;

        CINNAMON_API LoggingLevel getLoggingLevelFromString(std::string level);

        CINNAMON_API void setLoggingLevel(LoggingLevel level);

        CINNAMON_API void setLoggingLevel(std::string level);
        
        // logging TODO: announce what mod sent the log
        // maybe get rid of c style casting

        CINNAMON_API void log(std::string message, LoggingLevel levelInt);

        CINNAMON_API void log(std::string message, std::string level);
    }
}