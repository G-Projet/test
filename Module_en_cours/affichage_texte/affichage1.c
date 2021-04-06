

#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "initialisation.h"

int main (int argc, char** argv)
{

    SDL_Window *ecran = NULL;

    SDL_Surface *texte1,*texte2,*texte3, *texte4,*texte5,*texte6; //*fond = NULL;
        texte1=texte2=texte3=texte4=texte5=texte6=NULL;

    SDL_Rect position;

    SDL_Event event;

    TTF_Font *police1 = NULL,* police2=NULL ;

    SDL_Color couleurJaune = {250,234,115};
    //SDL_Color couleurNoir = { 0,0,0 };

    int continuer = 1;

    SDL_Init(SDL_INIT_VIDEO);

    TTF_Init();

    //    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    //    SDL_WM_SetCaption("Gestion du texte avec SDL_ttf", NULL);

    ecran =  SDL_CreateWindow(
                "Duck_Tales",                       // window title
                SDL_WINDOWPOS_CENTERED,           // initial x position
                SDL_WINDOWPOS_CENTERED,           // initial y position
                1600,                               // width, in pixels
                900,                               // height, in pixeldanss
                0                  // flags - see below
                );
    
    
    SDL_Surface *pSurf = SDL_GetWindowSurface(ecran);
    
    SDL_Surface * fond = IMG_Load("paysage.png");

	
    /* Chargement de la police */

    police1 = TTF_OpenFont("JMH Typewriter.ttf", 40);// police et taille de la police
    police2 = TTF_OpenFont("JMH Typewriter.ttf", 30);
 
	
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

    while (continuer)
    {
		SDL_WaitEvent(&event);
		
		switch(event.type)
		{
		    case SDL_QUIT:
		    continuer = 0;
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
            
            
		    SDL_UpdateWindowSurface(ecran);
    }
    
    TTF_CloseFont(police1);
    TTF_CloseFont(police2);
   
    TTF_Quit();

    SDL_FreeSurface(texte1);
    SDL_FreeSurface(texte2);
    SDL_FreeSurface(texte3);
    SDL_FreeSurface(texte4);
    SDL_FreeSurface(texte5);
    SDL_FreeSurface(texte6);
    
    SDL_FreeSurface(pSurf);
    SDL_FreeSurface(fond);


    SDL_Quit();

    return EXIT_SUCCESS;
}





