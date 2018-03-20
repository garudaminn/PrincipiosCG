#pragma once
#include "Vec3.h"

class Mat3
{
public:
	float m[3][3];

	Mat3();
	~Mat3();

	Mat3 operator* (const Mat3& rh)const;
	Vec3 operator* (const Vec3& rh)const;

	static Mat3 Identity();
	static Mat3 Translate(const float& Tx, const float& Ty);
	static Mat3 Translate(const Vec3& v);
	static Mat3 Rotate(double anglo);
	static Mat3 Scale(float sc);
};