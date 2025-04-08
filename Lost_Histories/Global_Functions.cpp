#include "Global_Functions.h"
#include <iostream>


void Globals::sleep(int time) {
	std::this_thread::sleep_for(std::chrono::milliseconds(time));
}

void Globals::letter_by_letter_output(std::string text, int amountOfEndl) {
	for (int i = 0; i < text.length(); i++) {
		std::cout << text.at(i);

		if (text.at(i) == ',' || text.at(i) == '.' && i != text.length() -1) {
			sleep(500);
		}
		else {
			sleep(25);
		}
	}
	for (int i = 0; i < amountOfEndl; i++) {
		std::cout << std::endl;
	}
}

void Globals::clear_invalid_input() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Globals::enter_to_continue() {
	std::string enterToContinue;
	clear_invalid_input();
	std::cout << "ENTER TO CONTINUE...";
	std::getline(std::cin, enterToContinue);
	system("cls");
}
