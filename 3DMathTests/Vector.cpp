#include "Vector.h"
#include <cmath>

Vector Vector::operator-() const
{
	return Vector(-x, -y, -z);
}

Vector Vector::operator+(const Vector& v) const
{
	return Vector(x + v.x, y + v.y, z + v.z);
}

Vector Vector::operator-(const Vector& v) const
{
	return Vector(x - v.x, y - v.y, z - v.z);
}

Vector Vector::Normalized() const
{
	return (*this) / Length();
}

void Vector::Normalize()
{
	(*this) = (*this) / Length();
}

Vector Vector::operator*(float s) const
{
	return Vector(x * s, y * s, z * s);
}

Vector Vector::operator/(float s) const
{
	return Vector(x / s, y / s, z / s);
}

float Vector::Length() const
{
	return sqrt(x*x + y*y + z*z);
}

float Vector::LengthSqr() const
{
	return (x*x + y*y + z*z);
}

float Vector::Dot(const Vector& v) const
{
	return x*v.x + y*v.y + z*v.z;
}

Vector Vector::Cross(const Vector& v) const
{
	Vector c;

	c.x = y*v.z - z*v.y;
	c.y = z*v.x - x*v.z;
	c.z = x*v.y - y*v.x;

	return c;
}