#pragma once
#include "pybind11.h"
#include <string>
#undef ERROR

enum class LoggingLevel {
    DEBUG = 0,
    INFO = 1,
    WARNING = 2,
    ERROR = 3,
    CRITICAL = 4
};

int loggingLevelStringToInt(std::string level) {
    if (level == "DEBUG")
        return (int)LoggingLevel::DEBUG;
    else if (level == "INFO")
        return (int)LoggingLevel::INFO;
    else if (level == "WARNING")
        return (int)LoggingLevel::WARNING;
    else if (level == "ERROR")
        return (int)LoggingLevel::ERROR;
    else if (level == "CRITICAL")
        return (int)LoggingLevel::CRITICAL;
    
    return (int)LoggingLevel::INFO;
}

namespace globals {
    bool debugMode = false;
    LoggingLevel loggingLevel = LoggingLevel::INFO;

    std::multimap<std::string, py::function> pyHookmap = std::multimap<std::string, py::function>();
    std::multimap<std::string, PVOID> hookmap = std::multimap<std::string, PVOID>();
	std::map<std::string, py::object> modules = std::map<std::string, py::object>();
}