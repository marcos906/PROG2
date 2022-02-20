CC = @gcc -c -Wall -pedantic
LCC = @gcc -Wall -pedantic -o

all: P1 clean
P1: p1_e2.o point.o map.o
	$(LCC) P1 p1_e2.o point.o map.o
point.o: point.c point.h types.h
	$(CC) point.c 
map.o: map.c point.h types.h map.h
	$(CC) map.c 
clean:
	rm -f *.o
