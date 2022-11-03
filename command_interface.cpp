#include "errors_def.h"
#include "command_interface.h"
#include "Users.h"
#include <iostream>

namespace cli = command_line_interface;

static std::string current_user;
Users *users = Users::get_instance();

std::pair<std::string, std::string> get_id(){
	std::string username, password;
	std::cout << "Enter username: ";
	std::cin >> username;
	std::cout << "Enter password: ";
	std::cin >> password;
	return std::make_pair(username, password);
}

bool cli::login()
{
	auto id = get_id();
	if (users->exists(id.first, id.second)){
		current_user = id.first;
		return true;
	}
	return false;
}

bool cli::signup() {
	auto id = get_id();
	if(users->add_user(User(id.first, id.second))){
		current_user = id.first;
		return true;
	}
	return false;
}

void cli::exit(){
	quick_exit(0);
}

void cli::delete_account() { users->delete_user(current_user); }

//std::string cli::ask_pwd();

std::tuple<std::string, std::string, std::string> cli::add_new_credentials(){

}

void cli::delete_credentials(){
	std::string site, username;
	std::cout << "enter site and username";
	std::cin >> site >> username;
	users->get_user(current_user)->delete_credentials(site, username);
}

//std::string cli::add_notes();

std::tuple<std::string, std::string, std::string> cli::ask_change(enum to_change change);