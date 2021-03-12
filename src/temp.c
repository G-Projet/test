

/**
* \file sdl.c
* \brief Contient toutes les fonctions pour interface graphique
* \date Mardi 18 mars 2021
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
	bool error = 0;
	
	bienvenus();

	SDL_Window * window    = NULL; // Declare a pointer
	SDL_Renderer* renderer = NULL;//Déclaration du rendu
	SDL_Surface * image  = NULL; 
	SDL_Texture * texture  = NULL; // creation d'image sur la fenetre
	SDL_Rect dest_rect     = {0,0,640,480}; // encadrement pour le rendu 

	//TTF_Font *police = NULL; // Le pointeur vers notre police
		 
	//sdl_init (&error,SDL_Init(SDL_INIT_VIDEO)); // Initialize SDL2
	
	if(SDL_Init(SDL_INIT_VIDEO)!=0) //Gestion des erreurs
	{
		clean_ressources(NULL,NULL,NULL);
		message_erreurs();
	}

	//if (SDL_Init(SDL_INIT_VIDEO) <= -1)

		//message_erreurs();
	
	// Création de la fenêtre :

    window = SDL_CreateWindow(
        		"Duck_Tales",                       // window title
        		SDL_WINDOWPOS_CENTERED,           // initial x position
        		SDL_WINDOWPOS_CENTERED,           // initial y position
        		640,                               // width, in pixels
        		480,                               // height, in pixeldanss
        		0                  // flags - see below
    			);
    			
	if(window == NULL) // Gestion des erreurs
	{
		clean_ressources(NULL,NULL,NULL);
		message_erreurs();
	}
	
	// Création du renderer			

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE); //SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); 

	if(renderer == NULL)//gestion des erreurs
	{
		clean_ressources(window,NULL,NULL);
		message_erreurs();
	}
	
	//picture=SDL_LoadBMP("adresse_image");
	//La texture monImage contient maintenant l'image importée

	//affichage d'une image

	image = IMG_Load("paysage.png");

	if(image==NULL)
	{
		//clean_ressources(window,renderer, NULL);
		
		message_erreurs();
	}

	texture = SDL_CreateTextureFromSurface(renderer,image);  
	SDL_FreeSurface(image);

	if(texture==NULL)
	{
		clean_ressources(window,renderer, NULL);
		message_erreurs();
	}

	if(SDL_QueryTexture(texture,NULL,NULL,&dest_rect.w,&dest_rect.h)!=0)
	{
		clean_ressources(window,renderer, texture);
		message_erreurs();
	}


	if(SDL_RenderCopy(renderer,texture,NULL,&dest_rect)!=0)
	{
		clean_ressources(window,renderer, texture);
		message_erreurs();
	}

	//SDL_Renderer* SDL_GetRenderer(SDL_Window* window); // rendu du renderer
	

	SDL_RenderPresent(renderer);// affichage du rendu 

	SDL_Delay(5000); // Pause execution for 5000 milliseconds, for example
	

	//arret_programme(image,renderer,window);

	clean_ressources(window,renderer, texture);

	return EXIT_SUCCESS;
}


