#ifndef Y_ENGINE_COMPONENTS_SIMULATION_CAMERA_CAMERA_H_
#define Y_ENGINE_COMPONENTS_SIMULATION_CAMERA_CAMERA_H_

#include <vector>

#include "../Utilities/Transform/Transform.h"

class Camera {

public:

	Camera();
	~Camera();

	void update();

	void transform(Transform transform);

	std::vector<Transform*> getTransforms();

private:

	std::vector<Transform*> transforms;
};

#endif
