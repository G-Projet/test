

#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

int main (int argc, char** argv)
{
	SDL_Renderer *renderer=NULL;
	
    SDL_Window   *pWindow = NULL;

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

    pWindow =  SDL_CreateWindow(
                "Duck_Tales",                       // window title
                SDL_WINDOWPOS_CENTERED,           // initial x position
                SDL_WINDOWPOS_CENTERED,           // initial y position
                1600,                               // width, in pixels
                900,                               // height, in pixeldanss
                0                  // flags - see below
                );
    
   	renderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); 
	
    //SDL_Surface *pSurf = SDL_GetWindowSurface(ecran);
    
    SDL_Surface * image = IMG_Load("paysage.png");

	//SDL_Texture *image_tex = NULL;
	//image_tex= SDL_CreateTextureFromSurface(renderer, image); 
	
	position.x = 10;
	position.y = 10;
	
	//SDL_RenderClear(renderer);	
	
	police1 = TTF_OpenFont("JMH Typewriter.ttf", 40);// police et taille de la police
 						
	texte1 = TTF_RenderText_Blended(police1, 
	 								"***********************************************", couleurJaune);
	SDL_Texture *text_tex=NULL;
	text_tex = SDL_CreateTextureFromSurface(renderer, texte1);
	
	if(text_tex==NULL)
		EXIT_FAILURE;
	
	
	
	SDL_QueryTexture(text_tex, NULL, NULL, &(position.w), &(position.h));
	
	
	
	//SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    //SDL_RenderCopy(renderer, texte1, NULL, &position); // pour l'image
    
	
	//position.x = 200;   position.y = 200;
					
	//SDL_QueryTexture(image_tex, NULL, NULL, &(position.w), &(position.h));
	//SDL_RenderCopy(renderer, image_tex, NULL, &position);
	
	
	SDL_RenderPresent(renderer);							
								
    /* Chargement de la police */

   
 
	
    /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
	/*
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
			//SDL_FillRect(pSurf, NULL, SDL_MapRGB(pSurf->format, 0, 0, 0));//font noir
			
			//SDL_RenderCopy(renderer, image_tex, NULL, &position);
			
			//position.x = 200;   position.y = 40;
			
			//SDL_RenderCopy(renderer, texte1, NULL, &position);
			//SDL_RenderPresent(renderer);
			
			
			
			/*
			position.x = 200;   position.y = 40;
			
			SDL_RenderCopy(renderer, image_tex, NULL, &position);
			
			SDL_BlitSurface(texte1, NULL, pSurf, &position); 

			position.x = 250; position.y = 70;
			SDL_BlitSurface(texte2, NULL, pSurf, &position); 

			position.x =570; position.y = 125;
			SDL_BlitSurface(texte3, NULL, pSurf, &position);  

			position.x = 200; position.y = 160;
			SDL_BlitSurface(texte4, NULL, pSurf, &position);  


            // partie inférieur 
			position.x =200; position.y = 60;
			SDL_BlitSurface(texte5, NULL, pSurf, &position);  

			position.x =200; position.y = 80;
			SDL_BlitSurface(texte5, NULL, pSurf, &position);  

			position.x =200; position.y = 100;
			SDL_BlitSurface(texte5, NULL, pSurf, &position);  

			position.x =200; position.y = 120;
			SDL_BlitSurface(texte5, NULL, pSurf, &position);  

			position.x =200; position.y = 140;
			SDL_BlitSurface(texte5, NULL, pSurf, &position); 

             //   partie supérieur
			position.x =1350; position.y = 60;
			SDL_BlitSurface(texte5, NULL, pSurf, &position);  

			position.x =1350; position.y = 80;
			SDL_BlitSurface(texte5, NULL, pSurf, &position);  

			position.x =1350; position.y = 100;
			SDL_BlitSurface(texte5, NULL, pSurf, &position); 

			position.x =1350; position.y = 120;
			SDL_BlitSurface(texte5, NULL, pSurf, &position); 

			position.x =1350; position.y = 140;
			SDL_BlitSurface(texte5, NULL, pSurf, &position);  
 
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
            
            
		    SDL_UpdateWindowSurface(ecran);*/
    }
    
    TTF_CloseFont(police1);
    TTF_CloseFont(police2);
   
    TTF_Quit();

    SDL_FreeSurface(texte1);
   /* SDL_FreeSurface(texte2);
    SDL_FreeSurface(texte3);
    SDL_FreeSurface(texte4);
    SDL_FreeSurface(texte5);
    SDL_FreeSurface(texte6);
    */
     
    SDL_FreeSurface(image);


    SDL_Quit();

    return EXIT_SUCCESS;
}





