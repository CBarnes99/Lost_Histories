#include "Player.h"
#include <iostream>

using namespace std;

Player::Player() {
	this->playerName = "Default";
	this->playerInventory = {}; //ADD A RUSTY ROOM KEY TO INVENTRY THAT BREAKS ON USE TO GET OUT OF THE FIRST ROOM
	this->hasLight = false;
}

void Player::set_player_name(string nName) {
	this->playerName = nName;
}

string Player::get_player_name() {
	return playerName;
}

void Player::add_item_to_inventory(Item nItem) {
	playerInventory.push_back(nItem);
}

void Player::output_all_items_in_inventory() {
	if (this->playerInventory.size() < 1) {
		cout << "You have no items in your inventory" << endl;
	}
	else {
		for (int i = 0; i < this->playerInventory.size(); i++) {
			if (this->playerInventory[i].is_item_destroyed() == false) {
				cout << "[" << i << "] " << this->playerInventory[i].get_item_description() << endl;
			}
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

string Player::get_item_name_from_inventory(int index) {
	return playerInventory[index].get_item_name();
}
