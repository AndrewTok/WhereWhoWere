#pragma once
#include <string>
#include <vector>
#include <ctime>
#include <sstream>
#include <map>
#include <iostream>

#include "path_finder.h"
#include "users_file_line.h"

std::vector<std::string> split_string(const std::string& str, const std::string split_symbols);

users_file_line convert_log_line(const std::string& line);

std::vector<users_file_line> get_log_arr(std::istream& input);

place convert_place_line(const std::string& line);

std::vector<place> get_places_arr(std::istream& input);

time_t convert_str_to_time(const std::string& str);

