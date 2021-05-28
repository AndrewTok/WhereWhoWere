#pragma once
#include <string>
#include <vector>
#include <map>
#include <ctime>

#include "place.h"
#include "point.h"
#include "users_file_line.h"
#include "user.h"

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

	path_finder() = default;
	~path_finder() = default;

	//std::multimap<time_t, place> get_user_path(const std::vector<users_file_line>& parsed_file, const std::vector<place>& places_arr, const std::string& u_name);
	
	std::multimap<time_t, place> get_user_path(const std::vector<users_file_line>& parsed_file, const std::vector<place>& places_arr, const user& user);




private:

	place check_places(const std::vector<place>& places_arr, const point& pos);
	std::vector<place> arr_get_places(const std::vector<place>& places_arr, const point& pos);

};

