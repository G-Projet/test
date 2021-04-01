
/**
* \file sdl.c
* \brief Contient toutes les fonctions pour interface graphique
* \date Mardi 01 mars 2021
*/


#include "init.h"

int main(int argc, char** argv)
{
	int temps_Actuel= SDL_GetTicks();

	bienvenus();
	
	/******** gestion évenement *******/

	continuer=VRAI;

	while (continuer)
	{
		while(SDL_WaitEvent(&event))
		{	
			switch(event.type)
			{
			    case SDL_QUIT:
			    
			    	continuer = FAUX;
			    	break;
 
			    // gestion des touches du clavier

				case SDL_KEYDOWN: //appuyer
					switch(event.key.keysym.sym)
					{
						case SDLK_b:
							SDL_DestroyRenderer(renderer);
							affichagePage1();
							continue; //break;

 						case SDLK_a:
							//affichagePage2();
							continue; //break;

						default:
							 break;
					}

				case SDL_KEYUP: // relacher
					switch(event.key.keysym.sym)
					{
						case SDLK_a:

							printf(" vous avez relacher la touche B \n");
							//affichagePage2();
							continuer=FAUX; //break;

						case SDLK_b:
							SDL_DestroyRenderer(renderer);
							affichagePage1();
							continuer=FAUX; //break;

						default:
							 break;
					}
			}
		}

	}

	liberation_ressources(window,renderer,image,texture);

	printf(" %d s écoulées \n",((SDL_GetTicks()-temps_Actuel)/1000));// le temps d'éxecution de la SDL

	SDL_Quit(); // On quitte la SDL

	return EXIT_SUCCESS;
}

