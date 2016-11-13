#include <iostream>

#include "Material.h"
#include "Color/Color.h"

Material::Material() {
	texture = "";
	color = new Color();
}

Material::Material(std::string texture) {
	this->texture = texture;
	color = new Color();
}

Material::~Material() {

}

void Material::setTexture(std::string texture) {
	this->texture = texture;
}

void Material::setColor(Color* color) {
	this->color = color;
}

std::string Material::getTexture() {
	return texture;
}

Color* Material::getColor() {
	return color;
}
