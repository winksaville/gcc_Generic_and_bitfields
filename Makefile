CC = gcc
O = 3
STD = c11
M = 32

test: test.c Makefile
	$(CC) -O$(O) -m$(M) -Wall -std=$(STD) test.c -o test

clean:
	rm -f test
