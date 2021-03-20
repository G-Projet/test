
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
	
	

	
void anime(void)
{
	SDL_Rect positionFond, positionZozor, oldpositionZozor;
	SDL_Rect positionFond_c, positionZozor_c;

	SDL_Rect clipper;
	
	int avanceX = 1, avanceY = 1;

	positionFond.x = 0;
	positionFond.y = 0;

	positionZozor.x = 0;
	positionZozor.y = 0;

	oldpositionZozor.x = 0;
	oldpositionZozor.y = 0;


	while (1) {
		
		clipper.x = oldpositionZozor.x;
		clipper.y = oldpositionZozor.y;
		clipper.h = zozor->h;
		clipper.w = zozor->w;
		SDL_SetClipRect(ecran,&clipper);

		positionFond_c.x = positionFond.x;
		positionFond_c.y = positionFond.y;

		positionZozor_c.x = positionZozor.x;
		positionZozor_c.y = positionZozor.y;


		SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond_c);

                SDL_SetClipRect(ecran,NULL); // J'ai choisi cette solution
                
		SDL_BlitSurface(zozor, NULL, ecran, &positionZozor_c);

		oldpositionZozor.x = positionZozor.x;
		oldpositionZozor.y = positionZozor.y;
			
		if (avanceX) {
			positionZozor.x++;
		} else {
			positionZozor.x--;
		}

		if (avanceY) {
			positionZozor.y++;
		} else {
			positionZozor.y--;
		}

		if (positionZozor.x == ecran->w - zozor->w - 1)
			avanceX = 0;
		else if (positionZozor.x == 0)
			avanceX = 1;

		if (positionZozor.y == ecran->h - zozor->h - 1)
			avanceY = 0;
		else if (positionZozor.y == 0)
			avanceY = 1;

		//SDL_Flip(ecran);
		//input_handle();
		//SDL_Delay(10);
	}
}
 



