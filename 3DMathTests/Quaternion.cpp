#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>
#include "Quaternion.h"
#include "Vector.h"

Quaternion::Quaternion() : m_inDegrees(true)
{
	
}

Quaternion::Quaternion(Vector vec, float angle)
{
	if(m_inDegrees) 
	{
		// 360 degrees = 2pi radians
		angle = angle / 360 * (float)M_PI * 2;
	}

	// x, y, z coordinates (v * sin (theta/2))
	x = vec.x * sin(angle/2);
	y = vec.y * sin(angle/2);
	z = vec.z * sin(angle/2);

	// 4th coordinate
	w = cos(angle/2);
}

void Quaternion::PrintQuaternion(Vector vec, float angle)
{
	Quaternion q(vec, angle);
	std::cout << "Creating quaternion rotated by " << std::fixed << std::setprecision(2) << angle 
		<< " degrees around (" << vec.x << ", " << vec.y << ", " << vec.z << ")" << std::endl;
	std::cout << "Quaternion: [" << q.x << ", " << q.y << ", " << q.z << ", " << q.w << "]" << std::endl;
}