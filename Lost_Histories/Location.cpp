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


string Location::get_loc_name() {
	return this->locName;
}

string Location::get_loc_description() {
	return this->locDescription;
}

string Location::get_not_lit_description() {
	return locNoLightSearchDescription;
}

string Location::get_loc_distant_description() {
	return this->locDistantDescription;
}

void Location::search_location() {
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

void Location::set_light_in_area(bool light) {
	this->isLight = light;
}

void Location::set_item_no_longer_in_location() {
	this->isItemInArea = false;
	this->roomSearchDescription = "You examine the area but theres nothing of note in the area.";
	this->locNoLightSearchDescription = "Its too dark to examine the area. But you remember you've already searched this location before.";
}

void Location::add_pathway(Location& newPathway) {
	pathways.push_back(&newPathway);
}

void Location::set_location_path_is_blocked(Obstacle& obs) {
	this->isPathBlocked = true;
	this->pathBlockedByObstacle = obs.get_obstacle_name();
}

void Location::set_location_unblocked() {
	this->isPathBlocked = false;
}
vector<Location*> Location::get_pathways() {
	return pathways;
}

void Location::set_item_in_location(Item& lItem) {
	this->isItemInArea = true;
	this->locItems = lItem;
	this->roomSearchDescription = this->locItems.get_item_search_description();
}