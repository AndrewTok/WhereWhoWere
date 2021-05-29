#pragma once
#include "point.h"


#include <string>

class place final
{
public:

	place() = delete;

	place(const std::string& name, const point& p1, const point& p2);

	bool contains_point(const point& pos) const;

	const std::string& get_name() const;

private:
	std::string name;
	point upper_left, lower_right;

};

