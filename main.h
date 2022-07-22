#pragma once

#include"raylib.h"
#include"snake.h"
#include<string>
#include"goldenApple.h"

void cheackMove(dir& d);
bool play();
void sleep();
void gameOver(snake& p, dir d);
void checkEat(snake& p, apple& a, goldenApple& g);