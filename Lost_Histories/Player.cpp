#include "Player.h"
#include <iostream>

using namespace std;

Player::Player() {
	this->playerName = "Default";
	this->playerInventory = {}; //ADD A RUSTY ROOM KEY TO INVENTRY THAT BREAKS ON USE TO GET OUT OF THE FIRST ROOM
	this->hasLight = false;
}

void Player::set_Player_Name(string nName) {
	this->playerName = nName;
}

string Player::get_Player_Name() {
	return playerName;
}

void Player::add_Item_To_Inventory(Item nItem) {
	playerInventory.push_back(nItem);
}

void Player::output_All_Items_In_Inventory() {
	for (int i = 0; i < this->playerInventory.size(); i++) {
		if (this->playerInventory[i].is_Item_Destroyed() == false) {
			this->playerInventory[i].get_Item_Description();
		}
	}
}

void Player::set_Light(bool hasLight) {
	this->hasLight = hasLight;
	if (this->hasLight == true) {
		cout << "You've lightend up the room" << endl;
	}
	else {
		cout << "The area has darkened" << endl;
	}
}
