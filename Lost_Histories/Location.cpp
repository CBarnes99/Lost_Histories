#include "Location.h"
#include "Global_Functions.h"
#include <iostream>

using namespace std;

Location::Location(string lName, string lDesc, string lDistDesc) {	//constructor for the location object
	this->locName = lName;
	this->locDescription = lDesc;
	this->locDistantDescription = lDistDesc;
	
	this->isLight = false;
	this->locNoLightSearchDescription = "Its too dark to examine the area.";

	this->isObjectInArea = false;
	//this->locItems = Item();
	this->roomSearchDescription = "You examine the area but theres nothing of note in the vicinity.";

	this->isPathBlocked = false;
	this->pathBlockedByObstacle = nullptr;

	this->locObject = {};
	this->pathways = {};
}


string Location::get_loc_name() {
	return this->locName;
}

string Location::get_loc_description() {
	return this->locDescription;
}

string Location::get_not_lit_description() {
	return this->locNoLightSearchDescription;
}

string Location::get_loc_distant_description() {
	return this->locDistantDescription;
}

vector<Location*> Location::get_pathways() {
	return this->pathways;
}

void Location::add_pathway(Location& newPathway) {
	this->pathways.push_back(&newPathway);
}

void Location::set_light_in_area(bool light) {
	this->isLight = light;
}

void Location::set_object_in_location(Object& lObject) {
	this->isObjectInArea = true;
	this->locObject.push_back(&lObject);
	//this->locItems = lItem;
	//this->roomSearchDescription = this->locItems.get_item_search_description();
}

vector<Object*> Location::get_all_objects() {
	return this->locObject;
}

//void Location::set_item_no_longer_in_location() {
//	this->isObjectInArea = false;
//	this->roomSearchDescription = "You examine the area but theres nothing of note in the area.";
//	this->locNoLightSearchDescription = "Its too dark to examine the area. But you remember you've already searched this location before.";
//}

void Location::set_location_path_is_blocked_by(Obstacle& obs) {
	this->isPathBlocked = true;
	this->pathBlockedByObstacle = &obs;
}

string Location::get_obstacle_name_from_location() {
	//return this->pathBlockedByObstacle.get_obstacle_name();
	return this->pathBlockedByObstacle->get_obstacle_name();
}

void Location::set_location_unblocked() {
	this->isPathBlocked = false;
}

