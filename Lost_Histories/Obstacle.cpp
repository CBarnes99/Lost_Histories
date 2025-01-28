#include "Obstacle.h"

using namespace std;

Obstacle::Obstacle(string obsName, string obsDesc, string obsKeyName, string obsHint) {
	this->obstacleName = obsName;
	this->obstacleDescription = obsDesc;
	this->obstacleKeyName = obsKeyName;
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

void Obstacle::set_Obstacle_Key_Name(Item itemKey) {
	this->obstacleKeyName = itemKey.get_Item_Name();
}