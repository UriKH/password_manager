#include "User.h"

User::User(const std::string &username, const std::string &password) 
	: _username(username), _password(password) {}

User::User(const User &other){
	_username = other._username;
	_password = other._password;
	_credentials = other._credentials;
}

User::~User(){}

/*bool User::equals(const User& other){
	return other._password == _password;
}*/

void User::set_pwd(const std::string &new_pwd){ _password = new_pwd; }
void User::set_username(const std::string &username) { _username = username; }
void User::append(const Credentials &c) { _credentials.push_back(c); }

const std::vector<Credentials> &User::get_credentials() const { return _credentials; }
const std::string &User::get_pwd() const { return _password; }
const std::string &User::get_username() const { return _username; }

void User::delete_credentials(std::string site, std::string username){
	for (int i = 0; i < _credentials.size(); i++) {
		if (_credentials[i].get_site() == site && _credentials[i].get_username() == username){
			_credentials.erase(_credentials.begin() + i);
			return;
		}
	}
}
