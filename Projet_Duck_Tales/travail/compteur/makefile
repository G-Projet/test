

CC=gcc

FLAGS=-Wall -g
 
SDL_DIR=${HOME}/SDL2
SDLLIB_DIR=${SDL_DIR}/lib
SDLINC_DIR=${SDL_DIR}/include
LIBS=-L${SDLLIB_DIR} -lSDL2 -lSDL2_ttf -lSDL2_image
INCS=-I${SDLINC_DIR}

LDFLAGS=${LIBS} ${INCS} ${FLAGS}


PROG1=fenetre
PROG2=temps
 
all:fenetre temps
 
temps:temps.o 
	${CC} -o ${PROG2} temps.o ${LDFLAGS} 

temps.o: temps.c 
	${CC} -o temps.o -c temps.c ${LDFLAGS}

	

##################


fenetre:fenetre.o 
	${CC} -o ${PROG1} fenetre.o ${LDFLAGS} 

fenetre.o: fenetre.c 
	${CC} -o fenetre.o -c fenetre.c ${LDFLAGS}

clean:

	rm -f ${PROG}
	rm -f *.o







