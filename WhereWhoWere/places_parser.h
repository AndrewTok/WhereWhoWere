#pragma once
#include "places_data_base.h"

class places_parser
{
public:
	static place get_place(const std::string& line);

	static places_data_base parse(std::istream& input);
};

