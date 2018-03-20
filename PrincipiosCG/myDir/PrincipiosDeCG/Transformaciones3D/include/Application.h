#pragma once

#include "BaseApplication.h"
#include "Sierpinsky.h"
#include "Mat4.h"
#include "Vec4.h"
#include <vector>



class Application :public BaseApplication
{
public:
	Sierpinsky s;
	Mat4 m;
	std::vector<Vec4> vertc;
	int cx = WIDTH/2, cy = HEIGHT/2, cz = 0;
	Vec4 *target, *eye, *up;
	int xl, yl;
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
	void drawTriangle(Vec4 a, Vec4 b, Vec4 c);
	void draw() override;
};



