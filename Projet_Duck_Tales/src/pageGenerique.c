
/**
*\file pageGenerique.c
*\brief Fichier contenant le fonction d'affichage du générique
*\author Belkadi Smail
*\version 2.0
*\date 07 avril 2021
**/
 
#include "fonction.h"

/**
*\brief La fonction qui affiche la 1e générique
**/

int affichagePage1(SDL_Window *window, SDL_Renderer *renderer)
{
	SDL_RenderClear( renderer );
	
	//texture[0]=texture_fond , texture[7]=texture_entree 
	
	for(i=0;i<tailleTexture;i++) /** initialisation de la texture  **/
	
		texture[i]=NULL;
		
	for(i=0;i<tailleSurface;i++)  /** initialisation de la SDL_surface  **/
	
		Stexte[i]=NULL;	
 
	SDL_Rect position, entree;

	// initialisation 

	SDL_Color couleurJaune = {250,234,115}; /** déclaration des couleurs  **/
	 
	image =NULL;
	image2=NULL;
	
    police1 = police2 = NULL ;
 
	imgDestRect.x=50;
	imgDestRect.y=250;
	imgDestRect.w=0;//longueur_ecran;
	imgDestRect.h=0;
	
	entree.x=700;
	entree.y=720;

	txtDestRect.x=0;
	txtDestRect.y=0;
	txtDestRect.w=0;
	txtDestRect.h=0;
 
   //************ traitement image
  
   	image = IMG_Load("image/Générique2.jpg");

   	if(image==NULL)
	{	liberation_ressources(window,NULL,NULL, NULL);	message_erreurs("Chargement image fond"); }

   	texture[0] = SDL_CreateTextureFromSurface(renderer, image);

   	if (texture[0] == NULL)
		{ printf("erreurs : Ouverture texture \n "); return EXIT_FAILURE;}

	SDL_QueryTexture(texture[0], NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
	
	//************ traitement image2
  
   	image2 = IMG_Load("image/entree2.jpg");//bouton de validation

   	if(image2==NULL)
	{	liberation_ressources(window,NULL,NULL, NULL);	message_erreurs("Chargement image fond"); }

   	texture[7] = SDL_CreateTextureFromSurface(renderer, image2);

   	if (texture[7] == NULL)
		{ printf("erreurs : Ouverture texture \n "); return EXIT_FAILURE;}
		
	SDL_QueryTexture(texture[7], NULL, NULL, &(entree.w), &(entree.h));
	
	// ************************ traitement texte
	
	TTF_Init();

    police1 = TTF_OpenFont("image/JMH Typewriter.ttf", 40);// police et taille de la police
    police2 = TTF_OpenFont("image/JMH Typewriter.ttf", 30);
 
	if (police1 == NULL || police2==NULL)
		{ printf("erreurs : Ouverture police \n "); return EXIT_FAILURE;}


	// Écriture du texte dans la SDL_Surface texte 

		//..........................
    Stexte[1] = TTF_RenderText_Solid(police1, 
        "***********************************************", couleurJaune );
     if (Stexte[1] == NULL)
		{ printf("erreurs : Ouverture texte \n "); return EXIT_FAILURE;}

	 texture[1]=SDL_CreateTextureFromSurface(renderer, Stexte[1]);

    if (texture[1] == NULL)
		{ printf("erreurs : Ouverture texture_txt \n "); return EXIT_FAILURE;}

			//.............................
 
    Stexte[5] = TTF_RenderText_Solid(police1, "*", couleurJaune);
    texture[5]=SDL_CreateTextureFromSurface(renderer, Stexte[5]);

    Stexte[2] = TTF_RenderText_Solid(police1, 
        "  Bienvenue sur la platforme de jeux Duck_Tales ", couleurJaune);
    texture[2]=SDL_CreateTextureFromSurface(renderer, Stexte[2]);

    Stexte[3]= TTF_RenderText_Solid(police2, 
        " SDL version :              ", couleurJaune);
    texture[3]=SDL_CreateTextureFromSurface(renderer, Stexte[3]);

    Stexte[4] = TTF_RenderText_Solid(police1, 
        "***********************************************", couleurJaune);
    texture[4]=SDL_CreateTextureFromSurface(renderer, Stexte[4]);

	//recupération de la version SDL
	SDL_version nb;
    SDL_VERSION(&nb);
    
	char c1[6]; sprintf(c1, "%d ." , nb.major);
	char c2[6]; sprintf(c2, "%d ." , nb.minor);
	char c3[6]; sprintf(c3, "%d ." , nb.patch); 

	temp=FAUX;
	continuer=FAUX;
	
	while (!continuer)
	{     	
    	//while(SDL_PollEvent(&event))
		//{
			SDL_WaitEvent(&event);
			
			switch(event.type)
			{
				case SDL_QUIT:
					printf(" arrêt inopiné : Page Générique...........\n");
					temp=VRAI;
					continuer= VRAI;  
					break;
					
				case SDL_MOUSEMOTION: // gestion coordonnées de la souris 
					printf(" %d | %d \n",event.motion.x,event.motion.y);
					break;
					
					//5 = largeur bouton = longueur bouton	
				case SDL_MOUSEBUTTONUP:
						if (event.button.button == SDL_BUTTON_LEFT)
						{//printf(" j'appuie sur la gauche de la souris *******  1\n");
						
							if(event.button.x > 700 && event.button.x < 
								800 && event.button.y > 720 && event.button.y < 770) // joueur 
								
			// Test des coordonnées de la souris pour savoir si elles sont au meme emplacement que le bouton 1
							{
								printf(" j'appuie sur la gauche de la souris *******  2\n");
								menu(window,renderer);
								 
							} 
						}
						
				
				case SDL_KEYDOWN:// entrée clavier
					switch (event.key.keysym.sym)
					{
						case SDLK_q:
							printf(" je rentre ici a page G .......................1\n");						
							continuer = VRAI;						
							break;
						
						default:
							break;
					}
						
				default:
						break;			
			} 
			
			SDL_RenderClear( renderer );

			position.x = 200;   position.y = 40;
			SDL_QueryTexture(texture[1], NULL, NULL, &(position.w), &(position.h));
			SDL_RenderCopy(renderer, texture[1], NULL, &position); 

			position.x = 250; position.y = 70;
			SDL_QueryTexture(texture[2], NULL, NULL, &(position.w), &(position.h));
			SDL_RenderCopy(renderer, texture[2], NULL, &position);


			position.x =570; position.y = 125;
			SDL_QueryTexture(texture[3], NULL, NULL, &(position.w), &(position.h));
			SDL_RenderCopy(renderer, texture[3], NULL, &position);

			position.x = 200; position.y = 160;
			SDL_QueryTexture(texture[4], NULL, NULL, &(position.w), &(position.h));
			SDL_RenderCopy(renderer, texture[4], NULL, &position);

				// partie inférieur
			position.x =200; position.y = 60;
			SDL_QueryTexture(texture[5], NULL, NULL, &(position.w), &(position.h));
			SDL_RenderCopy(renderer, texture[5], NULL, &position);

			position.x =200; position.y = 80;
			SDL_QueryTexture(texture[5], NULL, NULL, &(position.w), &(position.h));
			SDL_RenderCopy(renderer, texture[5], NULL, &position); 

			position.x =200; position.y = 100;
			SDL_QueryTexture(texture[5], NULL, NULL, &(position.w), &(position.h));
			SDL_RenderCopy(renderer, texture[5], NULL, &position);

			position.x =200; position.y = 120;
			SDL_QueryTexture(texture[5], NULL, NULL, &(position.w), &(position.h));
			SDL_RenderCopy(renderer, texture[5], NULL, &position);  

			position.x =200; position.y = 140;
			SDL_QueryTexture(texture[5], NULL, NULL, &(position.w), &(position.h));
			SDL_RenderCopy(renderer,texture[5], NULL, &position); 

				 //   partie supérieur

			position.x =1350; position.y = 60;
			SDL_QueryTexture(texture[5], NULL, NULL, &(position.w), &(position.h));
			SDL_RenderCopy(renderer, texture[5], NULL, &position); 

			position.x =1350; position.y = 80;
			SDL_QueryTexture(texture[5], NULL, NULL, &(position.w), &(position.h));
			SDL_RenderCopy(renderer, texture[5], NULL, &position);

			position.x =1350; position.y = 100;
			SDL_QueryTexture(texture[5], NULL, NULL, &(position.w), &(position.h));
			SDL_RenderCopy(renderer, texture[5], NULL, &position);

			position.x =1350; position.y = 120;
			SDL_QueryTexture(texture[5], NULL, NULL, &(position.w), &(position.h));
			SDL_RenderCopy(renderer, texture[5], NULL, &position); 

			position.x =1350; position.y = 140;
			SDL_QueryTexture(texture[5], NULL, NULL, &(position.w), &(position.h));
			SDL_RenderCopy(renderer, texture[5], NULL, &position); 

				//version 

			Stexte[6]= TTF_RenderText_Blended(police2,c1, couleurJaune);
			texture[6]=SDL_CreateTextureFromSurface(renderer, Stexte[6]); 

			position.x =820; position.y = 125;
			SDL_QueryTexture(texture[6], NULL, NULL, &(position.w), &(position.h));
			SDL_RenderCopy(renderer, texture[6], NULL, &position);


			Stexte[6]= TTF_RenderText_Blended(police2,c2, couleurJaune);
			texture[6]=SDL_CreateTextureFromSurface(renderer, Stexte[6]); 
			position.x =870; position.y = 125;
			SDL_QueryTexture(texture[6], NULL, NULL, &(position.w), &(position.h));
			SDL_RenderCopy(renderer, texture[6], NULL, &position);

			Stexte[6]= TTF_RenderText_Blended(police2,c3, couleurJaune);
			texture[6]=SDL_CreateTextureFromSurface(renderer, Stexte[6]); 
			position.x =920; position.y = 125;
			SDL_RenderCopy(renderer, texture[6], NULL, &position);

			// ******************************

			SDL_RenderCopy(renderer, texture[0], NULL, &imgDestRect);
			
			SDL_RenderCopy(renderer, texture[7], NULL, &entree); // bouton entree
						
		    SDL_RenderPresent(renderer);
  	 // }
   }
   
    if(temp!=VRAI)/** on quite la page, mais on reste dans le jeu **/
    
    	continuer=FAUX;

	liberation_ressourcesTTF(police1,police2);
	
	liberation_ressourcesTexture(texture);/** libérer des textures **/
	
	liberation_ressourcesSurface(Stexte);
	
	SDL_FreeSurface(image); 
	SDL_FreeSurface(image2); 
 
	TTF_Quit();
	printf(" je sort part la générique .................\n");
    return EXIT_SUCCESS;
}




