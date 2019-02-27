cc = gcc
ofile = main.o SimpsonInte.o FcnBeInte.o
hfile = SimpsonInte.h FcnBeInte.h

SimpsonInte: $(ofile)
	$(cc) $(ofile) -lm -o SimpsonInte

main.o: main.c SimpsonInte.h
	$(cc) -c main.c
SimpsonInte.o: SimpsonInte.c FcnBeInte.h
	$(cc) -c SimpsonInte.c
FcnBeInte.o: FcnBeInte.c
	$(cc) -c FcnBeInte.c

.PHONY: clean
clean:
	rm SimpsonInte *.o

