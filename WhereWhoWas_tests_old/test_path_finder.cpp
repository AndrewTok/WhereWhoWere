#include "pch.h"
#include "path_finder.h"
#include "places_data_base.h"
#include "users_positions_data_base.h"



class TestPath : public ::testing::Test
{
protected:
	void SetUp()
	{

	}
	void TearDown()
	{
	}

	void fill_places(size_t count)
	{
		/* создаем массив вложенных квадратов*/
		point beginning = { 0, 0 };
		for (int i = 1; i <= count; i++)
		{
			point curr_second_point = { 10 * i, 10 * i };
			place curr_place(std::to_string(10 * i), beginning, curr_second_point);
			places.insert(curr_place);
		}
	}

	void update_users_places_db(int start_index, int end_index, const user& u) //ходим по прямой x = y
	{
		for (int i = start_index; i < end_index; i++)
		{
			point p = { i, i };
			user_position_info curr_pos = { i, u.get_user_id(),  p };
			u_p_db.insert(curr_pos);
		}
	}

	void fill_users(size_t count)
	{
		for (size_t i = 0; i < count; i++)
		{
			user u(std::to_string(i));
			users.insert(users.end(), u);
		}
	}

	void insert_places_sliced_arr(std::multimap<time_t, place>& pth, time_t ts, size_t slice_idx)
	{
		std::vector<place> curr_places = places.get_all_places();
		for (size_t i = slice_idx; i < curr_places.size(); i++)
		{
			std::pair<time_t, place> p = { ts, curr_places[i] };
			pth.insert(p);
		}
	}

	//bool check_u_path()
	//{
	//	expected_u_path == u_path;
	//	if (u_path.size() != expected_u_path.size())
	//	{
	//		return false;
	//	}
	//	for (auto& [time_st, plc] : expected_u_path)
	//	{
	//		auto& itr = u_path.find(time_st);
	//		if (itr == u_path.end())
	//		{
	//			return false;
	//		}
	//		size_t key_v_count = u_path.count(time_st);
	//		bool find = false;
	//		for (size_t i = 0; i < key_v_count; i++)
	//		{
	//			auto& curr_place = u_path.extract(itr);
	//		}
	//	}
	//}

	places_data_base places;
	users_positions_data_base u_p_db;
	std::multimap<time_t, place> u_path;
	std::multimap<time_t, place> expected_u_path;
	std::vector<user> users;


	std::string input;
	std::stringstream input_stream;
	std::vector<double> output;
	std::vector<double> test_output;

};



TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST_F(TestPath, user_avoid_known_places)
{
	fill_users(1); 
	fill_places(10);
	update_users_places_db(-10, -1, users[0]);
	u_path = path_finder::get_user_path(u_p_db, places, users[0]);
	for (auto& [time_st, plc] : u_path)
	{
		ASSERT_TRUE(plc.get_lower_right_p() == plc.get_upper_left_p());
		point p = plc.get_lower_right_p();
		ASSERT_EQ(p.x, p.y);
		ASSERT_EQ(time_st, p.x);
	}

}

TEST_F(TestPath, user_go_throw_known_places)
{
	fill_users(1);
	fill_places(10);
	update_users_places_db(0, 100, users[0]);
	u_path = path_finder::get_user_path(u_p_db, places, users[0]);

	for (int i = 0; i < 100; i++)
	{
		insert_places_sliced_arr(expected_u_path, i, (i - 1) / 10);
	}
	ASSERT_TRUE(expected_u_path == u_path);

}

TEST_F(TestPath, user_go_throw_one_known_place)
{
	fill_users(1);
	fill_places(10);
	update_users_places_db(100, 105, users[0]);

	u_path = path_finder::get_user_path(u_p_db, places, users[0]);
	insert_places_sliced_arr(expected_u_path, 100, 9);
	for (int i = 101; i < 105; i++)
	{
		point p = { i, i };
		place curr_plc = { "" , p, p };
		expected_u_path.insert(std::pair<time_t, place>(i, curr_plc));
	}
	ASSERT_TRUE(expected_u_path == u_path);
}