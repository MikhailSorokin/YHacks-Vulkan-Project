#include "Vector3.h"

Vector3::Vector3() {
	x = 0;
	y = 0;
	z = 0;
}

Vector3::Vector3(const Vector3& vector3) {
	set(vector3);
}

Vector3::Vector3(float x, float y, float z) {
	set(x, y, z);
}

Vector3::~Vector3() {

}

void Vector3::set(Vector3 vector3) {
	setX(vector3.getX());
	setY(vector3.getY());
	setZ(vector3.getZ());
}

void Vector3::set(float x, float y, float z) {
	setX(x);
	setY(y);
	setZ(z);
}

void Vector3::setX(float x) {
	this->x = x;
}

void Vector3::setY(float y) {
	this->y = y;
}

void Vector3::setZ(float z) {
	this->z = z;
}

void Vector3::increment(Vector3 vector3) {
	incrementX(vector3.getX());
	incrementY(vector3.getY());
	incrementZ(vector3.getZ());
}

void Vector3::increment(float x, float y, float z) {
	incrementX(x);
	incrementY(y);
	incrementZ(z);
}

void Vector3::incrementX(float x) {
	setX(getX() + x);
}

void Vector3::incrementY(float y) {
	setY(getY() + y);
}

void Vector3::incrementZ(float z) {
	setZ(getZ() + z);
}

void Vector3::decrement(Vector3 vector3) {
	decrementX(vector3.getX());
	decrementY(vector3.getY());
	decrementZ(vector3.getZ());
}

void Vector3::decrement(float x, float y, float z) {
	decrementX(x);
	decrementY(y);
	decrementZ(z);
}

void Vector3::decrementX(float x) {
	setX(getX() - x);
}

void Vector3::decrementY(float y) {
	setY(getY() - y);
}

void Vector3::decrementZ(float z) {
	setZ(getZ() - z);
}

void Vector3::setMagnitude(float magnitude) {

}

float Vector3::getX() {
	return x;
}

float Vector3::getY() {
	return y;
}

float Vector3::getZ() {
	return z;
}

float Vector3::getMagnitude() {
	return 0;
}
