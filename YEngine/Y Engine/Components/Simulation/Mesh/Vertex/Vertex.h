#ifndef Y_ENGINE_COMPONENTS_SIMULATION_MESH_VERTEX_VERTEX_H_
#define Y_ENGINE_COMPONENTS_SIMULATION_MESH_VERTEX_VERTEX_H_

#include "../../Utilities/Vector3/Vector3.h"

class Vertex {

public:

	Vertex();
	Vertex(float x, float y, float z);
	Vertex(const Vertex& vertex);

	~Vertex();

	void setPosition(Vector3* position);
	void setTransformation(Vector3* transformation);

	void setNormal(Vector3* normal);

	Vector3* getPosition();
	Vector3* getTransformation();

	Vector3* getNormal();

private:

	Vector3* position;
	Vector3* transformation;

	Vector3* normal;
};

#endif
