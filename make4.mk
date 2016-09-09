C=gcc
CFLAGS=-c

udp: udps udpc

udps: udp1.o
	$(CC) udp1.o -o udps
udpc: udp2.o
	$(CC) udp2.o -o udpc
sockprog.o: udp1.c
	$(CC) $(CFLAGS) udp1.c
cli.o: udp2.c
	$(CC) $(CFLAGS) udp2.c
clean:
	rm -rf *.o
