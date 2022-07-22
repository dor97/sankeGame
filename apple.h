#pragma once

#include"point.h"
#include <vector>
#include <random>

class apple :public point {
	int screenHight, screenWidth;
	float rad;
	Color color;
public:
	apple(Color color, int screenWidth,  int screenHight, float rad) : color(color), rad(rad), screenHight(screenHight), screenWidth(screenWidth){}
	apple(int row, int col, Color color, int screenWidth, int screenHight, float rad):point(row, col), color(color), rad(rad), screenHight(screenHight), screenWidth(screenWidth) {}
	//int getAppleRow() { return this->getRow(); }
	//int getAppleCol() { return this->getCol(); }
	float getRadius() { return rad; }
	void findPlaceToSpawn(const std::vector<std::pair<int, int>> &snake);
	bool isOpen(const std::vector<std::pair<int, int>>& snake, int row, int col);
	void draw();
};