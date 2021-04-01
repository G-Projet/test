 
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
	
sdl.o: sdl.c init.h
	${CC} -o sdl.o -c sdl.c ${LDFLAGS}

fonction.o: fonction.c page1.c
	${CC} -o fonction.o -c fonction.c ${LDFLAGS}

affichage1.o: affichage1.c
	${CC} -o affichage1.o -c affichage1.c ${LDFLAGS}

affichage2.o: affichage2.c init.h
	${CC} -o affichage2.o -c affichage2.c ${LDFLAGS}



page2.o: page2.c
	${CC} -o page2.o -c page2.c ${LDFLAGS}

page1.o: page1.c
	${CC} -o page1.o -c page1.c ${LDFLAGS}




clean:

	rm -f ${PROG}
	rm -f *.o
