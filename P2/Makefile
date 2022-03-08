CC = @gcc -c -Wall -pedantic
LCC = @gcc -o

all: P2e1a P2e1b P2e1c P2e2 clean

P2e1a: p2_e1a.o point.o map.o
	$(LCC) P2e1a p2_e1a.o map.o point.o -lm -pthread

P2e1b: p2_e1b.o point.o map.o
	$(LCC) P2e1b p2_e1b.o map.o point.o -lm -pthread -Llibrerias -lstack_fDoble

P2e1c: p2_e1c.o point.o map.o
	$(LCC) P2e1c p2_e1c.o map.o point.o -lm -pthread -Llibrerias -lstack_fDoble

P2e2: p2_e2.o point.o map.o
	$(LCC) P2e2 p2_e2.o map.o point.o -lm -pthread -Llibrerias -lstack_fDoble

p2_e1a.o: p2_e1a.c map.h point.h types.h
	$(CC) p2_e1a.c 

p2_e1b.o: p2_e1b.c map.h point.h types.h
	$(CC) p2_e1b.c -Ilibrerias

p2_e1c.o: p2_e1c.c map.h point.h types.h
	$(CC) p2_e1c.c -Ilibrerias

p2_e2.o: p2_e2.c map.h point.h types.h
	$(CC) p2_e2.c -Ilibrerias

point.o: point.c point.h types.h
	$(CC) point.c 

map.o: map.c point.h types.h map.h
	$(CC) map.c -Ilibrerias

clean:
	rm -f *.o
