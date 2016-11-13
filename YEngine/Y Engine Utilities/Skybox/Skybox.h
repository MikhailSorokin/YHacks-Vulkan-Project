#ifndef Y_ENGINE_UTILITIES_SKYBOX_SKYBOX_H_
#define Y_ENGINE_UTILITIES_SKYBOX_SKYBOX_H_

#include "../../Y Engine/Components/Simulation/Mesh/Mesh.h"

class Skybox {

public:

	Skybox(std::string texture);

private:

	Mesh* mesh;
};

#endif
