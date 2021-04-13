

#ifndef FONCTION_H
#define FONCTION_H

#include "commun.h"

 
extern void bienvenue(); 

extern char message_erreurs(const char *);

//extern void evenement (SDL_bool program_launched );

extern int menu(SDL_Window * window,SDL_Renderer *renderer);

extern int affichagePage1(SDL_Window *window, SDL_Renderer *renderer);

extern int jeu1(SDL_Window * window, SDL_Renderer *renderer);


extern void chargement_cheminA_1(int  *chemin_aller , int t);
 
 

/** libération de ressources **/

extern void liberation_ressourcesTexture(SDL_Texture  *tabTexture[tailleTexture] );

extern void liberation_ressourcesSurface(SDL_Surface  *tabSurface[tailleSurface]);

extern void liberation_ressources(SDL_Window* w, SDL_Renderer *r,SDL_Surface* image, SDL_Texture *t);

extern void liberation_ressourcesTTF(TTF_Font *p1,TTF_Font *p2);


#endif /* FONCTION_H */





