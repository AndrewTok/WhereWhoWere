#pragma once
#include <vector>


#include "place.h"

class places_data_base final
{
public:

	void insert(const place& _place);

	std::vector<place> get_all_places() const;

	std::vector<place> choose_places_by_point(const point& p) const;



private:
	std::vector<place> places;
};

