#pragma once

struct Location
{
	int x;
	int y;

	Location operator+( const Location& loc ) const
	{
		Location result;
		result.x = this->x + loc.x;
		result.y = this->y + loc.y;
		return result;
	}

	Location operator-( const Location& loc ) const
	{
		Location result;
		result.x = this->x - loc.x;
		result.y = this->y - loc.y;
		return result;
	}

	bool operator==( const Location& loc ) const
	{
		return (this->x == loc.x && this->y == loc.y);
	}
};