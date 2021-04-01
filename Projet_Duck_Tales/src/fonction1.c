

#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "fonction.h"

void bienvenus()
{
	SDL_version nb;
	SDL_VERSION(&nb);
	
	system("clear");
	printf("\t********************************************************\n");
	printf("\t*    Bienvenus sur la platforme de jeux Duck_Tales     *  \n");
	printf("\t* \t \t SDL version : %d . %d . %d              *\n", nb.major, nb.minor, nb.patch );
	printf("\t********************************************************\n");	
	sleep(1);
}
/*
extern
void evenement (SDL_bool vBouleen )
{
	while(vBouleen)
	{
		SDL_Event event;

		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{    
			  	// Gestion des évenements claviers ou souris

				case SDL_QUIT:
					vBouleen = SDL_FALSE;
					break;

				default:
					break;
			}
		}
	}
}
*/
extern
char message_erreurs(const char* message )
{
	fprintf(stderr, "ERREUR : %s >(%s)\n", message, SDL_GetError());
	SDL_Quit(); // On quitte la SDL
	return EXIT_FAILURE;
}
	
extern
void liberation_ressources(SDL_Window* w, SDL_Renderer *r,SDL_Surface* image, SDL_Texture *t) // libération des resources subsistantes
{
	if(w!=NULL)
		SDL_DestroyWindow(w);
	if(r!=NULL)
		SDL_DestroyRenderer(r);
	if(image!=NULL)
		SDL_FreeSurface(image); //permet de libérer la mémoire quand on n'a plus besoin d'une surface
	if(t!=NULL)
		SDL_DestroyTexture(t);
}
