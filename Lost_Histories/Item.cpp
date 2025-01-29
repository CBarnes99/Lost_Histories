#include "Item.h"

using namespace std;

Item::Item() {
	this->itemName = "iName";
	this->itemDescription = "iDesc";
	this->isDestroyed = false;
}


void Item::set_Item_Defaults(string iName, string iDesc, string iSearch) {
	this->itemName = iName;
	this->itemDescription = iDesc;
	this->itemSearchLocationDescription = iSearch;
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

string Item::get_Item_Search_Description() {
	return this->itemSearchLocationDescription;
}

bool Item::is_Item_Destroyed() {
	return this->isDestroyed;
}
