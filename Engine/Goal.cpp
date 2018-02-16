#include "Goal.h"
#include "Board.h"
#include "Snake.h"
#include <random>


Goal::Goal()
	:
	xdis( 0, Board::width - 1 ),
	ydis( 0, Board::height - 1 )
{
	std::random_device rd;
	rnd.seed( rd() );
	NewLoc();
}

bool Goal::IsEaten( Location locin )
{
	if( loc == locin )
	{
		NewLoc();
		return true;
	}
	else
		return false;
}

void const Goal::Draw( Board& brd )
{
	brd.Draw( loc, c );
}

void Goal::NewLoc()
{
	loc.x = xdis( rnd );
	loc.y = ydis( rnd );
}

bool Goal::TestSnake()
{
	return true;
}
