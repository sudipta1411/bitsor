CC = gcc
CFLAGS = -I.
DFLAGS =  -DNUM=1024*128 -DNUM_THREAD=16
FFLAGS = -fopenmp
LFLAGS = -lm
INCLUDE = bits.h do_or.h
OBJ = bits.o main.o do_or.o
EXEC = bitsor

%.o: %.c $(INCLUDE)
	$(CC) -c -o $@ $< $(CFLAGS) $(DFLAGS) $(FFLAGS) $(LFLAGS)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(DFLAGS) $(FFLAGS) $(LFLAGS)

clean:
	rm -fv *.o
	rm -v $(EXEC)
