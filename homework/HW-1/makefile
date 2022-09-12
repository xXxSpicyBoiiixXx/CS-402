CC = gcc

CFLAGS = -g -Wall -lm -O3

all: int-matrix.c double-matrix.c int-matrix-reversed.c double-matrix-reversed.c
	$(CC) $(CFLAGS) int-matrix.c -o int-matrix.o
	$(CC) $(CFLAGS) double-matrix.c -o double-matrix.o
	$(CC) $(CFLAGS) int-matrix-reversed.c -o int-matrix-reversed.o
	$(CC) $(CFLAGS) double-matrix-reversed.c -o double-matrix-reversed.o

part1: 
	./extractor.sh 
	./hex2dec.sh
	
part2: 
	./int-matrix.o
	./double-matrix.o

part2-r:
	./int-matrix-reversed.o
	./double-matrix-reversed.o

clean: 
	rm -rf ./results/*.txt ./temp/*.txt *.o *.~ *.dSYM
