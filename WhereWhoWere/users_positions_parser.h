#pragma once
#include "user.h"
#include "users_positions_data_base.h"
#include "user_position_info.h"

class users_positions_parser final
{
public:
	static user_position_info get_user_position(const std::string& line);

	static users_positions_data_base parse(std::istream& input);
};

