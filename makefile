# Makefile
# build with make

CC = g++
FLAGS += -std=c++17 -pedantic -Wall -Wextra -Weffc++ 
SFML += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
INC += -I${SFML_ROOT}/include -L${SFML_ROOT}/lib

OBJECTS = Chart.o

main: bin ${OBJECTS} makefile src/main.cc
	${CC} ${FLAGS} src/main.cc ${OBJECTS} ${SFML} -o bin/game

bin: 
	@ \mkdir -p bin
Chart.o: src/header/Chart.h 
	${CC} ${FLAGS} -c src/Chart.cc ${SFML} 

clean:
	@ \rm -f *.o *.gch
	@ \rm -f -r bin
zap:
	@ \rm -f *.~*
