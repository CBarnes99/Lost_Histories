#pragma once
#include "Item.h"
#include "Obstacle.h"
#include "Player.h"
#include "Object.h"
#include <string>
#include <vector>

using namespace std;

class Location
{
private:
	/**
	*	@brief Name of the location. Private
	*/
	string locName;

	/**
	*	@brief The locations description when you are in that location
	*/
	string locDescription;

	/**
	*	@brief The locations description when searched when theres no light
	*/
	string locNoLightSearchDescription;

	/**
	*	@brief The locations description from another location from where you can move from
	*/
	string locDistantDescription;

	/**
	*	@brief If the room is lit from a light source, this will be true, otherwise false
	*/
	bool isLight;

	/**
	*	@brief A check to see if theres a searchable object in the area
	*/
	bool isObjectInArea;

	/**
	*	@brief This is an item that is placed within the room
	*/
	vector<Object*> locObject;

	/**
	*	@brief What appears when you search a room
	*	Depending on if theres a searchable object in the room, the result will be different
	*/
	string roomSearchDescription;

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
	vector<Location*> pathways;

public:

	/**
	*	@brief Constructor for the Location.
	*	@param lName The name of the Location, as a String
	*	@param lDesc The description for the Location, as a String
	*	@param lDistDesc The Description for the location when viewed from another location, as a String
	*/
	Location(string lName, string lDesc, string lDistDesc);

	/**
	*	@brief Gets the Locations name
	*	@return The name of the location as a String
	*/
	string get_loc_name();

	/**
	*	@brief Gets the Locations description
	*	@return The locations description as a String
	*/
	string get_loc_description();

	/**
	*	@brief Gets the Locations description if the location is not lit up
	*	@return The locations description as a String
	*/
	string get_not_lit_description();

	/**
	*	@brief Gets the Locations description from a connecting location
	*	@return The distant location description as a String
	*/
	string get_loc_distant_description();

	/**
	*	@brief Displayes the connecting locations from this one
	*	@return The locations connecting this as a vector of strings
	*/
	vector<Location*> get_pathways();

	/**
	*	@brief Adds a pathway to this location connecting to another location
	*	@param A location object that is the new path, as a Location object
	*/
	void add_pathway(Location& newPathway);

	/**
	*	@brief changes if theres light in the area
	*	@param light True if theres light in the area, false if there is no longer light, as a bool
	*/
	void set_light_in_area(bool light);

	/**
	*	@brief Set an item into the area
	*	@param lItem The Item that is now in that location, as an Item object
	*/
	void set_object_in_location(Object& lObject);

	/**
	*	@brief Returns all the searchable objects in this location
	*	@return All searchable objects, as a vector of Object*
	*/
	vector<Object*> get_all_objects();

	/**
	*	@brief remove the item from the location
	*/
	void set_item_no_longer_in_location();

	/**
	*	@brief Set that the path is blocked by an obstacle
	*/
	void set_location_path_is_blocked_by(Obstacle& obs);

	/**
	*	@brief Gets the name of the obstacle thats blocking this location
	*	@return The name of the obstacle, as a String
	*/
	string get_obstacle_name_from_location();

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
	*	@param currentLoc The players current location, as a Location object
	*	@param userInput The players input for the location choice, as an Int
	*	@prarm player The player, as a Player object
	*/
	bool move_to_location(Location* currentLoc, int userInput, Player& player);
};

