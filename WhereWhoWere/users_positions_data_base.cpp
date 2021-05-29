#include "users_positions_data_base.h"

void users_positions_data_base::insert(const user_position_info& u_pos_inf)
{
	data.insert(data.end(), u_pos_inf);
}

const std::vector<user_position_info>& users_positions_data_base::get_data() const
{
	return data;
}

std::vector<user_position_info> users_positions_data_base::get_data_of_one_user(const user& _user) const
{
	std::vector<user_position_info> user_movements;
	for (auto& user_place_info : data)
	{
		user curr_user = user_place_info.get_user();
		if (curr_user == _user)
		{
			user_movements.insert(user_movements.end(), user_place_info);
		}
	}
	return user_movements;
}
