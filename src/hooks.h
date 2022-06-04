#pragma once

#include "macros.h"
#include "utilities.h"
#include "MinHook.h"
#include "globals.h"
#include <pybind11/functional.h>
#include <map>
#include <string>

#include "geometrydash.h"

namespace hooks {
	class PythonHook {
	private:
		std::string m_functionname;
		size_t m_address;
		py::function m_detour;
	public:
		PythonHook(std::string functionname, size_t address, py::function detour) {
			m_functionname = functionname;
			m_address = address;
			m_detour = detour;
			
			globals::pyHookmap.insert(std::pair<std::string, py::function>(functionname, detour));
		}

		void enable() {
			MH_EnableHook((PVOID)m_address);
		}
	};

	void hookPython(std::string functionname, size_t address, py::function detour) {
		PythonHook hook = PythonHook(functionname, address, detour);
		hook.enable();
	}
}