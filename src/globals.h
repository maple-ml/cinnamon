#pragma once
#include "pybind11.h"
#include <string>

namespace globals {
    std::multimap<std::string, py::function> pyhookmap = std::multimap<std::string, py::function>();
    std::multimap<std::string, PVOID> hookmap = std::multimap<std::string, PVOID>();
	std::map<std::string, py::object> modules = std::map<std::string, py::object>();
}