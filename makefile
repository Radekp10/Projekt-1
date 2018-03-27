#makefile

__start__: a.out
	./a.out

a.out: main.o zbior.o
	g++ main.o zbior.o

main.o: main.cpp zbior.h
	g++ -c -Wall main.cpp


zbior.o: zbior.h zbior.cpp
	g++ -c -Wall zbior.cpp

clean: 
	rm main.o zbior.o a.out
