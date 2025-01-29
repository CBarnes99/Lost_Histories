#include "Item.h"

using namespace std;

Item::Item(string nName, string nDesc, Obstacle linkedObs) {
	this->itemName = nName;
	this->itemDescription = nDesc;
	this->linkedObstacleForItem = linkedObs;
	this->isDestroyed = false;
	this->itemSearchLocationDescription = "iSearch";
}

<<<<<<< Updated upstream
string Item::getItemName() {
=======
void Item::set_Item_Defaults(string iName, string iDesc, string iSearch) {
	this->itemName = iName;
	this->itemDescription = iDesc;
	this->itemSearchLocationDescription = iSearch;
}

string Item::get_Item_Name() {
>>>>>>> Stashed changes
	return this->itemName;
}

string Item::getItemDescription() {
	return this->itemDescription;
}
void Item::destroyItem() {
	this->isDestroyed = true;
<<<<<<< Updated upstream
}
=======
}

string Item::get_Item_Search_Description() {
	return this->itemSearchLocationDescription;
}


bool Item::is_Item_Destroyed() {
	return this->isDestroyed;
}
>>>>>>> Stashed changes
