CC 			= gcc
CFLAGS		= -Wall -Wextra -pedantic -pedantic-errors
LDFLAGS    	= -lGL -lglfw

all: clean example1 example2

clean:
	rm -f *.bin

example1:
	$(CC) $(CFLAGS) example1.c T20/*.c $(LDFLAGS) -o $@.bin

example2:
	$(CC) $(CFLAGS) example2.c T20/*.c $(LDFLAGS) -o $@.bin


