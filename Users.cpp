#include "Users.h"
#include "errors_def.h"


Users *Users::_singleton = nullptr;

Users *Users::get_instance(){
	if (_singleton == nullptr)
		_singleton = new Users();
	return _singleton;
}


bool Users::add_user(User user){
	for (auto& temp : _users){
		if (temp.get_username().compare(user.get_username()) == 0){
			std::cout << USER_ALREADY_EXIST << std::endl;
			return false;
		}
	}
	_users.emplace_back(user);
	return true;
}

User *Users::get_user(const std::string& username){
	for (size_t i = 0; i < _users.size(); i++)
		if (_users[i].get_username().compare(username) == 0)
			return &(_users[i]);
	return nullptr;
}

bool Users::exists(std::string username, std::string password)
{
	const User* user = get_user(username);
	if (user == nullptr){
		std::cout << USER_NOT_EXIST << std::endl;
		return false;
	}
	if (user->get_pwd().compare(password) != 0){
		std::cout << WRONG_PWD << std::endl;
		return false;
	}
	return true;
}

void Users::delete_user(std::string username){
	for (size_t i = 0; i < _users.size(); i++) {
		if (_users[i].get_username().compare(username) == 0){
			_users.erase(_users.begin() + i);
			return;
		}
	}
}