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

void Application::draw()
{
	int cx = WIDTH / 2;
	int cy = HEIGHT / 2;
	for (int angle = 0; angle < 360; ++angle) {
		int x = 300 * cos(angle*M_PI / 180);
		int y = 300 * sin(angle*M_PI / 180);
		line (cx,cy,x+cx,y+cy);
	
	}
}
