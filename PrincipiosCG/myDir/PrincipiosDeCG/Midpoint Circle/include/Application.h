#pragma once

#include "BaseApplication.h"
#include <vector>

class Application :public BaseApplication
{
public:
	int cx = WIDTH / 2;
	int cy = HEIGHT / 2;
	std::vector<int> x;
	std::vector<int> y;
	std::vector<int> r;
	void setup() override;
	void update() override;
	void circle(int x0, int y0, int radio) ;
	void draw() override;
};

