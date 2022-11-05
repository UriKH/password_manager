#include "Account.h"

Account::Account(const std::string &site, const std::string &username, const std::string &pwd){
	_site = site;
	_username = username;
	_pwd = pwd;
}

void Account::set_pwd(const std::string &pwd) { _pwd = pwd; }
void Account::set_site(const std::string &site) { _site = site; }
void Account::set_username(const std::string &username){ _username = username; }

const std::string Account::get_pwd() const { return _pwd; }
const std::string Account::get_site() const { return _site; }
const std::string Account::get_username() const { return _username; }
