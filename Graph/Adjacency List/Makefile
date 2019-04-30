CC=gcc
CFLAGS=-gdwarf-2

Graph: Graph.o Queue.o testGraph.o 
	$(CC) -o Graph Graph.o Queue.o testGraph.o

Graph.o: Graph.c Graph.h

Queue.o: Queue.c Queue.h

testGraph.o: testGraph.c Graph.h

clean:
	rm -f *.o core
