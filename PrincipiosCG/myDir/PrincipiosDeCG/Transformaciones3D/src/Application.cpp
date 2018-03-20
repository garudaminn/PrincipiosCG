#define _USE_MATH_DEFINES
#include "Application.h"
#include <math.h>
#include <iostream>
#include "Vec4.h"
#include "Mat4.h"

void Application::setup()
{
	Vec4 a, b, c, d, e, f, g, h;
	a.m[0] = c.m[0] = e.m[0] = g.m [0] = 100;
	b.m[0] = d.m[0] = f.m[0] = h.m[0] = -100;
	a.m[1] = b.m[1] = e.m[1] = f.m[1] = 100;
	c.m[1] = d.m[1] = g.m[1] = h.m[1] = -100;
	a.m[2] = b.m[2] = c.m[2] = d.m[2] = -100;
	e.m[2] = f.m[2] = g.m[2] = h.m[2] =100;
	s.generateCube(a, b, c, d, e, f, g, h);

	target = new Vec4(0, 0, 0);
	eye = new Vec4(0,0,-100);
	up = new Vec4(eye->m[0],eye->m[1]+1000,eye->m[2]);
}

void Application::update()
{
	vertc.clear();
	Mat4 trans = m.Perspective(50, WIDTH / HEIGHT, 0.01, 100) * m.LookAt(*eye, *target, *up)*m.Translate(cx, cy, 0)*m.RotateZ(ang2*2)*m.RotateY(ang1) * m.Translate(300,0,0)*  m.RotateX(ang2) * m.RotateY(ang1*2);
	
	for (int i = 0; i < s.vert4.size(); ++i) {
		vertc.push_back(trans * s.vert4[i]);
	}
	
	ang1 += 1.07;
	ang2 -= .48;
	sc = .8 * sin( ang1*M_PI / 180) + 1;
	
	r = 210 * sin(ang1*M_PI / 180) + 1;
	g = 210 * cos(ang2*M_PI / 180) + 1;
	b = 210 * tan(ang1*M_PI / 180) + 1;

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

void Application::drawTriangle(Vec4 a, Vec4 b, Vec4 c)
{
	moveTo(a.x(), a.y());
	lineTo(b.x(), b.y());
	lineTo(c.x(), c.y());
	lineTo(a.x(), a.y());
}

void Application::draw()
{
	clearScreen();
	for (int i = 0; i < s.vert4.size(); i+=3) {
		drawTriangle(vertc[i], vertc[i + 1], vertc[i + 2]);
		//drawTriangle(s.vert4[i], s.vert4[i + 1], s.vert4[i + 2]);
	}	
}







