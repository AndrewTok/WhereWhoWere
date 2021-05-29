#pragma once
#include <string>
#include <vector>
#include <ctime>
#include <sstream>
#include <map>
#include <iostream>

#include "path_finder.h"
#include "user_position_info.h"

std::vector<std::string> split_string(const std::string& str, const std::string split_symbols);

time_t convert_str_to_time(const std::string& str);

