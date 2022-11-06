CC = g++
CFLAGS = -Wall -pedantic
BUILDFLAGS = -c -g

main.exe: main.o execute.o load.o Account.o User.o Users.o command_interface.o
	$(CC) -g $(CFLAGS) main.o execute.o load.o Account.o User.o Users.o command_interface.o -o main.exe
main.o: main.cpp load.h execute.h
	$(CC) $(BUILDFLAGS) $(CFLAGS) main.cpp -o main.o
execute.o: execute.cpp command_interface.h errors_def.h
	$(CC) $(BUILDFLAGS) $(CFLAGS) execute.cpp -o execute.o
load.o: load.cpp Users.h #loade.h
	$(CC) $(BUILDFLAGS) $(CFLAGS) load.cpp -o load.o
Account.o: Account.cpp Account.h
	$(CC) $(BUILDFLAGS) $(CFLAGS) Account.cpp -o Account.o
User.o: User.cpp User.h Account.h
	$(CC) $(BUILDFLAGS) $(CFLAGS) User.cpp -o User.o
Users.o: Users.cpp errors_def.h
	$(CC) $(BUILDFLAGS) $(CFLAGS) Users.cpp -o Users.o
command_interface.o: command_interface.cpp command_interface.h Users.h errors_def.h
	$(CC) $(BUILDFLAGS) $(CFLAGS) command_interface.cpp -o command_interface.o

clean:
	rm *.o