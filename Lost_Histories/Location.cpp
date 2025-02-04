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

string Location::get_obstacle_name_from_location() {
	return this->pathBlockedByObstacle.get_obstacle_name();
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
			cout << roomSearchDescription << endl;
		}
	}
	else {
		cout << locNoLightSearchDescription << endl;
	}
}

bool Location::move_to_location(Location* currentLoc, int userInput, Player& player) {
	if (currentLoc->get_pathways()[userInput]->isPathBlocked == true) {	//if the pathway the user selected is blocked by an obstacle
		currentLoc->get_pathways()[userInput]->pathBlockedByObstacle.get_obstacle_description();
		
		cout << "The path is blocked by " << currentLoc->get_pathways()[userInput]->get_obstacle_name_from_location() << ", What do you want to do? " << endl << endl;

		int choice = -1;

		while (choice < 0 || choice > 2) {
			cout << "[0] Use an item \n[1] Return to previous room \n[2] Get hint for obstacle" << endl;
			cin >> choice;
		}
		
		switch (choice) {
		case(0):	//Use an item
			if (player.get_inventory_size() < 1) {
				system("cls");
				cout << "You have no Items in your inventory, you turn back" << endl;
				return false;
			}
			choice = -1;

			while (choice < 0 || choice > player.get_inventory_size()) {
				player.output_all_items_in_inventory();
				cout << "Which item do you want to use?\n>>> ";
				cin >> choice;
			}
			if (currentLoc->get_pathways()[userInput]->pathBlockedByObstacle.get_obstacle_key() == player.get_item_name_from_inventory(choice)) {
				cout << currentLoc->get_pathways()[userInput]->pathBlockedByObstacle.get_obstacle_removed() << endl;
				currentLoc->get_pathways()[userInput]->set_location_unblocked();
				cout << "You move into the " << currentLoc->get_pathways()[userInput]->get_loc_description() << endl;
				return true;
			}
			break;

		case(1):	//return to previous room
			return false;
			break;

		case(2):	//get hint for obstacle
			cout << currentLoc->get_pathways()[userInput]->pathBlockedByObstacle.get_obstacle_hint() << endl;
			return false;
			break;

		default:
			return false;
		}
		
	}
	else {
		return true;
	}
	//if this doesnt work
	cout << "THE MOVE TO LOCATION METHOD DIDNT WORK!!!!!!!!" << endl;
	return false;
}