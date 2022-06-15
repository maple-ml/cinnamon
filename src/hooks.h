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
	bool m_enabled;

	PythonHook() {
		m_enabled = false;
	}

	PythonHook(std::string functionname, size_t address, py::function detour) {
		m_functionname = functionname;
		m_address = address;
		m_detour = detour;
		m_enabled = false;
		
		globals::pyHookmap.insert(std::pair<std::string, py::function>(functionname, detour));
	}

	void enable() {
		MH_EnableHook((PVOID)m_address);
		m_enabled = true;
	}

	void disable() {
		MH_DisableHook((PVOID)m_address);
		m_enabled = false;
	}
};

PythonHook hookPython(std::string functionname, size_t address, py::function detour) {
	PythonHook hook = PythonHook(functionname, address, detour);
	hook.enable();
	return hook;
}

PythonHook hookPython(py::function toHook, py::function detour) {
	std::pair<std::string, size_t> ret = toHook(detour).cast<std::pair<std::string, size_t>>();

	std::string functionname = ret.first;
	size_t address = ret.second;

	PythonHook hook = PythonHook(functionname, address, detour);
	hook.enable();
	return hook;
}

}