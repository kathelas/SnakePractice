#pragma once
#include "Location.h"
#include "Snake.h"
#include "Board.h"
#include "Colors.h"
#include <random>
#include <list>

class Goal
{
private:
	//Settings
	static constexpr Color c = { 204, 102, 0 };	//Goalcolor

public:
	Goal();
	bool IsEaten( Location locin );

	void const Draw( Board& brd );

	bool TestSnake( std::list<Location> listin );

	void NewLoc();

private:
	Location loc;

	std::mt19937 rnd;
	std::uniform_int_distribution<int> xdis;
	std::uniform_int_distribution<int> ydis;


};