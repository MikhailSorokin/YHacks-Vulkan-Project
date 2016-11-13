#include "Skybox.h"

#include "../../Y Engine/Components/Simulation/Mesh/Vertex/Vertex.h"
#include "../../Y Engine/Components/Simulation/Mesh/Mesh.h"
#include "../../Y Engine/Components/Simulation/Mesh/Polygon/Material/Material.h"

Mesh* generateSkybox(std::string texture) {

	Mesh* mesh = new Mesh();

	Material* material = new Material();
	material->setTexture(texture);

	mesh->addVertex(new Vertex(-.5, -.5, -.5));
	mesh->addVertex(new Vertex(-.5, -.5, .5));
	mesh->addVertex(new Vertex(-.5, .5, -.5));
	mesh->addVertex(new Vertex(-.5, .5, .5));
	mesh->addVertex(new Vertex(.5, -.5, -.5));
	mesh->addVertex(new Vertex(.5, -.5, .5));
	mesh->addVertex(new Vertex(.5, .5, -.5));
	mesh->addVertex(new Vertex(.5, .5, .5));

	Polygon* left = new Polygon();
	Polygon* right = new Polygon();
	Polygon* top = new Polygon();
	Polygon* bottom = new Polygon();
	Polygon* front = new Polygon();
	Polygon* back = new Polygon();

	left->setMaterial(material);
	right->setMaterial(material);
	top->setMaterial(material);
	bottom->setMaterial(material);
	front->setMaterial(material);
	back->setMaterial(material);

	left->addVertex(0);
	left->addVertex(1);
	left->addVertex(3);
	left->addVertex(2);

	right->addVertex(4);
	right->addVertex(5);
	right->addVertex(7);
	right->addVertex(6);

	bottom->addVertex(0);
	bottom->addVertex(1);
	bottom->addVertex(5);
	bottom->addVertex(4);

	top->addVertex(2);
	top->addVertex(3);
	top->addVertex(7);
	top->addVertex(6);

	back->addVertex(0);
	back->addVertex(2);
	back->addVertex(6);
	back->addVertex(4);

	front->addVertex(1);
	front->addVertex(3);
	front->addVertex(7);
	front->addVertex(5);

	left->setTexCoord(0, new Vector3(0.0 / 4.0, 2.0 / 3.0, 0));
	left->setTexCoord(1, new Vector3(1.0 / 4.0, 2.0 / 3.0, 0));
	left->setTexCoord(2, new Vector3(0.0 / 4.0, 1.0 / 3.0, 0));
	left->setTexCoord(3, new Vector3(1.0 / 4.0, 1.0 / 3.0, 0));

	right->setTexCoord(4, new Vector3(3.0 / 4.0, 2.0 / 3.0, 0));
	right->setTexCoord(5, new Vector3(2.0 / 4.0, 2.0 / 3.0, 0));
	right->setTexCoord(6, new Vector3(3.0 / 4.0, 1.0 / 3.0, 0));
	right->setTexCoord(7, new Vector3(2.0 / 4.0, 1.0 / 3.0, 0));

	bottom->setTexCoord(0, new Vector3(1.0 / 4.0, 3.0 / 3.0, 0));
	bottom->setTexCoord(1, new Vector3(1.0 / 4.0, 2.0 / 3.0, 0));
	bottom->setTexCoord(4, new Vector3(2.0 / 4.0, 3.0 / 3.0, 0));
	bottom->setTexCoord(5, new Vector3(2.0 / 4.0, 2.0 / 3.0, 0));

	top->setTexCoord(2, new Vector3(1.0 / 4.0, 0.0 / 3.0, 0));
	top->setTexCoord(3, new Vector3(1.0 / 4.0, 1.0 / 3.0, 0));
	top->setTexCoord(6, new Vector3(2.0 / 4.0, 0.0 / 3.0, 0));
	top->setTexCoord(7, new Vector3(2.0 / 4.0, 1.0 / 3.0, 0));

	back->setTexCoord(0, new Vector3(4.0 / 4.0, 2.0 / 3.0, 0));
	back->setTexCoord(2, new Vector3(4.0 / 4.0, 1.0 / 3.0, 0));
	back->setTexCoord(4, new Vector3(3.0 / 4.0, 2.0 / 3.0, 0));
	back->setTexCoord(6, new Vector3(3.0 / 4.0, 1.0 / 3.0, 0));

	front->setTexCoord(1, new Vector3(1.0 / 4.0, 2.0 / 3.0, 0));
	front->setTexCoord(3, new Vector3(1.0 / 4.0, 1.0 / 3.0, 0));
	front->setTexCoord(5, new Vector3(2.0 / 4.0, 2.0 / 3.0, 0));
	front->setTexCoord(7, new Vector3(2.0 / 4.0, 1.0 / 3.0, 0));

	mesh->addPolygon(left);
	mesh->addPolygon(right);
	mesh->addPolygon(top);
	mesh->addPolygon(bottom);
	mesh->addPolygon(front);
	mesh->addPolygon(back);

	return mesh;
}
