


#include <stdio.h>
#include<stdlib.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#define TAILLE 161

SDL_Window * window    = NULL; // Declare a pointer

SDL_Renderer* renderer = NULL;//Déclaration du rendu

SDL_Surface * image    = NULL; 
SDL_Surface *texte=NULL;
SDL_Surface *perso=NULL;


SDL_Texture * texture  = NULL; // creation d'image sur la fenetre
 
 //                        x  y   l  largeur
SDL_Rect dest_rect     = {0,200,1500,600};//{0,200,1500,600};//{0,0,640,480}; // encadrement pour le rendu 



	
TTF_Font *police = NULL; // Le pointeur vers notre police

// Une variable de couleur noirecd c
SDL_Color couleurNoire = {0, 0, 0};
SDL_Color couleurBlanche = {255, 255, 255};

