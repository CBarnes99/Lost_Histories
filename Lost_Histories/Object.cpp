#include "Object.h"


Object::Object() {
	this->objectName = "DefualtObjectName";
	this->item = Item();
	this->isObjectBlocked = false;
	this->blockedByObstacle = nullptr;
	this->unblockedDescription = "DefualtUnblockedDescription";
	this->objectNeedsOpening = false;
	this->objectOpeningDescription = "DefualtObjectOpeningDescription";
}

void Object::set_object_name(string oName) {
	this->objectName = oName;
}

void Object::set_item(Item oItem) {
	this->item = oItem;
}

void Object::set_obstacle(Obstacle* oObstacle, string oUnblocked) {
	this->blockedByObstacle = oObstacle;
	this->unblockedDescription = oUnblocked;
}

void Object::set_needs_opening(string oOpeningDescription) {
	this->objectNeedsOpening = true;
	this->objectOpeningDescription = oOpeningDescription;
}

string Object::get_object_name() {
	return this->objectName;
}

Item& Object::get_item() {
	return this->item;
}

Obstacle* Object::get_obstacle() {
	return this->blockedByObstacle;
}

string Object::get_object_opening_description() {
	return this->objectOpeningDescription;
}