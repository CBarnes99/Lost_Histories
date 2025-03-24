#pragma once
#include <string>
#include "item.h"
#include "Obstacle.h"

using namespace std;

class Searchables
{
private:
	/**
	*	@brief The Searchables Name. Private
	*/
	string searchablesName;

	/**
	*	@brief The Item in or at the Searchables. Private
	*/
	Item item;

	/**
	*	@brief If true, the item has already been taken. Private
	*/
	bool isThereAnItem;

	/**
	*	@brief Is Searchables blocked. Private
	*/
	bool isSearchablesBlocked;

	/**
	*	@brief If the obstacle is blocked by an obstacle, this is the Obstacle. Private
	*/
	Obstacle* blockedByObstacle;

	/**
	*	@brief When the obstacle is no longer blocked, this is displayed to the player. Private
	*/
	string unblockedDescription;

	/**
	*	@brief If the Searchables needs opening like a cupboard. Private
	*/
	bool searchablesNeedsOpening;

	/**
	*	@brief When item is opened, show player the description of the Searchables openeing. Private.
	*/
	string searchablesOpeningDescription;

public:
	/**
	*	@brief Defualt constructor for Searchables object
	*/
	Searchables();

	/**
	*	@breif Set the name of the searchable
	*	@param sName The name of the searchable, as a String
	*/
	void set_searchables_name(string sName);

	/**
	*	@brief Set the item in the searchable, if you dont, it'll output to the player nothing is here
	*	@param sItem The item in the searchable, as an Item object
	*/
	void set_item(Item sItem);

	/**
	*	@brief A check to see if theres an item in the searchable
	*	@return A Bool, True if there is an item, False if there isn't
	*/
	bool is_there_an_item();

	/**
	*	@brief Once item has been taken, set isThereAnItem to true
	*/
	void set_item_taken();

	/**
	*	@brief Sets an obstacle blocking the searchable and you require an item to open the searchable
	*	@param sObstacle The obstacle blocking the searchable, as an Obstacle object
	*	@param sUnblocked The string stated when the obstacle is removed, as a String
	*/
	void set_obstacle(Obstacle* sObstacle, string sUnblocked);

	/**
	*	@brief What is displayed if the searchable needs opening like a cupboard door
	*	@param sOpeningDescription The description of the opening, as a String
	*/
	void set_needs_opening(string sOpeningDescription);

	/**
	*	@brief After obstacle has been removed, set isSearchablesBlocked to false
	*/
	void set_searchables_not_blocked_by_obstacle();

	/**
	*	@brief Gets the item from the searchable and puts it into the players inventory
	*	@param player The player, as a Player object
	*/
	void get_item_from_searchables(Player& player);

	/**
	*	@brief A check to see if the searchable is blocked by an obstacle
	*	@return True if searchable is blocked, False if not blocked, as a Bool
	*/
	bool is_searchables_blocked_by_obstacle();

	/**
	*	@breif Returns the searchables name
	*	@return The name of the searchable, as a String
	*/
	string get_searchables_name();

	/**
	*	@brief gets the obstacle that is blocking the searchable
	*	@return The obstacle, as an Obstacle object*
	*/
	Obstacle* get_obstacle();
};

