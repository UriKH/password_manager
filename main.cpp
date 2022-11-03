#include "execute.h"
#include "load.h"

int main(){
	load("hello world" /*here sould go the DB file path*/);
	execute_commands();
	return 0;
}

