
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
 
#include "fonction.h"

void bienvenus()
{
	SDL_version nb;
	SDL_VERSION(&nb);
	 
	printf("********************************************************\n");
	printf("* Bienvenus sur la platforme de jeux Duck_Tales        *  \n");
	printf("* \t \t SDL version : %d . %d . %d              *\n", nb.major, nb.minor, nb.patch );
	printf("********************************************************\n");	
}

extern
void sdl_init(bool* const error, int (*sdlInit)(int*))
{
  //if (SDL_Init(SDL_INIT_VIDEO) == 0)

  //if (sdlInit) == 0)

	if(sdlInit) // -1

      *error = TRUE;
}

extern
char message_erreurs()
{
	fprintf(stderr, "U5_SDL.c > SDL init failed (%s)\n", SDL_GetError());
	return EXIT_FAILURE;
}

extern 
void arret_programme(SDL_Surface* image,SDL_Renderer* renderer,SDL_Window * window)
{
	SDL_FreeSurface(image); //permet de libérer la mémoire quand on n'a plus besoin d'une surface
	SDL_DestroyRenderer(renderer); // Destruction du renderer  
	SDL_DestroyWindow(window); // Close and destroy the window
}	
	
	
extern
void clean_ressources(SDL_Window*w, SDL_Renderer *r, SDL_Texture *t) // libération des resources subsistantes
{
	if(t!=NULL)
		SDL_DestroyTexture(t);
	if(r!=NULL)
		SDL_DestroyRenderer(r);
	if(w!=NULL)
		SDL_DestroyWindow(w);
}
	
	
	
	
	




