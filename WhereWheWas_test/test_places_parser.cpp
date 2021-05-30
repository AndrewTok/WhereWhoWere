#include "pch.h"


#include "places_parser.h"
#include "places_data_base.h" 
#include "path_finder.h"


class TestPlacesParser : public ::testing::Test
{
protected:
	void SetUp()
	{
	}
	void TearDown()
	{
	}

	bool try_get_place()
	{
		bool success;
		try
		{
			place curr_place = places_parser::get_place(line);
			success = true;
		}
		catch (std::exception& exc)
		{
			success = false;
		}
		return success;
	}

	void fill_correct_lines_and_expected_data_base()
	{
		std::string curr_line;
		//place curr_note;
		for (int i = 0; i < 100; i+=5)
		{
			std::string index_string = std::to_string(i);
			curr_line = get_line_from_index(i, 5); //index_string + " " + index_string + " " + index_string;
			point p1 = { i + 1, i + 2 };
			point p2 = { i + 3, i + 4 };
			place curr_note = { index_string, p1, p2 };
			correct_lines.insert(correct_lines.end(), curr_line);
			expected_p_data_base.insert(curr_note);
		}
	}

	std::string get_line_from_index(int i, int count)
	{
		std::string out;
		for (int k = 0; k < count; k++)
		{
			out += std::to_string(i + k);
			if (k != count - 1)
			{
				out += " ";
			}
		}
		return out;
	}

	void fill_input_with_correct_line()
	{
		for (size_t i = 0; i < correct_lines.size(); i++)
		{
			input << correct_lines[i];
			if (i != correct_lines.size() - 1)
			{
				input << "\n";
			}
		}
	}
	places_data_base p_data_base;
	places_data_base expected_p_data_base;
	std::string line;
	std::stringstream input;
	std::vector<place> expected_places;
	std::vector<std::string> correct_lines;

};


TEST_F(TestPlacesParser, get_place_empty_input) {
	line.clear();
	ASSERT_FALSE(try_get_place());
}

TEST_F(TestPlacesParser, get_place_incorrect_input) {
	std::vector<std::string> incorrect_lines = { "incorrect", "150namepos", " name 23 150 23", "name 1 2 3 a", "            \t      " };
	bool success;
	for (auto& curr_line : incorrect_lines)
	{
		line = curr_line;
		success = try_get_place();
		ASSERT_FALSE(success);
	}
}

TEST_F(TestPlacesParser, test_get_places) { // also tests get_place correct input
	fill_correct_lines_and_expected_data_base();
	bool success;
	fill_input_with_correct_line();
	p_data_base = places_parser::parse(input);
	ASSERT_EQ(p_data_base.get_all_places(), expected_p_data_base.get_all_places());
}