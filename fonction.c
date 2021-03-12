
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
void evenement (SDL_bool program_launched )
{
	while(program_launched)
	{
		SDL_Event event;

		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{    
			  	/* Gestion des évenements claviers ou souris  */

				case SDL_QUIT:
					program_launched = SDL_FALSE;
					break;

				default:
					break;
			}
		}
	}
}

extern
char message_erreurs(const char* message )
{
	fprintf(stderr, "ERREUR : %s >(%s)\n", message, SDL_GetError());
	SDL_Quit(); // On quitte la SDL
	return EXIT_FAILURE;
}
	
extern
void clean_ressources(SDL_Window* w, SDL_Renderer *r,SDL_Surface* image, SDL_Texture *t) // libération des resources subsistantes
{
	if(t!=NULL)
		SDL_DestroyTexture(t);
	if(r!=NULL)
		SDL_DestroyRenderer(r);
	if(w!=NULL)
		SDL_DestroyWindow(w);
	if(image!=NULL)
		SDL_FreeSurface(image); //permet de libérer la mémoire quand on n'a plus besoin d'une surface
}
	
	

	
	




