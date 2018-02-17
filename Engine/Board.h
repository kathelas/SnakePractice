#pragma once
#include "Graphics.h"
#include "Location.h"
#include "Colors.h"
#include <math.h>

class Board
{
	//Settings
public:
	static constexpr int height = 15;
	static constexpr int width = 15;
private:
	//Position of the Board
	static constexpr int xpos = 50;
	static constexpr int ypos = 50;

	static constexpr int cellsize = 30;
	static constexpr int padding = 1;

public:
	Board( Graphics& gfx);

	void Draw( Location loc, Color c );
	void DrawCircle( Location loc, Color c );
	void DrawBorder();

private:
	struct Border
	{
		//Settings (Border)
		static constexpr int size = 10;
		static constexpr Color c = { 0, 102, 204 };
		static constexpr int padding = 8;
	};

	int radiussqr = (int) std::pow( (cellsize / 2 - padding), 2 );
	
	Graphics& gfx;
	Border brdr;
};

