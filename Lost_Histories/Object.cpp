#include "Object.h"


Object::Object() {
	this->objectName = "DefualtObjectName";
	this->item = nullptr;
	this->isObjectBlocked = false;
	this->blockedByObstacle = nullptr;
	this->unblockedDescription = "DefualtUnblockedDescription";
	this->objectNeedsOpening = false;
	this->objectOpeningDescription = "DefualtObjectOpeningDescription";
}

void Object::set_object_name(string oName) {
	this->objectName = oName;
}

void Object::set_item(Item* oItem) {
	this->item = oItem;
}

void set_obstacle(Obstacle* oObstacle, string oUnblocked);

void set_needs_opening(string oOpeningDescription);

string get_object_name();

Item* get_item();

Obstacle* get_obstacle();

string get_object_opening_description();