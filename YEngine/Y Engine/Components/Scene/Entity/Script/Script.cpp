#include <iostream>

#include "Script.h"

Script::Script() {
	entity = NULL;
	removed = false;
}

Script::~Script() {

}

void Script::setEntity(Entity* entity) {
	this->entity = entity;
}

void Script::remove() {
	removed = true;
}

Entity* Script::getEntity() {
	return entity;
}

bool Script::isRemoved() {
	return removed;
}

void Script::onInitialize() {

}

void Script::onUpdate() {

}

void Script::onActivate() {

}

void Script::onDeactivate() {

}

void Script::onDestroy() {

}
