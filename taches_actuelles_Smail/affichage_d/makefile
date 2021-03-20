
CC=gcc

FLAGS=-Wall -g
 
SDL_DIR=${HOME}/SDL2

SDLLIB_DIR=${SDL_DIR}/lib
SDLINC_DIR=${SDL_DIR}/include

LIBS=-L${SDLLIB_DIR} -lSDL2 -lSDL2_ttf -lSDL2_image
INCS=-I${SDLINC_DIR}


PROG=affichage
PROG2=animation
PROG3=essaye
PROG4=rotation

all:affichage 
all:animation
all:rotation
#all:essaye 
 

affichage: affichage.o 
	${CC} -o ${PROG} affichage.o ${LIBS} ${INCS} ${FLAGS}
       
affichage.o: affichage.c initialisation.h
	${CC} -o affichage.o -c affichage.c ${LIBS} ${INCS} ${FLAGS}
	
	

animation: animation.o 
	${CC} -o ${PROG2} animation.o ${LIBS} ${INCS} ${FLAGS}
 
animation.o: animation.c initialisation.h
	${CC} -o animation.o -c animation.c ${LIBS} ${INCS} ${FLAGS}

	
#essaye: essaye.o
	#${CC} -o ${PROG3} essaye.o ${LIBS} ${INCS} ${FLAGS}
       
#essaye.o: essaye.c initialisation.h
#	${CC} -o essaye.o -c essaye.c ${LIBS} ${INCS} ${FLAGS}
	
	
	
rotation: rotation.o
	${CC} -o ${PROG4} rotationo ${LIBS} ${INCS} ${FLAGS}
       
rotation.o: rotation.c initialisation.h
	${CC} -o rotation.o -c rotation.c ${LIBS} ${INCS} ${FLAGS}		
	
	

clean:

	rm -f ${PROG} ${PROG2} ${PROG3} ${PROG4}
	rm -f *.o


	
	
