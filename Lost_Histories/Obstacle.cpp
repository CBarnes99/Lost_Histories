#include "Obstacle.h"

Obstacle::Obstacle() {
	this->obstacleName = "obsName";
	this->obstacleDescription = "obsDesc";
	this->obstcaleKey = "obsKey";
	this->obstacleHint = "obsHint";
	this->obstacleRemoved = "obsRemoved";
}

void Obstacle::set_obstacle_defualts(string obsName, string obsDesc, string obsKey, string obsHint, string obsRemoved) {
	this->obstacleName = obsName;
	this->obstacleDescription = obsDesc;
	this->obstcaleKey = obsKey;
	this->obstacleHint = obsHint;
	this->obstacleRemoved = obsRemoved;
}

string Obstacle::get_obstacle_name() {
	return obstacleName;
}

string Obstacle::get_obstacle_description() {
	return obstacleDescription;
}

string Obstacle::get_obstacle_hint() {
	return obstacleHint;
}

string Obstacle::get_obstacle_key() {
	return this->obstcaleKey;
}

string Obstacle::get_obstacle_removed() {
	return this->obstacleRemoved;
}
