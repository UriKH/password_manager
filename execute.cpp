#include <map>
#include <iostream>
#include <sstream>
#include "command_interface.h"
#include "errors_def.h"
#include "execute.h"

namespace cli = command_line_interface;

enum cmd_id
{
	login,
	signup,
	exit_prog,
	delete_user,
	add_account,
	delete_account,
	change_pwd,
	change_usrnm
};

std::map<int, std::string>::iterator itr;
std::map<int, std::string> commands = {
	{login, "login"},
	{signup, "signup"},
	{exit_prog, "exit"},
	{delete_user, "delete_user"},
	{add_account, "add_account"},
	{delete_account, "delete_account"},
	{change_pwd, "change_user_password"},
	{change_usrnm, "change_username"}};

void execute_commands() {
	std::string command_str = "";
	bool skip = false;
	bool valid_cmd = false;
	bool logged_in = false;

	while (command_str != commands[exit_prog])
	{
		if (!skip)
		{
			// skiping if command was already inserted when the last one was wrong
			std::string line;
			std::getline(std::cin, line);
		}

		// checking if the command is valid
		valid_cmd = false;
		for (itr = commands.begin(); itr != commands.end(); itr++)
		{
			if (itr->second == command_str)
			{
				valid_cmd = true;
				break;
			}
		}

		if (!valid_cmd)
		{
			// if the command is not valid ask the user to print all valid commands
			std::cout << NO_SUCH_COMMAND << std::endl;
			std::cout << SHOW_COMMAND_LIST;

			std::string to_show;
			std::getline(std::cin, to_show);

			// print all the available commands
			if (to_show == SHOW_COMMAND)
				for (auto &cmd : commands)
					std::cout << cmd.second;
			else
			{
				// use the new inserted command insted
				command_str = to_show;
				skip = true;
			}
			continue;
		}

		switch (itr->first)
		{
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
			//throw std::exception("exiting");
		default:
			if (logged_in)
				switch (itr->first)
				{
					case delete_account:
						cli::delete_site();
						break;
					case add_account:
						cli::add_new_site();
						break;
					case delete_user:
						cli::delete_user();
						break;
					case change_pwd:
						cli::change_account_info(cli::PASSWORD);
						break;
					case change_usrnm:
						cli::change_account_info(cli::USERNAME);
						break;
					default:
					break;
				}
		}
	}
}