#include "Player.h"
#include <iostream>

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

void Player::add_item_to_inventory(Item nItem) {
	playerInventory.push_back(nItem);
}

void Player::output_all_items_in_inventory() {
	if (this->playerInventory.size() < 1) {
		cout << "You have no items in your inventory" << endl;
	}
	else {
		int itemCount = 0;
		cout << "You open your inventory, you have:" << endl;
		for (int i = 0; i < this->playerInventory.size(); i++) {
			if (this->playerInventory[i].is_item_destroyed() == false) {
				cout << "[" << itemCount << "]	" << this->playerInventory[i].get_item_description() << endl;
				itemCount++;
			}
		}
		cout << endl;
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

Item Player::get_item_from_inventory(int index) {
	return this->playerInventory[index];
}

void Player::reduce_item_durability(Item&& item, int index) {
	item.reduce_item_durability();
	if (item.is_item_destroyed() == true) {
		cout << item.get_item_name() << " has broken and can no longer be used." << endl;
		this->playerInventory.erase(this->playerInventory.begin() + index);
	}
}

void Player::remove_item_from_inventory(int index) {
	this->playerInventory.erase(this->playerInventory.begin() + index);
}