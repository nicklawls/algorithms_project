CC = clang++

CFLAGS = -std=c++11 -stdlib=libc++ -Wall -Werror

all: square

square: main.o Board.o
	$(CC) $(CFLAGS) main.o Board.o -o square

tsquare: test.o Board.o
	$(CC) $(CFLAGS)  test.o Board.o -o tsquare

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

test.o: test.cpp
	$(CC) $(CFLAGS) -c test.cpp

Board.o: Board.cpp
	$(CC) $(CFLAGS) -c Board.cpp

clean:
	rm -rf *.o square tsquare test output.txt
