#include "Character.h"

Character::Character(std::string name) {
	this->charactersName = name;
}

std::string Character::get_character_name()
{
	return this->charactersName;
}
