CC = @gcc -c -Wall -pedantic
LCC = @gcc -Wall -pedantic -o

all: P1 clean
P1: p1_e1.o point.o
	@$(LCC) P1 p1_e1.o point.o
p1_e1.o: p1_e1.c point.h types.h
	$(CC) p1_e1.c 
point.o: point.c point.h types.h
	$(CC) point.c 
clean:
	rm -f *.o
