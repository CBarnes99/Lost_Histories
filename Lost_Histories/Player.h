#pragma once
#include <string>
#include <vector>
#include "Item.h"

using namespace std;


class Player
{
	
private:
	/**
	*	@brief The players name
	*/
	string playerName;

	/**
	*	@brief The players invventory as a vector of items
	*/
	vector<Item> playerInventory;

	/**
	*	@brief If the player has light, it'll change the location the player is in.
	*/
	bool hasLight;


	//int playerSanity ----------- might be fun to play with down the line


public:
	/**
	*	@brief Constructor for the Player Class
	*/
	Player();

	/**
	*	@brief Set the players name
	*	@param nName The name inputed by the player, as a string
	*/
	void set_player_name(string nName);

	/**
	*	@brief Gets the players name
	*	@return The players name returned as a string
	*/
	string get_player_name();

	/**
	*	@brief Adds the item found within the location to the players inventory
	*	@param nItem The item added to the inventory, as an Item object
	*/
	void add_item_to_inventory(Item nItem);

	/**
	*	@brief Outputs all the items in the players inventory
	*/
	void output_all_items_in_inventory();

	/**
	*	@brief Sets the players light soruce to true or false
	*	@param set if the player has light on them, as a Bool
	*/
	void set_light(bool hasLight);

	/**
	*	@brief returns the size of the players inventory
	*	@return players inventory size, as an int
	*/
	size_t get_inventory_size();

	/**
	*	@brief Get a specific item from the players inventory
	*	@param index The Location of the item in the inventory vector, as an Int
	*	@return The Item in your inventory at the specified index, as an Item object
	*/
	Item get_item_from_inventory(int index);

	/**
	*	@brief Removes an item from your inventory
	*	@param item The Item that is getting its durability reduced, as an item reference
	*	@param index The index of the item in the inventory
	*/
	void reduce_item_durability(Item item, int index);
};