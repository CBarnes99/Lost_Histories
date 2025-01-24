#include "Obstacle.h"

Obstacle::Obstacle(string obsName, string obsDesc, Item obsKey, string obsHint) {
	this->obstacleName = obsName;
	this->obstacleDescription = obsDesc;
	this->obstcaleKey = obsKey;
	this->obstacleHint = obsHint;
}

string Obstacle::getObstacleName() {
	return obstacleName;
}

string Obstacle::getObstacleDescription() {
	return obstacleDescription;
}

string Obstacle::getObstacleHint() {
	return obstacleHint;
}