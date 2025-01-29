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
	*/
	void set_Player_Name(string nName);

	/**
	*	@brief Gets the players name
	*	@return The players name returned as a string
	*/
	string get_Player_Name();

	/**
	*	@brief Adds the item found within the location to the players inventory
	*/
	void add_Item_To_Inventory(Item nItem);

	/**
	*	@brief Outputs all the items in the players inventory
	*/
	void output_All_Items_In_Inventory();

	/**
	*	@brief Sets the players light soruce to true or false
	*/
	void set_Light(bool hasLight);


};