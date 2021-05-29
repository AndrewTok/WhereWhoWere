#pragma once
#include <string>
#include <vector>
#include <map>
#include <ctime>

#include "place.h"
#include "point.h"
#include "user_position_info.h"
#include "places_data_base.h"
#include "user.h"
#include "users_positions_data_base.h"

//struct point
//{
//	int x;
//	int y;
//};
//
//struct place
//{
//	std::string name;
//	point first_point, second_point; // first - лева€ верхн€€, second - нижн€€ права€
//	bool is_point_inside(const point& pos) const
//	{
//		return pos.x >= first_point.x && pos.x <= second_point.x && pos.y <= first_point.y && pos.y >= second_point.y;
//	}
//};
//
//struct Note
//{
//	time_t ts; // timestamp of the operation
//	std::string name; // person's id
//	point pos; // координаты
//	std::string get_name() const
//	{
//		return name;
//	}
//
//	time_t get_ts() const
//	{
//		return ts;
//	}
//
//	point get_pos() const 
//	{
//		return pos;
//	}
//};

class path_finder final
{
public:

	//std::multimap<time_t, place> get_user_path(const std::vector<users_file_line>& parsed_file, const std::vector<place>& places_arr, const std::string& u_name);
	
	static std::multimap<time_t, place> get_user_path(const users_positions_data_base& users, const places_data_base& places, const user& user);




private:

	static place check_places(const std::vector<place>& places_arr, const point& pos);
	static std::vector<place> arr_get_places(const std::vector<place>& places_arr, const point& pos);

};

