# Makefile
# build with make

CC = g++
FLAGS += -std=c++17 -pedantic -Wall -Wextra -Weffc++ 
SFML += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
INC += -I${SFML_ROOT}/include -L${SFML_ROOT}/lib

OBJECTS = Chart.o Animation.o Pacman.o

main: bin ${OBJECTS} makefile src/main.cc
	${CC} ${FLAGS} src/main.cc ${OBJECTS} ${SFML} -o bin/game

bin: 
	@ \mkdir -v -p bin
Chart.o: src/Chart.h src/Chart.cc
	${CC} ${FLAGS} -c src/Chart.cc ${SFML} 
Animation.o: src/Animation.h src/Animation.cc
	${CC} ${FLAGS} -c src/Animation.cc ${SFML}
Pacman.o: src/Pacman.h src/Pacman.cc
	${CC} ${FLAGS} -c src/Pacman.cc ${SFML}

clean:
	@ \rm -f *.o *.gch
	@ \rm -f -r bin
zap:
	@ \rm -f *~*
	@ \rm -f src/*~