void Location::search_location(Player& player) {
	if (isLight == true) {	//check to see if theres light in the current location
		if (isObjectInArea == true) {	//check to see if theres an item in the current location
			cout << "In this area, you see: " << endl;
			int count = 0;
			for (count; count < this->locObject.size(); count++) {
				cout << "[" << count << "] " << this->locObject.at(count)->get_object_name() << endl;
			}
			cout << "[" << count << "] Return" << endl;
			cout << "Do you want to search an object? Select the number next to the object." << endl;
			int playerAnswerInt;
			cin >> playerAnswerInt;

			if (playerAnswerInt >= 0 && playerAnswerInt < count) {
				system("cls");
				if (this->locObject.at(playerAnswerInt)->is_object_blocked_by_obstacle() == false) {
					this->locObject.at(playerAnswerInt)->get_item_from_object(player);
					//cout << this->locObject.at(playerAnswerInt)->get_object_opening_description() << endl;
					//if (this->locObject.at(playerAnswerInt)->is_there_an_item() == true) {

					//	cout << "You see: " << this->locObject.at(playerAnswerInt)->get_item().get_item_name();
					//	cout << endl << "Do you want to pick it up? Y or N" << endl;

					//	string playerAnswerString;
					//	cin >> playerAnswerString;
					//	if (playerAnswerString == "y" || playerAnswerString == "Y") { //if user wants to pick up the item
					//		system("cls");

					//		cout << "You pick up the " << this->locObject.at(playerAnswerInt)->get_item().get_item_name() << endl;
					//		player.add_item_to_inventory(this->locObject.at(playerAnswerInt)->get_item());
					//		this->locObject.at(playerAnswerInt)->set_item_taken();

					//	}
					//	else {
					//		//You decided not to pick up an item
					//		system("cls");
					//		cout << "You didnt pick up the " << this->locObject.at(playerAnswerInt)->get_item().get_item_name() << endl;
					//	}

					//}
					//else {
					//	//If theres no item in the object
					//	cout << "You don't see anthing else here." << endl;
					//}

				}
				else {
					//The object is blocked by an obstacle
					cout << this->locObject.at(playerAnswerInt)->get_object_name() << " is blocked by " << this->locObject.at(playerAnswerInt)->get_obstacle()->get_obstacle_name() << endl;
					if (this->locObject.at(playerAnswerInt)->get_obstacle()->obstacle_choice(player) == true) {
						
						this->locObject.at(playerAnswerInt)->set_object_not_blocked_by_obstacle();
					
						cout << "You unlock the " << this->locObject.at(playerAnswerInt)->get_object_name() << endl;	//output the location moved into
						this->locObject.at(playerAnswerInt)->get_item_from_object(player);
					}
					else {


					}
				}
			}
			else {
				//if you didnt search the objects
				cout << "You didn't search the objects" << endl;
			}
		}
		else {	
			//if theres no item in the location, print defualt room search description
			cout << roomSearchDescription << endl;
		}
	}
	else {
		//if theres no item in the location, print defualt no light room search description
		cout << locNoLightSearchDescription << endl;
	}
}
//bool Location::move_to_location(Location* currentLoc, int userInput, Player& player) {
//	if (currentLoc->get_pathways()[userInput]->isPathBlocked == true) {	//if the pathway the user selected is blocked by an obstacle
//		
//		cout << "The path is blocked by " << currentLoc->get_pathways()[userInput]->get_obstacle_name_from_location() << ", What do you want to do? " << endl << endl;
//
//		int choice = -1;
//
//		while (choice < 0 || choice > 2) { //promt the user to either use an item, return to the previous room, or inspect the obstacle
//			cout << "[0] Use an item. \n[1] Return to previous room. \n[2] Inspect the obstacle." << endl;
//			cin >> choice;
//			while (cin.fail()) {	//checks for invalid input from the user
//				clear_invalid_input();
//				cout << "Wrong input" << endl;
//				cin >> choice;
//				
//			}
//			if (choice < 0 || choice > 2) {
//				system("cls");
//				cout << "Wrong Input" << endl;
//			}
//		}
//		
//		switch (choice) {
//		case(0):	//Use an item
//			if (player.get_inventory_size() < 1) {	//if the player has no items in their inventory
//				system("cls");
//				cout << "You have no items in your inventory, you turn back" << endl;
//				return false;
//			}
//			choice = -1;
//
//			while (choice < 0 || choice > player.get_inventory_size()) { //if there is items in their inventory, output all the items ( size is 1+ than items in inventory, 1+ will be to back out of inventory)
//				player.output_all_items_in_inventory();
//				cout << "[" << player.get_inventory_size() << "] Turn Back." << endl;
//				cout << "Which item do you want to use?\n>>> ";
//				cin >> choice;
//			}
//			if (choice < player.get_inventory_size()) { // if selected an item
//				//if item selected is the item required to unblock the obstacle in the way
//				if (currentLoc->get_pathways()[userInput]->pathBlockedByObstacle->get_obstacle_key() == player.get_item_from_inventory().at(choice)->get_item_name()) {	//if the item is the same item that is required to remove the and move into the room
//					system("cls");
//					cout << currentLoc->get_pathways()[userInput]->pathBlockedByObstacle->get_obstacle_removed_description() << endl; //prints to the console the obstacle removed
//					currentLoc->get_pathways()[userInput]->set_location_unblocked();	//sets location as unblocked so user can freely moved between locations
//
//					player.get_item_from_inventory().at(choice)->reduce_item_durability();	//reduce the item used durability
//					if (player.get_item_from_inventory().at(choice)->is_item_destroyed() == true) {	//if durability reaches 0, remove item from inventory
//						player.remove_item_from_inventory(choice);
//					}
//
//					cout << "You move into the " << currentLoc->get_pathways()[userInput]->get_loc_name() << endl;	//output the location moved into
//					return true;
//				}
//				//if the wrong item was chosen
//				else {
//					system("cls");
//					cout << player.get_item_from_inventory().at(choice)->get_item_name() << " has no effect on " << currentLoc->get_pathways()[userInput]->pathBlockedByObstacle->get_obstacle_name() << endl;
//					cout << "You turn back." << endl;
//					return false;
//				}
//				break;
//			}
//
//		case(1):	//return to previous room
//			system("cls");
//			cout << "You turn back." << endl;
//			return false;
//			break;
//
//		case(2):	//get the description for  the obstacle
//			system("cls");
//			cout << currentLoc->get_pathways()[userInput]->pathBlockedByObstacle->get_obstacle_description() << endl;
//			return false;
//			break;
//
//		default:
//			return false;
//		}
//		
//	}
//	else {
//		return true;
//	}
//	//if this doesnt work
//	cout << "THE MOVE TO LOCATION METHOD DIDNT WORK!!!!!!!!" << endl;
//	return false;
//}



