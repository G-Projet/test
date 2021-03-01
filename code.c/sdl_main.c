#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
//#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include <sdl_fonction.h>

int main(int argc, char * argv[]){

	int now = 0;
	int ex = 0;
	int periodeFps = 33;	/* 33ms soit fps = 30 img/s */
	int date = 0;
	float delta_s = 0;

	Acteurs_t mesActors;
	mesActors.running = 1;	/* debut while */

	/* Initialisation de SDL */
	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0){
		fprintf(stderr, "Erreur d'initialisation : %s\n", SDL_GetError());
		return EXIT_FAILURE;
	}

	action_create(&mesActors);

	while(mesActors){
		now = SDL_GetTicks();
		date = now - ex;	/* Calcul de temps */

		if(date > periodeFps){
			delta_s = date/1000.0;
			SDL_PollEvent(&mesActors.event);
			action_event(&mesActors);
			action_update(&mesActors, delta_s);
			action_render(&mesActors);

			ex = now;
		}else{
			SDL_Delay(periodeFps - date);
		}
	}

	action_dispose(&mesActors);

	SDL_Quit();	/* Quitter SDl */
	return EXIT_SUCCESS;
}