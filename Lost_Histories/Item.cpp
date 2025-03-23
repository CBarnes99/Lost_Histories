#include "Item.h"
#include <iostream>
#include "Global_Functions.h"
using namespace std;

Item::Item() {
	this->itemName = "iName";
	this->itemDescription = "iDesc";
	this->isDestroyed = false;
	this->itemDurability = 1;
}


void Item::set_item_defaults(string iName, string iDesc, int iUses) {
	this->itemName = iName;
	this->itemDescription = iDesc;
	this->itemDurability = iUses;
}

string Item::get_item_name() {
	return this->itemName;
}

string Item::get_item_description() {
	return this->itemDescription;
}

void Item::reduce_item_durability() {
	this->itemDurability--;
	//cout << this->itemDurability << endl;
	if (this->itemDurability < 1) {
		letter_by_letter_output(this->itemName, true);
		letter_by_letter_output(" has broken after being used", false);
		this->isDestroyed = true;
	}
}

//string Item::get_item_search_description() {
//	return this->itemSearchLocationDescription;
//}

bool Item::is_item_destroyed() {
	return this->isDestroyed;
}
