#pragma once
#include <ctime>
#include <string>

#include "point.h"
#include "place.h"

struct users_file_line
{
	std::string get_name() const;

	time_t get_ts() const;

	point get_pos() const;

private:
	time_t ts; // timestamp of the operation
	std::string name; // person's id
	point pos; // координаты
};

