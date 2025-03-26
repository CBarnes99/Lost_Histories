#include "Player.h"
#include <iostream>
#include "Global_Functions.h"

using namespace std;

Player::Player() {
	this->playerName = "Default";
	this->playerInventory = {};
	this->hasLight = false;
}

void Player::set_player_name(string nName) {
	this->playerName = nName;
}

string Player::get_player_name() {
	return playerName;
}

void Player::add_item_to_inventory(Item& nItem) {
	playerInventory.push_back(&nItem);
}

void Player::output_all_items_in_inventory(bool usingItem) {
	if (this->playerInventory.size() < 1) {
		
		cout << "You have no items in your inventory" << endl;
	}
	else {
		cout << "You open your inventory, you have:" << endl;
		if (usingItem == true) {
			for (int i = 0; i < this->playerInventory.size(); i++) {
				cout << "[" << i << "] " << this->playerInventory.at(i)->get_item_name() << endl;
			}
			cout << endl;
		}
		else {
			for (int i = 0; i < this->playerInventory.size(); i++) {
				cout << this->playerInventory.at(i)->get_item_name() << endl;
				cout << endl << "[0] Inspect an Item." << endl;
				cout << "[1] Return." << endl;

				int choice = -1;
				clear_invalid_input();
				cin >> choice;

				if (choice == 0) {
					system("cls");
					for (int i = 0; i < this->playerInventory.size(); i++) {
						cout << "[" << i << "] " << this->playerInventory.at(i)->get_item_name() << endl;
					}

					choice = -1;
					cin >> choice;
					while (cin.fail()) { //check for input that is not a number
						cout << "Input a number" << endl;
						clear_invalid_input();
						cin >> choice;
						while (choice < 0 || choice > this->playerInventory.size()) {  //checks for wrong input
							cout << "Wrong input, try again!" << '\n' << ">>>";
							clear_invalid_input();
							cin >> choice;
						}
					}

					letter_by_letter_output(this->playerInventory.at(choice)->get_item_description(), 2);


				}

			}
			cout << endl;
		}
		
	}
}

void Player::set_light(bool hasLight) {
	this->hasLight = hasLight;
	if (this->hasLight == true) {
		cout << "You've lightend up the room" << endl;
	}
	else {
		cout << "The area has darkened" << endl;
	}
}

size_t Player::get_inventory_size() {
	return this->playerInventory.size();
}

vector<Item*> Player::get_item_from_inventory() {
	return playerInventory;
}

void Player::remove_item_from_inventory(int index) {
	this->playerInventory.erase(this->playerInventory.begin() + index);
}
