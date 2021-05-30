#include "pch.h"

#include "places_data_base.h"
#include "users_positions_data_base.h"

#include <iostream>
#include <sstream>
#include <string>

class TestPlacesDb : public ::testing::Test
{
protected:
	void SetUp()
	{

	}
	void TearDown()
	{
	}

	bool check_slice_places(size_t begin_slice_index, size_t end_slice_index)
	{
		places_data_base test_db(choosen_places);
		if (end_slice_index > test_places.size())
		{
			return false;
		}
		for (size_t i = begin_slice_index; i < end_slice_index; i++)
		{
			place curr_place = test_places[i];
			if (!(test_db.contains(curr_place)))
			{
				return false;
			}
		}
		return true;
	}
	std::vector<place> test_places;
	std::vector<place> choosen_places;
	places_data_base places;
};

TEST_F(TestPlacesDb, test_choose_places)
{
	/* созздаем массив вложенных квадратов*/
	point beginning = { 0, 0 };
	//std::vector<place> test_places;
	for (int i = 1; i < 11; i++)
	{
		point curr_second_point = { 10*i, 10*i };
		place curr_place(std::to_string(10*i), beginning, curr_second_point);
		places.insert(curr_place);
		test_places.insert(test_places.end(), curr_place);
	}
	/* проверяем принадлежность угловых точек ко всем объемлющим квадратам и не принадлежность к остальным */
	point testing_p;
	for (int i = 0; i < 11; i ++)
	{
		testing_p = { 10 * i, 10 * i };
		choosen_places = places.choose_places_by_point(testing_p);
		places_data_base test_db(choosen_places);
		for (int j = 0; j < test_places.size(); j++)
		{
			place curr_place = test_places[j];
			ASSERT_TRUE((test_db.contains(curr_place) == (j >= (i - 1))));
		}
	}
}

//TEST_F(TestPlacesDb, test_ctor)
//{
//	std::vector
//}

