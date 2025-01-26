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
	//Item obstcaleKey;

	/**
	*	@brief A hint on how to pass this obstacle
	*/
	string obstacleHint;


public:
	/**
	*	@brief Constructor for the obstacle
	*	@param obsName Obstacle name, as a string
	*	@param obsDesc Obstacle description, as a string
	*	@param obsKey The key to the obstacle that allows the player to pass through, as an Item Class
	*	@param obsHint A hint for how to pass the obstacle, as a string
	*/
	Obstacle(string obsName, string obsDesc, string obsHint);
	//Item obsKey,

	/**
	*	@brief The obstacles name
	*	@return The obstacles name returned as a string
	*/
	string get_Obstacle_Name();

	/**
	*	@brief The obstacles descripition
	*	@return The obstacles description returned as a string
	*/
	string get_Obstacle_Description();

	/**
	*	@brief The hint to bypass this obstacle
	*	@return The hint to bypass this obstacle returned as a string
	*/
	string get_Obstacle_Hint();

};

