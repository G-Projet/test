
 
#include "fonction.h"

int affichagePage1(SDL_Window *window, SDL_Renderer *renderer)
{
	SDL_Texture *texture_fond=NULL ,*texture_txt1=NULL,

	*texture_txt2=NULL ,*texture_txt3=NULL ,*texture_txt4=NULL ,*texture_txt5=NULL ,
	*texture_txt6=NULL;

	SDL_Rect position;

	// initialisation 

	SDL_Color couleurJaune = {250,234,115};
	 
	image =NULL;

	texte1 = texte2 = texte3 = texte4 = texte5 = texte6 = NULL;

    police1 = police2 = NULL ;
 
	imgDestRect.x=500;
	imgDestRect.y=300;
	imgDestRect.w=0;
	imgDestRect.h=0;

	txtDestRect.x=0;
	txtDestRect.y=0;
	txtDestRect.w=0;
	txtDestRect.h=0;
 
   //************ traitement image
  
   	image = IMG_Load("image/Générique.jpg");

   	if(image==NULL)
	{	liberation_ressources(window,NULL,NULL, NULL);	message_erreurs("Chargement image fond"); }

   	texture_fond = SDL_CreateTextureFromSurface(renderer, image);

   	if (texture_fond == NULL)
		{ printf("erreurs : Ouverture texture \n "); return EXIT_FAILURE;}

	SDL_QueryTexture(texture_fond, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));

	// ************************ traitement texte
	
	TTF_Init();

    police1 = TTF_OpenFont("image/JMH Typewriter.ttf", 40);// police et taille de la police
    police2 = TTF_OpenFont("image/JMH Typewriter.ttf", 30);
 
	if (police1 == NULL || police2==NULL)
		{ printf("erreurs : Ouverture police \n "); return EXIT_FAILURE;}


	// Écriture du texte dans la SDL_Surface texte 

		//..........................
    texte1 = TTF_RenderText_Solid(police1, 
        "***********************************************", couleurJaune );
     if (texte1 == NULL)
		{ printf("erreurs : Ouverture texte \n "); return EXIT_FAILURE;}

	 texture_txt1=SDL_CreateTextureFromSurface(renderer, texte1);

    if (texture_txt1 == NULL)
		{ printf("erreurs : Ouverture texture_txt \n "); return EXIT_FAILURE;}

			//.............................
 
    texte5 = TTF_RenderText_Solid(police1, "*", couleurJaune);
    texture_txt5=SDL_CreateTextureFromSurface(renderer, texte5);

    texte2 = TTF_RenderText_Solid(police1, 
        "  Bienvenue sur la platforme de jeux Duck_Tales ", couleurJaune);
    texture_txt2=SDL_CreateTextureFromSurface(renderer, texte2);

    texte3 = TTF_RenderText_Solid(police2, 
        " SDL version :              ", couleurJaune);
    texture_txt3=SDL_CreateTextureFromSurface(renderer, texte3);

    texte4 = TTF_RenderText_Solid(police1, 
        "***********************************************", couleurJaune);
    texture_txt4=SDL_CreateTextureFromSurface(renderer, texte4);

	//recupération de la version SDL
	SDL_version nb;
    SDL_VERSION(&nb);
    
	char c1[6]; sprintf(c1, "%d ." , nb.major);
	char c2[6]; sprintf(c2, "%d ." , nb.minor);
	char c3[6]; sprintf(c3, "%d ." , nb.patch); 

	continuer = FAUX;

    while (!continuer)
    {
    	while(SDL_PollEvent(&event))
		{
			SDL_WaitEvent(&event);
			
			switch(event.type)
			{
			    case SDL_QUIT:
			    continuer = VRAI;
			    break;

			    default:
					break;
			}	 
				SDL_RenderClear( renderer );

				position.x = 200;   position.y = 40;
				SDL_QueryTexture(texture_txt1, NULL, NULL, &(position.w), &(position.h));
				SDL_RenderCopy(renderer, texture_txt1, NULL, &position); 

				position.x = 250; position.y = 70;
				SDL_QueryTexture(texture_txt2, NULL, NULL, &(position.w), &(position.h));
				SDL_RenderCopy(renderer, texture_txt2, NULL, &position);


				position.x =570; position.y = 125;
				SDL_QueryTexture(texture_txt3, NULL, NULL, &(position.w), &(position.h));
				SDL_RenderCopy(renderer, texture_txt3, NULL, &position);

				position.x = 200; position.y = 160;
				SDL_QueryTexture(texture_txt4, NULL, NULL, &(position.w), &(position.h));
				SDL_RenderCopy(renderer, texture_txt4, NULL, &position);

					// partie inférieur
				position.x =200; position.y = 60;
				SDL_QueryTexture(texture_txt5, NULL, NULL, &(position.w), &(position.h));
				SDL_RenderCopy(renderer, texture_txt5, NULL, &position);

				position.x =200; position.y = 80;
				SDL_QueryTexture(texture_txt5, NULL, NULL, &(position.w), &(position.h));
				SDL_RenderCopy(renderer, texture_txt5, NULL, &position); 

				position.x =200; position.y = 100;
				SDL_QueryTexture(texture_txt5, NULL, NULL, &(position.w), &(position.h));
				SDL_RenderCopy(renderer, texture_txt5, NULL, &position);

				position.x =200; position.y = 120;
				SDL_QueryTexture(texture_txt5, NULL, NULL, &(position.w), &(position.h));
				SDL_RenderCopy(renderer, texture_txt5, NULL, &position);  

				position.x =200; position.y = 140;
				SDL_QueryTexture(texture_txt5, NULL, NULL, &(position.w), &(position.h));
				SDL_RenderCopy(renderer, texture_txt5, NULL, &position); 

					 //   partie supérieur

				position.x =1350; position.y = 60;
				SDL_QueryTexture(texture_txt5, NULL, NULL, &(position.w), &(position.h));
				SDL_RenderCopy(renderer, texture_txt5, NULL, &position); 

				position.x =1350; position.y = 80;
				SDL_QueryTexture(texture_txt5, NULL, NULL, &(position.w), &(position.h));
				SDL_RenderCopy(renderer, texture_txt5, NULL, &position);

				position.x =1350; position.y = 100;
				SDL_QueryTexture(texture_txt5, NULL, NULL, &(position.w), &(position.h));
				SDL_RenderCopy(renderer, texture_txt5, NULL, &position);

				position.x =1350; position.y = 120;
				SDL_QueryTexture(texture_txt5, NULL, NULL, &(position.w), &(position.h));
				SDL_RenderCopy(renderer, texture_txt5, NULL, &position); 

				position.x =1350; position.y = 140;
				SDL_QueryTexture(texture_txt5, NULL, NULL, &(position.w), &(position.h));
				SDL_RenderCopy(renderer, texture_txt5, NULL, &position); 

					//version 

				texte6= TTF_RenderText_Blended(police2,c1, couleurJaune);
				texture_txt6=SDL_CreateTextureFromSurface(renderer, texte6); 

				position.x =820; position.y = 125;
				SDL_QueryTexture(texture_txt6, NULL, NULL, &(position.w), &(position.h));
				SDL_RenderCopy(renderer, texture_txt6, NULL, &position);


				texte6= TTF_RenderText_Blended(police2,c2, couleurJaune);
				texture_txt6=SDL_CreateTextureFromSurface(renderer, texte6); 
				position.x =870; position.y = 125;
				SDL_QueryTexture(texture_txt6, NULL, NULL, &(position.w), &(position.h));
				SDL_RenderCopy(renderer, texture_txt6, NULL, &position);

				texte6= TTF_RenderText_Blended(police2,c3, couleurJaune);
				texture_txt6=SDL_CreateTextureFromSurface(renderer, texte6); 
				position.x =920; position.y = 125;
				SDL_RenderCopy(renderer, texture_txt6, NULL, &position);

				// ******************************

				SDL_RenderCopy(renderer, texture_fond, NULL, &imgDestRect);

			    SDL_RenderPresent(renderer);	
	    }
    }

	liberation_ressourcesTTF(police1,police2);
	liberation_ressourcesSurface(texte1,texte2,texte3,texte4,texte5,texte6);
	liberation_ressourcesSurface(image,NULL,NULL,NULL,NULL,NULL);
	SDL_DestroyTexture(texture_fond);
	SDL_DestroyTexture(texture_txt1);
	
	TTF_Quit();

    return EXIT_SUCCESS;
}

