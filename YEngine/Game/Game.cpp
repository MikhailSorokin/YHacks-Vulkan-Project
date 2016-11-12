#include "Game.h"
#include "../Scene/Scene.h"

Game::Game() {

	setID("Game");

	add(new Scene());
}

Game::~Game() {

}

void Game::start() {
	((Scene*) get("Scene"))->start();
}

void Game::stop() {
	((Scene*) get("Scene"))->stop();
}
