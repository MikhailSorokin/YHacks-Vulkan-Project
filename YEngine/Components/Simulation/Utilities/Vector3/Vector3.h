#ifndef Y_ENGINE_COMPONENTS_SIMULATION_UTILITIES_VECTOR3_VECTOR3_H_
#define Y_ENGINE_COMPONENTS_SIMULATION_UTILITIES_VECTOR3_VECTOR3_H_

class Vector3 {

public:

	Vector3();
	Vector3(float x, float y, float z);
	Vector3(Vector3 vector3);

private:

	float x;
	float y;
	float z;
};

#endif
