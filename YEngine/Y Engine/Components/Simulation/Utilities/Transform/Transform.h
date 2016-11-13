#ifndef Y_ENGINE_COMPONENTS_SIMULATION_UTILITIES_TRANSFORM_TRANSFORM_H_
#define Y_ENGINE_COMPONENTS_SIMULATION_UTILITIES_TRANSFORM_TRANSFORM_H_

#include "../Vector3/Vector3.h"

class Transform {

public:

	Transform();
	Transform(float x, float y, float z);
	Transform(Vector3 transform);
	~Transform();

private:

	Vector3 transform;
};

#endif
