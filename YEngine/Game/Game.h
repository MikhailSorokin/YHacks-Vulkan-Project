#ifndef GAME_GAME_H_
#define GAME_GAME_H_

#include "../Engine/Engine.h"

class Game : public Engine {

public:

	Game();
	~Game();

	void start();
	void stop();
};

#endif
