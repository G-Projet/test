
#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>


#define TAILLE 161
#define longueur_ecran 1600
#define largeur_ecran 800
#define departX 0
#define departY 535

int main(int argc, char** argv)
{
	SDL_Window *window =NULL;
	
	SDL_Renderer *renderer=NULL;
	
	SDL_Surface *image = NULL;
	
	SDL_Texture *texture_fond=NULL ,*texture_txt=NULL;
	
	SDL_Rect txtDestRect,imgDestRect;
	
	imgDestRect.x=100;
	imgDestRect.y=200;
	imgDestRect.w=500;
	imgDestRect.h=100;
	//************
	txtDestRect.x=0;
	txtDestRect.y=0;
	txtDestRect.w=0;
	txtDestRect.h=0;
	
	
	TTF_Font *police = NULL;
	SDL_Surface *texte=NULL;
	
	SDL_Color couleurJaune = {250,234,115},couleurBlanche = {255, 255, 255};
 
	int temps_Actuel = SDL_GetTicks() ; 
  
	int continuer = 0;
	
  	window =  SDL_CreateWindow(
            "Duck_Tales",            // window title
            SDL_WINDOWPOS_CENTERED,  // initial x position
            SDL_WINDOWPOS_CENTERED,  // initial y position
            longueur_ecran,          // width, in pixels
            largeur_ecran,           // height, in pixeldanss
            0                        // flags - see below
            );
    if(window == NULL) { printf("erreurs : Ouverture Window \n "); return EXIT_FAILURE;}
               
 	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
 	
	//********************** chargement image de fond 
	
	image=NULL;
	if( (image = IMG_Load("Générique.jpg"))==NULL)
	{ printf("erreurs : Ouverture image \n "); return EXIT_FAILURE;}
	
	texture_fond = SDL_CreateTextureFromSurface(renderer, image);
	
	if (texture_fond == NULL)
		{ printf("erreurs : Ouverture texture \n "); return EXIT_FAILURE;}
		
	SDL_FreeSurface(image);	
	
	SDL_QueryTexture(texture_fond, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
	SDL_RenderCopy(renderer, texture_fond, NULL, &imgDestRect);	
	
	//**************************** chargement texte 
	TTF_Init();
	
	police = TTF_OpenFont("JMH Typewriter.ttf", 40);
	if (police == NULL)
		{ printf("erreurs : Ouverture police \n "); return EXIT_FAILURE;}
		
	texte = TTF_RenderText_Solid(police, 
        "  Bienvenue sur la platforme de jeux Duck_Tales ", couleurBlanche);
    if (texte == NULL)
		{ printf("erreurs : Ouverture texte \n "); return EXIT_FAILURE;}
		
        
    texture_txt=SDL_CreateTextureFromSurface(renderer, texte);
    if (texture_txt == NULL)
		{ printf("erreurs : Ouverture texture_txt \n "); return EXIT_FAILURE;}
      
    SDL_QueryTexture(texture_txt, NULL, NULL, &(txtDestRect.w), &(txtDestRect.h));
	SDL_RenderCopy(renderer, texture_txt, NULL, &txtDestRect);
	
	//**********************************chargement d'un carre 
	
	SDL_Rect r;
    
    r.x = 100; 
    r.y = 100; 
    r.w = 60;
    r.h = 60;
    
   
    SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );
    
    SDL_RenderFillRect( renderer, &r );//Render rect
    
    
    //******************************************
    
		
	SDL_RenderPresent(renderer);
	
	SDL_RenderClear( renderer );
	 
 	while (!continuer)
	{
		SDL_Event event;
 		
		while(SDL_PollEvent(&event))
		{
			SDL_WaitEvent(&event);
		
			switch(event.type)
			{    
				case SDL_QUIT:
					
					continuer = 1;//SDL_TRUE;
					break;
					
				case SDL_MOUSEMOTION: // gestion coordonnées de la souris 
					//event.motion.xrel || yrel (position relative)
					printf(" %d | %d \n",event.motion.x,event.motion.y);
					break;
						
				case SDL_KEYDOWN: // Gestion des évenements claviers ou souris(appuyer)
				
					switch(event.key.keysym.sym)
					{
						case SDLK_a:
							printf(" je suis la *********** A \n");
							
							break; 

						case SDLK_b:
							printf(" je suis la *********** B\n");
						 
							break;

						default:
							break;
					}	
				default:
					break;
			}
		}
	}
 
	printf(" %d s écoulées \n",((SDL_GetTicks()-temps_Actuel)/1000));// le temps d'éxecution de la SDL

		 
	SDL_DestroyWindow(window);

	SDL_DestroyRenderer(renderer);

	SDL_DestroyTexture(texture_fond);
	SDL_DestroyTexture(texture_txt);	
		
	SDL_Quit(); // On quitte la SDL

	return EXIT_SUCCESS;
}


