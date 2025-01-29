#include "Location.h"
#include <iostream>

using namespace std;

<<<<<<< Updated upstream

Location::Location(string lName, string lDesc, string locNotLitDesc, string locDistDesc, bool isLit, Item item, bool blocked, string blockedBy) {
	this->locName = lName;
	this->locDescription = lDesc;
	this->locNotLightDescription = locNotLitDesc;
	this->locDistantDescription = locDistDesc;
	this->isLight - isLit;
	this->locItems = item;
	this->isPathBlocked = blocked;
	this->pathBlockedBy = blockedBy;
	//this->roomSearch = ADD DESCRITPION OF THE ITEM TO THIS 
}

string Location::getName() {
=======
//Location::Location(string lName, string lDesc, string locNotLitDesc, string locDistDesc, bool isLit, Item item, string locSearchDesc, bool blocked, string blockedBy) {
//	this->locName = lName;
//	this->locDescription = lDesc;
//	this->locNoLightDescription = locNotLitDesc;
//	this->locDistantDescription = locDistDesc;
//	this->isLight = isLit;
//	this->locItems = item;
//	this->roomSearchDescription = locSearchDesc;
//	this->isPathBlocked = blocked;
//	this->pathBlockedByObstacle = blockedBy;
//	this->pathways = {};
//	
//}


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


string Location::get_Name() {
>>>>>>> Stashed changes
	return locName;
}

string Location::getLocDescription() {
	return locDescription;
}

<<<<<<< Updated upstream
string Location::getNotLitDescription() {
	return locNotLightDescription;
=======
string Location::get_Not_Lit_Description() {
	return locNoLightSearchDescription;
>>>>>>> Stashed changes
}

string Location::getLocDistantDescription() {
	return locDistantDescription;
}

<<<<<<< Updated upstream
void Location::setIsLight(bool isLit) {
	this->isLight = isLit;
}


void Location::roomSearch() {
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


void Location::removeItemFromLoc() {
	cout << "NOTE ---- ADD REMOVE ITEM FROM LOCATION" << endl; ////////////////////////////////////////////////
}
void Location::blockedPath(bool blocked) {
	this->isPathBlocked = blocked;
}

void Location::addPathway(Location& newPathway) {
	this->pathways.push_back(newPathway);
}
vector<Location&> Location::getPathways() {
	return pathways;
=======
void Location::add_Pathway(Location& newPathway) {
	this->pathways.push_back(&newPathway);
}

vector<Location*> Location::get_Pathways() {

	return pathways;
	/*for (int i = 0; this->pathways.size() > i; i++) {
		cout << pathways[i]->get_Loc_Distant_Description();
	}*/
}

void Location::set_Light_In_Area(bool light) {
	this->isLight = light;
}

void Location::set_Item_In_Location(Item& lItem) {
	this->isItemInArea = true;
	this->locItems = lItem;
	this->roomSearchDescription = this->locItems.get_Item_Search_Description();
}

void Location::set_Item_No_Longer_In_Location() {
	this->isItemInArea = false;
	this->roomSearchDescription = "You examine the area but theres nothing of note in the area.";
	this->locNoLightSearchDescription = "Its too dark to examine the area. But you remember you've already searched this location before.";
}

void Location::set_Location_Path_Is_Blocked(Obstacle& obs) {
	this->isPathBlocked = true;
	this->pathBlockedByObstacle = obs.get_Obstacle_Name();
}

void Location::set_Location_Unblocked() {
	this->isPathBlocked = false;
>>>>>>> Stashed changes
}