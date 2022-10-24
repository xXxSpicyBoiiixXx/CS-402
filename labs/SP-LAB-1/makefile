GCC_EXEC = gcc
CLANG_EXEC = clang

CLANG_IGNORED_WARNINGS = reserved-id-macro \
						 variadic-macros   \
						 undef \
						 gnu-zero-variadic-macro-arguments \
						 documentation \
						 padded \
						 missing-noreturn \
						 unused-parameter \
						 covered-switch-default \
						 disabled-macro-expansion \
						 pedantic 

CLANG_WARNING_FLAGS = -Weverything $(addprefix -Wno, $(CLANG_IGNORED_WARNINGS))

GCC_IGNORED_FLAGS = packed-bitfield-compat \
					unused-parameter \
					cast-function-type

GCC_WARNING_FLAGS = -Wall -Wextra $(addprefix -Wno-, $(GCC_IGNORED_WARNINGS))

CFLGS = -g -Wall -lm -O3

all: main.c	menu.c options.c
		$(CC) $(CFLAGS) menu.c -o menu.o
		$(CC) $(CFLAGS) options.c -o options.o
		$(CC) $(CFLAGS) main.c -o main.o	

run:
		./main.o

clean: 
		$(RM) -rf *.o *.~ *.dSYM 

