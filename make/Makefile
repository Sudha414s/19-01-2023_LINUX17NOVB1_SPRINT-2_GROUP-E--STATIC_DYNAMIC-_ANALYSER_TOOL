# Turn on the warning we want
MAKEFLAGS = -w
CC = g++
.PHONY: clean
run: sprint2.o
	$(CC) sprint2.o -Wall -o run

sprint2.o: sprint2.cpp
	$(CC) -c  sprint2.cpp -Wall -o  sprint2.o

clean:
	rm *.o run
