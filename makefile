CC 			= gcc
CFLAGS		= -Wall -Wextra -pedantic -pedantic-errors
LDFLAGS    	= -lGL -lglfw

all: clean example1 example2

clean:
	rm -f *.bin

example1:
	$(CC) $(CFLAGS) example1.c $(LDFLAGS) -o $@.bin

example2:
	$(CC) $(CFLAGS) example2.c $(LDFLAGS) -o $@.bin

debug: clean example1
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./example1.bin


