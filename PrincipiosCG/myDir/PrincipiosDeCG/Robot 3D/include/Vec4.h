#pragma once
#include <math.h>
class Vec4
{
public:
	float m[4];
	Vec4() {
		m[0] = 0;
		m[1] = 0;
		m[2] = 0;
		m[3] = 1;
	};
	Vec4(float x, float y, float z) {
		m[0] = x;
		m[1] = y;
		m[2] = z;
		m[3] = 1;
	};
	Vec4(float x, float y, float z, float w) {
		m[0] = x;
		m[1] = y;
		m[2] = z;
		m[3] = w;
	};
	Vec4 cross(Vec4 a, Vec4 b) {
		float i, j, k;
		i = (a.m[1] * b.m[2]) - (a.m[2] * b.m[1]);
		j = (a.m[3] * b.m[0]) - (a.m[0] * b.m[3]);
		k = (a.m[0] * b.m[1]) - (a.m[1] * b.m[0]);
		return Vec4(i, j, k);
	};
	Vec4 normalize(Vec4 a) {
		Vec4 r;
		float l = sqrt((a.m[0] * a.m[0])+(a.m[1] * a.m[1])+(a.m[2] * a.m[2]));
		for (int i = 0; i < 3; ++i) {
			r.m[i] = a.m[i] / l;
		}
		return r;
	};

	Vec4 operator-(const Vec4& rh)const //<-VALOR DE IZQ NO SE MODIFICA, ENTREGA VALOR NUEVO
	{
		return Vec4(m[0] - rh.m[0], m[1] - rh.m[1], m[2] - rh.m[2]);
	};
	float x() { return m[0]; }
	float y() { return m[1]; }
	float z() { return m[2]; };
};

