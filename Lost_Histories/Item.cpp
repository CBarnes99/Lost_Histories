#include "Item.h"
#include <iostream>
#include "Global_Functions.h"

Item::Item() {
	this->itemName = "iName";
	this->itemDescription = "iDesc";
	this->isDestroyed = false;
	this->itemDurability = 1;
	this->itemDestroyedText = "iDest";
}


void Item::set_item_defaults(std::string iName, std::string iDesc, int iUses) {
	this->itemName = iName;
	this->itemDescription = iDesc;
	this->itemDurability = iUses;
}

std::string Item::get_item_name() {
	return this->itemName;
}

std::string Item::get_item_description() {
	return this->itemDescription;
}

void Item::reduce_item_durability() {
	this->itemDurability--;
	if (this->itemDurability < 1) {
		Globals::letter_by_letter_output(this->itemDestroyedText, 2);
		this->isDestroyed = true;
	}
}

bool Item::is_item_destroyed() {
	return this->isDestroyed;
}

void Item::set_item_destroyed_text(std::string text) {
	this->itemDestroyedText = text;
}
