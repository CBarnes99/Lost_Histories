#pragma once
#include "Item.h"
#include "Obstacle.h"
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
<<<<<<< Updated upstream
	string locNotLightDescription;
=======
	string locNoLightSearchDescription;
>>>>>>> Stashed changes

	/**
	*	@brief The locations description from another location from where you can move from
	*/
	string locDistantDescription;

	/**
	*	@brief If the room is lit from a light source, this will be true, otherwise false
	*/
	bool isLight;

	/**
	*	@brief A check to see if theres an item in the area
	*/
	bool isItemInArea;

	/**
	*	@brief This is an item that is placed within the room
	*/
	Item locItems;

	/**
	*	@brief What appears when you search a room
	*	Depending on if theres an item in the room, the result will be different
	*/
	string roomSearch;

	/**
	*	@brief Check to see if this path is blocked by an on obstacle
	*/
	bool isPathBlocked;

	/**
	*	@brief The obstacles name that is blocking the path if the path is blocked
	*/
	string pathBlockedBy;

	/**
	*	@brief A vector of locations that the player cand move to from this location
	*/
	vector<Location&> pathways;

public:
	//Location(string lName, string lDesc, string locNotLitDesc, string locDistDesc, bool isLit, Item item, string locSearchDesc, bool blocked, string blockedBy);
	/**
	*	@brief Constructor for the Location.
	*	@param lName The name of the Location, as a String
	*	@param lDesc The description for the Location, as a String
<<<<<<< Updated upstream
	*	@param locNotLitDesc The Description for the location when the location is not lit, as a String
	*	@param locDistDesc The Description for the location when viewed from another location, as a String
	*	@param isLit Is the room lit by default, as a Bool
	*	@param Item Is there an Item in the room that can be picked up by the player, as an Item class
	*	@param blocked Is the location blocked by an obstacle, as a Bool
	*	@param blockedBy What is the location blocked by, as a String
	*/
	Location(string lName, string lDesc, string locNotLitDesc, string locDistDesc, bool isLit, Item Item, bool blocked, string blockedBy);
=======
	*	@param lDistDesc The Description for the location when viewed from another location, as a String
	*/
	Location(string lName, string lDesc, string lDistDesc);

	/*
	@param locNotLitDesc The Description for the location when the location is not lit, as a String
	@param isLit Is the room lit by default, as a Bool
	@param item Is there an Item in the room that can be picked up by the player, as an Item class
	@param locSearchDesc What is outputed if you search the area for an Item
	@param blocked Is the location blocked by an obstacle, as a Bool
	@param blockedBy What is the location blocked by, as a String
	*/

	/**
	*	@brief changes if theres light in the area
	*	@param light True if theres light in the area, false if there is no longer light, as a bool
	*/
	void set_Light_In_Area(bool light);

	/**
	*	@brief Set an item into the area
	*	@param lItem The Item that is now in that location, as an Item object
	*/
	void set_Item_In_Location(Item& lItem);

	/**
	*	@brief remove the item from the location
	*/
	void set_Item_No_Longer_In_Location();

	/**
	*	@brief Set that the path is blocked by an obstacle
	*/
	void set_Location_Path_Is_Blocked(Obstacle& obs);

	/**
	*	@brief Sets the location unblocked so you can now pass through
	*/
	void set_Location_Unblocked();
>>>>>>> Stashed changes

	/**
	*	@brief Gets the Locations name
	*	@return The name of the location as a String
	*/
	string getName();

	/**
	*	@brief Gets the Locations description
	*	@return The locations description as a String
	*/
	string getLocDescription();

	/**
	*	@brief Gets the Locations description if the location is not lit up
	*	@return The locations description as a String
	*/
	string getNotLitDescription();

	/**
	*	@brief Gets the Locations description from a connecting location
	*	@return The distant location description as a String
	*/
	string getLocDistantDescription();

	/**
<<<<<<< Updated upstream
	*	@brief Set the location to being lit or unlit depending on the param inputed
	*/
	void setIsLight(bool isLit);

	/**
	*	@brief When item is picked up from this location, remove item from location and add it to the players inventory
	*/
	void removeItemFromLoc();

	/**
	*	@brief Set pathway to either blocked or unblocked depending on param inputed
	*/
	void blockedPath(bool blocked);

	/**
	*	@brief Searches the current location you are in
	*/
	void roomSearch();

	/**
=======
>>>>>>> Stashed changes
	*	@brief Adds a pathway to this location connecting to another location
	*/
	void addPathway(Location& newPathway);

	/**
	*	@brief Displayes the connecting locations from this one
	*	@return The locations connecting this as a vector of strings
	*/
<<<<<<< Updated upstream
	vector<Location&> getPathways();


=======
	//void get_Pathways();
	vector<Location*> get_Pathways();
>>>>>>> Stashed changes
};

