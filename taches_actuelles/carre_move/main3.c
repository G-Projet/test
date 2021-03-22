 
 
#include<stdio.h>
#include<stdlib.h>


#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
   
#include <SDL2/SDL.h>

SDL_Window *  ecran;
SDL_Surface *imageDeFond;
SDL_Surface *zozor;

char message_erreurs(const char* message );			
void clean_ressources(SDL_Window* w,  SDL_Surface* image ) ;
void input_handle(void);
void anime(void);
void clean_ressources(SDL_Window* w,  SDL_Surface* image );



int main(void)
{
 
	
	SDL_Renderer* renderer = NULL;
    SDL_Surface * image    = NULL; 
    SDL_Texture * texture = NULL;
    
    SDL_Init(SDL_INIT_VIDEO);
    
    ecran = SDL_CreateWindow(
        		"Duck_Tales",                       // window title
        		SDL_WINDOWPOS_CENTERED,           // initial x position
        		SDL_WINDOWPOS_CENTERED,           // initial y position
        		640,                               // width, in pixels
        		480,                               // height, in pixeldanss
        		0                  // flags - see below
    			);
    
    renderer =  SDL_CreateRenderer( ecran, -1, SDL_RENDERER_ACCELERATED);
	
	//SDL_Surface *screen = SDL_SetVideoMode(640, 480, 0, SDL_FULLSCREEN | SDL_OPENGL);

	imageDeFond = IMG_Load("paysage.png");
	
	zozor = IMG_Load("duck.png");
	
	texture= SDL_CreateTextureFromSurface(renderer,image);
	
	SDL_RenderPresent(renderer);// affichage du rendu
	
	if(imageDeFond==NULL || zozor==NULL)
	{
		clean_ressources(ecran, NULL);
		message_erreurs("Chargement image");
	}
	
	SDL_Rect positionFond;
	
	positionFond.x = 0;
	positionFond.y = 0;

	SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
	
	SDL_Delay( 5000 );
	//anime();
	return 0;
}
 

void input_handle(void)
{
	SDL_Event event;

	while (SDL_PollEvent(&event)) {

		switch (event.type) {
		case SDL_QUIT:
			SDL_Quit();
			exit(0);
			break;
		}
	}
}
/*
void anime(void)
{
	SDL_Rect positionFond, positionZozor, oldpositionZozor;
	
	SDL_Rect positionFond_c, positionZozor_c;
	
	SDL_Rect clipper;
	
	int avanceX = 1, avanceY = 1;

	positionFond.x = 0;
	positionFond.y = 0;

	positionZozor.x = 0;
	positionZozor.y = 0;

	oldpositionZozor.x = 0;
	oldpositionZozor.y = 0;


	while (1) {
		
		clipper.x = oldpositionZozor.x;
		clipper.y = oldpositionZozor.y;
		clipper.h = zozor->h;
		clipper.w = zozor->w;
		
		SDL_SetClipRect(ecran, &clipper);

		positionFond_c.x = positionFond.x;
		positionFond_c.y = positionFond.y;

		positionZozor_c.x = positionZozor.x;
		positionZozor_c.y = positionZozor.y;
/*
int SDL_BlitSurface(SDL_Surface*    src,
                    const SDL_Rect* srcrect,
                    SDL_Surface*    dst,
                    SDL_Rect*       dstrect)

		 SDL_Rect r;
    r.x = 50; 
    r.y = 50; 
    r.w = 50; 
    r.h = 50; 
    
		SDL_BlitSurface(imageDeFond, r,ecran, &positionFond_c);

        SDL_SetClipRect(ecran,NULL); // J'ai choisi cette solution
                
		SDL_BlitSurface(zozor, r,ecran, &positionZozor_c);

		oldpositionZozor.x = positionZozor.x;
		oldpositionZozor.y = positionZozor.y;
			
		if (avanceX) {
			positionZozor.x++;
		} else {
			positionZozor.x--;
		}

		if (avanceY) {
			positionZozor.y++;
		} else {
			positionZozor.y--;
		}

		if (positionZozor.x == ecran->w - zozor->w - 1)
			avanceX = 0;
		else if (positionZozor.x == 0)
			avanceX = 1;

		if (positionZozor.y == ecran->h - zozor->h - 1)
			avanceY = 0;
		else if (positionZozor.y == 0)
			avanceY = 1;

		//SDL_Flip(ecran);
		input_handle();
		//SDL_Delay(10);
	}
}*/

void clean_ressources(SDL_Window* w,  SDL_Surface* image ) // libération des resources subsistantes
{
	
	if(w!=NULL)
		SDL_DestroyWindow(w);
		
	if(image!=NULL)
	
		SDL_FreeSurface(image); //permet de libérer la mémoire quand on n'a plus besoin d'une surface
}



char message_erreurs(const char* message )
{
	fprintf(stderr, "ERREUR : %s >(%s)\n", message, SDL_GetError());
	SDL_Quit(); // On quitte la SDL
	return EXIT_FAILURE;
}





