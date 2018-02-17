#pragma once
#include "Graphics.h"
#include "Location.h"
#include "Colors.h"

class Board
{
	//Settings
public:
	static constexpr int height = 20;
	static constexpr int width = 20;
private:
	//Position of the Board
	static constexpr int xpos = 100;
	static constexpr int ypos = 100;

	static constexpr int cellsize = 20;
	static constexpr int padding = 1;

public:
	Board( Graphics& gfx);

	void Draw( Location loc, Color c );
	void DrawBorder();

private:
	struct Border
	{
		//Settings (Border)
		static constexpr int size = 10;
		static constexpr Color c = { 0, 102, 204 };
		static constexpr int padding = 8;
	};
	
	Graphics& gfx;
	Border brdr;
};

