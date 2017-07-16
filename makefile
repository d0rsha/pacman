# Makefile
# build with make

CC = g++
FLAGS += -std=c++17 -pedantic -Wall -Wextra -Weffc++ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

OBJECTS = Chart.o

main: bin ${OBJECTS} makefile src/main.cc
	${CC} ${FLAGS} src/main.cc ${OBJECTS} -o bin/game

bin: 
	@ \mkdir -p bin
Chart.o: src/Chart.h 
	${CC} ${FLAGS} -c src/Chart.cc 

clean:
	@ \rm -f *.o *.gch
	@ \rm -f -r bin
zap:
	@ \rm -f *.~*
