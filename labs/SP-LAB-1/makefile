GCC_EXEC = gcc

GCC_IGNORED_FLAGS = packed-bitfield-compat \
					unused-parameter \
					cast-function-type

GCC_WARNING_FLAGS = -Wall -Wextra $(addprefix -Wno-, $(GCC_IGNORED_WARNINGS))

CFLGS = -g -Wall -lm -O3

all: main.c	menu.c options.c employee.c readfile.c
		$(GCC_EXEC) $(CFLAGS) menu.c -o menu.o
		$(GCC_EXEC) $(CFLAGS) options.c -o options.o
		$(GCC_EXEC) $(CFLAGS) employee.c -o employee.o
		$(GCC_EXEC) $(CFLAGS) readfile.c -o readfile.o
		$(GCC_EXEC) $(CFLAGS) -o workerDB main.c menu.o options.o employee.o readfile.o

run:
		./workerDB 

clean: 
		$(RM) -rf ./workerDB *.o *.~ *.dSYM 

