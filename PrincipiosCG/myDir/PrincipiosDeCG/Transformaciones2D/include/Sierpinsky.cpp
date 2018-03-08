#include "Sierpinsky.h"



void Sierpinsky::generate(Vec3 a, Vec3 b, Vec3 c, int subd)
{

	if (subd == 0) {
		vert.push_back(a);
		vert.push_back(b);
		vert.push_back(c);
	}
	else {
		Vec3 ab = midPoint(a, b), bc = midPoint(b, c), ca = midPoint(c, a);

		generate(a, ab, ca, subd - 1);
		generate(ab, b, bc, subd - 1);
		generate(ca, bc, c, subd - 1);
	}
}

Vec3 Sierpinsky::midPoint(const Vec3 & p0, const Vec3 & p1)
{
	Vec3 r;
	for (int i = 0; i < 3; ++i) {
		r.m[i] = (p0.m[i] + p1.m[i]) / 2;
	}
	return r;
}
