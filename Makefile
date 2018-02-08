SHELL = /bin/sh
CC = gcc
FLG = -Wall -Werror -Wextra -pedantic -pedantic-errors -std=c11 -O2
AR = ar rcs
SRC = $(filter-out sources/main.c, $(wildcard sources/*.c))
HDR = $(patsubst sources/%.c, headers/%.h, $(SRC))
OBJ = $(patsubst sources/%.c, objects/%.o, $(SRC))


all: compilation/executable compilation/libGaShell.a
library: libGaShell.a


compilation/executable: objects/main.o compilation/libGaShell.a
	${CC} ${FLG} -o compilation/executable objects/main.o -Lcompilation -lGaShell

objects/main.o: sources/main.c headers/main.h
	${CC} ${FLG} -c sources/main.c -o objects/main.o

objects/%.o: sources/%.c headers/%.h
	$(CC) $(FLG) -c $< -o $@

compilation/libGaShell.a: ${OBJ}
	${AR} compilation/libGaShell.a ${OBJ}


clean:
	rm -f objects/*.o headers/*.gch
reset:
	rm -f compilation/* objects/* headers/*.gch
