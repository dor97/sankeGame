#include"apple.h"
//find a valid place for the apple to spawn
void apple::findPlaceToSpawn(const std::vector<std::pair<int, int>> &snake)
{
	int col = rand() % (screenWidth - (int)radius / 5 * 4) + (radius / 5 * 2);
	int row = rand() % (screenHight - (int)radius / 5 * 4) + (radius / 5 * 2);
	while (!isOpen(snake, row, col))
	{
		int col = rand() % (screenWidth - (int)radius / 5 * 4) + (radius / 5 * 2);
		int row = rand() % (screenHight - (int)radius / 5 * 4) + (radius / 5 * 2);
	}
	this->setRow(row);
	this->setCol(col);
}
//check if the spot if valid for the apple to spawn
bool apple::isOpen(const std::vector<std::pair<int, int>>& snake, int row, int col)
{
	for (int i = 0; i < snake.size(); ++i)
		if (snake[i].first == row && snake[i].second == col)
			return false;
	return true;
}

void apple::draw()
{
	DrawCircle(this->getCol() * 10 , this->getRow() * 10, radius, color);
}