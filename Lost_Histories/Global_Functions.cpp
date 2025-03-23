#include "Global_Functions.h"
#include <iostream>

using namespace std;

void clear_invalid_input() {	//clears invalid input by the user to avoid endless loops
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void sleep(int time) {
	this_thread::sleep_for(chrono::milliseconds(time));
}

void letter_by_letter_output(string text, bool moreTextAfterwards) {
	for (int i = 0; i < text.length(); i++) {
		cout << text.at(i);
		sleep(25);
	}
	if (moreTextAfterwards == false) {
		cout << endl << endl;
	}
	
}