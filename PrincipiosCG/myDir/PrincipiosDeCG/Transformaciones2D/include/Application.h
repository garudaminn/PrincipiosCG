#pragma once

#include "BaseApplication.h"
#include "Sierpinsky.h"
#include "Mat3.h"
#include "Vec3.h"
#include <vector>



class Application :public BaseApplication
{
public:
	Sierpinsky s;
	Mat3 m;
	std::vector<Vec3> vert2;
	std::vector<Vec3> vertc;
	int cx = WIDTH/2, cy = HEIGHT/2;
	int xl, yl;
	int ir = 4;
	int ig = 1;
	int ib = 2;
	int r = 0;
	int g = 200;
	int b = 0;
	float is = 0.01;
	double ang1 = 0;
	double ang2 = 0;
	float sc = 1;

	void setup() override;
	void update() override;
	void line(int x0, int y0, int x1, int y1) ;
	void create(int lados, int radio);
	void clearScreen();
	void moveTo(int x, int y);
	void lineTo(int x, int y);
	void drawTriangle(Vec3 a, Vec3 b, Vec3 c);
	void draw() override;
};



