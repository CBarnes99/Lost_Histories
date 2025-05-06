#pragma once
#include "Item.h"
#include "Obstacle.h"
#include "Player.h"
#include "Searchables.h"
#include <string>
#include <vector>

class Location
{
private:
	/**
	*	@brief Name of the location. Private
	*/
	std::string locName;

	/**
	*	@brief The locations description when you are in that location
	*/
	std::string locDescription;

	/**
	*	@brief The locations description from another location from where you can move from
	*/
	std::string locInspectLocation;

	/**
	*	@brief A check to see if theres a searchable Searchables in the area
	*/
	bool isSearchablesInArea;

	/**
	*	@brief This is an item that is placed within the room
	*/
	std::vector<Searchables*> locSearchables;

	/**
	*	@brief What appears when you search a room
	*	Depending on if theres a searchable Searchables in the room, the result will be different
	*/
	std::string roomSearchDescription;

	/**
	*	@brief Check to see if this path is blocked by an on obstacle
	*/
	bool isPathBlocked;

	/**
	*	@brief The obstacles name that is blocking the path if the path is blocked
	*/
	Obstacle* pathBlockedByObstacle;

	/**
	*	@brief A vector of locations that the player cand move to from this location
	*/
	std::vector<Location*> pathways;

public:

	/**
	*	@brief Constructor for the Location.
	*	@param lName The name of the Location, as a String
	*	@param lDesc The description for the Location, as a String
	*	@param lInspectDesc The Description for the location when inspected, as a String
	*/
	Location(std::string lName, std::string lDesc, std::string lInspectDesc);

	/**
	*	@brief Gets the Locations name
	*	@return The name of the location as a String
	*/
	std::string get_loc_name();

	/**
	*	@brief Gets the Locations description
	*	@return The locations description as a String
	*/
	std::string get_loc_description();

	/**
	*	@brief Gets the Locations description from a connecting location
	*	@return The distant location description as a String
	*/
	std::string get_loc_inspect_location();

	/**
	*	@brief Displayes the connecting locations from this one
	*	@return The locations connecting this as a vector of strings
	*/
	std::vector<Location*> get_pathways();

	/**
	*	@brief Adds a pathway to this location connecting to another location
	*	@param A location Searchables that is the new path, as a Location Object
	*/
	void set_pathway(Location& newPathway);

	/**
	*	@brief Set an item into the area
	*	@param lItem The Item that is now in that location, as an Item Object
	*/
	void set_searchables_in_location(Searchables& lSearchables);

	/**
	*	@brief Returns all the searchable Searchables in this location
	*	@return All searchable Searchables, as a vector of Searchables*
	*/
	vector<Searchables*> get_all_searchables();

	/**
	*	@brief Set that the path is blocked by an obstacle
	*/
	void set_location_path_is_blocked_by(Obstacle& obs);

	/**
	*	@brief Gets the name of the obstacle thats blocking this location
	*	@return The name of the obstacle, as a String
	*/
	std::string get_obstacle_interact_from_location();

	/**
	*	@brief Sets the location unblocked so you can now pass through
	*/
	void set_location_unblocked();

	/**
	*	@brief Searches the current location you are in and promts the user to pick up an item if there is one
	*	@param The player, as a Player object
	*/
	void search_location(Player& player);

	/**
	*	@breif Moves player to the new location if its not blocked by an obstacle
	*	@prarm player The player, as a Player object
	*/
	bool is_loc_accessible(Player& player);

};

