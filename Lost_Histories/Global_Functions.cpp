#include "Global_Functions.h"
#include <iostream>

using namespace std;

void clear_invalid_input() {	//clears invalid input by the user to avoid endless loops
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}