#pragma once
#include "Location.h"
#include "Snake.h"
#include "Board.h"
#include "Colors.h"
#include <random>

class Goal
{
public:
	Goal();
	bool IsEaten( Location locin );
	void const Draw( Board& brd );


private:
	Location loc;
	Color c = { 204, 102, 0 };

	std::mt19937 rnd;
	std::uniform_int_distribution<int> xdis;
	std::uniform_int_distribution<int> ydis;

	void NewLoc();

	bool TestSnake();

	

};