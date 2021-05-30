#pragma once
#include <vector>


#include "place.h"

class places_data_base final
{
public:
	places_data_base(const std::vector<place>& _places);

	places_data_base() = default;

	void insert(const place& _place);

	std::vector<place> get_all_places() const;

	std::vector<place> choose_places_by_point(const point& p) const;

	bool contains(const place& _place) const;

private:
	std::vector<place> places;
};

