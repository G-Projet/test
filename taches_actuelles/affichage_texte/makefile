
CC=gcc

FLAGS=-Wall -g
 
SDL_DIR=${HOME}/SDL2

SDLLIB_DIR=${SDL_DIR}/lib
SDLINC_DIR=${SDL_DIR}/include

LIBS=-L${SDLLIB_DIR} -lSDL2 -lSDL2_ttf -lSDL2_image
INCS=-I${SDLINC_DIR}

LDFLAGS=${LIBS} ${INCS} ${FLAGS}

PROG=affichage

all:affichage 
 
affichage: affichage.o 
	${CC} -o ${PROG} affichage.o ${LDFLAGS} 
       
affichage.o: affichage.c initialisation.h
	${CC} -o affichage.o -c affichage.c ${LDFLAGS}
 
clean:

	rm -f ${PROG}
	rm -f *.o


	
	
