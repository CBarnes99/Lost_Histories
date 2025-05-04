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

void Searchables::set_obstacle(Obstacle* sObstacle) {
	this->blockedByObstacle = sObstacle;
	this->isSearchablesBlocked = true;
	this->unblockedDescription = sObstacle->get_obstacle_removed_description();
}

void Searchables::set_opening_description(string sOpeningDescription) {
	this->searchablesNeedsOpening = true;
	this->searchablesOpeningDescription = sOpeningDescription;
}

void Searchables::set_searchables_not_blocked_by_obstacle() {
	this->isSearchablesBlocked = false;
}

void Searchables::get_item_from_searchables(Player& player) {
	Globals::letter_by_letter_output(this->searchablesOpeningDescription, 1);
	if (is_there_an_item() == true) {

		Globals::letter_by_letter_output("You see: ", 0);
		Globals::letter_by_letter_output(item.get_item_name(), 1);
		Globals::sleep(50);
		Globals::letter_by_letter_output("Do you want to pick it up? Y or N", 1);
		
		Globals::clear_invalid_input(false);
		string playerAnswerString;
		cin >> playerAnswerString;
		if (playerAnswerString == "y" || playerAnswerString == "Y") { //if user wants to pick up the item
			system("cls");

			Globals::letter_by_letter_output("You pick up the " + item.get_item_name() + ".", 2);
			player.add_item_to_inventory(item);
			set_item_taken();

		}
		else {
			//You decided not to pick up an item
			system("cls");
			Globals::letter_by_letter_output("You didn't pick up the ", 0);
			Globals::letter_by_letter_output(item.get_item_name(), 2);
		}

	}
	else {
		//If theres no item in the Searchables
		Globals::letter_by_letter_output("You don't see anthing else here.", 2);
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