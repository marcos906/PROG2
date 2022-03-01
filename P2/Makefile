CC = @gcc -c -Wall -pedantic
LCC = @gcc -o

all: P2e1a clean

P2e1a: p2_e1a.o point.o map.o
	$(LCC) P2e1a p2_e1a.o map.o point.o -lm -pthread

p2_e1a.o: p2_e1a.c map.h point.h types.h
	$(CC) p2_e1a.c 

point.o: point.c point.h types.h
	$(CC) point.c 

map.o: map.c point.h types.h map.h
	$(CC) map.c 

clean:
	rm -f *.o
