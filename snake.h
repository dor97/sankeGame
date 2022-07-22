#pragma once

#include"point.h"
#include<vector>
#include"direction.h"

class snake :public point {
	int screenHight, screenWidth;
	int width, hight;
	Color color = GREEN;
	std::vector<std::pair<int, int>> player;
	int size = 1;
	int score = 0;
	bool sizeUp = false;
	int val = 10;

public:
	snake(int screenWidth, int screenHight, int width, int hight) : screenHight(screenHight), screenWidth(screenWidth), width(width), hight(hight) { player.push_back(std::make_pair(screenHight * 10 / 2, screenWidth * 10 / 2)); }
	int getScore() { return score; }
	int getSize() { return size; }
	const std::vector<std::pair<int, int>>& getPlayer() { return player; }
	void movePlayer(dir d);
	void draw();
	Rectangle getRec();
	void scoreUp(int up) { sizeUp = true; score += up;}
	bool isGameOver(dir d);
	std::pair<int, int> whereTo(std::pair<int,int> pos, dir d);

};