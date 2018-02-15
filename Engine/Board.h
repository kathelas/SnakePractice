#pragma once
#include "Graphics.h"
#include "Location.h"
#include "Colors.h"

class Board
{
public:
	Board( Graphics& gfx);

	void Draw( Location loc, Color c );
	void DrawBorder();
private:
	void DrawCell( Graphics& gfx, Location loc, Color c );
	

	struct Border
	{
		static constexpr int size = 10;
		static constexpr Color c = Colors::Blue;
		static constexpr int padding = 5;
	};
	
	//Position of the Board
	static constexpr int xpos = 100;
	static constexpr int ypos = 100;

	static constexpr int height = 20;
	static constexpr int width = 20;
	static constexpr int cellsize = 20;
	static constexpr int padding = 1;
	

	Graphics& gfx;
	Border brdr;


};

