#pragma once

#include "BaseApplication.h"

class Application :public BaseApplication
{
public:
	int xl = WIDTH/2, yl = HEIGHT/2;
	void setup() override;
	void update() override;
	void line(int x0, int y0, int x1, int y1) ;
	void create(int lados, int radio);
	void clearScreen();
	void moveTo(int x, int y);
	void lineTo(int x, int y);
	void draw() override;
};

