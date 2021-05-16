#include "path_finder.h"

std::map<time_t, place> path_finder::get_user_path(const std::vector<Note>& log_arr, const std::vector<place>& places_arr, const std::string& u_name)
{
    std::map<time_t, place> user_places = {};
    for (auto& note : log_arr)
    {
        if (note.get_name() != u_name)
        {
            continue;
        }
        user_places[note.get_ts()] = check_places(places_arr, note.get_pos());
    }
    return user_places;
}

place path_finder::check_places(const std::vector<place>& places_arr, const point& pos)
{
    for (auto& place : places_arr)
    {
        if (place.is_point_inside(pos))
        {
            return place;
        }
    }
    place invalid_place;
    invalid_place.name = {"no place"};
    invalid_place.first_point = { 0, 0 };
    invalid_place.second_point = { 0, 0 };
    return invalid_place;
}
