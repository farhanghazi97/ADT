CC=gcc
CFLAGS=-gdwarf-2

Graph: Graph.o testGraph.o
	$(CC) -o Graph Graph.o testGraph.o

Graph.o: Graph.c Graph.h

testGraph.o: testGraph.c Graph.h

clean:
	rm -f *.o core
