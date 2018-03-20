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
	eye = new Vec4(50,-20,-100);
	up = new Vec4(eye->m[0],eye->m[1]+1000,eye->m[2]);
}

void Application::update()
{
	trans.clear();
	vert1.clear();
	vert2.clear();
	vert3.clear();
	vert4.clear();
	vert5.clear();
	vert6.clear();
	vert7.clear();
	vert8.clear();
	vert9.clear();
	vert10.clear();
	vert11.clear();
	trans.push_back(m.Translate(cx+100, cy+150, 0)*m.RotateY(ang1/3)*m.Translate(380,0,0)*m.Scale(0.5,0.5,0.5)); //coxis
	trans.push_back(trans[0]*m.Translate(0, -270, 0));//torso
	trans.push_back(trans[1]* m.Translate(0, -300, 0));//cabeza
	trans.push_back(trans[1] * m.Translate(170,10,0) *m.Translate(-100, -100, 0)* m.RotateX(45*sin(ang1*M_PI/180))*m.Translate(100,100,0));//brazo derecho
	trans.push_back(trans[3] * m.Translate(0, 350, 0) *m.Translate(-100, -100, 0)* m.RotateX(45 * sin(ang1*M_PI / 180)-45)*m.Translate(100, 100, 0)); //antebrazo derecho 
	trans.push_back(trans[1] * m.Translate(-170, 10, 0)*m.Translate(-100, -100, 0)* m.RotateX(-45 * sin(ang1*M_PI / 180))*m.Translate(100, 100, 0));//brazo izquierdo
	trans.push_back(trans[5] * m.Translate(0, 350, 0)*m.Translate(0, -100, 0)* m.RotateX(-45 * sin(ang1*M_PI / 180)-45)*m.Translate(0, 100, 0));//antebrazo izquierdo
	trans.push_back(trans[0] * m.Translate(60, 200, 0)*m.Translate(0, -100, 0)* m.RotateX(-45 * sin(ang1*M_PI / 180))*m.Translate(0, 100, 0));//muslo derecha
	trans.push_back(trans[7] * m.Translate(0, 280, 0)*m.Translate(0, -100, 0)* m.RotateX(-45 * sin(ang1*M_PI / 180)+45)*m.Translate(0, 100, 0));//pierna derecho
	trans.push_back(trans[0] * m.Translate(-60, 200, 0)*m.Translate(0, -100, 0)* m.RotateX(45 * sin(ang1*M_PI / 180))*m.Translate(0, 100, 0)); //muslo izq
	trans.push_back(trans[9] * m.Translate(0, 280, 0)*m.Translate(0, -100, 0)* m.RotateX(45 * sin(ang1*M_PI / 180)+45)*m.Translate(0, 100, 0));//pierna izq
	trans[0] = trans[0] * m.Scale(1, 0.5, 0.5);//coxis
	trans[1] = trans[1] * m.Scale(1, 2, 0.5);//torso
	trans[2] = trans[2] * m.Scale(0.5, 0.75, 0.75); //cabeza
	trans[3] = trans[3] * m.Scale(0.4, 2, 0.7); //brazo derecho
	trans[4] = trans[4] * m.Scale(0.4, 1.4, 0.7);//antebrazo derecho
	trans[5] = trans[5] * m.Scale(0.4, 2, 0.7);//brazo izquierdo 
	trans[6] = trans[6] * m.Scale(0.4, 1.4, 0.7);//antebrazo izquierdo
	trans[7] = trans[7] * m.Scale(0.5, 1.3, 0.8);//muslo derecho
	trans[8] = trans[8] * m.Scale(0.5, 1.3, 0.8);//pierna derecha
	trans[9] = trans[9] * m.Scale(0.5, 1.3, 0.8);//muslo izq
	trans[10] = trans[10] * m.Scale(0.5, 1.3, 0.8);//pierna izq

	for (int i = 0; i < trans.size(); ++i) {
		trans[i] = m.Perspective(50, WIDTH / HEIGHT, 0.01, 100) * m.LookAt(*eye, *target, *up)* trans[i];
	}
	for (int i = 0; i < s.vert4.size(); ++i) {
		vert1.push_back(trans[0] * s.vert4[i]);
		vert2.push_back(trans[1] * s.vert4[i]);
		vert3.push_back(trans[2] * s.vert4[i]);
		vert4.push_back(trans[3] * s.vert4[i]);
		vert5.push_back(trans[4] * s.vert4[i]);
		vert6.push_back(trans[5] * s.vert4[i]);
		vert7.push_back(trans[6] * s.vert4[i]);
		vert8.push_back(trans[7] * s.vert4[i]);
		vert9.push_back(trans[8] * s.vert4[i]);
		vert10.push_back(trans[9] * s.vert4[i]);
		vert11.push_back(trans[10] * s.vert4[i]);
	}
	
	ang1 += 4;
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
		drawTriangle(vert1[i], vert1[i + 1], vert1[i + 2]);
		drawTriangle(vert2[i], vert2[i + 1], vert2[i + 2]);
		drawTriangle(vert3[i], vert3[i + 1], vert3[i + 2]);
		drawTriangle(vert4[i], vert4[i + 1], vert4[i + 2]);
		drawTriangle(vert5[i], vert5[i + 1], vert5[i + 2]);
		drawTriangle(vert6[i], vert6[i + 1], vert6[i + 2]);
		drawTriangle(vert7[i], vert7[i + 1], vert7[i + 2]);
		drawTriangle(vert8[i], vert8[i + 1], vert8[i + 2]);
		drawTriangle(vert9[i], vert9[i + 1], vert9[i + 2]);
		drawTriangle(vert10[i], vert10[i + 1], vert10[i + 2]);
		drawTriangle(vert11[i], vert11[i + 1], vert11[i + 2]);
	}	
}







