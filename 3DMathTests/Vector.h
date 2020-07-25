#pragma once

class Vector
{
public:
	Vector() {}
	Vector(float X, float Y, float Z) 
		: x(X), y(Y), z(Z) {}

	float x, y, z;
	
	float Length() const;
	float LengthSqr() const;

	Vector operator-() const;

	Vector operator+(const Vector& v) const;
	Vector operator-(const Vector& v) const;

	Vector operator*(float s) const;
	Vector operator/(float s) const;

	Vector Normalized() const;
	void Normalize();

	float  Dot(const Vector& v) const;
	Vector Cross(const Vector& v) const;

};

inline const Vector operator*(float s, const Vector& v)
{
	return Vector(s*v.x, s*v.y, s*v.z);
}

inline const Vector operator/(float s, const Vector& v)
{
	return Vector(s/v.x, s/v.y, s/v.z);
}