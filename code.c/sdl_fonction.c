#include <stdio.h>
#include <SDL2/SDL.h>
//#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <string.h>
#include <sdl_fonction.h>

void action_create(Acteurs_t * acteurs){
	//bpp
	const SDL_VideoInfo * pinfo = NULL;
	pinfo = SDL_GetVideoInfo();

	int bpp = pinfo -> vfmt -> BitsPerPixel;

	// screen
	/* Initialiser l'ecrans */
	acteurs -> screen = NULL;
	/* Creation d'ecrans */
	acteurs -> screen = SDL_SetVideoMode(LARGEUR, HAUTEUR, bpp, SDL_HWSURFACE);
	SDL_WM_SetCaption("Ducktales", NULL);

	// paysage compatible 
	acteurs -> paysage = NULL;
	SDL_Surface * tmp = NULL; 	/* Creation d'une surface temporaire */
	tmp = IMG_Load("paysage.png");

	acteurs -> paysage = SDL_DisplayFormat(tmp);

	SDL_FreeSurface(tmp);

	// rect 
	SDL_GetClipRect(acteurs -> paysage, &acteurs -> paysage_rect);
}

/* Fonction qui permet de libérer les acteurs ou faire des free() */
void action_dispose(Acteurs_t * acteurs){
	SDL_FreeSurface(acteurs -> paysage);
}
/* Fonction qui permet de faire mise à jours des actions */
void action_update(Acteurs_t * acteurs, float delta_s){
	int i = 0;	/* variable static */
	i++;
	printf("Frame = %i, delta_s = %.4f\n", i, delta_s);
}

/* Fonction qui permet de gérer les evenements des acteurs example: touches, fermer une fenêtre */
void action_event(Acteurs_t * acteurs){
	switch(acteurs -> event.type){
		case SDL_Quit : acteurs -> running = 0; break;
		case SDL_KEYDOWN :					break;
		case SDL_KEYUP : 					break;
		default : 							break;

	}
}

/* Fonction qui permet de designer des acteurs à l'ecrans */
void action_render(Acteurs_t * acteurs){
	SDL_BlitSurface(acteurs -> paysage, NULL, acteurs -> screen, &acteurs -> paysage_rect);

	//flip
	SDL_Flip(acteurs -> screen);
}

































