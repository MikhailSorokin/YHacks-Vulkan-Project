#ifndef Y_ENGINE_COMPONENTS_SIMULATION_GEOMETRY_MESH_MESH_H_
#define Y_ENGINE_COMPONENTS_SIMULATION_GEOMETRY_MESH_MESH_H_

#include <iostream>
#include <vector>

#include "../Utilities/Transform/Transform.h"
#include "../Mesh/Polygon/Polygon.h"
#include "../Mesh/Vertex/Vertex.h"

class Mesh {

public:

	Mesh();
	Mesh(const Mesh& mesh);
	~Mesh();

	void transform(Transform* transform);

	void addVertex(Vertex* vertex);
	void addPolygon(Polygon* polygon);

	void setVisible();
	void setInvisible();

	void destroy();

	std::vector<Transform*> getTransforms();

	std::vector<Vertex*> getVertices();
	std::vector<Polygon*> getPolygons();

	bool isVisible();
	bool isDestroyed();

private:

	std::vector<Transform*> transforms;

	std::vector<Vertex*> vertices;
	std::vector<Polygon*> polygons;

	bool visible;
	bool destroyed;
};

#endif
