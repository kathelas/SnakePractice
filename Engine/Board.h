#pragma once
#include "Graphics.h"
#include "Location.h"
#include "Colors.h"

class Board
{
public:
	Board( Graphics& gfx);

	void DrawCell( Graphics& gfx, Location loc, Color c );
private:
	

	static constexpr int height = 20;
	static constexpr int width = 20;
	static constexpr int cellsize = 10;

	Graphics& gfx;


};

