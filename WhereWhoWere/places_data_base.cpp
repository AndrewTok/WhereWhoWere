#include "places_data_base.h"

places_data_base::places_data_base(const std::vector<place>& _places)
{
    places = _places;
}

void places_data_base::insert(const place& _place)
{
	places.insert(places.end(), _place);
}

std::vector<place> places_data_base::get_all_places() const
{
	return places;
}

std::vector<place> places_data_base::choose_places_by_point(const point& p) const
{
    std::vector<place> curr_places = {};
    for (auto& place : places)
    {
        if (place.contains_point(p))
        {
            curr_places.insert(curr_places.end(), place);
        }
    }
    return curr_places;
}

bool places_data_base::contains(const place& _place) const
{
    for (auto& plc : places)
    {
        if (_place == plc)
        {
            return true;
        }
   }
    return false;
}
