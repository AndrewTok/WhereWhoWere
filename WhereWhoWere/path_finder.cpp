#include "path_finder.h"

std::multimap<time_t, place> path_finder::get_user_path(const std::vector<Note>& log_arr, const std::vector<place>& places_arr, const std::string& u_name)
{
    std::multimap<time_t, place> user_places = {};
    std::vector<place> curr_places = {};
    for (auto& note : log_arr)
    {
        if (note.get_name() != u_name)
        {
            continue;
        }
        curr_places = arr_get_places(places_arr, note.get_pos());
        for (auto& plc : curr_places)
        {
            user_places.insert(std::pair<time_t, place>(note.get_ts(), plc));
        }
        //user_places[note.get_ts()] = check_places(places_arr, note.get_pos());
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

std::vector<place> path_finder::arr_get_places(const std::vector<place>& places_arr, const point& pos)
{
    std::vector<place> curr_places = {};
    for (auto& place : places_arr)
    {
        if (place.is_point_inside(pos))
        {
            curr_places.insert(curr_places.end(), place);
        }
    }
    return curr_places;
}
