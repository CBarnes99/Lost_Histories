#pragma once
#include <string>

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
	*	@brief When location is search, this is what appears to the player
	*/
	string itemSearchLocationDescription;

	/**
	*	@brief The amount of times the item can be used before it is destroyed
	*/
	int itemDurability;

public:
	/**
	*	@brief Defualt constructor for the Item.
	*/
	Item();

	/**
	*	@breif Set default name, description, and area search for Item
	*	@param iName The name of the Item, as a String
	*	@param iDesc The description for the item, as a String
	*	@param iSearch The description of what you see in the area for this item, as a String
	*/
	void set_item_defaults(string iName, string iDesc, string iSearch, int iUses);

	/**
	*	@brief Gets the Items name
	*	@return The name of the Item as a String
	*/
	string get_item_name();

	/**
	*	@brief Gets the Items description
	*	@return The Items description as a String
	*/
	string get_item_description();

	/**
	*	@brief Changes the item to be destroyed if the amount of uses reaches 0
	*/
	void reduce_item_durability();

	/**
	*	@brief A check to see if the Item is destroyed
	*	@return The items destroyed value as a Bool
	*/
	bool is_item_destroyed();

	/*
	*	@brief Gets the item search desciption
	*	@return itemSearchLocationDescription as a string
	*/
	string get_item_search_description();

	int item_durability();

	void set_item_durability();
};

