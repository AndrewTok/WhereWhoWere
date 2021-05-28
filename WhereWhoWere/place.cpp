#include "place.h"

bool place::is_point_inside(const point& pos) const
{
	// провериить сравнение
	return pos.x >= first_point.x && pos.x <= second_point.x && pos.y <= first_point.y && pos.y >= second_point.y;
}