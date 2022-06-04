#pragma once
#include "pybind11.h"
#include <string>
#undef ERROR

enum class LoggingLevel {
    DEBUG = 10,
    INFO = 20,
    WARNING = 30,
    ERROR = 40,
    CRITICAL = 50
};

namespace globals {
    loggingLevel = LoggingLevel::INFO;

    std::multimap<std::string, py::function> pyHookmap = std::multimap<std::string, py::function>();
    std::multimap<std::string, PVOID> hookmap = std::multimap<std::string, PVOID>();
	std::map<std::string, py::object> modules = std::map<std::string, py::object>();
}