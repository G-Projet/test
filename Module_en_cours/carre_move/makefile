

CC=gcc

FLAGS=-Wall -g
 
SDL_DIR=${HOME}/SDL2

SDLLIB_DIR=${SDL_DIR}/lib
SDLINC_DIR=${SDL_DIR}/include

LIBS=-L${SDLLIB_DIR} -lSDL2 -lSDL2_ttf -lSDL2_image
INCS=-I${SDLINC_DIR}

 
PROG1=depl_carre
PROG2=exe2
 
all:depl_carre
all: exe2

depl_carre: depl_carre.o
	${CC} -o ${PROG1} depl_carre.o ${LIBS} ${INCS} ${FLAGS}
    
depl_carre.o: depl_carre.c
	${CC} -o depl_carre.o -c depl_carre.c ${LIBS} ${INCS} ${FLAGS}

exe2: main3.o
	${CC} -o ${PROG2} main3.o ${LIBS} ${INCS} ${FLAGS}
        
main3.o: main3.c
	${CC} -o main3.o -c main3.c ${LIBS} ${INCS} ${FLAGS}




clean:

	rm -f ${PROG1} ${PROG2}
	rm -f *.o


	
