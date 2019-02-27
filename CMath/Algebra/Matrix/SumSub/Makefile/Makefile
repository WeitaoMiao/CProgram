cc = gcc
ofile = main.o Start.o IniMatrix.o \
		Input.o Calculate.o Print.o \
		Free.o Other.o Files.o
hfile = Start.h IniMatrix.h Print.h \
		Free.h Other.h Files.h



Run : $(ofile)
	$(cc) -o Run $(ofile)



main.o : main.c $(hfile)
	$(cc) -c main.c

Start.o : Start.c Files.h
	$(cc) -c Start.c

IniMatrix.o : IniMatrix.c Input.h Calculate.h
	$(cc) -c IniMatrix.c

Input.o : Input.c
	$(cc) -c Input.c

Calculate.o : Calculate.c
	$(cc) -c Calculate.c

Print.o : Print.c Files.h
	$(cc) -c Print.c

Free.o : Free.c
	$(cc) -c Free.c

Other.o : Other.c
	$(cc) -c Other.c

Files.o : Files.c
	$(cc) -c Files.c



.PHONY: clean
clean:
	rm Run *.o *.txt
