#ifndef Y_ENGINE_COMPONENTS_SIMULATION_UTILITIES_VECTOR3_VECTOR3_H_
#define Y_ENGINE_COMPONENTS_SIMULATION_UTILITIES_VECTOR3_VECTOR3_H_

class Vector3 {

public:

	Vector3();
	Vector3(const Vector3& vector3);
	Vector3(float x, float y, float z);

	~Vector3();

	void set(Vector3 vector3);
	void set(float x, float y, float z);
	void setX(float x);
	void setY(float y);
	void setZ(float z);

	void increment(Vector3 vector3);
	void increment(float x, float y, float z);
	void incrementX(float x);
	void incrementY(float y);
	void incrementZ(float z);

	void decrement(Vector3 vector3);
	void decrement(float x, float y, float z);
	void decrementX(float x);
	void decrementY(float y);
	void decrementZ(float z);

	void setMagnitude(float magnitude);

	float getX();
	float getY();
	float getZ();

	float getMagnitude();

private:

	float x;
	float y;
	float z;
};

#endif
