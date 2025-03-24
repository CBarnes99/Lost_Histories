#include "Searchables.h"
#include "Global_Functions.h"
#include <iostream>

Searchables::Searchables() {
	this->searchablesName = "DefualtSearchablesName";
	this->item = Item();
	this->isThereAnItem = false;
	this->isSearchablesBlocked = false;
	this->blockedByObstacle = nullptr;
	this->unblockedDescription = "DefualtUnblockedDescription";
	this->searchablesNeedsOpening = false;
	this->searchablesOpeningDescription = "DefualtOpeningDescription";
}

void Searchables::set_searchables_name(string sName) {
	this->searchablesName = sName;
}

void Searchables::set_item(Item sItem) {
	this->item = sItem;
	this->isThereAnItem = true;
}

void Searchables::set_obstacle(Obstacle* sObstacle, string sUnblocked) {
	this->blockedByObstacle = sObstacle;
	this->isSearchablesBlocked = true;
	this->unblockedDescription = sUnblocked;
}

void Searchables::set_needs_opening(string sOpeningDescription) {
	this->searchablesNeedsOpening = true;
	this->searchablesOpeningDescription = sOpeningDescription;
}

void Searchables::set_searchables_not_blocked_by_obstacle() {
	this->isSearchablesBlocked = false;
}

void Searchables::get_item_from_searchables(Player& player) {
	letter_by_letter_output(this->searchablesOpeningDescription, false);
	if (is_there_an_item() == true) {

		cout << "You see: " << item.get_item_name();
		cout << endl << "Do you want to pick it up? Y or N" << endl;

		clear_invalid_input();
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
		//If theres no item in the Searchables
		cout << "You don't see anthing else here." << endl;
	}
}

bool Searchables::is_searchables_blocked_by_obstacle() {
	return this->isSearchablesBlocked;
}

string Searchables::get_searchables_name() {
	return this->searchablesName;
}

bool Searchables::is_there_an_item() {
	return this->isThereAnItem;
}

void Searchables::set_item_taken() {
	this->isThereAnItem = false;
}

Obstacle* Searchables::get_obstacle() {
	return this->blockedByObstacle;
}