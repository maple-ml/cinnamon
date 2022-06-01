#pragma once

#include "hooks.h"
#include "globals.h"
#include "utilities.h"
#include "macros.h"

class PlayerObject : public CCNode {
public:
	void pushButton(PlayerObject* self, void* PlayerButton) { CINNAMON_FUNC(void, 0x1F4E40, CINNAMON_ARGS(PlayerObject*, void*), CINNAMON_ARGS(self, PlayerButton)) }
	CINNAMON_HOOK(pushButtonH, pushButtonO, CINNAMON_ARGS(self, PlayerButton), CINNAMON_ARGS(PlayerObject* self, int edx, void* PlayerButton));
	CINNAMON_ORIGINAL(pushButtonO, void, CINNAMON_ARGS(PlayerObject*, void*));
	CINNAMON_ADDRESS(pushButtonA, 0x1F4E40);
	CINNAMON_NAME(pushButtonN, "PlayerObject::pushButtonH");
};

void PlayerObject_init(py::module &m) {
	auto c = py::class_<PlayerObject>(m, "PlayerObject");
		c.def("pushButton", &PlayerObject::pushButton);
		c.def("pushButtonO", [](PlayerObject* self, void* PlayerButton) { return PlayerObject::pushButtonO(self, PlayerButton); });
		c.attr("pushButtonA") = PlayerObject::pushButtonA;
		c.attr("pushButtonN") = PlayerObject::pushButtonN;
		MH_CreateHook((PVOID)PlayerObject::pushButtonA, PlayerObject::pushButtonH, (LPVOID*)&PlayerObject::pushButtonO);
}