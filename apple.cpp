#include"apple.h"

void apple::findPlaceToSpawn(const std::vector<std::pair<int, int>> &snake)
{
	int col = rand() % (screenWidth - (int)rad / 5 * 4) + (rad / 5 * 2);
	int row = rand() % (screenHight - (int)rad / 5 * 4) + (rad / 5 * 2);
	while (!isOpen(snake, row, col))
	{
		int col = rand() % (screenWidth - (int)rad / 5 * 4) + (rad / 5 * 2);
		int row = rand() % (screenHight - (int)rad / 5 * 4) + (rad / 5 * 2);
	}
	this->setRow(row);
	this->setCol(col);
}

bool apple::isOpen(const std::vector<std::pair<int, int>>& snake, int row, int col)
{
	for (int i = 0; i < snake.size(); ++i)
		if (snake[i].first == row && snake[i].second == col)
			return false;
	return true;
}

void apple::draw()
{
	DrawCircle(this->getCol() * 10 , this->getRow() * 10, rad, color);
}