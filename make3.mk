CC=gcc
CFLAGS=-c

unix: uns unc

uns: unixser.o
	$(CC) unixser.o -o uns
unc: clcl.o
	$(CC) clcl.o -o unc
unixser.o: unixser.c
	$(CC) $(CFLAGS) unixser.c
clcl.o: clcl.c
	$(CC) $(CFLAGS) clcl.c
clean:
	rm -rf uns
	rm -rf unc
