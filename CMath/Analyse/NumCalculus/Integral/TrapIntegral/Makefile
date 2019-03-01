cc = gcc
ofile = main.o TrapezoidalFormula.o IntegrandFcn.o
hfile = TrapezoidalFormula.h IntegrandFcn.h

TrapezoidalFormula: $(ofile)
	$(cc) $(ofile) -lm -o TrapezoidalFormula

main.o: main.c TrapezoidalFormula.h
	$(cc) -c main.c
SimpsonInte.o: TrapezoidalFormula.c FcnBeInte.h
	$(cc) -c TrapezoidalFormula.c
IntegrandFcn.o: IntegrandFcn.c
	$(cc) -c IntegrandFcn.c

.PHONY: clean
clean:
	rm TrapezoidalFormula *.o
