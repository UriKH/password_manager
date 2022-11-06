#pragma once

//#include <utility>
//#include <tuple>
//#include <string>

namespace command_line_interface {
	enum to_change
	{
		PASSWORD,
		USERNAME
	};

	bool login();
	bool signup();
	void exit();

	void delete_user();

	void add_new_site();
	void delete_site();
	void show_sites();
	// std::string add_notes();

	void change_account_info(enum to_change);
};

