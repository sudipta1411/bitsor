CC=gcc
CFLAGS=-I.
INCLUDE = bits.h do_or.h
OBJ = bits.o main.o do_or.o

%.o: %.c $(INCLUDE)
	$(CC) -c -o $@ $< $(CFLAGS)

bits: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -fv *.o
