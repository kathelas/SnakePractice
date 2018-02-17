#include "Snake.h"
#include "Keyboard.h"
#include "Colors.h"
#include <list>

Snake::Snake()
{
	length = 1;
	segments[0].loc = startloc;
	segments[0].c = headcolor;
	dloc = { 0, 0 };
	movecounter = 0;
	grow = false;
	speed = startspeed;
	remkey = false;
	growsize = startgrowsize;
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
	if( !remkey )
	{
		if( kbd.KeyIsPressed( VK_UP ) )
		{
			if( !(dloc == down) )
			{
				dloc = up;
				remkey = true;
			}
		}
		if( kbd.KeyIsPressed( VK_DOWN ) )
		{
			if( !(dloc == up) )
			{
				dloc = down;
				remkey = true;
			}
		}
		if( kbd.KeyIsPressed( VK_LEFT ) )
		{
			if( !(dloc == right) )
			{
				dloc = left;
				remkey = true;
			}
		}
		if( kbd.KeyIsPressed( VK_RIGHT ) )
		{
			if( !(dloc == left) )
			{
				dloc = right;
				remkey = true;
			}
		}
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
			growsize--;
			if( growsize == 0 )
			{
				speed += speedgrow;
				grow = false;
				growsize = startgrowsize;
			}
		}

		//check if inside board or inside self
		if( !Inside( segments[0].loc + dloc ) || InsideSelf() )
		{
			return false;
		}

		//move the body
		for( int i = length - 1; i > 0; i-- )
			segments[i].loc = segments[i - 1].loc;

		//move the head
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

const std::list<Location> Snake::GetList()
{
	int counter = 0;
	std::list<Location> mylist( length );
	for( std::list<Location>::iterator it = mylist.begin(); it != mylist.end(); it++ )
	{
		*it = GetSegLoc( counter );
		counter++;
	}
	return mylist;
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

	//special case
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


