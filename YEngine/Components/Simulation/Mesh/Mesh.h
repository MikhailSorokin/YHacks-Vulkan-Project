#ifndef Y_ENGINE_COMPONENTS_SIMULATION_GEOMETRY_MESH_MESH_H_
#define Y_ENGINE_COMPONENTS_SIMULATION_GEOMETRY_MESH_MESH_H_

#include <iostream>
#include <vector>

#include "../Utilities/Transform/Transform.h"
#include "../Mesh/Polygon/Polygon.h"
#include "../Mesh/Vertex/Vertex.h"

class Mesh {

public:

	static const int RENDER_MODE_3D = 1;
	static const int RENDER_MODE_2D = 2;

	static const int ASPECT_MODE_ON = 1;
	static const int ASPECT_MODE_OFF = 2;
	static const int ASPECT_MODE_ABSOLUTE = 3;

	Mesh();
	Mesh(const Mesh& mesh);
	~Mesh();

	void setRenderMode(int renderMode);
	void setAspectMode(int aspectMode);

	void transform(Transform* transform);

	void addVertex(Vertex* vertex);
	void addPolygon(Polygon* polygon);

	void setVisible();
	void setInvisible();

	void destroy();

	int getRenderMode();
	int getAspectMode();

	std::vector<Transform*> getTransforms();

	std::vector<Vertex*> getVertices();
	std::vector<Polygon*> getPolygons();

	bool isVisible();
	bool isDestroyed();

private:

	int renderMode;
	int aspectMode;

	std::vector<Transform*> transforms;

	std::vector<Vertex*> vertices;
	std::vector<Polygon*> polygons;

	bool visible;
	bool destroyed;
};

#endif
