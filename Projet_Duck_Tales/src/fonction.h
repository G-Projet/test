

#ifndef FONCTION_H
#define FONCTION_H

#include "commun.h"


extern void bienvenue();

extern char message_erreurs(const char*);

extern void evenement (SDL_bool program_launched );

extern void anime(void);

extern int affichagePage1(SDL_Window *window, SDL_Renderer *renderer);

extern int jeu1(SDL_Window * window, SDL_Renderer *renderer);
extern int jeu2(SDL_Window * window,SDL_Renderer *renderer);
extern int jeu3(SDL_Window * window,SDL_Renderer *renderer);


extern void chargement_cheminA_1(int  *chemin_aller , int t);
 

extern int menu(SDL_Window * window,SDL_Renderer *renderer);

extern int  cheminV_1( int val);

extern void liberation_ressourcesTTF(TTF_Font *p1,TTF_Font *p2);

extern void liberation_ressources(SDL_Window* w, SDL_Renderer *r,SDL_Surface* image, SDL_Texture *t);

extern
void liberation_ressourcesTexture(SDL_Texture  *tabTexture[tailleTexture] );

extern
void liberation_ressourcesSurface(SDL_Surface  *tabSurface[tailleSurface]);


#endif /* FONCTION_H */





