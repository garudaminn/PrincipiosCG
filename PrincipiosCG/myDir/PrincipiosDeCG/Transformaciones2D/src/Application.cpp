#define _USE_MATH_DEFINES
#include "Application.h"
#include <math.h>
#include <iostream>
#include "Vec3.h"
#include "Mat3.h"

void Application::setup()
{
	Vec3 a, b, c;
	

	a.m[0] = cx - 200;
	b.m[0] = cx + 200;
	c.m[0] = cx;
	a.m[1] = b.m[1] = cy + 200;
	c.m[1] = cy - 200;
	s.generate(a, b, c, 3);
	vert2 = s.vert;

}

void Application::update()
{
	//vertc.clear();
	vertc = vert2;
	Mat3 trans= m.Translate(cx,cy)*m.Rotate(ang2)* m.Translate(300,0)*m.Scale(sc)*m.Rotate(ang1)*m.Translate(-cx,-cy);
	
	for (int i = 0; i < vert2.size(); ++i) {
		vertc[i] = trans* vertc[i];
	}
	
	ang1 += 3;
	ang2 -= .6;
	sc += is;
	r += ir;
	g += ig;
	b += ib;
	if (r >= 200) {
		ir = -ir;
	}
	else if (r <= 0) {
		ir = -ir;
	}
	if (g >= 200) {
		ig = -ig;
	}
	else if (g <= 0) {
		ig = -ig;
	}
	if (b >= 200) {
		ib = -ib;
	}
	else if (b <= 0) {
		ib = -ib;
	}
	if (sc >= 1.3) {
		is = -is;
	}
	else if (sc <= 0.9) {
		is = -is;
	}
	if (ang1 >= 360) {
		ang1 = 0;
	}
	if (ang2 <= -360) {
		ang2 = 0;
	}

}

