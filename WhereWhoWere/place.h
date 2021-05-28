#pragma once
#include "point.h"
#include <string>
class place
{
public:
	bool is_point_inside(const point& pos) const;

private:
	std::string name;
	point first_point, second_point; // first - лева€ верхн€€, second - нижн€€ права€

};

