CC= gcc
CFLAGS= -Wall -g -DNDEBUG
DEPS= dbg.h ex22.h

clean:
	rm -f functions

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) 

main_ex22: main_ex22.o ex22.o
	$(CC) main_ex22.o ex22.o -o main_ex22 $(CFLAGS) -I.
