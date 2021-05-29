#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <ctime>


#include "data_proccesing.h"
#include "places_data_base.h"
#include "users_movements_parser.h"
#include "places_parser.h"
#include "path_finder.h"

using namespace std;

int main()
{
	ifstream path_inp("path_input.txt");
	ifstream places_inp("places_input.txt");
	stringstream out;


	multimap<time_t, place> user_places;
	string username = "user_1";

	user u(username);

	path_finder fnd;

	places_data_base places = places_parser::parse(places_inp);
	users_positions_data_base u_pos = users_movements_parser::parse(path_inp);

	user_places = fnd.get_user_path(u_pos, places, u);

	for (auto& [time_st, plc] : user_places)
	{
		out << time_st << " " << plc.get_name() << endl;
	}

	cout << out.str() << endl;

	path_inp.close();
	places_inp.close();
}