#pragma once
#include "Location.h"
#include "Snake.h"

class Goal
{
public:
	Goal();
	bool Eating( Location locin );
private:
	Location loc;

};