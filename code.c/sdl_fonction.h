#ifndef _SDL_FONCTION_H
#define _SDL_FONCTION_H_

#define LARGEUR 840
#define HAUTEUR 480

/* Creation d'une strecture Acteurs */
typedef struct Acteurs_s {
	SDL_Surface * screen;
	SDL_Rect screen_rect;

	SDL_Event event;

	SDL_Surface * paysage; /* Le paysage d'arriere plans */
	SDL_Rect paysage_rect;

	int running;
}Acteurs_t;

/* Fonction qui permet de creer des acteurs */
void action_create(Acteurs_t * acteurs);
/* Fonction qui permet de libérer les acteurs ou faire des free() */
void action_dispose(Acteurs_t * acteurs);
/* Fonction qui permet de faire mise à jours des actions */
void action_update(Acteurs_t * acteurs, float delta_s);
/* Fonction qui permet de gérer les evenements des acteurs example: touches, fermer une fenêtre */
void action_event(Acteurs_t * acteurs);
/* Fonction qui permet de designer des acteurs à l'ecrans */
void action_render(Acteurs_t * acteurs);



#endif
