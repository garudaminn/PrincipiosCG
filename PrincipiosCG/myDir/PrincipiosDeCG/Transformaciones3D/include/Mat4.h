#pragma once
#include "Vec4.h"

class Mat4
{
public:
	float m[4][4];

	Mat4();
	~Mat4();

	Mat4 operator* (const Mat4& rh)const;
	Vec4 operator* (const Vec4& rh)const;

	static Mat4 Identity();
	static Mat4 Translate(const float& Tx, const float& Ty, const float& Tz);
	static Mat4 Translate(const Vec4& vec);
	static Mat4 RotateX(double anglo);
	static Mat4 RotateY(double anglo);
	static Mat4 RotateZ(double anglo);
	static Mat4 Scale(float sx, float sy, float sz);
	static Mat4 LookAt(Vec4 eye, Vec4 target, Vec4 up);
	static Mat4 Perspective(const float& fov, const float & aspect, const float & near, const float & far);
};

