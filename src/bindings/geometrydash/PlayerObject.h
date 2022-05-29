#pragma once

#include "hooks.h"
#include "globals.h"
#include "utilities.h"

class PlayerObject : public CCNode {
public:
	void pushButton(PlayerObject* self, void* PlayerButton) {
		return reinterpret_cast<void(__thiscall*)(PlayerObject*, void*)>(utilities::getBase() + 0x1F4E40)(self, PlayerButton);
	}
	static inline void(__thiscall* pushButtonO)(PlayerObject* self, void* PlayerButton);
	static inline size_t pushButtonA = 0x1F4E40;
	static void __fastcall pushButtonH(PlayerObject* self, int edx, void* PlayerButton) {
		std::cout << "func" << std::endl;
		if (globals::hookmap.find(__FUNCTION__) != globals::hookmap.end()) {
			std::cout << "calling python function " << __FUNCTION__ << std::endl;

			py::scoped_interpreter guard{};

			try {
				py::print(py::globals());
				//py::exec(py::module_::import("inspect").attr("getsource")(hookmap[__FUNCTION__]));
				//py::exec(hookmap[__FUNCTION__].attr("__name__").str() + py::str("('a', 'b')"));

				globals::hookmap[__FUNCTION__]("self", "PlayerButton");
				//utilities::runOnMain([=]() { hookmap[__FUNCTION__](self, PlayerButton); });
			}
			catch (py::error_already_set &e) {
				py::print(e.what());
			}

		}
		
		pushButtonO(self, PlayerButton);
	}	
};

void PlayerObject_init(py::module &m) {
	py::class_<PlayerObject>(m, "PlayerObject")
		.def("pushButton", &PlayerObject::pushButton)
		//.def("pushButtonH", &PlayerObject::pushButtonH)
		//.def("pushButtonO", &PlayerObject::pushButtonO)
		.attr("pushButtonA") = PlayerObject::pushButtonA;
}