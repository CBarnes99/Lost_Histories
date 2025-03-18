#pragma once
#include <string>
#include "item.h"
#include "Obstacle.h"

using namespace std;

class Object
{
private:
	/**
	*	@brief The Objects Name. Private
	*/
	string objectName;

	/**
	*	@brief The Item in or at the object. Private
	*/
	Item item;

	/**
	*	@brief If true, the item has already been taken. Private
	*/
	bool isThereAnItem;

	/**
	*	@brief Is object blocked. Private
	*/
	bool isObjectBlocked;

	/**
	*	@brief If the obstacle is blocked by an obstacle, this is the Obstacle. Private
	*/
	Obstacle* blockedByObstacle;

	/**
	*	@brief When the obstacle is no longer blocked, this is displayed to the player. Private
	*/
	string unblockedDescription;

	/**
	*	@brief If the object needs opening like a cupboard. Private
	*/
	bool objectNeedsOpening;

	/**
	*	@brief When item is opened, show player the description of the object openeing. Private.
	*/
	string objectOpeningDescription;

public:
	Object();

	void set_object_name(string oName);

	void set_item(Item oItem);

	bool is_there_an_item();

	void set_item_taken();

	void set_obstacle(Obstacle* oObstacle, string oUnblocked);

	void set_needs_opening(string oOpeningDescription);

	string get_object_name();

	Item& get_item();

	Obstacle* get_obstacle();

	string get_object_opening_description();


};

