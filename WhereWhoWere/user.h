#pragma once
#include <string>
class user
{
public:
	user(const std::string& u_id);

	const std::string& get_user_id() const;

	bool operator== (const user& r_user) const;

private:

	std::string user_id;


};

