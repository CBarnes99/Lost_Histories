#include "NPC.h"


NPC::NPC(std::string Name) : Character(Name) {
	diologueIndex = -1;
	diologue = {};
}

void NPC::addDiologue(std::string nDiologue) {
	diologue.push_back(nDiologue);
}

std::string NPC::getNextDiologue() {
	diologueIndex++;
	if (diologue.at(diologueIndex).empty()) {
		return "NO MORE DIOLOGUE OPTIONS! FIX THIS!";
	}
	else {
		return this->charactersName + ": " + this->diologue.at(diologueIndex);
	}
}
