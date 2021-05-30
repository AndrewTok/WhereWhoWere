#pragma once

class point final
{
	//bool is_point_inside_of_place(const place& _place) const;
public:
	bool operator== (const point & p) const;
	int x;
	int y;
};

