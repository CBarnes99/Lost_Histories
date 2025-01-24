#include "Player.h"
#include <iostream>

using namespace std;

Player::Player() {
	this->playerName = "Default";
	this->playerInventory = {}; //ADD A RUSTY ROOM KEY TO INVENTRY THAT BREAKS ON USE TO GET OUT OF THE FIRST ROOM
	this->hasLight = false;
}

void Player::setPlayerName(string nName) {
	this->playerName = nName;
}

string Player::getPlayerName() {
	return playerName;
}

void Player::addItemToInventory(Item nItem) {
	playerInventory.push_back(nItem);
}

void Player::outputAllItemsInInventory() {
	for (int i = 0; i < this->playerInventory.size(); i++) {
		this->playerInventory[i];//ADD ITEM DESCRIPTIONS HERE-------------------------------------------------------
	}
	
}
void Player::setLight(bool hasLight) {
	this->hasLight = hasLight;
	if (this->hasLight == true) {
		cout << "You've lightend up the room" << endl;
	}
	else {
		cout << "The area has darkened" << endl;
	}
}