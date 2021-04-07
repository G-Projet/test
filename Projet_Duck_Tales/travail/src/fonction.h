

#ifndef FONCTION_H
#define FONCTION_H

#include "commun.h"


extern void bienvenus();

extern char message_erreurs(const char*);

extern void evenement (SDL_bool program_launched );

extern int affichagePage1(SDL_Window *window);

extern void anime(void);

extern int jeu1(SDL_Window * window);

extern void liberation_ressources(SDL_Window* w, SDL_Renderer *r,SDL_Surface* image, SDL_Texture *t);

extern void liberation_ressourcesSurface(SDL_Surface* s1, SDL_Surface* s2, SDL_Surface* s3,
							SDL_Surface* s4, SDL_Surface* s5, SDL_Surface* s6);
							
extern void liberation_ressourcesTTF(TTF_Font *p1,TTF_Font *p2);

extern int jeu1();

extern void chargement_cheminA_1(int  *chemin_aller , int t);
extern
int  cheminV_1( int val);



#endif /* FONCTION_H */





