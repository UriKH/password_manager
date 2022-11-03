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
		if (temp.get_username() == user.get_username()){
			std::cout << USER_ALREADY_EXIST << std::endl;
			return false;
		}
	}
	_users.push_back(user);
	return true;
}

User *Users::get_user(const std::string& username){
	for (int i = 0; i < _users.size(); i++)
		if (_users[i].get_username() == username)
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
	if (user->get_pwd() != password){
		std::cout << WRONG_PWD << std::endl;
		return false;
	}
	return true;
}

void Users::delete_user(std::string username){
	for (int i = 0; i < _users.size(); i++) {
		if (_users[i].get_username() == username){
			_users.erase(_users.begin() + i);
			return;
		}
	}
}