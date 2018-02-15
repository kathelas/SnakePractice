#include "Snake.h"

Snake::Snake()
{
	length = 1;
	segments[0].loc = startloc;
	segments[0].c = headcolor;
}

void Snake::Draw( Board& brd )
{
	for( int i = 0; i < length; i++ )
	{
		brd.Draw( segments[i].loc, segments[i].c );
	}
}
