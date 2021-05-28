#include "users_file_line.h"

std::string users_file_line::get_name() const
{
	return name;
}

time_t users_file_line::get_ts() const
{
	return ts;
}

point users_file_line::get_pos() const
{
	return pos;
}
