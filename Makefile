CC=gcc
CFLAGS=-I.
INCLUDE = bits.h
OBJ = bits.o main.o

%.o: %.c $(INCLUDE)
	$(CC) -c -o $@ $< $(CFLAGS)

bits: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -fv *.o
