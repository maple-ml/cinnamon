#pragma once

#include "hooks.h"
#include "globals.h"
#include "utilities.h"
#include "macros.h"

class PlayerObject : public CCNode {
public:
	void pushButton(void* PlayerButton) { CINNAMON_FUNC(__thiscall, void, 0x1F4E40, CINNAMON_ARGS(PlayerObject*, void*), CINNAMON_ARGS(this, PlayerButton)) }
	CINNAMON_HOOK_OVERLOAD(pushButton, "PlayerObject::pushButtonH", 0x1F4E40);
	CINNAMON_HOOK_VOID(pushButtonH, pushButtonOO, CINNAMON_ARGS(self, PlayerButton), CINNAMON_ARGS(PlayerObject* self, int edx, void* PlayerButton));
	CINNAMON_ORIGINAL(pushButtonO_, void, CINNAMON_ARGS(PlayerObject*, void*));
	CINNAMON_ORIGINAL_HOOK_VOID("PlayerObject::pushButtonH", pushButtonO, pushButtonC, pushButtonO_, CINNAMON_ARGS(self, PlayerButton), CINNAMON_ARGS(PlayerObject* self, void* PlayerButton));
	CINNAMON_ADDRESS(pushButtonA, 0x1F4E40);
	CINNAMON_NAME(pushButtonN, "PlayerObject::pushButtonH");
};

void PlayerObject_init(py::module &m) {
	auto c = py::class_<PlayerObject>(m, "PlayerObject");
		c.def("pushButton", py::overload_cast<void*>(&PlayerObject::pushButton));
		c.def("pushButton", py::overload_cast<py::function>(&PlayerObject::pushButton));
		c.def("pushButtonO", [](PlayerObject* self, void* PlayerButton) { return PlayerObject::pushButtonO(self, PlayerButton); });
		c.attr("pushButtonA") = PlayerObject::pushButtonA;
		c.attr("pushButtonN") = PlayerObject::pushButtonN;
		utilities::hookCinnamon((PVOID)PlayerObject::pushButtonA, PlayerObject::pushButtonH, (LPVOID*)&PlayerObject::pushButtonO_);
}