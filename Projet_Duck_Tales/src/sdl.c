
/**
* \file sdl.c
* \brief Contient toutes les fonctions pour interface graphique
* \date Mardi 01 mars 2021
*/

#include "fonction.h"

int main(int argc, char** argv)
{
	bienvenus();
	
	if(SDL_Init(SDL_INIT_VIDEO)!=0) //Gestion des erreurs, initialisation sdl
	{
		liberation_ressources(NULL,NULL,NULL,NULL);
		message_erreurs("initialisation SDL");
	}

   	window = SDL_CreateWindow(
        		"Duck_Tales",                       // window title
        		SDL_WINDOWPOS_CENTERED,           // initial x position
        		SDL_WINDOWPOS_CENTERED,           // initial y position
        		1500,                               // width, in pixels
        		800,                               // height, in pixeldanss
        		0                  // flags - see below
    			);
   /*
    //Gestion de la surface de l'écran 			

    SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);
	
	printf("width : %d, height : %d\n", DM.w, DM.h);
		
	window = SDL_CreateWindow("Duck_Tales",SDL_WINDOWPOS_UNDEFINED,
												  SDL_WINDOWPOS_UNDEFINED,
												  DM.w-=200,
												  DM.h-=200,
												  SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);		
    */
	if(window == NULL) // Gestion des erreurs
	{
		liberation_ressources(NULL,NULL,NULL,NULL);
		message_erreurs("Ouverture Window");
	}

	// Création du renderer			

	renderer = SDL_CreateRenderer(window, -1,   SDL_RENDERER_SOFTWARE );//SDL_RENDERER_ACCELERATED);
	
	// SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); 

 

	if(renderer == NULL)//gestion des erreurs
	{
		liberation_ressources(window,NULL,NULL,NULL);
		message_erreurs("création renderer");
	}

	//affichage d'une image

	image=IMG_Load("../image/Générique.jpg");// chargement de l'image
	
	if(image==NULL)
	{
		liberation_ressources(window,renderer,NULL, NULL);
		message_erreurs("Chargement image");
	}

	texture = SDL_CreateTextureFromSurface(renderer,image);

	if(texture==NULL)
	{
		liberation_ressources(window,renderer, image,NULL);
		message_erreurs("Texture");
	}

	if(SDL_QueryTexture(texture,NULL,NULL,&dest_rect.w,&dest_rect.h)!=0)
	{
		liberation_ressources(window,renderer, image,texture);
		message_erreurs("Texture application");
	}

	if(SDL_RenderCopy(renderer,texture,NULL,&dest_rect)!=0)
	{
		liberation_ressources(window,renderer, image,texture);
		message_erreurs("Création rendu ");
	}

	SDL_RenderPresent(renderer);// affichage du rendu 

	/******** gestion évenement *******/

	evenement(SDL_TRUE); // program_launched = SDL_TRUE;
	
	liberation_ressources(window,renderer,image,texture);

	printf(" %d s écoulées \n",SDL_GetTicks()/1000);// le temps d'éxecution de la SDL

	SDL_Quit(); // On quitte la SDL

	return EXIT_SUCCESS;
}

