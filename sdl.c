
//  valgrind --leak-check=full ./exe

/**
* \file sdl.c
* \brief Contient toutes les fonctions pour interface graphique
* \date Mardi 01 mars 2021
*/

#include <stdio.h>
#include<stdlib.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "fonction.h"

int main(int argc, char** argv)
{
	bienvenus();

	SDL_Window * window    = NULL; // Declare a pointer
	SDL_Renderer* renderer = NULL;//Déclaration du rendu
	//SDL_Surface * image    = NULL; 
	SDL_Texture * texture  = NULL; // creation d'image sur la fenetre
	
	SDL_Rect dest_rect     = {0,0,640,480}; // encadrement pour le rendu 
	
	SDL_Surface *texte=NULL, *image=NULL;
    SDL_Surface *perso=NULL;
    
    	
	TTF_Font *police = NULL; // Le pointeur vers notre police
	// Une variable de couleur noire
	SDL_Color couleurNoire = {0, 0, 0};
	SDL_Color couleurBlanche = {255, 255, 255};
	
	
	
	if(SDL_Init(SDL_INIT_VIDEO)!=0) //Gestion des erreurs, initialisation sdl
	{
		clean_ressources(NULL,NULL,NULL,NULL);
		message_erreurs("initialisation");
	}

   window = SDL_CreateWindow(
        		"Duck_Tales",                       // window title
        		SDL_WINDOWPOS_CENTERED,           // initial x position
        		SDL_WINDOWPOS_CENTERED,           // initial y position
        		640,                               // width, in pixels
        		480,                               // height, in pixeldanss
        		0                  // flags - see below
    			);
    			
   /*  SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);
	
	printf("width : %d, height : %d\n", DM.w, DM.h);
		
	window = SDL_CreateWindow("Duck_Tales",SDL_WINDOWPOS_UNDEFINED,
												  SDL_WINDOWPOS_UNDEFINED,
												  DM.w,
												  DM.h,
												  SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);		
    */
    			
	if(window == NULL) // Gestion des erreurs
	{
		clean_ressources(NULL,NULL,NULL,NULL);
		message_erreurs("Ouverture Window");
	}


	// Création du renderer			

	renderer = SDL_CreateRenderer(window, -1,   SDL_RENDERER_SOFTWARE );//SDL_RENDERER_ACCELERATED);
	
	// SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); 

	if(renderer == NULL)//gestion des erreurs
	{
		clean_ressources(window,NULL,NULL,NULL);
		message_erreurs("création renderer");
	}
/*
	if( (police = TTF_OpenFont("ChowFun.ttf", 20)) == NULL){
		fprintf(stderr, "erreur chargement font\n");
		exit(EXIT_FAILURE);
	}
*/

	//affichage d'une image

 
	image=IMG_Load("image/demarage.jpg");// chargement de l'image
	//image=IMG_Load("image/duck.png");// chargement de l'image
	
	if(image==NULL)
	{
		clean_ressources(window,renderer,NULL, NULL);
		message_erreurs("Chargement image");
	}

	texture = SDL_CreateTextureFromSurface(renderer,image);

	//SDL_FreeSurface(image);// libération de l'image

	if(texture==NULL)
	{
		clean_ressources(window,renderer, image,NULL);
		message_erreurs("Texture");
	}

	if(SDL_QueryTexture(texture,NULL,NULL,&dest_rect.w,&dest_rect.h)!=0)
	{
		clean_ressources(window,renderer, image,texture);
		message_erreurs("Texture application");
	}


	if(SDL_RenderCopy(renderer,texture,NULL,&dest_rect)!=0)
	{
		clean_ressources(window,renderer, image,texture);
		message_erreurs("Création rendu ");
	}

	SDL_RenderPresent(renderer);// affichage du rendu 

	/******** gestion évenement *******/

	evenement(SDL_TRUE); // program_launched = SDL_TRUE;

	//SDL_Delay(3000); // Pause execution for 5000 milliseconds, for example
	
	clean_ressources(window,renderer, image,texture);

	printf(" %d s écoulées \n",SDL_GetTicks()/1000);// le temps d'éxecution de la SDL

	SDL_Quit(); // On quitte la SDL

	return EXIT_SUCCESS;
}

