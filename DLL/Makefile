CC=gcc

DLL: DLL.o testDLL.o
	$(CC) -o DLL DLL.o testDLL.o

DLL.o: DLL.c DLL.h

testDLL.o: testDLL.c DLL.h

clean:
	rm -f *.o core
