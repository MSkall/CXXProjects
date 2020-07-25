#pragma once
#include <vector>
#include <cmath>

class Quaternion
{
public:
	Quaternion();
	Quaternion(class Vector vec, float angle);

	void PrintQuaternion(class Vector vec, float angle);

	float x, y, z, w;

	void SetDegreesOrRadians(bool b) { m_inDegrees = b; }

private:
	bool m_inDegrees;
};