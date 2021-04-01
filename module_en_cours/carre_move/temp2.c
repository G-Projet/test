
#include<stdio.h>
#include<stdlib.h>


#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
   
#include <SDL2/SDL.h>

int main (int argc, char** argv)
{
    SDL_Window* window = NULL;
    
    window = SDL_CreateWindow
    (
        "DuckTales", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        1500,// taille horizontale
        800,// taille verticale
        SDL_WINDOW_SHOWN
    );

    //Setup renderer
    SDL_Renderer* renderer = NULL;
    
    renderer =  SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);

    //Set render color to red ( background will be rendered in this color )
    SDL_SetRenderDrawColor( renderer, 255,200,100,100);; // couleur de fond de la fenêtre

    //Clear winow
    SDL_RenderClear( renderer );//nettoie le contenu de la fenêtre.

    //Creat a rect at pos ( 50, 50 ) that's 50 pixels wide and 50 pixels high.
  
    SDL_Rect r;
    
    r.x = 600; 
    r.y = 300; 
    r.w = 60;
    r.h = 60;

    //Set render color to blue ( rect will be rendered in this color )
    
	SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );// SDL_SetRenderDrawColor(pRenderer, rouge, vert, bleu, transparence);
	
	SDL_RenderFillRect( renderer, &r );//Render rect

	SDL_RenderPresent(renderer);//Render the rect to the screen

	SDL_Event event;
	
	int open=1;
	
	while( open)
	{
		while(SDL_PollEvent(&event))
		{
			switch(event.type) /* Gestion des évenements claviers ou souris  */
			{    
				case SDL_QUIT:
					open=0;
					break;	
				case SDL_KEYUP: // gestion des touches du clavier
				
					switch(event.key.keysym.sym)
					{
						case SDLK_b:
						printf(" vous avez relacher la touche B \n");
						continue; //break;
						
						case SDLK_RIGHT:
						
									SDL_SetRenderDrawColor( renderer, 255,200,100,100);
									SDL_RenderClear( renderer );
									SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );
									
									if (r.x< 1500)
										r.x +=10; 
									
									SDL_RenderFillRect( renderer, &r );//actualisation des valeurs du renderer
									SDL_RenderPresent(renderer);//envoyer le rendu à l'écran
									break;
									
						case SDLK_LEFT:				
																	
									SDL_SetRenderDrawColor( renderer, 255,200,100,100);
									SDL_RenderClear( renderer );
									SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );
									
									if (r.x>=10)
										r.x -=10;
									
									SDL_RenderFillRect( renderer, &r );//actualisation des valeurs du renderer
									SDL_RenderPresent(renderer);//envoyer le rendu à l'écran
									break;
						
						
						case  SDLK_UP:
									SDL_SetRenderDrawColor( renderer, 255,200,100,100);
									SDL_RenderClear( renderer );
									SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );
									
									if(r.y>=10)
										r.y -=10;
									
									SDL_RenderFillRect( renderer, &r );//actualisation des valeurs du renderer
									SDL_RenderPresent(renderer);//envoyer le rendu à l'écran
									break;
									
						case SDLK_DOWN : 
									SDL_SetRenderDrawColor( renderer, 255,200,100,100);
									SDL_RenderClear( renderer );
									SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );

									if(r.y<=800)
										r.y +=10;
									
									SDL_RenderFillRect( renderer, &r );//actualisation des valeurs du renderer
									SDL_RenderPresent(renderer);//envoyer le rendu à l'écran
									break;
						default:
							break;	
					}
				default:
					break;
			}
		}
	}
 

    //Wait for 5 sec
    //SDL_Delay( 5000 );

    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}

