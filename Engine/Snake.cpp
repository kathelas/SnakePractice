#include "Snake.h"
#include "Keyboard.h"

Snake::Snake()
{
	length = 1;
	segments[0].loc = startloc;
	segments[0].c = headcolor;
	dloc = { 0, 0 };
	movecounter = 0;
	grow = false;
	speed = 1.5f;
	remkey = false;
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
	{
		dloc = { 0, -1 };
		remkey = true;
	}
	if( kbd.KeyIsPressed( VK_DOWN ) )
	{
		dloc = { 0, 1 };
		remkey = true;
	}
	if( kbd.KeyIsPressed( VK_LEFT ) )
	{
		dloc = { -1, 0 };
		remkey = true;
	}
	if( kbd.KeyIsPressed( VK_RIGHT ) )
	{
		dloc = { 1, 0 };
		remkey = true;
	}
}

bool Snake::Move()
{
	movecounter++;
	if( movecounter > int( 60 / speed ) )
	{
		movecounter = 0;
		remkey = false;

		if( grow )
		{
			segments[length].c = bodycolors[length % 4];
			length++;
			speed += 0.1f;
			grow = false;
		}

		if( !Inside( segments[0].loc + dloc ) || InsideSelf() )
		{
			return false;
		}

		for( int i = length - 1; i > 0; i-- )
			segments[i].loc = segments[i - 1].loc;

		segments[0].loc = segments[0].loc + dloc;

		return true;
	}

}

void Snake::Grow()
{
	grow = true;
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

const bool Snake::InsideSelf()
{
	if( length == 2 )
	{
		if( segments[0].loc + dloc == segments[1].loc )
		{
			return true;
		}
	}
	for( int i = 1; i < length - 1; i++ )
	{
		if( segments[0].loc + dloc == segments[i].loc )
		{
			return true;
		}
	}
	return false;
}


