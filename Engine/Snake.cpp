#include "Snake.h"
#include "Keyboard.h"

Snake::Snake()
{
	length = 1;
	segments[0].loc = startloc;
	segments[0].c = headcolor;
	dloc = { 0, 0 };
	movecounter = 0;
}

void const Snake::Draw( Board& brd )
{
	for( int i = 0; i < length; i++ )
	{
		brd.Draw( segments[i].loc, segments[i].c );
	}
}

void Snake::UpdateMovement( const Keyboard& kbd )
{
	if( kbd.KeyIsPressed( VK_UP ) )
		dloc = { 0, -1 };
	if( kbd.KeyIsPressed( VK_DOWN ) )
		dloc = { 0, 1 };
	if( kbd.KeyIsPressed( VK_LEFT ) )
		dloc = { -1, 0 };
	if( kbd.KeyIsPressed( VK_RIGHT ) )
		dloc = { 1, 0 };
}

bool Snake::Move()
{
	movecounter++;
	if( movecounter > 60 )
	{
		movecounter = 0;

		for( int i = length - 1; i > 0; i-- )
			segments[i].loc = segments[i - 1].loc;

		segments[0].loc = segments[0].loc + dloc;

		if( !Inside( segments[0].loc ) )
		{
			segments[0].loc = segments[0].loc - dloc;
			return false;
		}
		else
			return true;
	}

}

void Snake::Grow()
{
}

const Location Snake::GetSegLoc( int in )
{
	if( in >= 0 && in < length )
	{
		return segments[in].loc;
	}
}

const int Snake::GetLength()
{
	return length;
}

const bool Snake::Inside( Location loc )
{
	if( loc.x < 0 || loc.y < 0 || loc.x >= Board::width || loc.y >= Board::height )
		return false;
	else
		return true;
}


