#pragma once
#include "Item.h"
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
	*	@brief The locations description when the location is dark and not lit
	*/
	string locNoLightDescription;

	/**
	*	@brief The locations description from another location from where you can move from
	*/
	string locDistantDescription;

	/**
	*	@brief If the room is lit from a light source, this will be true, otherwise false
	*/
	bool isLight;

	/**
	*	@brief This is an item that is placed within the room
	*/
	Item locItems;

	/**
	*	@brief What appears when you search a room
	*	Depending on if theres an item in the room, the result will be different
	*/
	string roomSearchDescription;

	/**
	*	@brief Check to see if this path is blocked by an on obstacle
	*/
	bool isPathBlocked;

	/**
	*	@brief The obstacles name that is blocking the path if the path is blocked
	*/
	string pathBlockedByObstacle;

	/**
	*	@brief A vector of locations that the player cand move to from this location
	*/
	vector<Location*> pathways;

public:
	/**
	*	@brief Constructor for the Location.
	*	@param lName The name of the Location, as a String
	*	@param lDesc The description for the Location, as a String
	*	@param locNotLitDesc The Description for the location when the location is not lit, as a String
	*	@param locDistDesc The Description for the location when viewed from another location, as a String
	*	@param isLit Is the room lit by default, as a Bool
	*	@param Item Is there an Item in the room that can be picked up by the player, as an Item class
	*	@param blocked Is the location blocked by an obstacle, as a Bool
	*	@param blockedBy What is the location blocked by, as a String
	*/
	Location(string lName, string lDesc, string locNotLitDesc, string locDistDesc, bool isLit, Item item, string locSearchDesc, bool blocked, string blockedBy);

	/**
	*	@brief Gets the Locations name
	*	@return The name of the location as a String
	*/
	string get_Name();

	/**
	*	@brief Gets the Locations description
	*	@return The locations description as a String
	*/
	string get_Loc_Description();

	/**
	*	@brief Gets the Locations description if the location is not lit up
	*	@return The locations description as a String
	*/
	string get_Not_Lit_Description();

	/**
	*	@brief Gets the Locations description from a connecting location
	*	@return The distant location description as a String
	*/
	string get_Loc_Distant_Description();

	/**
	*	@brief Set the location to being lit or unlit depending on the param inputed
	*/
	void set_Is_Light(bool isLit);

	/**
	*	@brief When item is picked up from this location, remove item from location and add it to the players inventory
	*/
	void remove_Item_From_Loc();

	/**
	*	@brief Set pathway to either blocked or unblocked depending on param inputed
	*/
	void blocked_Path(bool blocked);

	/**
	*	@brief Searches the current location you are in
	*/
	void room_Search_Description();

	/**
	*	@brief Adds a pathway to this location connecting to another location
	*/
	void add_Pathway(Location& newPathway);

	/**
	*	@brief Displayes the connecting locations from this one
	*	@return The locations connecting this as a vector of strings
	*/
	vector<Location*> get_Pathways();


};

