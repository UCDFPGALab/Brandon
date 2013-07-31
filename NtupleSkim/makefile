CC=g++
CFLAGS= -c `root-config --cflags`
OFLAGS = `root-config --libs`

skim: ntupleskim.o koptions.o
	$(CC) $(OFLAGS) ntupleskim.o koptions.o -o skim

ntupleskim.o: ntupleskim.cc
	$(CC) $(CFLAGS) ntupleskim.cc

koptions.o: koptions.cc
	$(CC) $(CFLAGS) koptions.cc

clean:
	rm -rf *o skim
