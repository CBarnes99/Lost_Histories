#pragma once
#include <string>

using namespace std;

class Character
{

protected:
	
	/**
	*	@brief The players name
	*/
	string charactersName;

public:
	/**
	*	@brief Constructor for the Player Class
	*/
	Character(string Name);

	/**
	*	@brief Gets the players name
	*	@return The players name returned as a string
	*/
	string get_character_name();
};