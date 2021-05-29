#include "user.h"

user::user(const std::string& u_id)
{
    user_id = u_id;
}

const std::string& user::get_user_id() const
{
    return user_id;
}

bool user::operator==(const user& r_user)
{
    return user_id == r_user.get_user_id();
}

//bool user::operator==(const user& l_user, const user& r_user)
//{
//    return l_user.get_user_id() == r_user.get_user_id();
//}
