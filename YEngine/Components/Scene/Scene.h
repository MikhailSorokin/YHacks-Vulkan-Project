#ifndef SCENE_SCENE_H_
#define SCENE_SCENE_H_

#include <iostream>
#include <vector>

#include "../../Engine/Engine.h"
#include "Entity/Entity.h"

class Scene : public Engine {

public:

	Scene();
	~Scene();

	void start();
	void stop();

	void run();

	void setTickInterval(int tickInterval);
	void setTicksPerSecond(int ticksPerSecond);

	void addEntity(Entity* entity);

	Entity* getByTag(std::string tag);
	std::vector<Entity*> getAllByTag(std::string tag);

private:

	bool running;
	bool updating;

	int tickInterval;

	std::vector<Entity*> entities;
};

#endif
