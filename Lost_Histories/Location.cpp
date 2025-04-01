#include "Location.h"
#include "Global_Functions.h"
#include <iostream>

using namespace std;

Location::Location(string lName, string lDesc, string lInspectDesc) {	//constructor for the location object
	this->locName = lName;
	this->locDescription = lDesc;
	this->locInspectLocation = lInspectDesc;


	this->isSearchablesInArea = false;
	this->roomSearchDescription = "You examine the area but theres nothing of note in the vicinity.";

	this->isPathBlocked = false;
	this->pathBlockedByObstacle = nullptr;

	this->locSearchables = {};
	this->pathways = {};
}


string Location::get_loc_name() {
	return this->locName;
}

string Location::get_loc_description() {
	return this->locDescription;
}

string Location::get_loc_inspect_location() {
	return this->locInspectLocation;
}

vector<Location*> Location::get_pathways() {
	return this->pathways;
}

void Location::set_pathway(Location& newPathway) {
	this->pathways.push_back(&newPathway);
}

void Location::set_searchables_in_location(Searchables& lSearchables) {
	this->isSearchablesInArea = true;
	this->locSearchables.push_back(&lSearchables);
}

vector<Searchables*> Location::get_all_searchables() {
	return this->locSearchables;
}

void Location::set_location_path_is_blocked_by(Obstacle& obs) {
	this->isPathBlocked = true;
	this->pathBlockedByObstacle = &obs;
}

string Location::get_obstacle_name_from_location() {
	return this->pathBlockedByObstacle->get_obstacle_name();
}

void Location::set_location_unblocked() {
	this->isPathBlocked = false;
}

void Location::search_location(Player& player) {
if (isSearchablesInArea == true) {	//check to see if theres an item in the current location
	cout << "In this area, you see: " << endl;
	int count = 0;
	for (count; count < this->locSearchables.size(); count++) {
		cout << "[" << count << "] " << this->locSearchables.at(count)->get_searchables_name() << endl;
	}
	cout << endl << "[" << count << "] Return" << endl;

	int playerAnswerInt;
	clear_invalid_input();
	cin >> playerAnswerInt;

	if (playerAnswerInt >= 0 && playerAnswerInt < count) {
		system("cls");
		if (this->locSearchables.at(playerAnswerInt)->is_searchables_blocked_by_obstacle() == false) {
			this->locSearchables.at(playerAnswerInt)->get_item_from_searchables(player);
		}

		else {
			//The object is blocked by an obstacle
			cout << this->locSearchables.at(playerAnswerInt)->get_searchables_name() << " is blocked by " << this->locSearchables.at(playerAnswerInt)->get_obstacle()->get_obstacle_name() << endl;
			if (this->locSearchables.at(playerAnswerInt)->get_obstacle()->obstacle_choice(player) == true) {
					
				this->locSearchables.at(playerAnswerInt)->set_searchables_not_blocked_by_obstacle();
					
				cout << "You unlock the " << this->locSearchables.at(playerAnswerInt)->get_searchables_name() << endl;	//output the location moved into
				this->locSearchables.at(playerAnswerInt)->get_item_from_searchables(player);
			}
			else {


			}
		}
	}
	else {
		//if you didnt search the Searchables
		cout << "You didn't search the Searchables" << endl;
	}
}
else {	
	//if theres no item in the location, print defualt room search description
	cout << roomSearchDescription << endl;
	}
}

bool Location::is_loc_accessible(Player& player)
{
	if (isPathBlocked == true) {	//if the pathway the user selected is blocked by an obstacle

		letter_by_letter_output("The path is blocked by ", 0);
		letter_by_letter_output(get_obstacle_name_from_location(), 0);
		letter_by_letter_output(", What do you want to do?", 2);

		if (this->pathBlockedByObstacle->obstacle_choice(player) == true) {

			set_location_unblocked();	//sets location as unblocked so user can freely moved between locations

			letter_by_letter_output("You move into -- ", 0);
			letter_by_letter_output(get_loc_name(), 2);
			
			return true;
		}
		else {
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
