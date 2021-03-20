

CIBLE = DuckTales

CC = gcc

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

	

	

	

	

	
