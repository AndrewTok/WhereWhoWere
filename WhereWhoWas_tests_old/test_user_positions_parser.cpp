#include "pch.h"
#include "users_positions_parser.h"
#include "users_positions_data_base.h"


#include "path_finder.h"


class TestUserPositionsParser : public ::testing::Test
{
protected:
	void SetUp()
	{
	}
	void TearDown()
	{
	}

	bool try_get_user_info()
	{
		bool success;
		try
		{
			user_position_info note = users_positions_parser::get_user_position(line);
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
		for (int i = 0; i < 100; i += 4)
		{
			std::string u_id = std::to_string(i + 1);
			curr_line = get_line_from_index(i, 4);
			point p = { i + 2, i + 3 };
			user_position_info curr_note = {i, u_id, p};
			correct_lines.insert(correct_lines.end(), curr_line);
			expected_up_data_base.insert(curr_note);
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
	users_positions_data_base up_data_base;
	users_positions_data_base expected_up_data_base;
	std::string line;
	std::stringstream input;
	std::vector<place> expected_places;
	std::vector<std::string> correct_lines;

};


TEST_F(TestUserPositionsParser, get_u_inf_empty_input) {
	line.clear();
	ASSERT_FALSE(try_get_user_info());
}

TEST_F(TestUserPositionsParser, get_u_inf_incorrect_input) {
	std::vector<std::string> incorrect_lines = { "incorrect", "150namepos", "32 name 23 d", "            \t      " };
	bool success;
	for (auto& curr_line : incorrect_lines)
	{
		line = curr_line;
		success = try_get_user_info();
		ASSERT_FALSE(success);
	}
}

TEST_F(TestUserPositionsParser, test_get_up_data_base) {
	fill_correct_lines_and_expected_data_base();
	bool success;
	fill_input_with_correct_line();
	up_data_base = users_positions_parser::parse(input);
	ASSERT_EQ(up_data_base.get_data(), expected_up_data_base.get_data());
}