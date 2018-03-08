#pragma once
#include "Vec3.h"
#include "Mat3.h"
#include <vector>

class Sierpinsky {
public:
	std::vector<Vec3> vert;

	void generate(Vec3 a, Vec3 b, Vec3 c, int subd);
	Vec3 midPoint(const Vec3& p0, const Vec3& p1);
};