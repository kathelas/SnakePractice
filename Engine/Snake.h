#pragma once
#include "Board.h"
#include "Colors.h"
#include "Location.h"
#include "Board.h"
#include "Keyboard.h"
#include "Goal.h"

class Snake
{
public:
	Snake();

	const Location& headloc = segments[0].loc;

	void const Draw( Board& brd );
	void UpdateMovement( const Keyboard& kbd );
	bool Move();

private:
	class Segment
	{
	public:
		Location loc;
		Color c;
	};

	bool Inside( Location loc );

	static constexpr Location startloc = { 0, 0 };
	static constexpr int maxsegments = 100;
	static constexpr Color headcolor = Colors::Green;


	Color bodycolors[4] = { { 0, 153, 0},{ 0, 102, 0 },{ 0, 153, 0 },{ 0, 204, 0 } };

	int length;

	Location dloc;
	int movecounter;

	Segment segments[100];

};
