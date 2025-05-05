#include "Obstacle.h"
#include "Global_Functions.h"
#include <iostream>

using namespace std;

Obstacle::Obstacle() {	//defualt constructor for the obstacle object
	this->obstacleName = "obsName";
	this->obstacleInteract = "obsInteract";
	this->obstacleInspect = "obsInspect";
	this->obstcaleKey = "obsKey";
	this->obstacleRemoved = "obsRemoved";
}

void Obstacle::set_obstacle_defualts(string obsName, string obsInteract, string obsInspect, string obsKey, string obsRemoved) {
	this->obstacleName = obsName;
	this->obstacleInteract = obsInteract;
	this->obstacleInspect = obsInspect;
	this->obstcaleKey = obsKey;
	this->obstacleRemoved = obsRemoved;
}

string Obstacle::get_obstacle_name() {
	this->obstacleName;
}

string Obstacle::get_obstacle_interact() {
	return obstacleInteract;
}

string Obstacle::get_obstacle_description() {
	return obstacleInspect;
}

string Obstacle::get_obstacle_key() {
	return this->obstcaleKey;
}

string Obstacle::get_obstacle_removed_description() {
	return this->obstacleRemoved;
}

bool Obstacle::obstacle_choice(Player& player)
{
	int choice = -1;

	while (choice < 0 || choice > 2) { //promt the user to either use an item, return to the previous room, or inspect the obstacle
		cout << "[0] Use an item. \n[1] Return to previous room. \n[2] Inspect the obstacle." << endl;
		Globals::clear_invalid_input(false);
		cin >> choice;
		while (cin.fail()) {	//checks for invalid input from the user
			Globals::clear_invalid_input(false);
			cout << "Wrong input" << endl;
			cin >> choice;

		}
		if (choice < 0 || choice > 2) {
			system("cls");
			cout << "Wrong Input" << endl;
		}
	}
	switch (choice) {
	case(0):	//Use an item
		if (player.get_inventory_size() < 1) {	//if the player has no items in their inventory
			system("cls");
			Globals::letter_by_letter_output("You have no items in your inventory, you turn back.", 2);
			return false;
		}
		choice = -1;

		while (choice < 0 || choice > player.get_inventory_size()) { //if there is items in their inventory, output all the items ( size is 1+ than items in inventory, 1+ will be to back out of inventory)
			player.output_all_items_in_inventory(true);
			cout << "[" << player.get_inventory_size() << "] Turn Back." << endl;
			Globals::letter_by_letter_output("Which item do you want to use?", 1);
			Globals::clear_invalid_input(false);
			cin >> choice;
		}
		if (choice < player.get_inventory_size()) { // if selected an item
			//if item selected is the item required to unblock the obstacle in the way
			if (this->get_obstacle_key() == player.get_item_from_inventory().at(choice)->get_item_name()) {	//if the item is the same item that is required to remove the and move into the room
				system("cls");
				Globals::letter_by_letter_output(this->get_obstacle_removed_description(), 2); //prints to the console the obstacle removed
				
				player.get_item_from_inventory().at(choice)->reduce_item_durability();	//reduce the item used durability
				if (player.get_item_from_inventory().at(choice)->is_item_destroyed() == true) {	//if durability reaches 0, remove item from inventory
					player.remove_item_from_inventory(choice);
				}

				
				return true;
			}
			//if the wrong item was chosen
			else {
				system("cls");
				Globals::letter_by_letter_output(player.get_item_from_inventory().at(choice)->get_item_name() + " has no effect on " + this->get_obstacle_interact(), 2);
				Globals::sleep(500);
				Globals::letter_by_letter_output("You turn back.", 2);
				Globals::sleep(500);

				return false;
			}
			break;
		}

	case(1):	//return to previous room
		system("cls");
		Globals::letter_by_letter_output("You turn back.", 2);
		return false;
		break;

	case(2):	//get the description for  the obstacle
		system("cls");
		Globals::letter_by_letter_output(get_obstacle_description(), 2);
		return false;
		break;

	default:
		return false;
	}


	cout << "OBSTACLE CHOICE DIDNT WORK!!!!!!!!" << endl;
	return false;
}
