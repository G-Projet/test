
CC=gcc

FLAGS=-Wall -g

#CPPFLAGS = -I. -I$(HOME)/SDL2/include $(shell sdl2-config --cflags)  
 
SDL_DIR=${SDL2}/SDL2

SDLLIB_DIR=${SDL_DIR}/lib
SDLINC_DIR=${SDL_DIR}/include 

LIBS=-L${SDLLIB_DIR} -lSDL2 -lSDL2_ttf -lSDL2_image
INCS=-I${SDLINC_DIR} 

PROG=sdl_test 

all: sdl_text

sdl_text: sdl_test.c
	${CC} -o ${PROG} sdl_test.c ${LIBS} ${INCS} ${FLAGS}

clean:
	rm -f ${PROG}
	rm -f *.o

