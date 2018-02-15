#include "Board.h"
#include <assert.h>



Board::Board( Graphics& gfx )
	:
	gfx( gfx )
{
}

void Board::Draw( Location loc, Color c )
{
	DrawCell( gfx, loc, c );
}


void Board::DrawCell( Graphics& gfx, Location loc, Color c )
{
	assert( loc.x >= 0 );
	assert( loc.y >= 0 );
	assert( loc.x <= width );
	assert( loc.y <= height );


	for( int i = xpos + loc.x * cellsize + padding + brdr.size; i < xpos + loc.x * cellsize + cellsize - padding + brdr.size; i++ )
	{
		for( int j = ypos + loc.y * cellsize + padding + brdr.size; j < ypos + loc.y * cellsize + cellsize - padding + brdr.size; j++ )
		{
			gfx.PutPixel( i, j, c );
		}		
	}
}

void Board::DrawBorder()
{
	//top
	for( int i = xpos; i < xpos + width * cellsize + 2 * brdr.size ; i++ )
	{
		for( int j = ypos; j < ypos + brdr.size - brdr.padding; j++ )
		{
			gfx.PutPixel( i, j, brdr.c );
		}
	}

	//left
	for( int i = xpos; i < xpos + brdr.size - brdr.padding; i++ )
	{
		for( int j = ypos + brdr.size - brdr.padding; j < ypos + height * cellsize + 2 * brdr.size; j++ )
		{
			gfx.PutPixel( i, j, brdr.c );
		}
	}

	//right
	for( int i = xpos + width * cellsize + brdr.size + brdr.padding; i < xpos + width * cellsize + 2 * brdr.size; i++ )
	{
		for( int j = ypos + brdr.size - brdr.padding; j < ypos + height * cellsize + 2 * brdr.size; j++ )
		{
			gfx.PutPixel( i, j, brdr.c );
		}
	}

	//bottom
	for( int i = xpos + brdr.size - brdr.padding; i < xpos + width * cellsize + brdr.size + brdr.padding; i++ )
	{
		for( int j = ypos + height * cellsize + brdr.size + brdr.padding; j < ypos + height * cellsize + 2 * brdr.size; j++ )
		{
			gfx.PutPixel( i, j, brdr.c );
		}
	}
}
