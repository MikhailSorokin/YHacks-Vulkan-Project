#include "Engine.h"

#include <iostream>
#include <vector>

Engine::Engine() {

	setID("Engine");

	parent = NULL;
	children = std::vector<Engine*>();
}

Engine::~Engine() {

}

void Engine::setID(std::string id) {
	this->id = id;
}

void Engine::setParent(Engine* parent) {
	this->parent = parent;
}

void Engine::add(Engine* engine) {

	engine->setParent(this);

	children.push_back(engine);
}

Engine* Engine::remove(std::string id) {
	return removeFrom(getMain(), id);
}

Engine* Engine::removeFrom(Engine* engine, std::string id) {

	for(unsigned int i = 0; i < engine->getChildren().size(); i++) {

		if(engine->getChildren().at(i)->getID().compare(id) == 0) {

			Engine* toReturn = engine->getChildren().at(i);
			engine->getChildren().erase(engine->getChildren().begin() + i);

			return toReturn;
		}
	}

	for(unsigned int i = 0; i < engine->getChildren().size(); i++) {

		Engine* toReturn = engine->getChildren().at(i)->removeFrom(engine->getChildren().at(i), id);

		if(toReturn != NULL) {
			return toReturn;
		}
	}

	return NULL;
}

std::string Engine::getID() {
	return id;
}

Engine* Engine::getParent() {
	return parent;
}

Engine* Engine::getMain() {

	Engine* engine = this;

	while(true) {

		if(engine->getParent() == NULL) {
			return engine;
		}

		engine = engine->getParent();
	}
}

std::vector<Engine*> Engine::getChildren() {
	return children;
}

Engine* Engine::get(std::string id) {
	return getFrom(getMain(), id);
}

Engine* Engine::getFrom(Engine* engine, std::string id) {

	for(unsigned int i = 0; i < engine->getChildren().size(); i++) {

		if(engine->getChildren().at(i)->getID().compare(id) == 0) {
			return engine->getChildren().at(i);
		}
	}

	for(unsigned int i = 0; i < engine->getChildren().size(); i++) {

		Engine* toReturn = engine->getChildren().at(i)->getFrom(engine->getChildren().at(i), id);

		if(toReturn != NULL) {
			return toReturn;
		}
	}

	return NULL;
}

bool Engine::has(std::string id) {
	return get(id) != NULL;
}
