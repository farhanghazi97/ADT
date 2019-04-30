CC=gcc

AMGraph : AMGraph.o Queue.o
	$(CC) -o AMGraph AMGraph.o Queue.o

AMGraph.o : AMGraph.c AMGraph.h

Queue.o : Queue.c Queue.h

clean:
	rm -f *.o core
