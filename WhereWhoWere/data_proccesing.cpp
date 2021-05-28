#include "data_proccesing.h"


std::vector<std::string> split_string(const std::string& str, const std::string split_symbols)
{
	std::string word;
	std::vector<std::string> words = {};
	size_t pos = 0;
	for (size_t num = 0;;) {
		pos = str.find_first_not_of(split_symbols, pos);
		if (pos == std::string::npos) { break; }
		size_t pos1 = str.find_first_of(split_symbols, pos);
		size_t len = (pos1 == std::string::npos) ? std::string::npos : pos1 - pos;
		word = str.substr(pos, len);
		words.insert(words.end(), word);
		if (pos1 == std::string::npos) { break; }
		pos = pos1;
	}
	return words;
}

users_file_line convert_log_line(const std::string& line)
{
	users_file_line note;
	std::vector<std::string> words = split_string(line, " \t");
	note.ts = convert_str_to_time(words.at(0));
	note.name = words.at(1);
	note.pos.x = stol(words.at(2));
	note.pos.y = stol(words.at(3));
	return note;
}

std::vector<Note> get_log_arr(std::istream& input)
{
	std::string line;
	std::vector<Note> log_arr;
	Note curr_note;
	while (std::getline(input, line))
	{
		try
		{
			curr_note = convert_log_line(line);
		}
		catch (std::exception& excpt)
		{
			return std::vector<Note>();
		}
		log_arr.insert(log_arr.end(), curr_note);
	}
	return log_arr;
}

place convert_place_line(const std::string& line)
{
	place plc;
	point first, second;
	std::vector<std::string> words = split_string(line, " \t");
	first = { stol(words.at(1)), stol(words.at(2)) };
	second = { stol(words.at(3)), stol(words.at(4)) };
	plc = { words.at(0), first, second };
	return plc;
}

std::vector<place> get_places_arr(std::istream& input)
{
	std::string line;
	std::vector<place> places_arr;
	place curr_place;
	while (std::getline(input, line))
	{
		try
		{
			curr_place = convert_place_line(line);
		}
		catch (std::exception& excpt)
		{
			return std::vector<place>();
		}
		places_arr.insert(places_arr.end(), curr_place);
	}
	return places_arr;
}

time_t convert_str_to_time(const std::string& str)
{
	time_t ts;
	std::stringstream str_stream;
	str_stream << str;
	str_stream >> ts;
	return ts;
}
