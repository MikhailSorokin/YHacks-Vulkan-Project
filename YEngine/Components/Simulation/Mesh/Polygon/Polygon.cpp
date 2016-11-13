#include <iostream>
#include <vector>

#include "Polygon.h"

#include "Material/Material.h"
#include "../../Utilities/Vector3/Vector3.h"
#include "../Vertex/Vertex.h"

Polygon::Polygon() {

	material = new Material();

	vertices = std::vector<int>();
	texCoords = std::vector<Vector3*>();
}

Polygon::Polygon(const Polygon& polygon) {

	material = new Material();

	vertices = std::vector<int>();
	texCoords = std::vector<Vector3*>();

	// STUB
}

Polygon::~Polygon() {

}

void Polygon::setMaterial(Material* material) {
	this->material = material;
}

void Polygon::addVertex(int vertex) {
	vertices.push_back(vertex);
	texCoords.push_back(NULL);
}

void Polygon::setTexCoord(int vertex, Vector3* texCoord) {

	for(unsigned int i = 0; i < vertices.size(); i++) {

		if(vertices.at(i) == vertex) {
			texCoords.at(i) = texCoord;
			break;
		}
	}
}

Material* Polygon::getMaterial() {
	return material;
}

std::vector<int> Polygon::getVertices() {
	return vertices;
}

std::vector<Vector3*> Polygon::getTexCoords() {
	return texCoords;
}
