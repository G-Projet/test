
CC=gcc

FLAGS=-Wall -g
 
SDL_DIR=${HOME}/SDL2

SDLLIB_DIR=${SDL_DIR}/lib
SDLINC_DIR=${SDL_DIR}/include

LIBS=-L${SDLLIB_DIR} -lSDL2 -lSDL2_ttf -lSDL2_image
INCS=-I${SDLINC_DIR}

LDFLAGS=${LIBS} ${INCS} ${FLAGS}

PROG1=affichage1 
PROG2=affichage2
 
all:affichage1 affichage2
 
affichage1: affichage.o 
	${CC} -o ${PROG1} affichage.o ${LDFLAGS} 
       
affichage.o: affichage.c initialisation.h
	${CC} -o affichage.o -c affichage.c ${LDFLAGS}



affichage2: affichage2.o 
	${CC} -o ${PROG2} affichage2.o ${LDFLAGS} 
       
affichage2.o: affichage2.c initialisation.h
	${CC} -o affichage2.o -c affichage2.c ${LDFLAGS}
 
clean:

	rm -f ${PROG1} ${PROG2}
	rm -f *.o


	
	
