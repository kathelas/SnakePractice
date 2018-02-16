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
	void Grow();

	const Location GetSegLoc( int in );
	const int GetLength();

private:
	class Segment
	{
	public:
		Location loc;
		Color c;
	};

	const bool Inside( Location loc );
	const bool InsideSelf();

	static constexpr Location startloc = { 0, 0 };
	static constexpr int maxsegments = 100;
	static constexpr Color headcolor = Colors::Yellow;

	Color bc1 = { 102, 204, 0 };
	Color bc2 = { 76, 153, 0 };
	Color bc3 = { 51, 102, 0 };


	Color bodycolors[4] = { bc1, bc2, bc3, bc2 };

	int length;
	bool grow;
	float speed;

	Location dloc;
	int movecounter;
	bool remkey;

	Segment segments[100];


};
