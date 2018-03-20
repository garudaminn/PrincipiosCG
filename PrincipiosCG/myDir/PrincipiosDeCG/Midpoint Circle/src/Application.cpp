#define _USE_MATH_DEFINES
#include "Application.h"
#include <math.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */



void Application::setup()
{
	srand(time(NULL));
	for (int i = 0; i < 15; ++i) {
		x.push_back(rand() % WIDTH);
		y.push_back(rand() % HEIGHT);
		r.push_back(rand() % 1024/2);
		if ((x[i] + r[i]) >= WIDTH) {
			x[i] = x[i] - (r[i] + 100);
		}
		if ((x[i] - r[i]) <= 0) {
			x[i] = x[i] + (r[i] + 100);
		}
		if ((y[i] + r[i]) >= HEIGHT) {
			y[i] = y[i] - (r[i]+100);
		}
		if ((y[i] - r[i]) <= 0) {
			y[i] = y[i] + (r[i] + 100);
		}
	}
}

void Application::update()
{
}

void Application::circle(int x0, int y0, int radio)
{
	int x = 0;
	int y = radio;
	int dstart = 1 - radio;
	int d = dstart;
	
	while (x < y) {
		putPixel(x+x0, y+y0, 0, 255, 0, 255);
		putPixel(x+x0, -y+y0,0, 255, 0, 255);
		putPixel(y+x0, x+y0, 0, 255, 0, 255);
		putPixel(-y+x0, x+y0, 0, 255, 0, 255);
		putPixel(-x + x0, y + y0, 0, 255, 0, 255);
		putPixel(-x + x0, -y + y0, 0, 255, 0, 255);
		putPixel(y + x0, -x + y0, 0, 255, 0, 255);
		putPixel(-y + x0, -x + y0, 0, 255, 0, 255);
		if (d < 0) {
			d += (2 * x) + 3;
		}
		else {
			--y;
			d += (2 * x) - (2 * y) + 5;
			
		}
		++x;
	}
}



void Application::draw()
{
	for (int i = 0; i < x.size(); ++i) {
		circle(x[i],y[i],r[i]);
	}
	
}
