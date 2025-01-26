#include "Item.h"

using namespace std;

Item::Item() {
	this->itemName = "iName";
	this->itemDescription = "iDesc";
	this->isDestroyed = false;
}

void Item::set_Item_Defaults(string iName, string iDesc) {
	this->itemName = iName;
	this->itemDescription = iDesc;
}

string Item::get_Item_Name() {
	return this->itemName;
}

string Item::get_Item_Description() {
	return this->itemDescription;
}
void Item::destroy_Item() {
	this->isDestroyed = true;
}
