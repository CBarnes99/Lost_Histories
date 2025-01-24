#include "Item.h"

using namespace std;

Item::Item(string nName, string nDesc, Obstacle linkedObs) {
	this->itemName = nName;
	this->itemDescription = nDesc;
	this->linkedObstacleForItem = linkedObs;
	this->isDestroyed = false;
}

string Item::getItemName() {
	return this->itemName;
}

string Item::getItemDescription() {
	return this->itemDescription;
}
void Item::destroyItem() {
	this->isDestroyed = true;
}