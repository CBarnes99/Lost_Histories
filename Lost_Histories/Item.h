#pragma once
#include <string>
#include "Obstacle.h"

class Item
{

private:
	/**
	*	@brief Name of the Item. Private.
	*/
	string itemName;

	/**
	*	@brief The Items description. Private.
	*/
	string itemDescription;

	/**
	*	@brief If the item is destroyed, it wont be able to be used again. Private.
	*/
	bool isDestroyed;

	/**
	*	@brief The obstacle that your item is linked to.
	*	For example, a key might be linked to a specifc door. Private.
	*/
	Obstacle linkedObstacleForItem;

public:
	/**
	*	@brief Constructor for the Item. Requires Item name, description and a linked Obstacle
	*	@param nName The name of the Item, as a String
	*	@param nDesc The description for the item, as a String
	*	@param linkedObs The Obstacle that the item is linked to and can be used on, as an Obstacle Class
	*/
	Item(string nName, string nDesc, Obstacle linkedObs);

	/**
	*	@brief Gets the Items name
	*	@return The name of the Item as a String
	*/
	string getItemName();

	/**
	*	@brief Gets the Items description
	*	@return The Items description as a String
	*/
	string getItemDescription();

	/**
	*	@brief Changes the item to be destroyed
	*/
	void destroyItem();

};

