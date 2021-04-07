#ifndef _COMMUN_H_
#define _COMMUN_H_
 

#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#define TAILLE 161
#define longueur_ecran 1600
#define largeur_ecran 800
#define departX 0
#define departY 535


SDL_Window *window ;
SDL_Event event;

//jeu1

TTF_Font *police1 ;
SDL_Surface *win_surf;
SDL_Rect point, positionTemps;
SDL_Surface *arrierePlan1,*arrierePlan2,*arrierePlan3;

/* Definition du type booleen */
typedef enum booleen_s { FAUX , VRAI } booleen_t ;

extern booleen_t  err_t ;

booleen_t  continuer;

// ######   SDL 
/*
SDL_Window * window    = NULL; // Declare a pointer
SDL_Renderer* renderer = NULL;//Déclaration du rendu
SDL_Surface * image    = NULL; 
SDL_Surface *texte     = NULL;
SDL_Surface *perso     = NULL;
SDL_Event event;
SDL_Texture * texture  = NULL; // creation d'image sur la fenetre*/
 //                        x  y   l  largeur
//SDL_Rect dest_rect     = {0,200,1500,600};//{0,200,1500,600};//{0,0,640,480}; // encadrement pour le rendu 

//TTF_Font *police = NULL; // Le pointeur vers notre police

// Une variable de couleur noire cd c
//SDL_Color couleurNoire = {0, 0, 0};
//SDL_Color couleurBlanche = {255, 255, 255};


#endif /* _COMMUN_H_*/





