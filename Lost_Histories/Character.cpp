#include "Character.h"

Character::Character(string name) {
	this->charactersName = name;
}

string Character::get_character_name()
{
	return this->charactersName;
}
