#pragma once

#include <string>
#include <vector>
#include "Credentials.h"

class User{
private:
	std::string _username;
	std::string _password;
	std::vector<Credentials> _credentials;
public:
	User(const std::string&, const std::string&);
	User(const User&);
	~User();

	//bool equals(const User &other);

	void set_pwd(const std::string&);
	void set_username(const std::string &);
	void append(const Credentials &);

	void delete_credentials(std::string, std::string);

	const std::vector<Credentials> &get_credentials() const;
	const std::string &get_pwd() const;
	const std::string &get_username() const;
};