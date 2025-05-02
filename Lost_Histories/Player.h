#pragma once
#include "Character.h"
#include <vector>
#include "Item.h"

using namespace std;


class Player : public Character
{
	
private:

	/**
	*	@brief The players invventory as a vector of items
	*/
	vector<Item*> playerInventory;


public:
	/**
	*	@brief Constructor for the Player Class
	*/
	Player(string name);

	/**
	*	@brief Set the players name
	*	@param pName The name inputed by the player, as a string
	*/
	void set_player_name(string pName);

	/**
	*	@brief Adds the item found within the location to the players inventory
	*	@param nItem The item added to the inventory, as an Item object
	*/
	void add_item_to_inventory(Item& nItem);

	/**
	*	@brief Outputs all the items in the players inventory
	*	@param usingItem Are you using the item, as a Bool
	*/
	void output_all_items_in_inventory(bool usingItem);

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
	vector<Item*> get_item_from_inventory();

	/**
	*	@brief Removes an item from your inventory
	*	@param index The index of the item in the inventory, as an Int
	*/
	void remove_item_from_inventory(int index);
};