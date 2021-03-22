
CC=gcc

FLAGS=-Wall -g 
 
SDL_DIR=${HOME}/SDL2

SDLLIB_DIR=${SDL_DIR}/lib

SDLINC_DIR=${SDL_DIR}/include 

LIBS=-L${SDLLIB_DIR} -lSDL2 -lSDL2_ttf -lSDL2_image

INCS=-I${SDLINC_DIR} 


PROG=exe

all:exe

exe: ecran.o
	${CC} -o ${PROG} ecran.o ${LIBS} ${INCS} ${FLAGS}

ecran.o: ecran.c
	${CC} -o ecran.o -c ecran.c ${LIBS} ${INCS} ${FLAGS}

clean:
	rm -f ${PROG}
	rm -f *.o
 
