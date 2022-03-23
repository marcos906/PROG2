CC = @gcc -c -Wall -pedantic
LCC = @gcc -o

all: P3e1b clean

P3e1b: p3_e1b.o point.o utilities.o sorted_queue.o
	$(LCC) P3e1b p3_e1b.o point.o sorted_queue.o utilities.o -lm -pthread -Llibrerias -lqueue

stack_fDoble.o: stack_fDoble.c stack_fDoble.h types.h
	$(CC) stack_fDoble.c

sorted_queue.o: sorted_queue.c sorted_queue.h types.h 
	$(CC) sorted_queue.c -Ilibrerias 

p3_e1b.o: p3_e1b.c point.h utilities.h sorted_queue.h
	$(CC) p3_e1b.c

utilities.o: utilities.c 
	$(CC) utilities.c

point.o: point.c point.h types.h
	$(CC) point.c 

map.o: map.c point.h types.h map.h stack_fDoble.h
	$(CC) map.c 

clean:
	rm -f *.o
	
valgrindP2e1a:
	@echo ">>>>>>Running P2e1a with valgrind"
	valgrind --leak-check=full -s ./P2e1a 5
	
valgrindP2e1b:
	@echo ">>>>>>Running P2e1b with valgrind"
	valgrind --leak-check=full -s ./P2e1b 5
	
valgrindvP2e1c:
	@echo ">>>>>>Running P2e1c with valgrind"
	valgrind --leak-check=full -s ./P2e1c 5
	
valgrindP2e2:
	@echo ">>>>>>Running P2e2 with valgrind"
	valgrind --leak-check=full -s ./P2e2 laberinto_2.txt

