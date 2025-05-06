#include "Player.h"
#include <iostream>
#include "Global_Functions.h"

Player::Player(std::string name) : Character(name) {
	this->playerInventory = {};
}

void Player::set_player_name(std::string pName) {
	this->charactersName = pName;
}

void Player::add_item_to_inventory(Item& nItem) {
	playerInventory.push_back(&nItem);
}

void Player::output_all_items_in_inventory(bool usingItem) {
	if (this->playerInventory.size() < 1) {
		
		std::cout << "You have no items in your inventory" << std::endl << std::endl;
	}
	else {

		std::cout << std::endl << "You open your inventory, you have:" << std::endl;

		if (usingItem == true) {
			for (int i = 0; i < this->playerInventory.size(); i++) {
				std::cout << "[" << i << "] " << this->playerInventory.at(i)->get_item_name() << std::endl;
			}
			std::cout << std::endl;
		}
		else {
			for (int i = 0; i < this->playerInventory.size(); i++) {
				std::cout << this->playerInventory.at(i)->get_item_name() << std::endl;
			}
			
			std::cout << std::endl << "[0] Inspect an Item." << std::endl;
			std::cout << "[1] Return." << std::endl;
			
			int choice = -1;
			Globals::clear_invalid_input(false);
			std::cin >> choice;

			if (choice == 0) {
				system("cls");
				for (int i = 0; i < this->playerInventory.size(); i++) {
					std::cout << "[" << i << "] " << this->playerInventory.at(i)->get_item_name() << std::endl;
				}

				choice = -1;
				std::cin >> choice;
				while (std::cin.fail()) { //check for input that is not a number
					std::cout << "Input a number" << std::endl;
					Globals::clear_invalid_input(false);
					std::cin >> choice;
					while (choice < 0 || choice > this->playerInventory.size()) {  //checks for wrong input
						std::cout << "Wrong input, try again!" << '\n' << ">>>";
						Globals::clear_invalid_input(false);
						std::cin >> choice;
					}
				}
				Globals::letter_by_letter_output(this->playerInventory.at(choice)->get_item_description(), 2);
				Globals::sleep(1000);
				system("cls");
			}
		}
	}
}

size_t Player::get_inventory_size() {
	return this->playerInventory.size();
}

std::vector<Item*> Player::get_item_from_inventory() {
	return playerInventory;
}

void Player::remove_item_from_inventory(int index) {
	this->playerInventory.erase(this->playerInventory.begin() + index);
}
