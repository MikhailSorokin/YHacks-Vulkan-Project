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

	void addMesh(Mesh* mesh);
	void addEffect(Effect* effect);

	Camera* getCamera();

	std::vector<Mesh*> getMeshes();
	std::vector<Effect*> getEffects();

private:

	Camera* camera;

	std::vector<Mesh*> meshes;
	std::vector<Effect*> effects;
};

#endif