bool Location::is_Loc_Accessible(Player& player)
{
	if (isPathBlocked == true) {	//if the pathway the user selected is blocked by an obstacle

		cout << "The path is blocked by " << get_obstacle_name_from_location() << ", What do you want to do? " << endl << endl;
		if (this->pathBlockedByObstacle->obstacle_choice(player) == true) {

			set_location_unblocked();	//sets location as unblocked so user can freely moved between locations
			cout << "You move into the " << get_loc_name() << endl;	//output the location moved into

			return true;
		}
		else {

			return false;
		}
		//cout << "The path is blocked by " << get_obstacle_name_from_location() << ", What do you want to do? " << endl << endl;

		//int choice = -1;

		//while (choice < 0 || choice > 2) { //promt the user to either use an item, return to the previous room, or inspect the obstacle
		//	cout << "[0] Use an item. \n[1] Return to previous room. \n[2] Inspect the obstacle." << endl;
		//	cin >> choice;
		//	while (cin.fail()) {	//checks for invalid input from the user
		//		clear_invalid_input();
		//		cout << "Wrong input" << endl;
		//		cin >> choice;

		//	}
		//	if (choice < 0 || choice > 2) {
		//		system("cls");
		//		cout << "Wrong Input" << endl;
		//	}
		//}

		//switch (choice) {
		//case(0):	//Use an item
		//	if (player.get_inventory_size() < 1) {	//if the player has no items in their inventory
		//		system("cls");
		//		cout << "You have no items in your inventory, you turn back" << endl;
		//		return false;
		//	}
		//	choice = -1;

		//	while (choice < 0 || choice > player.get_inventory_size()) { //if there is items in their inventory, output all the items ( size is 1+ than items in inventory, 1+ will be to back out of inventory)
		//		player.output_all_items_in_inventory();
		//		cout << "[" << player.get_inventory_size() << "] Turn Back." << endl;
		//		cout << "Which item do you want to use?\n>>> ";
		//		cin >> choice;
		//	}
		//	if (choice < player.get_inventory_size()) { // if selected an item
		//		//if item selected is the item required to unblock the obstacle in the way
		//		if (pathBlockedByObstacle->get_obstacle_key() == player.get_item_from_inventory().at(choice)->get_item_name()) {	//if the item is the same item that is required to remove the and move into the room
		//			system("cls");
		//			cout << pathBlockedByObstacle->get_obstacle_removed_description() << endl; //prints to the console the obstacle removed
		//			set_location_unblocked();	//sets location as unblocked so user can freely moved between locations

		//			player.get_item_from_inventory().at(choice)->reduce_item_durability();	//reduce the item used durability
		//			if (player.get_item_from_inventory().at(choice)->is_item_destroyed() == true) {	//if durability reaches 0, remove item from inventory
		//				player.remove_item_from_inventory(choice);
		//			}

		//			cout << "You move into the " << get_loc_name() << endl;	//output the location moved into
		//			return true;
		//		}
		//		//if the wrong item was chosen
		//		else {
		//			system("cls");
		//			cout << player.get_item_from_inventory().at(choice)->get_item_name() << " has no effect on " << pathBlockedByObstacle->get_obstacle_name() << endl;
		//			cout << "You turn back." << endl;
		//			return false;
		//		}
		//		break;
		//	}

		//case(1):	//return to previous room
		//	system("cls");
		//	cout << "You turn back." << endl;
		//	return false;
		//	break;

		//case(2):	//get the description for  the obstacle
		//	system("cls");
		//	letter_by_letter_output(pathBlockedByObstacle->get_obstacle_description());
		//	//cout << pathBlockedByObstacle->get_obstacle_description() << endl;
		//	return false;
		//	break;

		//default:
		//	return false;
		//}

	}
	else {
		return true;
	}
	//if this doesnt work
	cout << "THE MOVE TO LOCATION METHOD DIDNT WORK!!!!!!!!" << endl;
	return false;
}
