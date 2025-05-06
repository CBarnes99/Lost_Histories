#pragma once
#include "Character.h"
#include <vector>


class NPC : public Character
{
private:
	
	/**
	*	@brief The current index of the diologue of what has already been said to the player
	*/
	int diologueIndex;

	/**
	*	@brief All the diologue a NPC has for the game
	*/
	std::vector<std::string> diologue;


public:
	/**
	*	@brief Constructor for the NPC class that is the child of the Character class
	*/
	NPC(std::string name);

	/**
	*	@brief Adds a piece of diologue into the vector
	*	@param nDiologue The text for the diologue, as a string
	*/
	void addDiologue(std::string nDiologue);

	/**
	*	@brief Outputs the next piece of diologue this NPC needs to say.
	*	@return The diologue, as a string
	*/
	std::string outputNextDiologue();

};

