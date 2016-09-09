CC=gcc
CFLAGS=-c

tcp: tcps tcpc

tcps: sockprog.o
	$(CC) sockprog.o -o tcps
tcpc: cli.o
	$(CC) cli.o -o tcpc
sockprog.o: sockprog.c
	$(CC) $(CFLAGS) sockprog.c
cli.o: cli.c
	$(CC) $(CFLAGS) cli.c
clean:
	rm -rf tcps
	rm -fr tcpc
