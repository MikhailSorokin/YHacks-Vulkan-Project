#include "Game.h"
#include "Components/Scene/Scene.h"
#include "Components/Simulation/Simulation.h"

Game::Game() {

	setID("Game");

	add(new Scene());
	add(new Simulation());
}

Game::~Game() {

}

void Game::start() {
	((Scene*) get("Scene"))->start();
}

void Game::stop() {
	((Scene*) get("Scene"))->stop();
}
