#pragma once
#include "Board.h"
#include "Colors.h"
#include "Location.h"
#include "Board.h"

class Snake
{
public:
	Snake();
	void Draw( Board& brd );

private:
	class Segment
	{
	public:
		Location loc;
		Color c;
	};

	static constexpr Location startloc = { 0, 0 };
	static constexpr int maxsegments = 100;
	static constexpr Color headcolor = Colors::Green;

	int length;

	Segment segments[100];
	
};
