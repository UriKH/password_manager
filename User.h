#pragma once

#include <string>
#include <vector>
#include "Account.h"

class User{
private:
	std::string _username;
	std::string _password;
	std::vector<Account> _accounts;
public:
	User(const std::string&, const std::string&);
	User(const User&);
	~User();

	//bool equals(const User &other);

	void set_pwd(const std::string&);
	void set_username(const std::string &);
	void append(const Account &);

	void delete_account(std::string, std::string);
	void User::add_new_account(std::string, std::string, std::string);

	const std::vector<Account> &get_accounts() const;
	const std::string &get_pwd() const;
	const std::string &get_username() const;
};