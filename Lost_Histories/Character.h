#pragma once
#include <string>


class Character
{

protected:
	
	/**
	*	@brief The players name
	*/
	std::string charactersName;

public:
	/**
	*	@brief Constructor for the Player Class
	*/
	Character(std::string Name);

	/**
	*	@brief Gets the players name
	*	@return The players name returned as a string
	*/
	std::string get_character_name();
};