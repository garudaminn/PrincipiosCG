#pragma once

#include "BaseApplication.h"

class Application :public BaseApplication
{
public:
	void setup() override;
	void update() override;
	void line(int x0, int y0, int x1, int y1) ;
	void draw() override;
};

