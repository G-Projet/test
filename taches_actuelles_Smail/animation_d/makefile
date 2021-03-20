
CC=gcc

FLAGS=-Wall -g
 
SDL_DIR=${HOME}/SDL2

SDLLIB_DIR=${SDL_DIR}/lib
SDLINC_DIR=${SDL_DIR}/include

LIBS=-L${SDLLIB_DIR} -lSDL2 -lSDL2_ttf -lSDL2_image
INCS=-I${SDLINC_DIR}

  
PROG1=anim1
PROG2=anim2
 

all:anim1 
all:anim2
 
 
anim1: anim1.o 
	${CC} -o ${PROG1} anim1.o ${LIBS} ${INCS} ${FLAGS}
       
anim1.o: anim1.c init.h
	${CC} -o anim1.o -c anim1.c ${LIBS} ${INCS} ${FLAGS}

	

anim2: anim2.o 
	${CC} -o ${PROG2} anim2.o ${LIBS} ${INCS} ${FLAGS}
 
anim2.o: anim2.c init.h
	${CC} -o anim2.o -c anim2.c ${LIBS} ${INCS} ${FLAGS}

 

clean:

	rm -f ${PROG1} ${PROG2} 
	rm -f *.o


	
	
