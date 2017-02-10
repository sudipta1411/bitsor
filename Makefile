CC = gcc
CFLAGS = -I.
DFLAGS = -DOMP -DNUM=1024*128 -DNUM_THREAD=16
FFLAGS = -fopenmp
INCLUDE = bits.h do_or.h
OBJ = bits.o main.o do_or.o
EXEC = bitsor

%.o: %.c $(INCLUDE)
	$(CC) -c -o $@ $< $(CFLAGS) $(DFLAGS) $(FFLAGS)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(DFLAGS) $(FFLAGS)

clean:
	rm -fv *.o
	rm -v $(EXEC)
