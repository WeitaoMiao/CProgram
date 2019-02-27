cc = gcc
ofile = main.o File.o TrapFormNum.o IntegrandFcn.o
hfile = File.h TrapFormNum.h IntegrandFcn.h


Bessel: $(ofile)
	$(cc) $(ofile) -lm -o Bessel
main.o: main.c TrapFormNum.h File.h
	$(cc) -c main.c
TrapFormNum.o: TrapFormNum.c IntegrandFcn.h
	$(cc) -c TrapFormNum.c
IntegrandFcn.o: IntegrandFcn.c
	$(cc) -c IntegrandFcn.c
File.o: File.c
	$(cc) -c File.c


.PHONY: clean
clean:
	rm Bessel *.o
