CC=gcc
CFLAGS=-c
all: 
serv: sockprog.c
	$(CC) $(CFLAGS) sockprog.c
clin: cli.c
	$(CC) -$(CFLAGS) cli.c
clean:
	rm -rf *.o dwt
