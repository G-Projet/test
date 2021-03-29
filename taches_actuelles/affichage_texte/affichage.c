

#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

int main (int argc, char** argv)
{
    SDL_Window *ecran = NULL;

    SDL_Surface *texte1,*texte2,*texte3, *texte4,*texte5; //*fond = NULL;

        texte1=texte2=texte3=texte4=texte5=NULL;

    SDL_Rect position;

    SDL_Event event;

    TTF_Font *police1 = NULL,* police2=NULL;

    SDL_Color couleurJaune = {250,234,115},couleurNoir= {0,0, 0};

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
    
    SDL_version nb;
    SDL_VERSION(&nb);

    SDL_Surface *pSurf = SDL_GetWindowSurface(ecran);
    
    //fond = IMG_Load("moraira.jpg");

    /* Chargement de la police */

    police1 = TTF_OpenFont("rainyhearts.ttf", 40);//texte police 
    police2 = TTF_OpenFont("rainyhearts.ttf", 30);

    /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */

    texte1 = TTF_RenderText_Blended(police1, 
        "********************************************************", couleurJaune);

    texte5 = TTF_RenderText_Blended(police1, "*", couleurJaune);

    texte2 = TTF_RenderText_Blended(police1, 
        "  Bienvenue sur la platforme de jeux Duck_Tales ", couleurNoir);
    
    texte3 = TTF_RenderText_Blended(police2, 
        " SDL version : %d . %d . %d           ", couleurJaune);
    
    texte4 = TTF_RenderText_Blended(police1, 
        "********************************************************", couleurJaune);

    /*
    printf("\t*    Bienvenus sur la platforme de jeux Duck_Tales     *  \n");
    printf("\t* \t \t SDL version : %d . %d . %d          *", nb.major, nb.minor, nb.patch );
    printf("\t********************************************************\n"); 
    sleep(1);
    */

    while (continuer)
    {
		SDL_WaitEvent(&event);
		switch(event.type)
		{
		    case SDL_QUIT:
		    continuer = 0;
		    break;
		}
		    SDL_FillRect(pSurf, NULL, SDL_MapRGB(pSurf->format, 255, 255, 255));

		        position.x = 300;   position.y = 40;
		    SDL_BlitSurface(texte1, NULL, pSurf, &position); /* Blit du texte */
                
                position.x = 310; position.y = 70;
            SDL_BlitSurface(texte2, NULL, pSurf, &position); /* Blit du texte */


            // partie inférieur 
              position.x =300; position.y = 60;
             SDL_BlitSurface(texte5, NULL, pSurf, &position); /* Blit du texte */

                position.x =300; position.y = 80;
             SDL_BlitSurface(texte5, NULL, pSurf, &position); /* Blit du texte */
                
                   position.x =300; position.y = 100;
             SDL_BlitSurface(texte5, NULL, pSurf, &position); /* Blit du texte */

                position.x =300; position.y = 120;
             SDL_BlitSurface(texte5, NULL, pSurf, &position); /* Blit du texte */

                position.x =300; position.y = 140;
             SDL_BlitSurface(texte5, NULL, pSurf, &position); /* Blit du texte */

             
             //   partie supérieur
                  position.x =1123; position.y = 60;
             SDL_BlitSurface(texte5, NULL, pSurf, &position); /* Blit du texte */

                position.x =1123; position.y = 80;
             SDL_BlitSurface(texte5, NULL, pSurf, &position); /* Blit du texte */
                
                   position.x =1123; position.y = 100;
             SDL_BlitSurface(texte5, NULL, pSurf, &position); /* Blit du texte */

                position.x =1123; position.y = 120;
             SDL_BlitSurface(texte5, NULL, pSurf, &position); /* Blit du texte */

                position.x =1123; position.y = 140;
             SDL_BlitSurface(texte5, NULL, pSurf, &position); /* Blit du texte */
            //
                position.x =800; position.y = 130;
            SDL_BlitSurface(texte3, NULL, pSurf, &position); /* Blit du texte */
                
                position.x = 300; position.y = 160;
            SDL_BlitSurface(texte4, NULL, pSurf, &position); /* Blit du texte */

                //position.x = 300; position.y = 180;

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

    SDL_Quit();

    return EXIT_SUCCESS;
}





