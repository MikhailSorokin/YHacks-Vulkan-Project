#ifndef Y_ENGINE_COMPONENTS_SIMULATION_MESH_POLYGON_POLYGON_H_
#define Y_ENGINE_COMPONENTS_SIMULATION_MESH_POLYGON_POLYGON_H_

#include <vector>

#include "Material/Material.h"
#include "../Vertex/Vertex.h"

class Polygon {

public:

	Polygon();
	Polygon(const Polygon& polygon);

	~Polygon();

	void setMaterial(Material* material);

	void addVertex(int vertex);
	void setTexCoord(int vertex, Vector3* texCoord);

	Material* getMaterial();

	std::vector<int> getVertices();
	std::vector<Vector3*> getTexCoords();

private:

	Material* material;

	std::vector<int> vertices;
	std::vector<Vector3*> texCoords;
};

#endif
