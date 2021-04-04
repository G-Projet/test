
CC=gcc

FLAGS=-Wall -g
 
SDL_DIR=${HOME}/SDL2
SDLLIB_DIR=${SDL_DIR}/lib
SDLINC_DIR=${SDL_DIR}/include
LIBS=-L${SDLLIB_DIR} -lSDL2 -lSDL2_ttf -lSDL2_image
INCS=-I${SDLINC_DIR}

LDFLAGS=${LIBS} ${INCS} ${FLAGS}

PROG1=exe
 
all:exe
 
exe:main.o page1.o fonction.o jeu1.o
	${CC} -o ${PROG1} main.o page1.o fonction.o jeu1.o ${LDFLAGS} 

main.o: main.c fonction.h commun.h
	${CC} -o main.o -c main.c ${LDFLAGS}

page1.o: page1.c fonction.h commun.h
	${CC} -o ${PROG2} page1.o -c page1.c ${LDFLAGS}
	 
fonction.o:fonction.c fonction.h commun.h
	${CC} -o ${PROG2} fonction.o -c fonction.c ${LDFLAGS}

jeu1.o:jeu1.c fonction.h commun.h
	${CC} -o ${PROG2} jeu1.o -c jeu1.c ${LDFLAGS}

clean:

	rm -f ${PROG}
	rm -f *.o


