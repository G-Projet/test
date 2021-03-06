/**
*\file main.c
*\brief Fichier qui lance le jeu de DuckTales
*\author Belkadi Smail
*\version 2.0
*\date 01 avril 2021
**/
 
#include "fonction.h" 


int main(int argc, char** argv)
{
	int temps_Actuel = SDL_GetTicks() ; 
 
	bienvenue();
	
 	SDL_Init(SDL_INIT_VIDEO);/** Initialisation de la SDL **/
 	
 	if(SDL_VideoInit(NULL) < 0) 
 		/** gestion des erreurs **/
 		{  message_erreurs("Initialisation SDL"); }
	
	window = NULL;
	
  	window =  SDL_CreateWindow(
            "Duck_Tales",            // window title
            SDL_WINDOWPOS_CENTERED,  // initial x position
            SDL_WINDOWPOS_CENTERED,  // initial y position
            longueur_ecran,          // width, in pixels
            largeur_ecran,           // height, in pixeldanss
            0                        // flags - see below
            );
            
    if(window == NULL)  {  message_erreurs("Ouverture Window"); }

    renderer=NULL;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); 

    if(renderer == NULL)  {  message_erreurs(" configuration renderer"); }
	

	affichagePage1(window,renderer);
	
	 //menu(window,renderer);

 	//jeu1(window,renderer);

	/*
	continuer = FAUX;

 	while (!continuer)
	{
		//SDL_Event event;
		
		printf(" continuer entrée (main)  = %i \n",continuer);
		
		//while(SDL_PollEvent(&event))
		//{
			SDL_WaitEvent(&event);
		
			switch(event.type)
			{    
				case SDL_QUIT:
				
					printf(" arrêt inopiné : main...........\n");
					
						continuer = VRAI;//SDL_TRUE;
					
					break;
				/*	
				case SDL_MOUSEMOTION: // gestion coordonnées de la souris 
					//event.motion.xrel || yrel (position relative)
					printf(" %d | %d \n",event.motion.x,event.motion.y);
					break;
						
				case SDL_KEYDOWN: // Gestion des évenements claviers ou souris(appuyer)
				
					switch(event.key.keysym.sym)
					{
						case SDLK_a:
							printf(" je suis la *********** SDLK_a\n");
							affichagePage1(window,renderer);
							 
							break; 

						case SDLK_b:
							printf(" je suis la *********** SDLK_b\n");
							jeu1(window,renderer);
					 
							break;

						default:
							break;
					}	
				default:
					break;
			//}
				
			}
	}*/
 	
	printf(" %d s écoulées \n",((SDL_GetTicks()-temps_Actuel)/1000));// le temps d'éxecution de la SDL

	liberation_ressources(window,renderer,NULL,NULL);

	SDL_Quit(); // On quitte la SDL

	return EXIT_SUCCESS;
}








