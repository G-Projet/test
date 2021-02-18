
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

int main(int argc, char** argv)
{
	SDL_version nb;
	SDL_VERSION(&nb);
	printf(" Bienvenue sur la SDL %d . %d . %d  ! \n ", nb.major, nb.minor, nb.patch );
	
	SDL_Window * window = NULL;

	if(SDL_Init(SDL_INIT_VIDEO)!=0)
	{
		SDL_Log("erreurs : initialisation SDL > %s \n",SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	window= SDL_CreateWindow("première fenêtre SDL 2",
								SDL_WINDOWPOS_CENTERED,
								SDL_WINDOWPOS_CENTERED,
								800,
								600,SDL_FULLSCREEN);
	
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

