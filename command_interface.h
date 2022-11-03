#pragma once

#include <utility>
#include <tuple>
#include <string>

namespace command_line_interface {
	//std::pair<std::string, std::string> get_id();
	bool login();
	bool signup();
	void exit();

	void delete_account();
	//std::string ask_pwd();

	std::tuple<std::string, std::string, std::string> add_new_credentials();
	void delete_credentials();
	// std::string add_notes();

	std::tuple<std::string, std::string, std::string> ask_change(enum to_change change);
};

enum to_change {
	PASSWORD,
	USERNAME,
	NOTES
};