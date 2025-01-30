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
	this->roomSearchDescription = "You examine the area but theres nothing of note in the vicinity.";

	this->isPathBlocked = false;
	this->pathBlockedByObstacle = Obstacle();

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

vector<Location*> Location::get_pathways() {
	return pathways;
}

void Location::add_pathway(Location& newPathway) {
	pathways.push_back(&newPathway);
}

void Location::set_light_in_area(bool light) {
	this->isLight = light;
}

void Location::set_item_in_location(Item& lItem) {
	this->isItemInArea = true;
	this->locItems = lItem;
	this->roomSearchDescription = this->locItems.get_item_search_description();
}

void Location::set_item_no_longer_in_location() {
	this->isItemInArea = false;
	this->roomSearchDescription = "You examine the area but theres nothing of note in the area.";
	this->locNoLightSearchDescription = "Its too dark to examine the area. But you remember you've already searched this location before.";
}

void Location::set_location_path_is_blocked_by(Obstacle& obs) {
	this->isPathBlocked = true;
	this->pathBlockedByObstacle = obs;
}

void Location::set_location_unblocked() {
	this->isPathBlocked = false;
}

void Location::search_location(Player& player) {
	if (isLight == true) {
		if (isItemInArea == true) {
			cout << locItems.get_item_search_description();
			cout << "Do you want to pick up the item? Y or N" << endl;
			string playerAnswer;
			cin >> playerAnswer;
			if (playerAnswer == "y" || playerAnswer == "n") {
				player.add_item_to_inventory(locItems);
				cout << "You pick up the " << locItems.get_item_name();
				set_item_no_longer_in_location();
			}
			else {
				cout << "You didnt pick up the " << locItems.get_item_name();
			}
		}
		else {
			cout << roomSearchDescription;
		}
	}
	else {
		cout << locNoLightSearchDescription;
	}
}

bool Location::move_to_location(Location& currentLoc, int& userInput) {
	if (currentLoc.get_pathways()[userInput]->isPathBlocked == true) {
		currentLoc.get_pathways()[userInput]->pathBlockedByObstacle.get_obstacle_description();
		return false;
	}
	else {
		return true;
	}
}