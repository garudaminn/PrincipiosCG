#define _USE_MATH_DEFINES
#include "Application.h"
#include <math.h>


void Application::setup()
{
}

void Application::update()
{
}

void Application::line(int x0, int y0, int x1, int y1) {
	if (x1 >= x0 && y1 >= y0 && abs(x1 - x0) > abs(y1 - y0)) {
		int dy = (y1 - y0);
		int	dx = (x1 - x0);
		int dinit = dy - dx / 2;
		int d = dinit;
		int x = x0;
		int y = y0;
		putPixel(x0, y0, 0, 255, 0, 255);
		for (int x = x0 + 1; x <= x1; x++) {
			if (d < 0) {// punto E
				d += dy;
			}
			else { // punto NE
				d += (dy - dx);
				++y;
			}
			putPixel(x, y, 0, 255, 0, 255);
		}
	} // oct 1

	if (x1 >= x0 && y1 >= y0 && abs(x1 - x0) <= abs(y1 - y0)) {
		int dy = (y1 - y0);
		int	dx = (x1 - x0);
		int dinit = dx - dy / 2;
		int d = dinit;
		int x = x0;
		int y = y0;
		putPixel(x0, y0, 0, 255, 0, 255);
		for (int y = y0 + 1; y <= y1; y++) {
			if (d < 0) {// punto E
				d += dx;
			}
			else { // punto NE
				d += (dx - dy);
				++x;
			}
			putPixel(x, y, 0, 255, 0, 255);
		}
	} //oct2

	if (x1 <= x0 && y1 >= y0 && abs(x1 - x0) <= abs(y1 - y0)) {
		int dy = (y1 - y0);
		int	dx = -(x1 - x0);
		int dinit = dx - dy / 2;
		int d = dinit;
		int x = x0;
		int y = y0;
		putPixel(x0, y0, 0, 255, 0, 255);
		for (int y = y0 + 1; y <= y1; y++) {
			if (d < 0) {// punto E
				d += dx;
			}
			else { // punto NE
				d += (dx - dy);
				--x;
			}
			putPixel(x, y, 0, 255, 0, 255);
		}
	} //oct 3

	if (x1 <= x0 && y1 >= y0 && abs(x1 - x0) >= abs(y1 - y0)) {
		int dy = (y1 - y0);
		int	dx = -(x1 - x0);
		int dinit = dy - dx / 2;
		int d = dinit;
		int x = x0;
		int y = y0;
		putPixel(x0, y0, 0, 255, 0, 255);
		for (int x = x0 - 1; x >= x1; x--) {
			if (d < 0) {// punto E
				d += dy;
			}
			else { // punto NE
				d += (dy - dx);
				++y;
			}
			putPixel(x, y, 0, 255, 0, 255);
		}
	}//oct 4

	if (x1 <= x0 && y1 <= y0 && abs(x1 - x0) >= abs(y1 - y0)) {
		int dy = -(y1 - y0);
		int	dx = -(x1 - x0);
		int dinit = dy - dx / 2;
		int d = dinit;
		int x = x0;
		int y = y0;
		putPixel(x0, y0, 0, 255, 0, 255);
		for (int x = x0 - 1; x >= x1; x--) {
			if (d < 0) {// punto E
				d += dy;
			}
			else { // punto NE
				d += (dy - dx);
				--y;
			}
			putPixel(x, y, 0, 255, 0, 255);
		}
	} //oct5

	if (x1 <= x0 && y1 <= y0 && abs(x1 - x0) <= abs(y1 - y0)) {
		int dy = -(y1 - y0);
		int	dx = -(x1 - x0);
		int dinit = dx - dy / 2;
		int d = dinit;
		int x = x0;
		int y = y0;
		putPixel(x0, y0, 0, 255, 0, 255);
		for (int y = y0 - 1; y >= y1; y--) {
			if (d < 0) {// punto E
				d += dx;
			}
			else { // punto NE
				d += (dx - dy);
				--x;
			}
			putPixel(x, y, 0, 255, 0, 255);
		}
	} //oct 6

	if (x1 >= x0 && y1 <= y0 && abs(x1 - x0) <= abs(y1 - y0)) {
		int dy = -(y1 - y0);
		int	dx = (x1 - x0);
		int dinit = dx - dy / 2;
		int d = dinit;
		int x = x0;
		int y = y0;
		putPixel(x0, y0, 0, 255, 0, 255);
		for (int y = y0 - 1; y >= y1; y--) {
			if (d < 0) {// punto E
				d += dx;
			}
			else { // punto NE
				d += (dx - dy);
				++x;
			}
			putPixel(x, y, 0, 255, 0, 255);
		}
	} //oct 7

	if (x1 >= x0 && y1 <= y0 && abs(x1 - x0) > abs(y1 - y0)) {
		int dy = -(y1 - y0);
		int	dx = (x1 - x0);
		int dinit = dy - dx / 2;
		int d = dinit;
		int x = x0;
		int y = y0;
		putPixel(x0, y0, 0, 255, 0, 255);
		for (int x = x0 + 1; x <= x1; x++) {
			if (d < 0) {// punto E
				d += dy;
			}
			else { // punto NE
				d += (dy - dx);
				--y;
			}
			putPixel(x, y, 0, 255, 0, 255);
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
	for (int y = 0; y < 1024; ++y) {
		for (int x = 0; x < 1024; ++x) {
			putPixel(x, y, 0, 0, 0, 255);
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
	xl = x;
	yl = y;
}

void Application::draw()
{
	int cx = WIDTH / 2;
	int cy = HEIGHT / 2;
	create(3, 300);
	clearScreen();
	create(5, 300);
	lineTo(200, cy);
	moveTo(100, 100);
	lineTo(1003, 360);
}
