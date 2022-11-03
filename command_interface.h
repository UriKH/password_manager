#pragma once

//#include <utility>
//#include <tuple>
//#include <string>

namespace command_line_interface {
	//std::pair<std::string, std::string> get_id();
	bool login();
	bool signup();
	void exit();

	void delete_user();
	//std::string ask_pwd();

	void add_new_account();
	void delete_account();
	// std::string add_notes();

	void change_account_info(enum to_change);
	
	enum to_change
	{
		PASSWORD,
		USERNAME
	};
};

