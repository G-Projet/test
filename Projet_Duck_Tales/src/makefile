 
CC=gcc

FLAGS=-Wall -g 
 
SDL_DIR=${HOME}/SDL2
SDLLIB_DIR=${SDL_DIR}/lib
SDLINC_DIR=${SDL_DIR}/include 

LIBS=-L${SDLLIB_DIR} -lSDL2 -lSDL2_ttf -lSDL2_image
INCS=-I${SDLINC_DIR} 

LDFLAGS=${LIBS} ${INCS} ${FLAGS}

PROG=exe

all: exe

exe: sdl.o fonction.o
	${CC} -o ${PROG} sdl.o fonction.o ${LDFLAGS} 

	
sdl.o: sdl.c fonction.h
	${CC} -o sdl.o -c sdl.c ${LDFLAGS}

fonction.o: fonction.c
	${CC} -o fonction.o -c fonction.c ${LDFLAGS}

clean:

	rm -f ${PROG}
	rm -f *.o
