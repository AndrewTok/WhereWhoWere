#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <ctime>


#include "data_proccesing.h"
#include "path_finder.h"

using namespace std;

int main()
{
	ifstream path_inp("path_input.txt");
	ifstream places_inp("places_input.txt");
	stringstream out;


	map<time_t, place> user_places;
	string username = "user_1";

	path_finder fnd;

	vector<place> places = get_places_arr(places_inp);
	vector<Note> log_arr = get_log_arr(path_inp);

	user_places = fnd.get_user_path(log_arr, places, username);

	for (auto& pair : user_places)
	{
		place curr_place = pair.second;
		out << pair.first << " " << curr_place.name << endl;
	}

	cout << out.str() << endl;

	path_inp.close();
	places_inp.close();
}