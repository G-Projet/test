
CC=gcc

FLAGS=-Wall -g 
 
SDL_DIR=${HOME}/SDL2

SDLLIB_DIR=${SDL_DIR}/lib

SDLINC_DIR=${SDL_DIR}/include 

LIBS=-L${SDLLIB_DIR} -lSDL2 -lSDL2_ttf -lSDL2_image

INCS=-I${SDLINC_DIR} 


PROG1=ecran
PROG2=imageMouve


all:ecran imageMouve

ecran: ecran.o
	${CC} -o ${PROG1} ecran.o ${LIBS} ${INCS} ${FLAGS}

ecran.o: ecran.c
	${CC} -o ecran.o -c ecran.c ${LIBS} ${INCS} ${FLAGS}


imageMouve: imageMouve.o
	${CC} -o ${PROG2} imageMouve.o ${LIBS} ${INCS} ${FLAGS}

imageMouve.o: imageMouve.c
	${CC} -o imageMouve.o -c imageMouve.c ${LIBS} ${INCS} ${FLAGS}



clean:
	rm -f ${PROG} ${PROG2}
	rm -f *.o
 
