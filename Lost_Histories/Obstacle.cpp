#include "Obstacle.h"

using namespace std;

Obstacle::Obstacle(string obsName, string obsDesc, string obsHint) {
	this->obstacleName = obsName;
	this->obstacleDescription = obsDesc;
	//this->obstcaleKey = Item();
	this->obstacleHint = obsHint;
}

string Obstacle::get_Obstacle_Name() {
	return obstacleName;
}

string Obstacle::get_Obstacle_Description() {
	return obstacleDescription;
}

string Obstacle::get_Obstacle_Hint() {
	return obstacleHint;
}
