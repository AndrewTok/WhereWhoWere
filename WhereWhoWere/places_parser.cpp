#include "places_parser.h"
#include "data_proccesing.h"

place places_parser::get_place(const std::string& line)
{
	std::vector<std::string> words = split_string(line, " \t");
	point first = { stol(words.at(1)), stol(words.at(2)) };
	point second = { stol(words.at(3)), stol(words.at(4)) };
	place plc = { words.at(0), first, second };
	return plc;
}

places_data_base places_parser::parse(std::istream& input)
{
	std::string line;
	places_data_base places;
	
	while (std::getline(input, line))
	{
		try
		{
			place curr_place = get_place(line);
			places.insert(curr_place);
		}
		catch (std::exception& excpt)
		{
			return places_data_base();
		}
		
	}
	return places;
}
