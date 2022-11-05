GCC_EXEC = gcc -c 

CFLGS = -g -Wall -Wextra -Werror -O3 #-target x86_64-apple-darwin20.3.0

all: main.c	menu.c readfile.c
		$(GCC_EXEC) $(CFLAGS) menu.c
#		$(GCC_EXEC) $(CFLAGS) employee.c
#	$(GCC_EXEC) $(CFLAGS) options.c 
		$(GCC_EXEC) $(CFLAGS) readfile.c
#		$(GCC_EXEC) $(CFLAGS) -o workerDB main.c menu.o options.o employee.o readfile.o
		$(GCC_EXEC) $(CFLAGS) main.c menu.o readfile.o
run:
		./main.o database.txt 

clean: 
		$(RM) -rf ./workerDB *.o *.~ *.dSYM 

