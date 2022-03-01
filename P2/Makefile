CC = @gcc -c -Wall -pedantic
LCC = @gcc -o

all: P1e1 P1e2 P1e3 P2e1a clean
P1e1: p1_e1.o point.o map.o
	$(LCC) P1e1 p1_e1.o point.o map.o
P1e2: p1_e2.o point.o map.o
	$(LCC) P1e2 p1_e2.o point.o map.o
P1e3: p1_e3.o point.o map.o
	$(LCC) P1e3 p1_e3.o point.o map.o
P2e1a: p2_e1a.o point.o map.o
	@gcc -lm -o P2e1a p2_e1a.o point.o map.o
point.o: point.c point.h types.h
	$(CC) point.c 
map.o: map.c point.h types.h map.h
	$(CC) map.c 
clean:
	rm -f *.o
