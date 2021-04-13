 
#ifndef _COMMUN_H_
#define _COMMUN_H_
 

/**
*\file affichage.c
*\brief Fichier contenant les fonctions utilisées dans le programme
*\author Belkadi Smail
*\version 2.0
*\date 07 avril 2021
**/

/**
*\brief Fichier commun.h
**/

/** déclaration des librairies c **/

#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>

/** déclaration des librairies SDL2 **/

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>


/** valeurs d'initialisation de la taille de la fenêtre **/

#define longueur_ecran 1600 
#define largeur_ecran 800

/** la taille du tableau comptenant les coordonnées du chemin jeu1 **/

#define TAILLE 161  
 
/** variable utilisés principalement par la fonction pageMenu.c **/
 

/** Definition du type booleen et variable entière**/

typedef enum booleen_s { FAUX , VRAI } booleen_t ;

//extern booleen_t  err_t ;

booleen_t  continuer,temp;

int score;

int i; 

/** déclaration du Fichier main.c **/

SDL_Window *window ;
SDL_Event event;
SDL_Renderer *renderer;

//    jeu1

/** valeurs de la position de départ du joueur jeu1 **/

#define departX 0
#define departY 530
#define taillePoint 5

TTF_Font *police1 ;

SDL_Surface *win_surf ;

SDL_Rect point, positionTemps ;

//SDL_Surface *arrierePlan1,*arrierePlan2,*arrierePlan3, *arrierePlanQ;




//   page1

#define tailleTexture 9
#define tailleSurface 8
 
SDL_Surface * image,*image2;

SDL_Surface *Stexte[tailleSurface];

SDL_Surface *arrierePlan[tailleSurface];
 
TTF_Font *police2 ; 

SDL_Rect txtDestRect,imgDestRect;

SDL_Texture *texture[tailleTexture];
	

#endif /* _COMMUN_H_*/










