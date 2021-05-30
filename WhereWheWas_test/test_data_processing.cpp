#include "pch.h"


#include "data_proccesing.h"

#include <iostream>

class TestSplitStr : public ::testing::Test
{
protected:
	void SetUp()
	{
		input = "";
		output = {};
		//input_stream << input;
		test_output = {};
	}
	void TearDown()
	{
	}
	std::string input;
	std::stringstream input_stream;
	std::vector<double> output;
	std::vector<double> test_output;

};

TEST_F(TestSplitStr, split_empty_line) {
	input.clear();
	std::vector<std::string> words = split_string(input, " \t\n");
	ASSERT_TRUE(words.empty());
}

TEST_F(TestSplitStr, split_only_spaces) {
	input = "       \n         \t		";
	std::vector<std::string> words = split_string(input, " \t\n");
	ASSERT_TRUE(words.empty());
}

TEST_F(TestSplitStr, split_one_word) {
	input = "  word  \n ";
	std::vector<std::string> words = split_string(input, " \t\n");
	ASSERT_EQ(words.size(), 1);
	ASSERT_EQ(input.substr(2, 4), words[0]);
}

TEST_F(TestSplitStr, split_lots_of_words) {
	input_stream.clear();
	for (size_t i = 0; i < 100; i++) {
		input_stream << i << " ";
	}
	input = input_stream.str();
	std::vector<std::string> words = split_string(input, " \t\n");
	ASSERT_EQ(words.size(), 100);
	for (size_t i = 0; i < 100; i++) {
		ASSERT_EQ(stol(words[i]), i);
	}
}