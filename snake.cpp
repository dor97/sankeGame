
#include"snake.h"

void snake::movePlayer(dir d)
{
	if (sizeUp)
	{
		player.push_back(player[size - 1]);
		++size;
		sizeUp = false;
	}
	for (int i = size - 1; i > 0; --i)
		player[i] = player[i - 1];
	if (d == dir::up)
		player[0].first -= val;
	else if (d == dir::right)
		player[0].second += val;
	else if(d == dir::left)
		player[0].second -= val;
	else
		player[0].first += val;

}

void snake::draw()
{
	for (int i = 0; i < size; ++i)
		DrawRectangle(player[i].second, player[i].first, width, hight, color);
}
//return the head of the snake
Rectangle snake::getRec()
{
	return Rectangle{ (float)player[0].second, (float)player[0].first, (float)width, (float)hight };
}
//check if snake run into himself or a wall
bool snake::isGameOver(dir d)
{
	std::pair<int, int> pos = whereTo(player[0], d);
	if (pos.first < 0 || pos.first > 600)
		return true;
	if (pos.second < 0 || pos.second > 800)
		return true;
	for (int i = 0; i < size; ++i)
		if(pos == player[i])
			return true;
	return false;
}
//return where the location of the snake in the next move 
std::pair<int, int> snake::whereTo(std::pair<int, int> pos, dir d)
{
	if (d == dir::up)
		pos.first -= val;
	else if (d == dir::right)
		pos.second += val;
	else if (d == dir::left)
		pos.second -= val;
	else
		pos.first += val;
	return pos;
}