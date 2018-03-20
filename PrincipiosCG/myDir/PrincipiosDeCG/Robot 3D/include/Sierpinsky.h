#pragma once
#include "Vec3.h"
#include "Mat3.h"
#include "Vec4.h"
#include "Mat4.h"
#include <vector>

class Sierpinsky {
public:
	std::vector<Vec3> vert;
	std::vector<Vec4> vert4;

	void generate(Vec3 a, Vec3 b, Vec3 c, int subd);
	void generateCube(Vec4 a, Vec4 b, Vec4 c, Vec4 d, Vec4 e, Vec4 f, Vec4 g, Vec4 h);
	Vec3 midPoint(const Vec3& p0, const Vec3& p1);
};