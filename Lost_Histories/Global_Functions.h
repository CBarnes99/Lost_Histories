#pragma once
#include <chrono>
#include <thread>
#include <string>

/**
*	@brief Clears invalid input from user, used after taken input and if that input was invalid
*/
void clear_invalid_input();

/**
*	@brief Stops the terminal for x amount of milliseconds
*	@param time The amount of milliseconds to stop the terminal, as an int
*/
void sleep(int time);

/**
*	@brief Outputs the string letter by letter similar to a typewriter
*	@param text The string you want to output letter by letter, as a String
*	@param moreTextAfterwards If true it wont endl after text output, if false it'll endl after text output, as a bool
*/
void letter_by_letter_output(std::string text, bool moreTextAfterwards);