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

void Player::add_item_to_inventory(Item& nItem) {
	playerInventory.push_back(&nItem);
}

void Player::output_all_items_in_inventory(bool usingItem) {
	if (this->playerInventory.size() < 1) {
		cout << "You have no items in your inventory" << endl;
	}
	else {
		int itemCount = 0;
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