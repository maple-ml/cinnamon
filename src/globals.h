#pragma once
#include "pybind11.h"
#include <string>

namespace globals {
    std::map<std::string, py::function> hookmap = std::map<std::string, py::function>();
	std::map<std::string, py::object> modules = std::map<std::string, py::object>();
}