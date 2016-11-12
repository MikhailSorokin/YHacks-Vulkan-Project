#ifndef Y_ENGINE_COMPONENTS_SIMULATION_MESH_POLYGON_POLYGON_H_
#define Y_ENGINE_COMPONENTS_SIMULATION_MESH_POLYGON_POLYGON_H_

#include <vector>

#include "Material/Material.h"

class Polygon {

private:

	Material material;

	std::vector<int> vertexIndices;
	std::vector<Vector3> texCoords;
};

#endif
