# Compiler to use
CC = gcc

# Options to use when compiling
CFLAGS = -ansi -Wpedantic -Wall -g

default: all 
all: list


list:  list.o
	$(CC) -o list list.o

list.o: list.c list.h 
	$(CC) $(CFLAGS) -c list.c 
		
clean:
	rm -f list.o