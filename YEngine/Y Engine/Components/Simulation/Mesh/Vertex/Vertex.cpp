#include "../../Utilities/Vector3/Vector3.h"
#include "Vertex.h"

#include <iostream>

Vertex::Vertex() {

	position = new Vector3(0, 0, 0);
	transformation = new Vector3(0, 0, 0);

	normal = NULL;
}

Vertex::Vertex(float x, float y, float z) {

	position = new Vector3(x, y, z);
	transformation = new Vector3(0, 0, 0);

	normal = NULL;
}

Vertex::Vertex(const Vertex& vertex) {

	position = new Vector3(0, 0, 0);
	transformation = new Vector3(0, 0, 0);

	normal = NULL;

	// STUB
}

Vertex::~Vertex() {

}

void Vertex::setPosition(Vector3* position) {
	this->position = position;
}

void Vertex::setTransformation(Vector3* transformation) {
	this->transformation = transformation;
}

void Vertex::setNormal(Vector3* normal) {
	this->normal = normal;
}

Vector3* Vertex::getPosition() {
	return position;
}

Vector3* Vertex::getTransformation() {
	return transformation;
}

Vector3* Vertex::getNormal() {
	return normal;
}
