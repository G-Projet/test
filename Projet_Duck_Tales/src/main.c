/**
* \file main.c
* \brief Contient touta fonction main
* \date Mardi 01 mars 2021
*/
 
#include "fonction.h" 


int main(int argc, char** argv)
{
	int temps_Actuel = SDL_GetTicks() ; 
 
	bienvenus();
 
	continuer = FAUX;
	
	window=NULL;
	
  	window =  SDL_CreateWindow(
            "Duck_Tales",            // window title
            SDL_WINDOWPOS_CENTERED,  // initial x position
            SDL_WINDOWPOS_CENTERED,  // initial y position
            longueur_ecran,          // width, in pixels
            largeur_ecran,           // height, in pixeldanss
            0                        // flags - see below
            );
    if(window == NULL)  {  message_erreurs("Ouverture Window"); }
               
	//affichagePage1(window);
	jeu1(window);
	
 	while (!continuer)
	{
		//SDL_Event event;
		
		//printf(" je suis la *********** \n");
		
		//while(SDL_PollEvent(&event))
		//{
		SDL_WaitEvent(&event);
		
			switch(event.type)
			{    
				case SDL_QUIT:
					
					continuer = VRAI;//SDL_TRUE;
					break;
					
				case SDL_MOUSEMOTION: // gestion coordonnées de la souris 
					//event.motion.xrel || yrel (position relative)
					printf(" %d | %d \n",event.motion.x,event.motion.y);
					break;
						
				case SDL_KEYDOWN: // Gestion des évenements claviers ou souris(appuyer)
				
					switch(event.key.keysym.sym)
					{
						case SDLK_a:
							printf(" je suis la *********** A \n");
							
							break; 

						case SDLK_b:
							printf(" je suis la *********** B\n");
							jeu1(window);
							break;

						default:
							break;
					}	
				default:
					break;
			}
		//}
	}
 
	printf(" %d s écoulées \n",((SDL_GetTicks()-temps_Actuel)/1000));// le temps d'éxecution de la SDL

	SDL_Quit(); // On quitte la SDL

	return EXIT_SUCCESS;
}

