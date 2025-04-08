#include "Global_Functions.h"
#include <iostream>


void Globals::sleep(int time) {
	std::this_thread::sleep_for(std::chrono::milliseconds(time));
}

void Globals::letter_by_letter_output(std::string text, int amountOfEndl) {
	for (int i = 0; i < text.length(); i++) {
		std::cout << text.at(i);
		sleep(25);
	}
	for (int i = 0; i < amountOfEndl; i++) {
		std::cout << std::endl;
	}
}

void Globals::clear_invalid_input() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
