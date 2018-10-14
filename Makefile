PROG = reaction
CC = gcc
CFLAGS = -Wall -g -O3
IDIR = ~/gsl/include
LDIR = ~/gsl/lib
OBJECTS = func.o main.o
LDFLAGS = -lgsl -lgslcblas -lm

$(PROG): $(OBJECTS)
	$(CC) -L $(LDIR) $(OBJECTS) -o $(PROG) $(LDFLAGS)

main.o : main.c func.h
	$(CC) $(CFLAGS) -I $(IDIR) -c main.c

func.o : func.c func.h
	$(CC) $(CFLAGS) -I $(IDIR)  -c func.c

clean:
	rm -f $(OBJECTS) reaction
