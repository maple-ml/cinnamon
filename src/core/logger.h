#pragma once
#include <stdio.h>
#include <iostream>
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

        LoggingLevel loggingLevel = LoggingLevel::INFO;

        LoggingLevel getLoggingLevelFromString(std::string level) {
            if (level == "DEBUG")
                return LoggingLevel::DEBUG;
            else if (level == "INFO")
                return LoggingLevel::INFO;
            else if (level == "WARNING")
                return LoggingLevel::WARNING;
            else if (level == "ERROR")
                return LoggingLevel::ERROR;
            else if (level == "CRITICAL")
                return LoggingLevel::CRITICAL;
            
            return LoggingLevel::INFO;
        }

        void setLoggingLevel(LoggingLevel level) {
            loggingLevel = level;
        }

        void setLoggingLevel(std::string level) {
            loggingLevel = getLoggingLevelFromString(level);
        }
        
        // logging TODO: announce what mod sent the log
        // maybe get rid of c style casting

        void log(std::string message, LoggingLevel levelInt) {
            std::string stringmap[] = {
                "DEBUG",
                "INFO", 
                "WARNING",
                "ERROR",
                "CRITICAL"
            };

            std::string level = stringmap[(int)levelInt];

            std::cout << "CINNAMON: " << level << " >> " << message << std::endl;
        }

        void log(std::string message, std::string level="INFO") {
            LoggingLevel logLevel = getLoggingLevelFromString(level);

            if ((int)logLevel >= (int)loggingLevel)
                std::cout << "CINNAMON: " << level << " >> " << message << std::endl;
        }
    }
}