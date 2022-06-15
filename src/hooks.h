#pragma once

#include "macros.h"
#include "utilities.h"
#include "MinHook.h"
#include "globals.h"
#include <pybind11/functional.h>
#include <map>
#include <string>

namespace cinnamon {

class PythonHook {
public:
	std::string m_functionname;
	size_t m_address;
	py::function m_detour;

	PythonHook() {}

	PythonHook(std::string functionname, size_t address, py::function detour) {
		m_functionname = functionname;
		m_address = address;
		m_detour = detour;
		
		globals::pyHookmap.insert(std::pair<std::string, py::function>(functionname, detour));

		MH_EnableHook(MH_ALL_HOOKS); // fuck it
	}
};

PythonHook hookPython(std::string functionname, size_t address, py::function detour) {
	return PythonHook(functionname, address, detour);;
}

PythonHook hookPython(py::function toHook, py::function detour) {
	std::pair<std::string, size_t> ret = toHook(detour).cast<std::pair<std::string, size_t>>();

	std::string functionname = ret.first;
	size_t address = ret.second;

	return PythonHook(functionname, address, detour);;
}

}