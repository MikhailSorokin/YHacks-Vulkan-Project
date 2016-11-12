#ifndef Y_ENGINE_COMPONENTS_SIMULATION_SIMULATION_H_
#define Y_ENGINE_COMPONENTS_SIMULATION_SIMULATION_H_

#include <iostream>
#include <vector>

#include "Camera/Camera.h"
#include "Effect/Effect.h"
#include "../../Engine/Engine.h"
#include "Mesh/Mesh.h"

class Simulation : public Engine {

public:

	Simulation();
	~Simulation();

	void update();

	Camera* getCamera();

	void addMesh(Mesh* mesh);
	void addEffect(Effect* effect);

private:

	Camera camera;

	std::vector<Mesh*> meshes;
	std::vector<Effect*> effects;
};

#endif