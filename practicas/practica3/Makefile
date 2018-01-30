all:
	gcc -o speed.exe main.c

main.o:
		gcc -c main.c

runtest: main.o
	gcc -o speed.exe main.o
	./testmain.tcl ./speed.exe
