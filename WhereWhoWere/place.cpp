#include "place.h"

place::place(const std::string& _name, const point& p1, const point& p2)
{
	name = _name;
	upper_left.x = (p1.x < p2.x) ? p1.x : p2.x;
	upper_left.y = (p1.y > p2.y) ? p1.y : p2.y;
	lower_right.x = (p1.x > p2.x) ? p1.x : p2.x;
	lower_right.y = (p1.y < p2.y) ? p1.y : p2.y;
}

bool place::contains_point(const point& pos) const
{

	return pos.x >= upper_left.x && pos.x <= lower_right.x && pos.y <= upper_left.y && pos.y >= lower_right.y;

}

const std::string& place::get_name() const
{
	return name;
}
