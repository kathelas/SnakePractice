#pragma once
#include "Board.h"
#include "Colors.h"
#include "Location.h"
#include "Board.h"
#include "Keyboard.h"

class Snake
{
public:
	Snake();
	void const Draw( Board& brd );
	void Update( const Keyboard& kbd );

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

	Color bodycolors[4] = { { 0, 153, 0},{ 0, 102, 0 },{ 0, 153, 0 },{ 0, 204, 0 } };
	int length;

	Segment segments[100];
	
};
