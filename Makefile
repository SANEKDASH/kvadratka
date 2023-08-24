all: Kvadratka

Kvadratka: main.o input.o algorithm.o output.o debug.o test.o
	g++ main.o input.o algorithm.o output.o debug.o -o Kvadratka 

main.o: main.cpp
	g++ -c main.cpp

input.o: input.cpp
	g++ -c input.cpp

algorithm.o: algorithm.cpp
	g++ -c algorithm.cpp

output.o: output.cpp
	g++ -c output.cpp

debug.o: debug.cpp
	g++ -c debug.cpp

test.o: test.cpp
	g++ -c test.cpp

clean:
	rm -rf *.o Kvadratka