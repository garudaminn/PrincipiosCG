#pragma once

class Vec3 {
public:
	float m[3];
	Vec3() {
		m[0] = 0;
		m[1] = 0;
		m[2] = 1;
	}
	Vec3(float x, float y, float w) {
		m[0] = x;
		m[1] = y;
		m[2] = w;
	}
	Vec3& operator-(const Vec3& rh)const //<-VALOR DE IZQ NO SE MODIFICA, ENTREGA VALOR NUEVO
	{
		return Vec3(m[0] - rh.m[0], m[1] - rh.m[1], 1);
	};
	float x() { return m[0]; }
	float y() { return m[1]; }
};
