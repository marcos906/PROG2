CC = @gcc -c -Wall -pedantic
LCC = @gcc -o

all: P3e1b clean



point.o: point.c point.h types.h
	$(CC) point.c 

map.o: map.c point.h types.h map.h
	$(CC) map.c -Ilibrerias

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

