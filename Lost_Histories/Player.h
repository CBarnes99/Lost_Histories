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
	*	@brief gets items name from a specific index in the inventory
	*	@param index The location of the item in the inventory, as an Int
	*	@return item name, as a string
	*/
	string get_item_name_from_inventory(int index);
};