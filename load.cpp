#include "extern/sqlite3.h"
#include <variant>
#include <utility>
#include <map>
#include <string>

#include "load.h"
#include "RSA.h"
#include "Users.h"
#include "errors_def.h"

/* load all the data from the database to the Users pointer after decryption */

static int callback_get_users(void *data, int argc, char** argv, char**col_name){
	std::map<std::string, std::string> *table = (std::map<std::string, std::string> *) data;

(*table)[argv[0]] = argv[1];
	std::cout << argv[0] << " , " << argv[1] << std::endl;
	return 0;
}

static int callback_get_sites(void *data, int argc, char **argv, char **col_name) {
	std::map<std::string, std::pair<std::string, std::string> *table = (std::map<std::string, std::pair<std::string, std::string>> *)data;

	(*table)[argv[0]] = std::make_pair<argv[1], argv[2]>;
	std::cout << argv[0] << " , " << argv[1] << " , " << argv[2] << std::endl;
	return 0;
}

bool load(const std::string &)
{
	sqlite3 *DB;
	int exit = 0;
	exit = sqlite3_open("pwds.db", &DB);

	char *err;
	if (exit)
	{
		LOG(DB_NOT_FOUND);
		std::string sql_req =
			"CREATE TABLE users("
			"user_id 	INT PRIMARY KEY	NOT NULL,"
			"username	TEXT 			NOT NULL,"
			"user_pwd	TEXT			NOT NULL);";
		exit = sqlite3_exec(DB, sql_req.c_str(), NULL, 0, &err);

		if (exit != SQLITE_OK)
		{
			LOG("could not create table1");
			sqlite3_free(err);
			return false;
		}

		std::string sql_req2 =
			"CREATE TABLE sites("
			"user_id 	INT PRIMARY KEY	NOT NULL,"
			"site		TEXT			NOT NULL,"
			"username	TEXT 			NOT NULL,"
			"pwd		TEXT			NOT NULL);";
		exit = sqlite3_exec(DB, sql_req2.c_str(), NULL, 0, &err);

		if (exit != SQLITE_OK)
		{
			LOG("could not create table2");
			sqlite3_free(err);
			return false;
		}
		sqlite3_close(DB);
		return true
	}

	Users *users = Users::get_instance();

	std::variant<>
	std::map<std::string, std::string> table;
	std::string query = "SELECT * FROM users;";

	sqlite3_exec(DB, query.c_str(), callback_get_users, &table, NULL);
	for (auto& row : table)
		users->add_user(User(row.first, row.second));

	std::string query = "SELECT * FROM sites;";

	std::map<std::string, std::string> table;
	sqlite3_exec(DB, query.c_str(), callback_get_sites, &table, NULL);

	sqlite3_close(DB);
	return true;
}
