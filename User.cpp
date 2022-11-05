#include "User.h"

User::User(const std::string &username, const std::string &password) 
	: _username(username), _password(password) {}

User::User(const User &other){
	_username = other._username;
	_password = other._password;
	_accounts = other._accounts;
}

User::~User(){}

/*bool User::equals(const User& other){
	return other._password == _password;
}*/

void User::set_pwd(const std::string &new_pwd){ _password = new_pwd; }
void User::set_username(const std::string &username) { _username = username; }
void User::append(const Account &c) { _accounts.push_back(c); }

const std::vector<Account> &User::get_accounts() const { return _accounts; }
const std::string &User::get_pwd() const { return _password; }
const std::string &User::get_username() const { return _username; }

void User::delete_account(const std::string &site, const std::string &username){
	for (size_t i = 0; i < _accounts.size(); i++) {
		if (_accounts[i].get_site().compare(site) && _accounts[i].get_username().compare(username)){
			_accounts.erase(_accounts.begin() + i);
			return;
		}
	}
}

void User::add_new_account(const std::string& site, const std::string &username, const std::string &password){
	_accounts.emplace_back(Account(site, username, password));
}