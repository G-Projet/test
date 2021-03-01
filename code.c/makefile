
CC=gcc

SDL_DIR=${HOME}/SDL2
SDLLIB_DIR=${SDL_DIR}/lib
SDLINC_DIR=${SDL_DIR}/include
SDLBIN_DIR=${SDL_DIR}/bin

LIBS=-L${SDLLIB_DIR} -lSDL2 -lSDL2_ttf 
LIBS=-L${SDLLIB_DIR} -lSDL2 -lSDL2_image
INCLUDES=-I${SDLINC_DIR} 

#PROG=sdl_test 
PROG=sdl_main

#all: sdl_text
all:  sdl_main fonction.o sdl_fonction.h

sdl_fonction.o: sdl_fonction.c 
	$(CC) -c sdl_fonction.c -o sdl_fonction.o 

#sdl_text: sdl_test.c
sdl_text: sdl_main.c
	#${CC} -o ${PROG} sdl_test.c ${LIBS} ${INCLUDES}
	${CC} -o ${PROG} sdl_main.c ${LIBS} ${INCLUDES}

clean: 
	rm -f ${PROG}
	rm -f *.o


