CC = @gcc -c -Wall -pedantic
LCC = @gcc -o

all: P2e1a P2e1b clean

P2e1a: p2_e1a.o point.o map.o
	$(LCC) P2e1a p2_e1a.o map.o point.o -lm -pthread

P2e1b: p2_e1b.o point.o map.o
	$(LCC) P2e1b p2_e1b.o map.o point.o -lm -pthread -Llibrerias -lstack_fDoble

p2_e1a.o: p2_e1a.c map.h point.h types.h
	$(CC) p2_e1a.c 

p2_e1b.o: p2_e1b.c map.h point.h types.h
	$(CC) p2_e1b.c -Ilibrerias

point.o: point.c point.h types.h
	$(CC) point.c 

map.o: map.c point.h types.h map.h
	$(CC) map.c 

clean:
	rm -f *.o
