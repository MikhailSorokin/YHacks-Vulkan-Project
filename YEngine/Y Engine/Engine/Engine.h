#ifndef ENGINE_H_
#define ENGINE_H_

#include <iostream>
#include <vector>

class Engine {

public:

	Engine();
	~Engine();

	void add(Engine* engine);
	Engine* remove(std::string id);

	Engine* get(std::string id);
	bool has(std::string id);

protected:

	void setID(std::string id);

private:

	// MEMBER FUNCTIONS

	void setParent(Engine* parent);

	Engine* removeFrom(Engine* engine, std::string id);
	Engine* getFrom(Engine* engine, std::string id);

	std::string getID();

	Engine* getParent();
	Engine* getMain();

	std::vector<Engine*> getChildren();

	// DATA MEMBERS

	std::string id;

	Engine* parent;
	std::vector<Engine*> children;
};

#endif
