#pragma once
#include "Board.h"
#include "Colors.h"
#include "Location.h"
#include "Board.h"
#include "Keyboard.h"
#include "Goal.h"
#include <list>

class Snake
{
private:
	//Settings
	static constexpr int startgrowsize = 2; //number of cells to grow
	static constexpr float speedgrow = 0.1f; //change in speed after growing

	static constexpr Location startloc = { 0, 0 };
	static constexpr Color headcolor = Colors::Yellow;

	//bodycolors (1,2,3,2)...
	static constexpr Color bc1 = { 102, 204, 0 };
	static constexpr Color bc2 = { 76, 153, 0 };
	static constexpr Color bc3 = { 51, 102, 0 };


	static constexpr int maxsegments = Board::width * Board::height;
public:
	Snake();

	const Location& headloc = segments[0].loc;

	void const Draw( Board& brd );
	void UpdateMovement( const Keyboard& kbd );
	bool Move();
	void Grow();

	const Location GetSegLoc( int in );
	const int GetLength();

	const std::list<Location> GetList();

private:
	struct Segment
	{
		Location loc;
		Color c;
	};

	const bool Inside( Location loc );
	const bool InsideSelf();

	static constexpr Location up = { 0, -1 };
	static constexpr Location down = { 0, 1 };
	static constexpr Location left = { -1, 0 };
	static constexpr Location right = { 1, 0 };

	int length;
	bool grow;
	float speed;
	int growsize;
	
	Location dloc;
	int movecounter;
	bool remkey;

	Segment segments[maxsegments];

	Color bodycolors[4] = { bc1, bc2, bc3, bc2 };
};
