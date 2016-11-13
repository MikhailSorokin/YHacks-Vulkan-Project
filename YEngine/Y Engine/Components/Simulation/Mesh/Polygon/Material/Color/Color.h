#ifndef Y_ENGINE_COMPONENTS_SIMULATION_UTILITIES_COLOR_COLOR_H_
#define Y_ENGINE_COMPONENTS_SIMULATION_UTILITIES_COLOR_COLOR_H_

class Color {

public:

	Color();
	Color(float red, float green, float blue);
	Color(float red, float green, float blue, float alpha);
	Color(const Color& color);

private:

	float red;
	float green;
	float blue;
	float alpha;
};

#endif
