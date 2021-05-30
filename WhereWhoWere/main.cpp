#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <ctime>


#include "data_proccesing.h"
#include "places_data_base.h"
#include "users_positions_parser.h"
#include "places_parser.h"
#include "path_finder.h"

using namespace std;

void demonstration(const std::string& users_path_input, const std::string& places_path_input, const std::string& username)
{
	ifstream path_inp(users_path_input); 
	ifstream places_inp(places_path_input); 
	stringstream out;


	multimap<time_t, place> user_places;
	//string username = "user_1";

	user u(username);

	path_finder fnd;

	places_data_base places = places_parser::parse(places_inp);
	users_positions_data_base u_pos = users_positions_parser::parse(path_inp);

	user_places = fnd.get_user_path(u_pos, places, u);

	for (auto& [time_st, plc] : user_places)
	{
		out << time_st << " " << plc.get_name() << endl;
	}

	for (auto& [time_st, plc] : user_places)
	{
		if (plc.get_name() != "")
		{
			out << plc.get_name() << " ";
		}
		
	}

	cout << out.str() << endl;

	path_inp.close();
	places_inp.close();
}

int main()
{
	demonstration("path_input.txt", "places_input.txt", "user_1");
}