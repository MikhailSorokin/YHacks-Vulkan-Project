#include <vector>

#include "Mesh.h"
#include "Polygon/Polygon.h"
#include "../Utilities/Transform/Transform.h"
#include "Vertex/Vertex.h"

Mesh::Mesh() {

	renderMode = 1;
	aspectMode = 1;

	transforms = std::vector<Transform*>();

	vertices = std::vector<Vertex*>();
	polygons = std::vector<Polygon*>();

	visible = true;
	destroyed = false;
}

Mesh::~Mesh() {

}

void Mesh::setRenderMode(int renderMode) {

	if(renderMode >= 1 && renderMode <= 2) {
		this->renderMode = renderMode;
	}
}

void Mesh::setAspectMode(int aspectMode) {

	if(aspectMode >= 1 && aspectMode <= 3) {
		this->aspectMode = aspectMode;
	}
}

void Mesh::transform(Transform* transform) {
	transforms.push_back(transform);
}

void Mesh::addVertex(Vertex* vertex) {
	vertices.push_back(vertex);
}

void Mesh::addPolygon(Polygon* polygon) {
	polygons.push_back(polygon);
}

void Mesh::setVisible() {
	visible = true;
}

void Mesh::setInvisible() {
	visible = false;
}

void Mesh::destroy() {
	destroyed = true;
}

int Mesh::getRenderMode() {
	return renderMode;
}

int Mesh::getAspectMode() {
	return aspectMode;
}

std::vector<Transform*> Mesh::getTransforms() {
	return transforms;
}

std::vector<Vertex*> Mesh::getVertices() {
	return vertices;
}

std::vector<Polygon*> Mesh::getPolygons() {
	return polygons;
}

bool Mesh::isVisible() {
	return visible;
}

bool Mesh::isDestroyed() {
	return destroyed;
}
