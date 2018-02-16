#include "Goal.h"

Goal::Goal()
{
}

bool Goal::Eating( Location locin )
{
	return (loc == locin);
}
