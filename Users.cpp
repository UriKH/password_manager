#include "Users.h"
#include "errors_def.h"


Users *Users::_singleton = nullptr;

Users *Users::get_instance(){
	if (_singleton == nullptr)
		_singleton = new Users();
	return _singleton;
}


bool Users::add_user(const User &user){
	for (auto& temp : _users){
		if (temp.get_username().compare(user.get_username()) == 0){
			LOG(USER_ALREADY_EXIST);
			return false;
		}
	}
	_users.push_back(user);
	return true;
}

User *Users::get_user(const std::string& username){
	for (size_t i = 0; i < _users.size(); i++)
		if (_users[i].get_username().compare(username) == 0)
			return &(_users[i]);
	return nullptr;
}

bool Users::exists(const std::string &username, const std::string &password)
{
	const User* user = get_user(username);
	if (user == nullptr){
		LOG(USER_NOT_EXIST);
		return false;
	}
	if (user->get_pwd().compare(password) != 0){
		LOG(WRONG_PWD);
		return false;
	}
	return true;
}

void Users::delete_user(const std::string &username){
	for (size_t i = 0; i < _users.size(); i++) {
		if (_users[i].get_username().compare(username) == 0){
			_users.erase(_users.begin() + i);
			return;
		}
	}
}