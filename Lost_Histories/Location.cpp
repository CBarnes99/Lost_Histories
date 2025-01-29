#include "Location.h"
#include <iostream>

using namespace std;

Location::Location(string lName, string lDesc, string lDistDesc) {
	this->locName = lName;
	this->locDescription = lDesc;
	this->locDistantDescription = lDistDesc;
	
	this->isLight = false;
	this->locNoLightSearchDescription = "Its too dark to examine the area.";

	this->isItemInArea = false;
	this->locItems = Item();
	this->roomSearchDescription = "You examine the area but theres nothing of note in the area.";

	this->isPathBlocked = false;
	this->pathBlockedByObstacle = "NULL";

	this->pathways = {};
}


string Location::get_Loc_Name() {
	return this->locName;
}

string Location::get_Loc_Description() {
	return this->locDescription;
}

string Location::get_Not_Lit_Description() {
	return locNoLightSearchDescription;
}

string Location::get_Loc_Distant_Description() {
	return this->locDistantDescription;
}

void Location::search_Location() {
	if (isLight == true) {
		//check to see if theres an item
			//if there is - say its description
				//ask the user if they want to pick it up
			//if there isnt
				//theres nothing of value here
		cout << "NOTE ---- NEED TO ADD TO CHECK IF THERES AN ITEM HERE" << endl;/////////////////////////////////////////
	}
	else {
		cout << "Its too dark to see anything";
	}
}

void Location::set_Light_In_Area(bool light) {
	this->isLight = light;
}

void Location::set_Item_No_Longer_In_Location() {
	this->isItemInArea = false;
	this->roomSearchDescription = "You examine the area but theres nothing of note in the area.";
	this->locNoLightSearchDescription = "Its too dark to examine the area. But you remember you've already searched this location before.";
}

void Location::add_Pathway(Location& newPathway) {
	pathways.push_back(&newPathway);
}

void Location::set_Location_Path_Is_Blocked(Obstacle& obs) {
	this->isPathBlocked = true;
	this->pathBlockedByObstacle = obs.get_Obstacle_Name();
}

void Location::set_Location_Unblocked() {
	this->isPathBlocked = false;
}
vector<Location*> Location::get_Pathways() {
	return pathways;
}

void Location::set_Item_In_Location(Item& lItem) {
	this->isItemInArea = true;
	this->locItems = lItem;
	this->roomSearchDescription = this->locItems.get_Item_Search_Description();
}