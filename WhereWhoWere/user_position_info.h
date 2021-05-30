#pragma once
#include <ctime>
#include <string>
#include <ctime>


#include "point.h"
#include "place.h"
#include "user.h"

struct user_position_info final
{
	user_position_info(time_t _ts, const std::string& u_id, const point& p);

	const std::string& get_user_id() const;

	user get_user() const;

	time_t get_ts() const;

	const point& get_pos() const;

	bool operator==(const user_position_info& up_inf) const;

private:
	time_t ts; // time when user was in this pos
	std::string user_id;
	point pos; // координаты
};

