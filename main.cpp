
#include"raylib.h"
#include<iostream>
#include"apple.h"
#include"shape.h"
#include<vector>
#include"snake.h"
#include"direction.h"
#include<string>
#include"goldenApple.h"

void cheackMove(dir& d);
bool play();
void sleep();
void gameOver(snake& p, dir d);
void checkEat(snake& p, apple& a, goldenApple& g);
using namespace std;

int main()
{
	InitWindow(800, 600, "Snake");
	SetTargetFPS(40);
	bool exit = false;

	while (!WindowShouldClose() && !exit)
	{
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("press space to play", 150, 250, 50, WHITE);
		if(IsKeyPressed(KEY_SPACE))
			exit = play();
		DrawFPS(10, 10);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}

bool play()
{
	apple a(RED, 800 / 10, 600 / 10, 10);
	snake p(800 / 10, 600 / 10, 10, 10);
	goldenApple g(YELLOW, 800 / 10, 600 / 10, 10);
	dir d = dir::right;
	a.findPlaceToSpawn(p.getPlayer());
	g.findPlaceToSpawn(p.getPlayer());
	bool getOut = false;
	while (!getOut)
	{
		BeginDrawing();
		ClearBackground(BLACK);
		if (WindowShouldClose())
			return true;
		g.countOneDown();
		a.draw();
		p.draw();
		cheackMove(d);
		checkEat(p, a, g);
		getOut = p.isGameOver(d);
		p.movePlayer(d);
		//getOut = p.isGameOver(d);
		DrawText((to_string(p.getScore())).c_str(), 700, 10, 20, WHITE);
		DrawFPS(10, 10);
		EndDrawing();
	}
	gameOver(p, d);
	return false;
}

void checkEat(snake& p, apple& a, goldenApple& g)
{
	if (CheckCollisionCircleRec(Vector2{ (float)a.getCol() * 10 , (float)a.getRow() * 10 }, a.getRadius(), p.getRec()))
	{
		p.scoreUp(1);
		a.findPlaceToSpawn(p.getPlayer());
	}
	if (g.isShow() && CheckCollisionCircleRec(Vector2{ (float)g.getCol() * 10 , (float)g.getRow() * 10 }, g.getRadius(), p.getRec()))
	{
		p.scoreUp(5);
		g.findPlaceToSpawn(p.getPlayer());
		g.rest();
	}
}

void gameOver(snake& p, dir d)
{
	p.movePlayer(d);
	BeginDrawing();
	p.draw();
	DrawText("game over!!", 250, 250, 50, RED);
	EndDrawing();
	sleep();
}

void sleep()
{
	double time = GetTime() + 1;
	while (time > GetTime()) {}
}

void cheackMove(dir &d)
{
	if (IsKeyPressed(KEY_W) && d != dir::down)
		d = dir::up;
	else if (IsKeyPressed(KEY_D) && d != dir::left)
		d = dir::right;
	else if (IsKeyPressed(KEY_S) && d != dir::up)
		d = dir::down;
	else if (IsKeyPressed(KEY_A) && d != dir::right)
		d = dir::left;
}