#pragma once
#include <vector>

#include "user.h"
#include "place.h"
#include "user_position_info.h"

class users_positions_data_base
{
public:

	void insert(const user_position_info& u_pos_inf);

	const std::vector<user_position_info>& get_data() const;

	std::vector<user_position_info> get_data_of_one_user(const user& _user) const;

private:
	std::vector<user_position_info> data;
};

