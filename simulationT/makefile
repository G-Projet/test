
CC=gcc

FLAGS=-Wall -g
 
PROG=deplacement
 
all:deplacement
 
deplacement: deplacement.o 
	${CC} -o ${PROG} deplacement.o  ${FLAGS}

deplacement.o: deplacement.c chemin.h
	${CC} -o deplacement.o -c deplacement.c  ${FLAGS}

clean:

	rm -f ${PROG}  
	rm -f *.o


	
	
