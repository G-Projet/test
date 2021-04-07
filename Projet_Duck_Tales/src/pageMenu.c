
 
#include "fonction.h"

extern
int menu(SDL_Window * window,SDL_Renderer *renderer)
{
	SDL_Surface *image = NULL;
	
	SDL_Texture *texture[nbTexture];
	
	int i;
	
	for( i=0;i<nbTexture;i++)
		texture[i]=NULL;
	
	//texture[0] <=> texture_fond = NULL 
	//texture[1] <=> texture_txt = NULL
	
	SDL_Rect txtDestRect,imgDestRect;
 
	imgDestRect.w=0;
	imgDestRect.h=0;
	//************
 
	txtDestRect.w=0;
	txtDestRect.h=0;

	TTF_Font *police = NULL;
	SDL_Surface *texte=NULL;
	
	SDL_Color couleurJaune = {250,234,115},
	couleurBlanche = {255, 255, 255};
 
	int temps_Actuel = SDL_GetTicks() ; 
  
	int continuer = 0;
	
	
	image=NULL;	
	if( (image = IMG_Load("image/images.jpeg"))==NULL)
	{ printf("erreurs : Ouverture image \n "); return EXIT_FAILURE;}
 
	// texte : ************************************************************
	
	TTF_Init();
	
	police = TTF_OpenFont("image/JMH Typewriter.ttf", 30);
	
	if (police == NULL){ printf("erreurs : Ouverture police \n "); return EXIT_FAILURE;}
		
	texte = TTF_RenderText_Solid(police, 
        "  Bienvenue sur la platforme de jeux Duck_Tales ", couleurBlanche);
    if (texte == NULL){ printf("erreurs : Ouverture texte \n "); return EXIT_FAILURE;}
		    
    texture[1]=SDL_CreateTextureFromSurface(renderer, texte);
    
    if (texture[1] == NULL) { printf("erreurs : Ouverture texture_txt \n "); return EXIT_FAILURE;}
    
    txtDestRect.x=400;   txtDestRect.y=50;
 
    SDL_QueryTexture(texture[1], NULL, NULL, &(txtDestRect.w), &(txtDestRect.h));
	SDL_RenderCopy(renderer, texture[1], NULL, &txtDestRect);
	
	texte = TTF_RenderText_Solid(police, "  Menu ", couleurBlanche);
	texture[2]=SDL_CreateTextureFromSurface(renderer, texte);
	
	txtDestRect.x=700;   txtDestRect.y=130;
 
    SDL_QueryTexture(texture[2], NULL, NULL, &(txtDestRect.w), &(txtDestRect.h));
	SDL_RenderCopy(renderer, texture[2], NULL, &txtDestRect);
	
		// boutons : **********************************************************
	//1
	texture[0] = SDL_CreateTextureFromSurface(renderer, image);
	imgDestRect.x=420; imgDestRect.y=250;
	SDL_QueryTexture(texture[0], NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
	SDL_RenderCopy(renderer, texture[0], NULL, &imgDestRect);
					 	
	texte = TTF_RenderText_Solid(police, "  Joueur seul ", couleurBlanche);	    
    texture[3]=SDL_CreateTextureFromSurface(renderer, texte);
    txtDestRect.x=450;   txtDestRect.y=245;
    SDL_QueryTexture(texture[3], NULL, NULL, &(txtDestRect.w), &(txtDestRect.h));
	SDL_RenderCopy(renderer, texture[3], NULL, &txtDestRect);
	
	//2
	imgDestRect.y=300;
	//SDL_QueryTexture(texture[0], NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
	SDL_RenderCopy(renderer, texture[0], NULL, &imgDestRect);
	
	texte = TTF_RenderText_Solid(police, "  Ordinateur seul ", couleurBlanche);	    
    texture[4]=SDL_CreateTextureFromSurface(renderer, texte);
    txtDestRect.y=300;
    SDL_QueryTexture(texture[4], NULL, NULL, &(txtDestRect.w), &(txtDestRect.h));
	SDL_RenderCopy(renderer, texture[4], NULL, &txtDestRect);
	
	//3

	imgDestRect.y=350;
	//SDL_QueryTexture(texture[0], NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
	SDL_RenderCopy(renderer, texture[0], NULL, &imgDestRect);
	
	texte = TTF_RenderText_Solid(police, "  Credit disponible ", couleurBlanche);	    
    texture[5]=SDL_CreateTextureFromSurface(renderer, texte);
    txtDestRect.y=350;
    SDL_QueryTexture(texture[5], NULL, NULL, &(txtDestRect.w), &(txtDestRect.h));
	SDL_RenderCopy(renderer, texture[5], NULL, &txtDestRect);
	
	//4
		
	imgDestRect.y=400;
	//SDL_QueryTexture(texture[0], NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
	SDL_RenderCopy(renderer, texture[0], NULL, &imgDestRect);
	
	texte = TTF_RenderText_Solid(police, "  Reprendre la partie", couleurBlanche);	    
    texture[6]=SDL_CreateTextureFromSurface(renderer, texte);
    txtDestRect.y=400;
    SDL_QueryTexture(texture[6], NULL, NULL, &(txtDestRect.w), &(txtDestRect.h));
	SDL_RenderCopy(renderer, texture[6], NULL, &txtDestRect);
	
	//5
		
	imgDestRect.y=450;
	//SDL_QueryTexture(texture[0], NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
	SDL_RenderCopy(renderer, texture[0], NULL, &imgDestRect);
	
	texte = TTF_RenderText_Solid(police, "  Finir la partie", couleurBlanche);	    
    texture[7]=SDL_CreateTextureFromSurface(renderer, texte);
    txtDestRect.y=450;
    SDL_QueryTexture(texture[7], NULL, NULL, &(txtDestRect.w), &(txtDestRect.h));
	SDL_RenderCopy(renderer, texture[7], NULL, &txtDestRect);
	
	//6
	
	imgDestRect.y=500;
	//SDL_QueryTexture(texture[0], NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
	SDL_RenderCopy(renderer, texture[0], NULL, &imgDestRect);
	
	texte = TTF_RenderText_Solid(police, "  Quitter", couleurBlanche);	    
    texture[8]=SDL_CreateTextureFromSurface(renderer, texte);
    txtDestRect.y=500;
    SDL_QueryTexture(texture[8], NULL, NULL, &(txtDestRect.w), &(txtDestRect.h));
	SDL_RenderCopy(renderer, texture[8], NULL, &txtDestRect);
	
	// presentation du menu 
	SDL_RenderPresent(renderer);
	
	SDL_RenderClear( renderer );
	
	
	continuer=FAUX;
	
	while (!continuer)
	{
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
					
					//5 = largeur bouton = longueur bouton
					
				case SDL_MOUSEBUTTONUP: // je te met juste ce cas
						if (event.button.button == SDL_BUTTON_LEFT)
						{
							//printf(" j'appuie sur la gauche de la souris *******  1\n");
		 
							if(event.button.x > 418 && event.button.x < 
								450 && event.button.y > 260 && event.button.y < 280) // joueur 
								
			// Test des coordonnées de la souris pour savoir si elles sont au meme emplacement que le bouton 1
							{
								printf(" j'appuie sur la gauche de la souris *******  2\n");
								jeu1(window,renderer);
								 
							} 
							
							if(event.button.x > 418 && event.button.x < 
								450 && event.button.y > 320 && event.button.y < 335) // Ordinateur 
								
			// Test des coordonnées de la souris pour savoir si elles sont au meme emplacement que le bouton 1
							{
								printf(" j'appuie sur la gauche de la souris *******  2\n");
								affichagePage1(window,renderer); // fonction affichage page
							} 	
						}
						break;
 	
				default:
					break;
			}
		}
	}

	SDL_FreeSurface(image);	
	
	liberation_ressourcesTTF(police,NULL);
	
	for( i=0;i<nbTexture;i++)
	
		SDL_DestroyTexture(texture[i]) ;
	
    return EXIT_SUCCESS;
}






