#pragma once


#include <vector>
#include "User.h"

/* 
Users is a singleton class representing the database containing all the users and their information.
The initialization of this call will accur once at the start and will be used with a single object all.

*/
class Users{
private:
	Users() = default;

	static Users *_singleton;
	std::vector<User> _users;
	std::string current_usr;

public:
	Users(const Users&) = delete;
	void operator=(const Users &) = delete;

	static Users* get_instance();

	User *get_user(const std::string &);
	bool add_user(const User &);
	bool exists(const std::string &, const std::string &);
	void delete_user(const std::string &);
};