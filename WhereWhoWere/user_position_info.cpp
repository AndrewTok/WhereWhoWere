#include "user_position_info.h"

user_position_info::user_position_info(time_t _ts, const std::string& u_id, const point& p)
{
	ts = _ts;
	user_id = u_id;
	pos = p;
}

const std::string& user_position_info::get_user_id() const
{
	return user_id;
}

user user_position_info::get_user() const
{
	return user(user_id);
}

time_t user_position_info::get_ts() const
{
	return ts;
}

const point& user_position_info::get_pos() const
{
	return pos;
}

bool user_position_info::operator==(const user_position_info& up_inf) const
{
	return (up_inf.get_pos() == pos)&&(up_inf.get_ts() == ts)&&(up_inf.get_user() == get_user());
}
