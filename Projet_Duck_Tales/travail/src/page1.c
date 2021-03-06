
 
#include "fonction.h"

int affichagePage1(SDL_Window *window)
{
	SDL_Rect txtDestRect,imgDestRect;
	
    SDL_Surface *pSurf  = NULL;
	SDL_Surface *image = NULL;
	SDL_Renderer *renderer=NULL;
	SDL_Texture *image_fond=NULL;
	
    SDL_Surface *texte1,*texte2,*texte3, *texte4,*texte5,*texte6; //*fond = NULL;

    texte1=texte2=texte3=texte4=texte5=texte6=NULL;

    SDL_Rect position;
 
    TTF_Font *police1 = NULL, *police2=NULL ;
	
    SDL_Color couleurJaune = {250,234,115};

    //SDL_Color couleurNoir = { 0,0,0 };

     if (SDL_Init(SDL_INIT_VIDEO) != 0 ) /* Initialisation simple */
    {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return -1;
    }

    TTF_Init();

    pSurf = SDL_GetWindowSurface(window);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); //

    if(pSurf==NULL)
    {	liberation_ressources(NULL,NULL,pSurf, NULL);	message_erreurs("Chargement image"); }
   
    
   	image = IMG_Load("../image/paysage.png");
   	if(image==NULL)
	{	liberation_ressources(window,NULL,NULL, NULL);	message_erreurs("Chargement image"); }

    image_fond = SDL_CreateTextureFromSurface(renderer, image); //

   	SDL_FreeSurface(image);
    
	
	
    /* Chargement de la police */

    police1 = TTF_OpenFont("../image/JMH Typewriter.ttf", 40);// police et taille de la police
    police2 = TTF_OpenFont("../image/JMH Typewriter.ttf", 30);
 
	
    /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */

    texte1 = TTF_RenderText_Blended(police1, 
        "***********************************************", couleurJaune);

    texte5 = TTF_RenderText_Blended(police1, "*", couleurJaune);

    texte2 = TTF_RenderText_Blended(police1, 
        "  Bienvenue sur la platforme de jeux Duck_Tales ", couleurJaune);
    
    texte3 = TTF_RenderText_Blended(police2, 
        " SDL version :              ", couleurJaune);
    
    texte4 = TTF_RenderText_Blended(police1, 
        "***********************************************", couleurJaune);
        
    // recupération des parametres de la version   
     
	SDL_version nb;
    SDL_VERSION(&nb);
    
	char c1[6];sprintf(c1, "%d ." , nb.major);
	char c2[6];sprintf(c2, "%d ." , nb.minor);
	char c3[6];sprintf(c3, "%d ." , nb.patch); 

	continuer = FAUX;

    while (!continuer)
    {
		SDL_WaitEvent(&event);
		
		switch(event.type)
		{
		    case SDL_QUIT:
		    continuer = VRAI;
		    break;
		}
			SDL_FillRect(pSurf, NULL, SDL_MapRGB(pSurf->format,0, 0, 0));//font noir
 
			position.x = 200;   position.y = 40;
			SDL_BlitSurface(texte1, NULL, pSurf, &position); /* Blit du texte */

			position.x = 250; position.y = 70;
			SDL_BlitSurface(texte2, NULL, pSurf, &position); /* Blit du texte */

			position.x =570; position.y = 125;
			SDL_BlitSurface(texte3, NULL, pSurf, &position); /* Blit du texte */

			position.x = 200; position.y = 160;
			SDL_BlitSurface(texte4, NULL, pSurf, &position); /* Blit du texte */


            // partie inférieur 
			position.x =200; position.y = 60;
			SDL_BlitSurface(texte5, NULL, pSurf, &position); /* Blit du texte */

			position.x =200; position.y = 80;
			SDL_BlitSurface(texte5, NULL, pSurf, &position); /* Blit du texte */

			position.x =200; position.y = 100;
			SDL_BlitSurface(texte5, NULL, pSurf, &position); /* Blit du texte */

			position.x =200; position.y = 120;
			SDL_BlitSurface(texte5, NULL, pSurf, &position); /* Blit du texte */

			position.x =200; position.y = 140;
			SDL_BlitSurface(texte5, NULL, pSurf, &position); /* Blit du texte */

             //   partie supérieur
			position.x =1350; position.y = 60;
			SDL_BlitSurface(texte5, NULL, pSurf, &position); /* Blit du texte */

			position.x =1350; position.y = 80;
			SDL_BlitSurface(texte5, NULL, pSurf, &position); /* Blit du texte */

			position.x =1350; position.y = 100;
			SDL_BlitSurface(texte5, NULL, pSurf, &position); /* Blit du texte */

			position.x =1350; position.y = 120;
			SDL_BlitSurface(texte5, NULL, pSurf, &position); /* Blit du texte */

			position.x =1350; position.y = 140;
			SDL_BlitSurface(texte5, NULL, pSurf, &position); /* Blit du texte */
 
                //version    
			
			texte6= TTF_RenderText_Blended(police2,c1, couleurJaune);    
			position.x =820; position.y = 125;
			SDL_BlitSurface(texte6, NULL, pSurf, &position);

			texte6= TTF_RenderText_Blended(police2,c2, couleurJaune);
			position.x =870; position.y = 125;
			SDL_BlitSurface(texte6, NULL, pSurf, &position);

			texte6= TTF_RenderText_Blended(police2,c3, couleurJaune);
			position.x =920; position.y = 125;
			SDL_BlitSurface(texte6, NULL, pSurf, &position);
            
            
		    

		    SDL_QueryTexture(image_fond, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
			SDL_RenderCopy(renderer, image_fond, NULL, &imgDestRect);

		    SDL_RenderPresent(renderer);
		    SDL_UpdateWindowSurface(window);
    }
    
	liberation_ressourcesTTF(police1,police2);
	liberation_ressourcesSurface(texte1,texte2,texte3,texte4,texte5,texte6);
	liberation_ressourcesSurface(image,pSurf,NULL,NULL,NULL,NULL);
	liberation_ressources(window,renderer,NULL,NULL);

	TTF_Quit();
    SDL_Quit();

    return EXIT_SUCCESS;
}

