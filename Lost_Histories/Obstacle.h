#pragma once
#include <string>
#include "Item.h"

using namespace std;

class Obstacle
{

private:
	/**
	*	@brief The name of the Obstacle
	*/
	string obstacleName;

	/**
	*	@brief The description of the obstacle
	*/
	string obstacleDescription;

	/**
	*	@brief The item that acts as a key to this obstale and allows the playe to pass
	*/
	string obstcaleKey;

	/**
	*	@brief What displays to the player when the obstacle is removed
	*/
	string obstacleRemoved;

public:
	/**
	*	@brief Defualt constructor for Obstacle Object
	*/
	Obstacle();

	/**
	*	@brief Setting the defualt obstacle parameters
	*	@param obsName The name of the Obstacle blocking the location, as a String
	*	@param obsDesc The description of the Obstacle, as a String
	*	@param obsKey The name of the Item object that unblocks the location, as a String
	*	@param obsRemoved What is displayed to the player when the obstacle is removed from the location, as a String
	*/
	void set_obstacle_defualts(string obsName, string obsDesc, string obsKey, string obsRemoved);

	/**
	*	@brief The obstacles name
	*	@return The obstacles name returned as a string
	*/
	string get_obstacle_name();

	/**
	*	@brief The obstacles descripition
	*	@return The obstacles description returned as a string
	*/
	string get_obstacle_description();

	/**
	*	@brief Get the key to the obstacle
	*/
	string get_obstacle_key();

	/**
	*	@brief Displays to the user once the obstacle has been removed
	*	@return The obstacleRemoved, as a String
	*/
	string get_obstacle_removed_description();
};

