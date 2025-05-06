#include "Global_Functions.h"
#include <iostream>



namespace Globals {
	void sleep(int time) {
		std::this_thread::sleep_for(std::chrono::milliseconds(time));
	}

	void letter_by_letter_output(std::string text, int amountOfEndl) {
		for (int i = 0; i < text.length(); i++) {
			std::cout << text.at(i);

			if (text.at(i) == ',' || text.at(i) == '.') {
				sleep(500);
			}
			else {
				sleep(20);
			}
		}
		for (int i = 0; i < amountOfEndl; i++) {
			std::cout << std::endl;
		}
	}

	void clear_invalid_input(bool clear) {
		if (std::cin.fail() || clear == true) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (clear != true) {
				std::cout << "Input the correct information." << std::endl;
			}
		}

	}

	void enter_to_continue() {
		std::string enterToContinue;
		if (std::cin.fail()) {
			clear_invalid_input(false);
		}
		std::cout << std::endl << "ENTER TO CONTINUE...";
		std::getline(std::cin, enterToContinue);
		system("cls");
	}
}