void Application::line(int x0, int y0, int x1, int y1) {
	if (x1 >= x0 && y1 >= y0 && abs(x1 - x0) > abs(y1 - y0)) {
		int dy = (y1 - y0);
		int	dx = (x1 - x0);
		int dinit = dy - dx / 2;
		int d = dinit;
		int x = x0;
		int y = y0;
		putPixel(x, y, r, g, b, 255);
		for (int x = x0 + 1; x <= x1; x++) {
			if (d < 0) {// punto E
				d += dy;
			}
			else { // punto NE
				d += (dy - dx);
				++y;
			}
			putPixel(x, y, r, g, b, 255);
		}
	} // oct 1

	if (x1 >= x0 && y1 >= y0 && abs(x1 - x0) <= abs(y1 - y0)) {
		int dy = (y1 - y0);
		int	dx = (x1 - x0);
		int dinit = dx - dy / 2;
		int d = dinit;
		int x = x0;
		int y = y0;
		putPixel(x, y, r, g, b, 255);
		for (int y = y0 + 1; y <= y1; y++) {
			if (d < 0) {// punto E
				d += dx;
			}
			else { // punto NE
				d += (dx - dy);
				++x;
			}
			putPixel(x, y, r, g, b, 255);
		}
	} //oct2

	if (x1 <= x0 && y1 >= y0 && abs(x1 - x0) <= abs(y1 - y0)) {
		int dy = (y1 - y0);
		int	dx = -(x1 - x0);
		int dinit = dx - dy / 2;
		int d = dinit;
		int x = x0;
		int y = y0;
		putPixel(x, y, r, g, b, 255);
		for (int y = y0 + 1; y <= y1; y++) {
			if (d < 0) {// punto E
				d += dx;
			}
			else { // punto NE
				d += (dx - dy);
				--x;
			}
			putPixel(x, y, r, g, b, 255);
		}
	} //oct 3

	if (x1 <= x0 && y1 >= y0 && abs(x1 - x0) >= abs(y1 - y0)) {
		int dy = (y1 - y0);
		int	dx = -(x1 - x0);
		int dinit = dy - dx / 2;
		int d = dinit;
		int x = x0;
		int y = y0;
		putPixel(x, y, r, g, b, 255);
		for (int x = x0 - 1; x >= x1; x--) {
			if (d < 0) {// punto E
				d += dy;
			}
			else { // punto NE
				d += (dy - dx);
				++y;
			}
			putPixel(x, y, r, g, b, 255);
		}
	}//oct 4

	if (x1 <= x0 && y1 <= y0 && abs(x1 - x0) >= abs(y1 - y0)) {
		int dy = -(y1 - y0);
		int	dx = -(x1 - x0);
		int dinit = dy - dx / 2;
		int d = dinit;
		int x = x0;
		int y = y0;
		putPixel(x, y, r, g, b, 255);
		for (int x = x0 - 1; x >= x1; x--) {
			if (d < 0) {// punto E
				d += dy;
			}
			else { // punto NE
				d += (dy - dx);
				--y;
			}
			putPixel(x, y, r, g, b, 255);
		}
	} //oct5

	if (x1 <= x0 && y1 <= y0 && abs(x1 - x0) <= abs(y1 - y0)) {
		int dy = -(y1 - y0);
		int	dx = -(x1 - x0);
		int dinit = dx - dy / 2;
		int d = dinit;
		int x = x0;
		int y = y0;
		putPixel(x, y, r, g, b, 255);
		for (int y = y0 - 1; y >= y1; y--) {
			if (d < 0) {// punto E
				d += dx;
			}
			else { // punto NE
				d += (dx - dy);
				--x;
			}
			putPixel(x, y, r, g, b, 255);
		}
	} //oct 6

	if (x1 >= x0 && y1 <= y0 && abs(x1 - x0) <= abs(y1 - y0)) {
		int dy = -(y1 - y0);
		int	dx = (x1 - x0);
		int dinit = dx - dy / 2;
		int d = dinit;
		int x = x0;
		int y = y0;
		putPixel(x, y, r, g, b, 255);
		for (int y = y0 - 1; y >= y1; y--) {
			if (d < 0) {// punto E
				d += dx;
			}
			else { // punto NE
				d += (dx - dy);
				++x;
			}
			putPixel(x, y, r, g, b, 255);
		}
	} //oct 7

	if (x1 >= x0 && y1 <= y0 && abs(x1 - x0) > abs(y1 - y0)) {
		int dy = -(y1 - y0);
		int	dx = (x1 - x0);
		int dinit = dy - dx / 2;
		int d = dinit;
		int x = x0;
		int y = y0;
		putPixel(x, y, r, g, b, 255);
		for (int x = x0 + 1; x <= x1; x++) {
			if (d < 0) {// punto E
				d += dy;
			}
			else { // punto NE
				d += (dy - dx);
				--y;
			}
			putPixel(x, y, r, g, b, 255);
		}
	}
}

void Application::create(int lados, int radio)
{
	int cx = WIDTH / 2;
	int cy = HEIGHT / 2;
	int x0 = radio;
	int y0 = 0;
	int x1, y1;
	if (lados >= 3 && lados <= 360) {
		float ang = 360 / lados;
		for (float angle = 0; angle < 360; angle += ang) {
			x1 = radio * cos(angle*M_PI / 180);
			y1 = radio * sin(angle*M_PI / 180);
			line(cx + x0, cy + y0, cx + x1, cy + y1);
			x0 = x1;
			y0 = y1;
		}
		line(cx + x0, cy + y0, cx + radio, cy);
	}
	else {
		std::cout << "cantidad de lados no valida" << std::endl;
	}
	xl = radio;
	yl = cy;
}

void Application::clearScreen()
{
	for (int y = 0; y < 1023; ++y) {
		for (int x = 0; x < 1023; ++x) {
			putPixel(x,y,0,0,0,255);
		}
	}
}

void Application::moveTo(int x, int y)
{
	xl = x;
	yl = y;
}

void Application::lineTo(int x, int y)
{
	line(xl, yl, x, y);
	moveTo(x, y);
}

void Application::drawTriangle(Vec3 a, Vec3 b, Vec3 c)
{
	moveTo(a.x(), a.y());
	lineTo(b.x(), b.y());
	lineTo(c.x(), c.y());
	lineTo(a.x(), a.y());
}

void Application::draw()
{
	clearScreen();
	for (int i = 0; i < s.vert.size(); i+=3) {
		drawTriangle(vertc[i], vertc[i + 1], vertc[i + 2]);
	}	
}







