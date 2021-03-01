
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "U_sdl.h"
 
int main(int argc, char** argv)
{
	SDL_version nb;
	SDL_VERSION(&nb);
	
	bool error;
	
	printf(" Bienvenue sur la SDL %d . %d . %d  ! \n ", nb.major, nb.minor, nb.patch );
	
	SDL_Window * window = NULL;
	
	U_sdl_init (&error);

	if(error)
	{
		exit(EXIT_FAILURE);
	}
	
	  // Create an application window with the following settings:
    window = SDL_CreateWindow(
        		"An SDL2 window",                  // window title
        		SDL_WINDOWPOS_UNDEFINED,           // initial x position
        		SDL_WINDOWPOS_UNDEFINED,           // initial y position
        		640,                               // width, in pixels
        		480,                               // height, in pixels
        		SDL_WINDOW_OPENGL                  // flags - see below
    			);

	
	if (window==NULL)
	{
		SDL_Log("erreurs : initialisation SDL > %s \n",SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_Delay(5000);
	
	SDL_DestroyWindow(window);
	SDL_Quit();

	return EXIT_SUCCESS;
}

