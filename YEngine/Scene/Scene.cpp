#include <iostream>
//#include <chrono>
//#include <thread>
#include <vector>

#include "Scene.h"
#include "Entity/Entity.h"

Scene::Scene() {

	setID("Scene");

	running = false;
	updating = false;

	tickInterval = (1000 / 60);

	entities = std::vector<Entity*>();
}

Scene::~Scene() {

}

void Scene::start() {

	running = true;

//	std::thread gameLoop = std::thread(run);

	run();
}

void Scene::stop() {
	running = false;
}

void Scene::run() {

	while(running) {

		updating = true;

		for(unsigned int i = 0; i < entities.size(); i++) {
			entities.at(i)->update();
		}

		updating = false;

//		std::this_thread::sleep_for(std::chrono::milliseconds(tickInterval));
	}
}

void Scene::setTickInterval(int tickInterval) {

	if(tickInterval > 0) {
		this->tickInterval = tickInterval;
	}
}

void Scene::setTicksPerSecond(int ticksPerSecond) {

	if(ticksPerSecond > 0) {
		tickInterval = 1000 / ticksPerSecond;
	}
}

void Scene::addEntity(Entity* entity) {

	entity->initialize(this);

	entities.push_back(entity);
}

Entity* Scene::getByTag(std::string tag) {

	for(unsigned int i = 0; i < entities.size(); i++) {

		if(entities.at(i)->isTagged(tag)) {
			return entities.at(i);
		}
	}

	for(unsigned int i = 0; i < entities.size(); i++) {

		Entity* toReturn = entities.at(i)->getByTag(tag);

		if(toReturn != NULL) {
			return toReturn;
		}
	}

	return NULL;
}

std::vector<Entity*> Scene::getAllByTag(std::string tag) {

	std::vector<Entity*> entitiesToReturn = std::vector<Entity*>();

	for(unsigned int i = 0; i < entities.size(); i++) {

		if(entities.at(i)->isTagged(tag)) {
			entitiesToReturn.push_back(entities.at(i));
		}
	}

	for(unsigned int i = 0; i < entities.size(); i++) {

		std::vector<Entity*> returnedEntities = entities.at(i)->getAllByTag(tag);

		for(unsigned int j = 0; j < entities.size(); j++) {
			entitiesToReturn.push_back(returnedEntities.at(j));
		}

		returnedEntities.clear();
	}

	return entitiesToReturn;
}
