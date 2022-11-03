#pragma once

#include <iostream>
#include <map>


class Credentials{
private:
	std::string _site;
	std::string _username;
	std::string _pwd;
	//std::string _notes;
public:
	//Credentials(const std::string &, const std::string &, const std::string &, const std::string &);
	Credentials(const std::string &, const std::string &, const std::string &);
	Credentials(const Credentials &);
	~Credentials();

	void set_pwd(const std::string &);
	void set_site(const std::string &);
	void set_username(const std::string &);
	//void set_notes(const std::string &);

	const std::string get_pwd() const;
	const std::string get_site() const;
	const std::string get_username() const;
	//const std::string get_notes() const;
};