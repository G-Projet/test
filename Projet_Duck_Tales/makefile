
CIBLE = DuckTales

CC=gcc

FLAGS=-Wall -g 
 
SDL_DIR=${HOME}/SDL2
SDLLIB_DIR=${SDL_DIR}/lib
SDLINC_DIR=${SDL_DIR}/include 
LIBS=-L${SDLLIB_DIR} -lSDL2 -lSDL2_ttf -lSDL2_image
INCS=-I${SDLINC_DIR} 

LDFLAGS=${LIBS} ${INCS} ${FLAGS}

SRCDIR = src
OBJDIR = obj
BINDIR = bin

DIRS = $(OBJDIR) $(BINDIR)

.PHONY: DIRS
all: $(DIRS) $(BINDIR)/$(CIBLE)

$(OBJDIR):
	mkdir -p $(OBJDIR)
$(BINDIR):
	mkdir -p $(BINDIR)

SOURCES = $(wildcard $(SRCDIR)/*.c)
INCLUDES = $(wildcard $(SRCDIR)/*.h)

OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

$(BINDIR)/$(CIBLE): $(OBJECTS)
	@$(CC) $(OBJECTS) -o $@
	@echo "Liens terminés!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(CC) -c $< -I$(SRCDIR) -o $@
	@echo "Compilation de "$<" terminée!"

.PHONY: clean
clean:
	-@rm -rf $(OBJDIR)
	@echo "Nettoyage terminé!"

.PHONY: remove
remove: clean
	-@rm -rf $(BINDIR)
	-@rm -rf docs/
	@echo "Exécutable et documentation supprimés!"

.PHONY: docs

docs:
	@doxygen

	


#CIBLE = DuckTales

#CC=gcc

#FLAGS=-Wall -g 
 
#SDL_DIR=${HOME}/SDL2
#SDLLIB_DIR=${SDL_DIR}/lib
#SDLINC_DIR=${SDL_DIR}/include 
#LIBS=-L${SDLLIB_DIR} -lSDL2 -lSDL2_ttf -lSDL2_image
#INCS=-I${SDLINC_DIR} 
#PROG=exe


#all: exe

#exe: sdl.o fonction.o
	#${CC} -o ${PROG} sdl.o fonction.o ${LDFLAGS}

	
#main.o: sdl.c fonction.h
	#${CC} -o sdl.o -c sdl.c ${LDFLAGS}

#fonction.o: fonction.c
	#${CC} -o fonction.o -c fonction.c ${LDFLAGS}

#clean:

	#rm -f ${PROG}
	#rm -f *.o
