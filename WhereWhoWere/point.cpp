#include "point.h"

//bool point::is_point_inside_of_place(const place& _place) const
//{
//	return _place.contains_point(*this);
//}

bool point::operator==(const point& p) const
{
    return (p.x == x) && (p.y == y);
}
