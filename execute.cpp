/* This it the main algorithem file called from main.
The function execute_commands() is respossible for the communication with the user and
for input and output.

author: Uri K.H. (2022)
*/

#include <map>
#include <iostream>
#include <sstream>
#include "command_interface.h"
#include "errors_def.h"
#include "execute.h"

namespace cli = command_line_interface;

// indexing the user commands with an enum
enum cmd_id
{
	login = 0,
	logout,
	signup,
	exit_prog,
	delete_user,
	add_account,
	delete_account,
	change_pwd,
	change_usrnm,
	show_sites
};

// list of possible user commands
std::map<int, std::string> commands = {
	{login, "login"},
	{logout, "logout"},
	{signup, "signup"},
	{exit_prog, "exit"},
	{delete_user, "delete_user"},
	{add_account, "add_account"},
	{delete_account, "delete_account"},
	{change_pwd, "change_user_password"},
	{change_usrnm, "change_username"},
	{show_sites, "show_sites"}
	};


void execute_commands() {
	std::map<int, std::string>::iterator itr; // iterator for going ober the commands list
	std::string command_str = ""; // temporary string containing the user command from the stream

	//flags
	bool skip = false;
	bool valid_cmd = false;
	bool logged_in = false;

	// running until the user command is exit
	while (command_str.compare(commands[exit_prog]) != 0)
	{
		// skiping if command was already inserted when the last one was wrong
		if (!skip)
			std::cin >> command_str;

		// checking if the command is valid
		valid_cmd = false;
		for (itr = commands.begin(); itr != commands.end(); itr++) {
			if (itr->second.compare(command_str) == 0) {
				valid_cmd = true;
				break;
			}
		}

		// if the command is not valid ask the user to print all valid commands
		if (!valid_cmd) {
			std::cout << NO_SUCH_COMMAND << std::endl;
			std::cout << SHOW_COMMAND_LIST << std::endl;

			std::string to_show;
			std::cin >> to_show;

			// print all the available commands
			if (to_show.compare(SHOW_COMMAND) == 0)
				for (auto &cmd : commands)
					std::cout << cmd.second << std::endl;
			else {
				// use the new inserted command insted
				command_str = to_show;
				skip = true;
			}
			continue;
		}

		// decide which command to run
		switch (itr->first) {
		case signup:
			if(cli::signup())
				logged_in = true;
			break;
		case login:
			if (cli::login())
				logged_in = true;
			break;
		case exit_prog:
			std::exit(0);
		default:
			if (logged_in){
				switch (itr->first) {
					case logout:
						logged_in = false;
						break;
					case delete_account:
						cli::delete_site();
						break;
					case add_account:
						cli::add_new_site();
						break;
					case delete_user:
						cli::delete_user();
						logged_in = false;
						break;
					case change_pwd:
						cli::change_account_info(cli::PASSWORD);
						break;
					case change_usrnm:
						cli::change_account_info(cli::USERNAME);
						break;
					case show_sites:
						cli::show_sites();
						break;
					default:
						break;
				}
			}
			else
				std::cout << NOT_LOGGED_IN << std::endl;
		}
	}
}