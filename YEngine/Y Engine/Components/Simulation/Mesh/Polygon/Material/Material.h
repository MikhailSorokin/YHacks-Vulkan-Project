#ifndef Y_ENGINE_COMPONENTS_SIMULATION_MATERIAL_MATERIAL_H_
#define Y_ENGINE_COMPONENTS_SIMULATION_MATERIAL_MATERIAL_H_

#include <iostream>

#include "Color/Color.h"

class Material {

public:

	Material();
	Material(std::string texture);

	~Material();

	void setTexture(std::string texture);
	void setColor(Color* color);

	std::string getTexture();
	Color* getColor();

private:

	std::string texture;
	Color* color;
};

#endif
