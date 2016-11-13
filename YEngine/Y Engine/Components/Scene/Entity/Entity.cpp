#include <iostream>
#include <vector>

#include "../../../Engine/Engine.h"
#include "Entity.h"

Entity::Entity() {

	engine = NULL;

	initialized = false;
	active = true;
	destroyed = false;

	children = std::vector<Entity*>();
}

Entity::~Entity() {

}

void Entity::initialize(Engine* engine) {

	if(initialized)
		return;

	initialized = true;
	this->engine = engine;

	onInitialize();

	for(unsigned int i = 0; i < children.size(); i++) {
		children.at(i)->initialize(engine);
	}
}

void Entity::update() {

	if(!active || destroyed)
		return;

	onUpdate();

	for(unsigned int i = 0; i < children.size(); i++) {

		children.at(i)->update();

		if(children.at(i)->isDestroyed()) {
			children.erase(children.begin() + i);
			i--;
		}
	}
}

void Entity::activate() {

	if(active)
		return;

	active = true;

	matchParentStatus(active);
}

void Entity::deactivate() {

	if(!active)
		return;

	active = false;

	matchParentStatus(active);
}

void Entity::matchParentStatus(bool active) {

	if(active) {
		onActivate();
	}

	else {
		onDeactivate();
	}

	for(unsigned int i = 0; i < children.size(); i++) {
		children.at(i)->matchParentStatus(active);
	}
}

void Entity::destroy() {

	if(destroyed)
		return;

	destroyed = true;

	for(unsigned int i = 0; i < children.size(); i++) {
		children.at(i)->destroy();
	}
}

void Entity::onInitialize() {

}

void Entity::onUpdate() {

}

void Entity::onActivate() {

}

void Entity::onDeactivate() {

}

void Entity::onDestroy() {

}

void Entity::addChild(Entity* child) {
	children.push_back(child);
}

void Entity::tag(std::string tag) {
	tags.push_back(tag);
}

void Entity::untag(std::string tag) {

	for(unsigned int i = 0; i < tags.size(); i++) {

		if(tags.at(i).compare(tag) == 0) {
			tags.erase(tags.begin() + i);
			i--;
		}
	}
}

Engine* Entity::getEngine() {
	return engine;
}

bool Entity::isActive() {
	return active;
}

bool Entity::isDestroyed() {
	return destroyed;
}

Entity* Entity::getByTag(std::string tag) {

	for(unsigned int i = 0; i < children.size(); i++) {

		if(children.at(i)->isTagged(tag)) {
			return children.at(i);
		}
	}

	for(unsigned int i = 0; i < children.size(); i++) {

		Entity* toReturn = children.at(i)->getByTag(tag);

		if(toReturn != NULL) {
			return toReturn;
		}
	}

	return NULL;
}

std::vector<Entity*> Entity::getAllByTag(std::string tag) {

	std::vector<Entity*> entitiesToReturn = std::vector<Entity*>();

	for(unsigned int i = 0; i < children.size(); i++) {

		if(children.at(i)->isTagged(tag)) {
			entitiesToReturn.push_back(children.at(i));
		}
	}

	for(unsigned int i = 0; i < children.size(); i++) {

		std::vector<Entity*> returnedEntities = children.at(i)->getAllByTag(tag);

		for(unsigned int j = 0; j < children.size(); j++) {
			entitiesToReturn.push_back(returnedEntities.at(j));
		}

		returnedEntities.clear();
	}

	return entitiesToReturn;
}

bool Entity::isTagged(std::string tag) {

	for(unsigned int i = 0; i < tags.size(); i++) {

		if(tags.at(i).compare(tag) == 0) {
			return true;
		}
	}

	return false;
}
