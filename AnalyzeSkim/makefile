CC=g++
CFLAGS= -c `root-config --cflags`
OFLAGS = `root-config --libs`

analyze: Camel.o
	$(CC) $(OFLAGS) Camel.o -o analyze

Camel.o: Camel.C
	$(CC) $(CFLAGS) Camel.C

clean:
	rm -rf *o analyze
