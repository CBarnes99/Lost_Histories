#include "Object.h"
#include "Global_Functions.h"
#include <iostream>

Object::Object() {
	this->objectName = "DefualtObjectName";
	this->item = Item();
	this->isThereAnItem = false;
	this->isObjectBlocked = false;
	this->blockedByObstacle = nullptr;
	this->unblockedDescription = "DefualtUnblockedDescription";
	this->objectNeedsOpening = false;
	this->objectOpeningDescription = "DefualtOpeningDescription";
}

void Object::set_object_name(string oName) {
	this->objectName = oName;
}

void Object::set_item(Item oItem) {
	this->item = oItem;
	this->isThereAnItem = true;
}

void Object::set_obstacle(Obstacle* oObstacle, string oUnblocked) {
	this->blockedByObstacle = oObstacle;
	this->isObjectBlocked = true;
	this->unblockedDescription = oUnblocked;
}

void Object::set_needs_opening(string oOpeningDescription) {
	this->objectNeedsOpening = true;
	this->objectOpeningDescription = oOpeningDescription;
}

void Object::set_object_not_blocked_by_obstacle() {
	this->isObjectBlocked = false;
}

void Object::get_item_from_object(Player& player) {
	letter_by_letter_output(get_object_opening_description(), false);
	if (is_there_an_item() == true) {

		cout << "You see: " << item.get_item_name();
		cout << endl << "Do you want to pick it up? Y or N" << endl;

		string playerAnswerString;
		cin >> playerAnswerString;
		if (playerAnswerString == "y" || playerAnswerString == "Y") { //if user wants to pick up the item
			system("cls");

			cout << "You pick up the " << item.get_item_name() << endl;
			player.add_item_to_inventory(item);
			set_item_taken();

		}
		else {
			//You decided not to pick up an item
			system("cls");
			cout << "You didnt pick up the " << item.get_item_name() << endl;
		}

	}
	else {
		//If theres no item in the object
		cout << "You don't see anthing else here." << endl;
	}
}

bool Object::is_object_blocked_by_obstacle() {
	return this->isObjectBlocked;
}

string Object::get_object_name() {
	return this->objectName;
}

Item& Object::get_item() {
	return this->item;
}

bool Object::is_there_an_item() {
	return this->isThereAnItem;
}

void Object::set_item_taken() {
	this->isThereAnItem = false;
}

Obstacle* Object::get_obstacle() {
	return this->blockedByObstacle;
}

string Object::get_object_opening_description() {
	return this->objectOpeningDescription;
}