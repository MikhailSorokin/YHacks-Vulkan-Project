#include <vector>

#include "Camera/Camera.h"
#include "Mesh/Mesh.h"
#include "Effect/Effect.h"
#include "Simulation.h"

Simulation::Simulation() {

	setID("Simulation");

	camera = new Camera();

	meshes = std::vector<Mesh*>();
	effects = std::vector<Effect*>();
}

Simulation::~Simulation() {

}

void Simulation::update() {

}

void Simulation::addMesh(Mesh* mesh) {
	meshes.push_back(mesh);
}

void Simulation::addEffect(Effect* effect) {
	effects.push_back(effect);
}

Camera* Simulation::getCamera() {
	return camera;
}

std::vector<Mesh*> Simulation::getMeshes() {
	return meshes;
}

std::vector<Effect*> Simulation::getEffects() {
	return effects;
}
