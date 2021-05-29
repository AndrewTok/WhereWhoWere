#include "users_movements_parser.h"
#include "data_proccesing.h"

user_position_info users_movements_parser::get_user_position(const std::string& line)
{
	std::vector<std::string> words = split_string(line, " \t");
	time_t ts = convert_str_to_time(words.at(0));
	std::string name = words.at(1);
	point p = { stol(words.at(2)), stol(words.at(3)) };
	user_position_info u_info(ts, name, p);
	return u_info;
}

users_positions_data_base users_movements_parser::parse(std::istream& input)
{
	std::string line;
	users_positions_data_base users_positions;
	while (std::getline(input, line))
	{
		try
		{
			user_position_info curr_note = get_user_position(line);
			users_positions.insert(curr_note);
		}
		catch (std::exception& excpt)
		{
			return users_positions_data_base();
		}
	}
	return users_positions;
}
