#pragma once

#include"point.h"
#include <vector>
#include <random>

class apple :public point {
	int screenHight, screenWidth;
	float radius;
	Color color;
public:
	apple(Color color, int screenWidth,  int screenHight, float radius) : color(color), radius(radius), screenHight(screenHight), screenWidth(screenWidth){}
	apple(int row, int col, Color color, int screenWidth, int screenHight, float radius):point(row, col), color(color), radius(radius), screenHight(screenHight), screenWidth(screenWidth) {}
	float getRadius() { return radius; }
	void findPlaceToSpawn(const std::vector<std::pair<int, int>> &snake);
	bool isOpen(const std::vector<std::pair<int, int>>& snake, int row, int col);
	void draw();
};