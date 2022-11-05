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
	if (!users->exists(id.first, id.second)){
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
	std::exit(0);
}

void cli::delete_user() { users->delete_user(current_user); }

void cli::add_new_site(){
	std::string site, username, pwd;
	std::cout << "enter site, username and password";
	std::cin >> site >> username >> pwd;
	users->get_user(current_user)->add_new_account(site, username, pwd);
}

void cli::delete_site(){
	std::string site, username;
	std::cout << "enter site and username";
	std::cin >> site >> username;
	users->get_user(current_user)->delete_account(site, username);
}

void cli::change_account_info(cli::to_change change) {
	if(change == cli::PASSWORD){
		std::string new_pwd;
		std::cout << "enter new password: ";
		std::cin >> new_pwd;
		users->get_user(current_user)->set_pwd(new_pwd);
	}
	else if (change == cli::USERNAME){
		std::string new_usrnm;
		std::cout << "enter new username: ";
		std::cin >> new_usrnm;
		users->get_user(current_user)->set_username(new_usrnm);
	}
	else
		throw std::invalid_argument("Fatal Error: not a changable account info");
	return;
}

// std::string cli::add_notes();