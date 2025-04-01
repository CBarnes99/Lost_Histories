#include "NPC.h"


NPC::NPC(string Name) : Character(Name) {
	diologueIndex = -1;
	diologue = {};
}

void NPC::addDiologue(string nDiologue) {
	diologue.push_back(nDiologue);
}

string NPC::outputNextDiologue() {
	diologueIndex++;
	if (diologue.at(diologueIndex).empty()) {
		return "NO MORE DIOLOGUE OPTIONS! FIX THIS!";
	}
	else {
		return this->diologue.at(diologueIndex);
	}
}
