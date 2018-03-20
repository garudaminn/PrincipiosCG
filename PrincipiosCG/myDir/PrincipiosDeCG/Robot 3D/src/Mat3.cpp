#define _USE_MATH_DEFINES
#include "Mat3.h"
#include <math.h>

Mat3::Mat3()
{
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (i == j) {
				m[i][j] = 1;
			}
			else {
				m[i][j] = 0;
			}
		}
	}
}


Mat3::~Mat3()
{
}

Mat3  Mat3::operator*(const Mat3 & rh) const
{
	// TODO: insertar una instrucción return aquí
	Mat3 r;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			r.m[i][j] = 0;
		}
	}
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 3; ++j){
			for (int k = 0; k < 3; ++k)
			{
				r.m[i][j] += m[i][k] * rh.m[k][j];
			}
		}
	}
	return r;
}

Vec3  Mat3::operator*(const Vec3 & rh) const
{
	// TODO: insertar una instrucción return aquí
	Vec3 r;

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j){
				r.m[i] += m[i][j] * rh.m[j];
		}
	}
	return r;
}


Mat3 Mat3::Identity()
{
	Mat3 result;
	return result;
	// TODO: insertar una instrucción return aquí
}

Mat3 Mat3::Translate(const float & Tx, const float & Ty)
{
	// TODO: insertar una instrucción return aquí
	Mat3 r = Mat3();

	r.m[2][2] = 1;
	r.m[0][2] = Tx;
	r.m[1][2] = Ty;
	return r;
}

Mat3  Mat3::Translate(const Vec3 & v)
{
	Mat3 r = Mat3::Translate(v.m[0], v.m[1]);
	return r;
	// TODO: insertar una instrucción return aquí
}

Mat3  Mat3::Rotate(double anglo)
{
	// TODO: insertar una instrucción return aquí
	Mat3 r = Mat3();

	r.m[0][0] = r.m[1][1] = cos(anglo*M_PI / 180);
	r.m[1][0] = sin(anglo*M_PI / 180);
	r.m[0][1] = -sin(anglo*M_PI / 180);
	return r;
}

Mat3  Mat3::Scale(float sc)
{
	// TODO: insertar una instrucción return aquí
	Mat3 r;

	r.m[2][2] = 1;
	r.m[0][0] = r.m[1][1] = sc;
	return r;
}