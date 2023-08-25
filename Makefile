CC=g++

CFLAGS=-c -Wall -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

all: Kvadratka

Kvadratka: main.o input.o algorithm.o output.o debug.o test.o
	$(CC) main.o input.o algorithm.o output.o debug.o -o Kvadratka

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

input.o: input.cpp
	$(CC) $(CFLAGS) input.cpp

algorithm.o: algorithm.cpp
	$(CC) $(CFLAGS) algorithm.cpp

output.o: output.cpp
	$(CC) $(CFLAGS) output.cpp

debug.o: debug.cpp
	$(CC) $(CFLAGS) debug.cpp

test.o: test.cpp
	$(CC) $(CFLAGS) test.cpp

clean:
	rm -rf *.o Kvadratka
