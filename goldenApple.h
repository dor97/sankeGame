#pragma once

#include"apple.h"
#include"raylib.h"
#include <random>

class goldenApple :public apple {
	
	int coun = rand() % 70 + 1000;
	bool show = false;
public:
	goldenApple(Color color, int screenWidth, int screenHight, float rad) : apple(color, screenWidth, screenHight, rad) {}
	void rest() { show = false; coun = rand() % 70 + 500; }
	void countOneDown();
	bool isShow() { return show; }

};