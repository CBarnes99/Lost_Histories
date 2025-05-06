#pragma once
#include <string>
#include "Player.h"

class Obstacle
{

private:

	/**
	*	@brief The name of the thing it is blocking
	*/
	std::string obstacleName;

	/**
	*	@brief What is shown when an obstacle is in the way
	*/
	std::string obstacleInteract;

	/**
	*	@brief The description of the obstacle
	*/
	std::string obstacleInspect;

	/**
	*	@brief The item that acts as a key to this obstale and allows the playe to pass
	*/
	std::string obstcaleKey;

	/**
	*	@brief What displays to the player when the obstacle is removed
	*/
	std::string obstacleRemoved;

public:
	/**
	*	@brief Defualt constructor for Obstacle Object
	*/
	Obstacle();

	/**
	*	@brief Setting the defualt obstacle parameters
	*	@param obsName The name of the Obstacle blocking the location, as a String
	*	@param obsInteract What is shown when interacting with the obstacle, as a String
	*	@param obsInspect The description of the Obstacle, as a String
	*	@param obsKey The name of the Item object that unblocks the location, as a String
	*	@param obsRemoved What is displayed to the player when the obstacle is removed from the location, as a String
	*/
	void set_obstacle_defualts(std::string obsName, std::string obsInteract, std::string obsInspect, std::string obsKey, std::string obsRemoved);

	/**
	*	@brief The obstacles name
	*	@return The obstacles name returned as a string
	*/
	std::string get_obstacle_name();

	/**
	*	@brief The obstacles interact message
	*	@return The obstacles interact message returned as a string
	*/
	std::string get_obstacle_interact();

	/**
	*	@brief The obstacles descripition
	*	@return The obstacles description returned as a string
	*/
	std::string get_obstacle_description();

	/**
	*	@brief Get the key to the obstacle
	*/
	std::string get_obstacle_key();

	/**
	*	@brief Displays to the user once the obstacle has been removed
	*	@return The obstacleRemoved, as a String
	*/
	std::string get_obstacle_removed_description();

	/**
	*	@brief Gives the player options on what to do when ecnountering an obstacle
	*	@param player The player, as a player object
	*/
	bool obstacle_choice(Player& player);
};

