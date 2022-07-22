#pragma once

#include"apple.h"
#include"raylib.h"


class goldenApple :public apple {
	
	int coun = rand() % 70 + 1000;	
	bool show = false;				//golden apple is or not on the screen
public:
	goldenApple(Color color, int screenWidth, int screenHight, float rad) : apple(color, screenWidth, screenHight, rad) {}
	void rest() { show = false; coun = rand() % 70 + 500; }
	void countOneDown();
	bool isShow() { return show; }	//is golden apple on the screen or not

};