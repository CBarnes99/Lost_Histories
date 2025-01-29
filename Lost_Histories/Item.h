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
<<<<<<< Updated upstream
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
=======
	*	@brief What is desplayed when a room is searched and this item is in the area. Private
	*/
	string itemSearchLocationDescription;

public:
	/**
	*	@brief Defualt constructor for the Item. 
	*/
	Item();

	/**
	*	@breif Set defualt name and description for Item
	*	@param iName The name of the Item, as a String
	*	@param iDesc The description for the item, as a String
	*	@param iSearch The description of what you see in the area for this item, as a String
	*/
	void set_Item_Defaults(string iName, string iDesc, string iSearch);
>>>>>>> Stashed changes

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
<<<<<<< Updated upstream
	void destroyItem();
=======
	void destroy_Item();

	/**
	*	@brief A check to see if the Item is destroyed
	*	@return The items destroyed value as a Bool
	*/
	bool is_Item_Destroyed();

	/*
	*	@brief Gets the item search desciption
	*	@return itemSearchLocationDescription as a string
	*/
	string get_Item_Search_Description();
>>>>>>> Stashed changes

};

