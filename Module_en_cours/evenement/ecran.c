
// valgrind --leak-check=full ./exe


#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>


int main(int argc, char** argv)
{
    
	SDL_Window* pWindow = NULL;//Le pointeur vers la fenetre
	
    SDL_Surface *texte=NULL, *image=NULL; //Le pointeur vers la surface incluse dans la fenetre
    
	SDL_Renderer *renderer=NULL;
	
	SDL_Rect txtDestRect,imgDestRect;

	TTF_Font *police = NULL; // Le pointeur vers notre police
	
	SDL_Color couleurNoire = {0, 0, 0};// Une variable de couleur noire

    if (SDL_Init(SDL_INIT_VIDEO) != 0 ) /* Initialisation simple */
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return -1;
    } 

	if(TTF_Init() == -1) /* Initialisation TTF */
	{
		fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}

	/* Création de la fenêtre */
	
	pWindow = SDL_CreateWindow(" Bienvenus dans ma 1er Fenêtre SDL2 !",SDL_WINDOWPOS_UNDEFINED,
												  SDL_WINDOWPOS_UNDEFINED,
												  1000,
												  600,
												  SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);

	if(!pWindow)
	{
		fprintf(stderr, "Erreur à la création de la fenetre : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}


	renderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
	
	if(renderer == NULL)
	{
		fprintf(stderr, "Erreur à la création du renderer\n");
		exit(EXIT_FAILURE);
	}

	if( (police = TTF_OpenFont("rainyhearts.ttf", 20)) == NULL)
	{
		fprintf(stderr, "erreur chargement font\n");
		exit(EXIT_FAILURE);
	}
	
	texte = TTF_RenderUTF8_Blended(police, "Projet DuckTales !", couleurNoire);
	
	if(!texte)
	{
		fprintf(stderr, "Erreur à la création du texte : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	
	SDL_Texture *texte_tex = SDL_CreateTextureFromSurface(renderer, texte); // creation d'une texture
	
	if(!texte_tex)
	{
		fprintf(stderr, "Erreur à la création du rendu du texte : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	SDL_FreeSurface(texte); /* on a la texture, plus besoin du texte */
	
	/* Position ou sera mis le texte dans la fenêtre */
	
    txtDestRect.x = txtDestRect.y = 10;
    
	SDL_QueryTexture(texte_tex, NULL, NULL, &(txtDestRect.w), &(txtDestRect.h));

	// load sample.png into image
	 //SDL_RWops *rwop=SDL_RWFromFile("affiche2018.png", "rb");
	//SDL_RWops *rwop=SDL_RWFromFile("paysage.png", "rb");
	
	image=IMG_Load("paysage.png");
	
	//image=IMG_LoadPNG_RW(rwop);
	
	if(!image) 
	{
	     printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}
	
	SDL_Texture *image_tex = SDL_CreateTextureFromSurface(renderer, image); 
	
	if(!image_tex)
	{
		fprintf(stderr, "Erreur à la création du rendu de l'image : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	SDL_FreeSurface(image); /* on a la texture, plus besoin de l'image */
	

	if( pWindow ) // gestion de la fenêtre
	{
		int running = 1; 
		
		while(running) 
		{ 
			SDL_Event e; 
			
			while(SDL_PollEvent(&e)) 
			{ 
				switch(e.type) 
				{ 
					case SDL_QUIT: running = 0; 
						break; 
						
						
					// gestion de la souris 
				
				//case SDL_MOUSEMOTION: // gestion coordonnées de la souris 
					//event.motion.xrel || yrel (position relative)
					printf(" %d | %d \n",e.motion.x,e.motion.y);
					break;
					
				case SDL_MOUSEBUTTONDOWN: // gestion coordonnées de la souris 
					//if(event.button.clicks>=2)
					//	printf("Double clic \n");
					if(e.button.button==SDL_BUTTON_RIGHT)//SDL_BUTTON_LEFT|MIDOLE
						printf("Clic droit \n");
					printf(" clic en %d | %d \n",e.button.x,e.button.y);
					break;
					
					case SDL_WINDOWEVENT:
					
						switch(e.window.event)
						{
							case SDL_WINDOWEVENT_EXPOSED:
							case SDL_WINDOWEVENT_SIZE_CHANGED:
							case SDL_WINDOWEVENT_RESIZED:
							case SDL_WINDOWEVENT_SHOWN:
								
                                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);/* Le fond de la fenêtre sera blanc */
								SDL_RenderClear(renderer);
                                
                                /* Ajout du texte en noir */
                                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                                SDL_RenderCopy(renderer, texte_tex, NULL, &txtDestRect);
								
                                /* Ajout de la seconde image à une certaine position */
                                
                                imgDestRect.x = 10;
								imgDestRect.y = 50;
								
								SDL_QueryTexture(image_tex, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
								SDL_RenderCopy(renderer, image_tex, NULL, &imgDestRect);
								
                                /* Ajout de la seconde image à une autre position */
                                
								imgDestRect.x = 250;
								
								SDL_RenderCopy(renderer, image_tex, NULL, &imgDestRect);
								
                                /* On fait le rendu ! */
                                
                                SDL_RenderPresent(renderer);
							break;
						}
					break;
				} 
			} 
		}
	} else 
	{
		fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
	}

	//Destruction de la fenetre
	SDL_DestroyWindow(pWindow);

	TTF_CloseFont(police); /* Doit être avant TTF_Quit() */
	TTF_Quit();
    SDL_Quit();
    
    return 0;
}


