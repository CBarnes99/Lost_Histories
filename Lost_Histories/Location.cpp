#include "Location.h"
#include <iostream>

using namespace std;

Location::Location(string lName, string lDesc, string locNotLitDesc, string locDistDesc, bool isLit, Item item, string locSearchDesc, bool blocked, string blockedBy) {
	this->locName = lName;
	this->locDescription = lDesc;
	this->locNoLightDescription = locNotLitDesc;
	this->locDistantDescription = locDistDesc;
	this->isLight = isLit;
	this->locItems = item;
	this->roomSearchDescription = locSearchDesc;
	this->isPathBlocked = blocked;
	this->pathBlockedByObstacle = blockedBy;
	this->pathways = {};
	
}

string Location::get_Name() {
	return locName;
}

string Location::get_Loc_Description() {
	return locDescription;
}

string Location::get_Not_Lit_Description() {
	return locNoLightDescription;
}

string Location::get_Loc_Distant_Description() {
	return locDistantDescription;
}

void Location::set_Is_Light(bool isLit) {
	this->isLight = isLit;
}


void Location::room_Search_Description() {
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


void Location::remove_Item_From_Loc() {
	cout << "NOTE ---- ADD REMOVE ITEM FROM LOCATION" << endl; ////////////////////////////////////////////////
}
void Location::blocked_Path(bool blocked) {
	this->isPathBlocked = blocked;
}

void Location::add_Pathway(Location& newPathway) {
	this->pathways.push_back(newPathway);
}
vector<Location> Location::get_Pathways() {
	return pathways;
}
