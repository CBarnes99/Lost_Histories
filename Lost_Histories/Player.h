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
	void setPlayerName(string nName);

	/**
	*	@brief Gets the players name
	*	@return The players name returned as a string
	*/
	string getPlayerName();

	/**
	*	@brief Adds the item found within the location to the players inventory
	*/
	void addItemToInventory(Item nItem);

	/**
	*	@brief Outputs all the items in the players inventory
	*/
	void outputAllItemsInInventory();

	/**
	*	@brief Sets the players light soruce to true or false
	*/
	void setLight(bool hasLight);


};