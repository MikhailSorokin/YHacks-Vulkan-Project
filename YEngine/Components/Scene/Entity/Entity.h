#ifndef SCENE_ENTITY_ENTITY_H_
#define SCENE_ENTITY_ENTITY_H_

#include <iostream>
#include <vector>

#include "../../../Engine/Engine.h"

class Entity {

public:

	Entity();
	virtual ~Entity();

	void initialize(Engine* engine);
	void update();
	void activate();
	void deactivate();
	void destroy();

	void addChild(Entity* child);

	void tag(std::string tag);
	void untag(std::string tag);

	Engine* getEngine();

	bool isActive();
	bool isDestroyed();

	Entity* getByTag(std::string tag);
	std::vector<Entity*> getAllByTag(std::string tag);

	bool isTagged(std::string tag);

protected:

	virtual void onInitialize();
	virtual void onUpdate();
	virtual void onActivate();
	virtual void onDeactivate();
	virtual void onDestroy();

private:

	void matchParentStatus(bool active);

	Engine* engine;

	bool initialized;
	bool active;
	bool destroyed;

	std::vector<Entity*> children;

	std::vector<std::string> tags;
};

#endif
