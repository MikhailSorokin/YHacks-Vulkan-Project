#ifndef Y_ENGINE_COMPONENTS_SCENE_ENTITY_SCRIPT_SCRIPT_H_
#define Y_ENGINE_COMPONENTS_SCENE_ENTITY_SCRIPT_SCRIPT_H_

class Script {

public:

	Script();
	virtual ~Script();

	void setEntity(Entity* entity);
	void remove();

	Entity* getEntity();
	bool isRemoved();

	virtual void onInitialize();
	virtual void onUpdate();
	virtual void onActivate();
	virtual void onDeactivate();
	virtual void onDestroy();

private:

	Entity* entity;
	bool removed;
};

#endif
