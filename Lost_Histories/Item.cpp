#include "Item.h"

using namespace std;

Item::Item() {
	this->itemName = "iName";
	this->itemDescription = "iDesc";
	this->isDestroyed = false;
}


void Item::set_item_defaults(string iName, string iDesc, string iSearch) {
	this->itemName = iName;
	this->itemDescription = iDesc;
	this->itemSearchLocationDescription = iSearch;
}

string Item::get_item_name() {
	return this->itemName;
}

string Item::get_item_description() {
	return this->itemDescription;
}

void Item::destroy_item() {
	this->isDestroyed = true;
}

string Item::get_item_search_description() {
	return this->itemSearchLocationDescription;
}

bool Item::is_item_destroyed() {
	return this->isDestroyed;
}
