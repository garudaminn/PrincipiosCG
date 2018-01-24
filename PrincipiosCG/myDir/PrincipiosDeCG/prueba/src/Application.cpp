#include "Application.h"



void Application::setup()
{
}

void Application::update()
{
}

void Application::draw()
{
	for (int i = 0; i < WIDTH; i++) {
		putPixel(i, HEIGHT / 2, 0, 255, 0, 255);
		putPixel(i, i, 0, 255, 0, 255);
		putPixel(WIDTH - i, i, 0, 255, 0, 255);
	}
	for (int i = 0; i < HEIGHT; i++) {
		putPixel(WIDTH / 2,i, 0, 255, 0, 255);
	}

}
