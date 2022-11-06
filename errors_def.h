#pragma once

#include <iostream>

#define USER_NOT_EXIST "Error: User does not exist"
#define TO_MANY_ARGS "Error: To many arguments for this line"
#define NO_SUCH_COMMAND "Error: No such command"
#define USER_ALREADY_EXIST "Error: User already exists"
#define ALREADY_LOGGED_IN "Error: User is already logged in"
#define WRONG_PWD "Error: Password is incorrect"
#define NOT_LOGGED_IN "Error: Not logged in, permission to run denied"

#define SHOW_COMMAND "show"
#define SHOW_COMMAND_LIST "[if you want to see the list of commands write \"show\"]"

#define LOG(msg) std::cout << msg << std::endl