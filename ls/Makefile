CFLAGS= -g

ls : ls.o
	cc -o ls ls.o

ls.o : ls.c
	cc $(CFLAGS) -c ls.c

clean :
	rm ls ls.o
