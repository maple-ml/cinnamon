#pragma once

#include "macros.h"
#include "utilities.h"
#include "MinHook.h"
#include "globals.h"
#include <pybind11/functional.h>
#include <map>
#include <string>

#include "bindings/geometrydash/geometrydash.h"
#include "bindings/cinnamon.h"

namespace hooks {
	class PythonHook {
	private:
		std::string m_functionname;
		size_t m_address;
		py::function m_detour;
	public:
		PythonHook(std::string functionname, size_t address, py::function detour) {
			functionname = functionname + "H";

			m_functionname = functionname;
			m_address = address;
			m_detour = detour;
			
			globals::hookmap.insert(std::pair<std::string, py::function>(functionname, detour));

			std::cout << "hooking " << PlayerObject::pushButtonA << std::endl;

			MH_STATUS status = MH_CreateHook((PVOID)address, PlayerObject::pushButtonH, (LPVOID*)&PlayerObject::pushButtonO);

			std::cout << "status: " << status << ": " << MH_StatusToString(status) << std::endl;

			MH_EnableHook((PVOID)address);
		}
	};

	void hookAddressPython(std::string functionname, size_t address, py::function detour) {
		PythonHook hook = PythonHook(functionname, address, detour);
	}
}