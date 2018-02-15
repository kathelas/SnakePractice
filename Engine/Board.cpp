#include "Board.h"
#include <assert.h>



Board::Board( Graphics& gfx )
	:
	gfx( gfx )
{
}


void Board::DrawCell( Graphics& gfx, Location loc, Color c )
{
	assert( loc.x >= 0 );
	assert( loc.y >= 0 );
	assert( loc.x <= width );
	assert( loc.x >= height );

	for( int i = loc.x * cellsize; i < loc.x * cellsize + cellsize; i++ )
	{
		for( int j = loc.y * cellsize; j < loc.y * cellsize + cellsize; j++ )
		{
			gfx.PutPixel( i, j, c );
		}		
	}
}
