LIB := $(shell find ./lib -name '*.o')
all:
	 gcc -c solution.c
	 gcc -c main.c
	 gcc -o solution.exe solution.o main.o $(LIB)

solutiontest: clean
	 gcc -c solution.c
	 gcc -c solutiontest.c
	 gcc -o solutiontest.exe solution.o solutiontest.o
	 ./solutiontest.exe

test:	 solutiontest

clean:
	 rm *.out *.o *.exe || exit 0

solution: clean
	 gcc -c solution.c
	 gcc -c main.c
	 gcc -o solution.exe solution.o main.o $(LIB)

run: solution
	 ./solution.exe

runtest: solution
	 ./maintest.tcl ./solution.exe
