CC=gcc
CFLAGS=-gdwarf-2

Graph: Graph.o Queue.o Stack.o testGraph.o
	$(CC) -o Graph Graph.o Queue.o Stack.o testGraph.o

Graph.o: Graph.c Graph.h

Queue.o: Queue.c Queue.h

Stack.o: Stack.c Stack.h

testGraph.o: testGraph.c Graph.h

clean:
	rm -f *.o core
