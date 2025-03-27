#include "NPC.h"


NPC::NPC(string Name) : Character(Name) {
	diologueIndex = 0;
	diologue = {};
}

void NPC::addDiologue(string nDiologue) {
	diologue.push_back(nDiologue);
}
