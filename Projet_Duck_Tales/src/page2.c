
#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

 
int affichagePage2()
{

	SDL_Window * window    = NULL; // Declare a pointer

	SDL_Renderer* renderer = NULL;//Déclaration du rendu

	SDL_Surface * image    = NULL; 

	SDL_Surface *texte=NULL;

	SDL_Surface *perso=NULL;

	SDL_Texture * texture  = NULL; // creation d'image sur la fenetre
	 
	SDL_Rect dest_rect     = {0,0,640,480}; // encadrement pour le rendu 
		
	TTF_Font *police = NULL; // Le pointeur vers notre police

	// Une variable de couleur noire

	SDL_Color couleurNoire = {0, 0, 0};

	SDL_Color couleurBlanche = {255, 255, 255};

	SDL_Event event;

	int continuer=1;

	if(SDL_Init(SDL_INIT_VIDEO)!=0) //Gestion des erreurs, initialisation sdl
		{	liberation_ressources(NULL,NULL,NULL,NULL);	message_erreurs("initialisation SDL"); }
 
   	window = SDL_CreateWindow(						//Gestion de la surface de l'écran 	
        		"Duck_Tales",                       // window title
        		SDL_WINDOWPOS_CENTERED,           // initial x position
        		SDL_WINDOWPOS_CENTERED,           // initial y position
        		1500,                               // width, in pixels
        		800,                               // height, in pixeldanss
        		0                  // flags - see below
    			);
  
	if(window == NULL) // Gestion des erreurs
	{ liberation_ressources(NULL,NULL,NULL,NULL);	message_erreurs("Ouverture Window"); }
		
	

	// Création du renderer			

	renderer = SDL_CreateRenderer(window, -1,   SDL_RENDERER_SOFTWARE );
	
	// SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); 

 
	if(renderer == NULL)//gestion des erreurs
	{	liberation_ressources(window,NULL,NULL,NULL);	message_erreurs("création renderer"); }
 
	//affichage d'une image

	image=IMG_Load("../image/Générique.jpg");// chargement de l'image
	
	if(image==NULL)
	{	liberation_ressources(window,renderer,NULL, NULL);	message_erreurs("Chargement image"); }
 
	texture = SDL_CreateTextureFromSurface(renderer,image);

	if(texture==NULL)
	{  liberation_ressources(window,renderer, image,NULL);	message_erreurs("Texture");	}
	

	if(SDL_QueryTexture(texture,NULL,NULL,&dest_rect.w,&dest_rect.h)!=0)
	{	liberation_ressources(window,renderer, image,texture);	message_erreurs("Texture application");}
		
 
	if(SDL_RenderCopy(renderer,texture,NULL,&dest_rect)!=0)
	{	liberation_ressources(window,renderer, image,texture);	message_erreurs("Création rendu "); }
	
	SDL_RenderPresent(renderer);// affichage du rendu 

	return 0;

}
		
