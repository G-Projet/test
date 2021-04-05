 
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


//page1

SDL_Surface *pSurf;
SDL_Surface * image;
SDL_Surface *texte1,*texte2,*texte3, *texte4,*texte5,*texte6; //*fond = NULL;
TTF_Font *police1 , *police2 ; 



	
/* Definition du type booleen */

typedef enum booleen_s { FAUX , VRAI } booleen_t ;

extern booleen_t  err_t ;

booleen_t  continuer;

 


#endif /* _COMMUN_H_*/


