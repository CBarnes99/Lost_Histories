#include "Location.h"
#include <iostream>

using namespace std;


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
	return locName;
}

string Location::getLocDescription() {
	return locDescription;
}

string Location::getNotLitDescription() {
	return locNotLightDescription;
}

string Location::getLocDistantDescription() {
	return locDistantDescription;
}

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
}