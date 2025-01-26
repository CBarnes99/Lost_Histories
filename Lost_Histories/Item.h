#pragma once
#include <string>
#include "Obstacle.h"

using namespace std;

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
	//Obstacle linkedObstacleForItem;

public:
	/**
	*	@brief Defualt constructor for the Item. 
	*/
	Item();
	//Obstacle iLinkedObs

	/**
	*	@breif Set defualt name and description for Item
	*	@param nName The name of the Item, as a String
	*	@param nDesc The description for the item, as a String
	*/
	void set_Item_Defaults(string iName, string iDesc);

	/**
	*	@brief Gets the Items name
	*	@return The name of the Item as a String
	*/
	string get_Item_Name();

	/**
	*	@brief Gets the Items description
	*	@return The Items description as a String
	*/
	string get_Item_Description();

	/**
	*	@brief Changes the item to be destroyed
	*/
	void destroy_Item();

};

