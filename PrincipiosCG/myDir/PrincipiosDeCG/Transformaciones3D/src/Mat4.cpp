#define _USE_MATH_DEFINES
#include "Mat4.h"
#include "Vec4.h"
#include <math.h>

Mat4::Mat4()
{
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (i == j) {
				m[i][j] = 1;
			}
			else {
				m[i][j] = 0;
			}
		}
	}
}


Mat4::~Mat4()
{
}

Mat4  Mat4::operator*(const Mat4 & rh) const
{
	// TODO: insertar una instrucción return aquí
	Mat4 r;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			r.m[i][j] = 0;
		}
	}
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 4; ++k)
			{
				r.m[i][j] += m[i][k] * rh.m[k][j];
			}
		}
	}
	return r;
}

Vec4  Mat4::operator*(const Vec4 & rh) const
{
	// TODO: insertar una instrucción return aquí
	Vec4 r;

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			r.m[i] += m[i][j] * rh.m[j];
		}
	}
	return r;
}


Mat4 Mat4::Identity()
{
	Mat4 result;
	return result;
	// TODO: insertar una instrucción return aquí
}

Mat4 Mat4::Translate(const float & Tx, const float & Ty, const float & Tz)
{
	// TODO: insertar una instrucción return aquí
	Mat4 r = Mat4();

	r.m[0][3] = Tx;
	r.m[1][3] = Ty;
	r.m[2][3] = Tz;
	return r;
}

Mat4  Mat4::Translate(const Vec4 & vec)
{
	Mat4 r = Mat4::Translate(vec.m[0], vec.m[1], vec.m[2]);
	return r;
	// TODO: insertar una instrucción return aquí
}

Mat4 Mat4::RotateX(double anglo)
{
	Mat4 r = Mat4();

	r.m[1][1] = r.m[2][2] = cos(anglo*M_PI / 180);
	r.m[2][1] = sin(anglo*M_PI / 180);
	r.m[1][2] = -sin(anglo*M_PI / 180);
	return r;
}

Mat4 Mat4::RotateY(double anglo)
{
	Mat4 r = Mat4();

	r.m[0][0] = r.m[2][2] = cos(anglo*M_PI / 180);
	r.m[0][2] = sin(anglo*M_PI / 180);
	r.m[2][0] = -sin(anglo*M_PI / 180);
	return r;
}

Mat4  Mat4::RotateZ(double anglo)
{
	// TODO: insertar una instrucción return aquí
	Mat4 r = Mat4();

	r.m[0][0] = r.m[1][1] = cos(anglo*M_PI / 180);
	r.m[1][0] = sin(anglo*M_PI / 180);
	r.m[0][1] = -sin(anglo*M_PI / 180);
	return r;
}

Mat4  Mat4::Scale(float sx, float sy, float sz)
{
	// TODO: insertar una instrucción return aquí
	Mat4 r;

	r.m[0][0] = sx;
	r.m[1][1] = sy;
	r.m[2][2] = sz;
	return r;
}

Mat4 Mat4::LookAt(Vec4 eye, Vec4 target, Vec4 up)
{
	Mat4 t, re,ro;
	Vec4 F = eye.normalize(target-eye);//z
	Vec4 R = eye.normalize(eye.cross(F, up));//x
	Vec4 U = eye.normalize(eye.cross(R, F));//y
	for (int i = 0; i < 3; ++i) {
		t.m[i][3] = -eye.m[i];
	}
	for (int i = 0; i < 3; ++i) {
		ro.m[0][i] = R.m[i];
		ro.m[1][i] = U.m[i];
		ro.m[2][i] = F.m[i];
	}
	re = ro * t;
	return re;
}

Mat4 Mat4::Perspective(const float & fov, const float & aspect, const float & near, const float & far)
{
	float y = cosf(fov*M_PI / 180);
	if (y != 0) {
		y = sinf(fov*M_PI / 180) / y;
		if (y != 0) {
			y = 1.0F / y;
		}
	}
	Mat4 m;
	m.m[0][0] = y / aspect;
	m.m[1][1] = y;
	m.m[2][2] = -((far+near) / (far - near));
	m.m[2][3] = -((2 * far*near) / (far - near));
	m.m[3][2] = 1; 
	return m;
}
