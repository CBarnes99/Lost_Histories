#pragma once
#include <string>

class Item
{

private:
	/**
	*	@brief Name of the Item. Private.
	*/
	std::string itemName;

	/**
	*	@brief The Items description. Private.
	*/
	std::string itemDescription;

	/**
	*	@brief If the item is destroyed, it wont be able to be used again. Private.
	*/
	bool isDestroyed;

	/**
	*	@brief The amount of times the item can be used before it is destroyed
	*/
	int itemDurability;

	/**
	*	@brief What is said when the item has no durability left
	*/
	std::string itemDestroyedText;

public:
	/**
	*	@brief Defualt constructor for the Item.
	*/
	Item();

	/**
	*	@breif Set default name, description, and the amount of uses for Item
	*	@param iName The name of the Item, as a String
	*	@param iDesc The description for the item, as a String
	*	@param iUses The amount of times the item can be used, as an Int
	*/
	void set_item_defaults(std::string iName, std::string iDesc, int iUses);

	/**
	*	@brief Gets the Items name
	*	@return The name of the Item as a String
	*/
	std::string get_item_name();

	/**
	*	@brief Gets the Items description
	*	@return The Items description as a String
	*/
	std::string get_item_description();

	/**
	*	@brief Changes the item to be destroyed if the amount of uses reaches 0
	*/
	void reduce_item_durability();

	/**
	*	@brief A check to see if the Item is destroyed
	*	@return The items destroyed value as a Bool
	*/
	bool is_item_destroyed();

	/**
	*	@brief What is said when the item has no durability left
	*	@param noDurability What is said when the item is used up, as a string
	*/
	void set_item_destroyed_text(std::string text);
};

