CC	= cc

pl0i	: inter.o  common.o
	$(CC) inter.o  common.o -o pl0i

myinter2.o	: inter.c
	$(CC) -c inter.c

common.o	: common.c
	$(CC) -c common.c

clean:	
	rm -f *~ *.o pl0i
