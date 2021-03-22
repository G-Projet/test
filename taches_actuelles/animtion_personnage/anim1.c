
#include "init.h"

int main (int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_Surface *win_surf;
    SDL_Surface *map_test;
    SDL_Event event;
    
    SDL_Surface *bas[4];
    SDL_Surface *haut[4];
    SDL_Surface *gauche[4];
    SDL_Surface *droite[4];
    
    SDL_Rect curr;
    
    int quit = 0;
    int i = 1;
    int j = 1;
    int k = 1;
    int temp_actuel = 0;
    int temp_precedent = 0;
    
    curr.x = 450;
    curr.y = 450;
 	
 	/*
    window = SDL_CreateWindow(
                 "ceci est un test",
                 SDL_WINDOWPOS_UNDEFINED,
                 SDL_WINDOWPOS_UNDEFINED,
                 800,
                 600,
                 SDL_WINDOW_BORDERLESS | SDL_WINDOW_SHOWN );*/
    window = SDL_CreateWindow
    (
        "DuckTales", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        1500,// taille horizontale
        800,// taille verticale
        SDL_WINDOW_SHOWN
    );
      
             map_test = IMG_Load("image/paysage2.jpg");
 
             //SDL_PixelFormat* SDL_AllocFormat(Uint32 pixel_format)

			 bas[1] =IMG_Load("image/duck.png"); 
			 bas[2] = IMG_Load("image/duck.png");
			 bas[3] = IMG_Load("image/duck.png");
		 
			 haut[1] = IMG_Load("image/duck.png");
			 haut[2] = IMG_Load("image/duck.png");
			 haut[3] = IMG_Load("image/duck.png");
			 
			 droite[1] = IMG_Load("image/duck.png");
			 droite[2] = IMG_Load("image/duck.png");
			 droite[3] = IMG_Load("image/duck.png");
 			
 			 gauche[1] = IMG_Load("image/duck.png");
			 gauche[2] = IMG_Load("image/duck.png");
			 gauche[3] = IMG_Load("image/duck.png");
  
	win_surf = SDL_GetWindowSurface(window);
	 
	SDL_BlitSurface (map_test, NULL,win_surf, NULL); // arrière plan = copie la photo sur l'ecran
	SDL_BlitSurface (bas[1], NULL, win_surf, &curr);// position de duck
		
	while (!quit)
	{
		//SDL_PollEvent(&event);
		SDL_WaitEvent(&event);
		
		switch(event.type)
		{
		    case SDL_QUIT:
		    quit = 1;
		    break;
		 
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_UP:
						for(i = 1; i<4; i++)
						{
							temp_actuel = SDL_GetTicks();
							if (temp_actuel - temp_precedent > 35)// /1000(millième de secondes)
							{
								SDL_BlitSurface (map_test, NULL,win_surf, NULL); // arrière plan
								SDL_BlitSurface(haut[j], NULL, win_surf, &curr);
								j++;
								if(j<4)
									j = 1;
								temp_precedent = temp_actuel;

							}
							SDL_UpdateWindowSurface(window);
							curr.y -=5;
							SDL_Delay(20);
						}
							break;
							
					case SDLK_DOWN:
					
						for(i = 1; i<4; i++)
						{
							temp_actuel = SDL_GetTicks();
							if (temp_actuel - temp_precedent > 35)
							{
								SDL_BlitSurface (map_test, NULL,win_surf, NULL); // arrière plan
								SDL_BlitSurface(bas[i], NULL, win_surf, &curr);
								i++;
								if(i<4)
									i = 1;
								temp_precedent = temp_actuel;
								SDL_UpdateWindowSurface(window);
							}
							curr.y +=5;
							SDL_Delay(20);
						}
						break;

					case SDLK_LEFT:
						for(i = 1; i<4; i++)
						{
							temp_actuel = SDL_GetTicks();
							if (temp_actuel - temp_precedent > 65)
							{
								k++;
								if(k<4)
									k = 1;
									SDL_BlitSurface (map_test, NULL,win_surf, NULL); // arrière plan
									SDL_BlitSurface(gauche[k], NULL, win_surf, &curr);
									temp_precedent = temp_actuel;
							}

							curr.x -=5;
							SDL_Delay(60);
							SDL_UpdateWindowSurface(window);
						}
						break;
				
					case SDLK_RIGHT:
						for(i = 1; i<4; i++)
						{
							temp_actuel = SDL_GetTicks();
							
							if (temp_actuel - temp_precedent > 35)
							{
								SDL_BlitSurface (map_test, NULL,win_surf, NULL); // arrière plan
								SDL_BlitSurface(droite[i], NULL, win_surf, &curr);
								i++;
								if(i<4)
									i = 1;
								temp_precedent = temp_actuel;
								SDL_UpdateWindowSurface(window);
							}
						
						curr.x +=5;
						SDL_Delay(20);
						SDL_UpdateWindowSurface(window);
						}

						break;
						
					}	
			}
			
        	SDL_UpdateWindowSurface(window);
    	}
    	
    SDL_FreeSurface(map_test);
    
    SDL_FreeSurface(bas[1]); SDL_FreeSurface(bas[2]); SDL_FreeSurface(bas[3]);
    SDL_FreeSurface(haut[1]);SDL_FreeSurface(haut[2]);SDL_FreeSurface(haut[3]);
    SDL_FreeSurface(gauche[1]);SDL_FreeSurface(gauche[2]);SDL_FreeSurface(gauche[3]);
    SDL_FreeSurface(droite[1]);SDL_FreeSurface(droite[2]);SDL_FreeSurface(droite[3]);
    
    SDL_DestroyWindow(window);
 
    
    SDL_Quit();
    return (0);
}







