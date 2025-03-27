#pragma once
#include "Character.h"
#include <vector>


class NPC : public Character
{
private:
	
	int diologueIndex;

	vector<string> diologue;


public:
	NPC(string name);

	void addDiologue(string nDiologue);

};

