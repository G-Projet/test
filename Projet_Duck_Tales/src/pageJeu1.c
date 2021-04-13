
/**
*\file pageJeu1.c 
*\brief Fichier contenant le fonction de la 1er page du jeu
*\author Belkadi Smail
*\version 2.0
*\date 07 avril 2021
**/
 
#include "fonction.h"

/**
*\brief La fonction qui lance le jeu
**/

extern 
int jeu1(SDL_Window * window, SDL_Renderer *renderer)
{
	SDL_Surface *pSurf;  
	
	SDL_Rect dest_rect = {0,200,1500,600};
 	
    SDL_Surface *imgBas[tailleSurface]  ; /** tableau de surface comptenant les photos du joueur **/
	SDL_Surface *imgHaut[tailleSurface]  ;
	SDL_Surface *imgGauche[tailleSurface];
	SDL_Surface *imgDroit[tailleSurface];
	SDL_Surface *imgObstacle[tailleSurface];
	
    for(i=0;i<tailleSurface;i++)
    {
		imgBas[i]=NULL;
		imgHaut[i]=NULL;
		imgGauche[i]=NULL;
		imgDroit[i]=NULL;	
		imgObstacle[i]=NULL;
    }
 
 	for (i=0;i<tailleSurface;i++)   
 		Stexte[i]=NULL;
  
    int temp_actuel = 0; /** initialisation des variables de la gestion **/
    int temp_precedent = 0;
    
    point.x = departX; /** initialisation des coordonnées de départ du joueur **/
    point.y = departY; //535;
    
    SDL_Rect pSerp,pScord, eScord,eTemps,cQuit;
    
    pSerp.x=  300; /** initialisation des coordonnées du serpent **/
    pSerp.y=  535;
    
    scord = 0;/** initialisation des coordonnées du temps **/
    
    pScord.x=  1500;
    pScord.y=  30;
    
    eScord.x = 1400; /** initialisation des coordonnées du scord **/
    eScord.y = 30;
    
    cQuit.x=700;
    cQuit.y=720;

    int chemin_aller[TAILLE];

	//tabPoint[5]={0,0,0,0,0};//{130,170,180,500,510}; /** initialisation du tableau des points **/
	
	int tabPoint[taillePoint]={130,170,180,500,510};
	
	for (i=0; i<taillePoint	;i++) /**  teste tableau **/
	
		printf("  tabPoint[%i] = %i  ******** \n",i, tabPoint[i]);
		
	
    chargement_cheminA_1(chemin_aller,TAILLE);

    // **** affichage 
    
    SDL_Color couleurJaune = {250,234,115};
    
    TTF_Init();
    
    police1 = NULL;
    police1 = TTF_OpenFont("image/JMH Typewriter.ttf", 20);// police et taille de la police
    police2=NULL;
    police2 = TTF_OpenFont("image/JMH Typewriter.ttf", 30);// police et taille de la police
     
    int temps=0;
    char c1[10];
    char c2[10]; 
    char c3[10];
    char c4[10]; 
	
	eTemps.x=40;
	eTemps.y=30;
	
    positionTemps.x =120; 
    positionTemps.y = 30;
    
    /** gestion arrière plans **/
    int pl = 1; /** vaiable de defilement des plans **/
    
 	/** tableau surface arrière plan **/
    for(i=0;i<tailleSurface;i++)   //arrierePlan[0] == quitter
    	arrierePlan[i]=NULL;
	
	
	arrierePlan[1] = IMG_Load("image/paysage_dem.png");
	arrierePlan[2]= IMG_Load("image/paysage11.png");
	arrierePlan[3] = IMG_Load("image/imag_F5.png");
	arrierePlan[4] = IMG_Load("image/imag_F12.png");
	
	arrierePlan[0] = IMG_Load("image/exit1.jpg");/** arrière plan quitter **/ 
	
	for(i=0;i<=4;i++)   //arrierePlan[0] == quitter
		if (arrierePlan[i]== NULL)
			{	liberation_ressources(window,NULL,NULL, NULL);	message_erreurs("Chargement image [arrierePlan]"); }

	// bas 
	
	imgBas[0] = IMG_Load("image/duck.png");
	imgBas[1] = IMG_Load("image/bas1.png");
	
	for(i=0;i<=1;i++)
		if(imgBas[0]==NULL)
			{	liberation_ressources(window,NULL,NULL, NULL);	message_erreurs("Chargement image : "); 
				printf(" \t imgBas[%i] \n",i);
			}
	
	//Mettre en transeparent le fond de personnage
	SDL_SetColorKey(imgBas[0], SDL_TRUE, SDL_MapRGB(imgBas[0]->format, 222, 222, 98));
	SDL_SetColorKey(imgBas[1], SDL_TRUE, SDL_MapRGB(imgBas[1]->format, 222, 222, 98));
	
	
	/** Chargement images obstacle **/
	
	imgObstacle[0] = IMG_Load("image/arbre.png");
	SDL_SetColorKey(imgObstacle[0], SDL_TRUE, SDL_MapRGB(imgObstacle[0]->format, 80, 240, 240));
	
	/** fin obstacle **/
	
	// haut 
	
	imgHaut[0] = IMG_Load("image/duck.png");
	imgHaut[1] = IMG_Load("image/duck.png");
	imgHaut[2] = IMG_Load("image/duck.png");
	
	for(i=0;i<=2;i++)
		if(imgHaut[i]==NULL)
		{	liberation_ressources(window,NULL,NULL, NULL);	message_erreurs(" Chargement image : "); 
			printf(" \t imgHaut[%i] \n",i);}
	
	SDL_SetColorKey(imgHaut[0], SDL_TRUE, SDL_MapRGB(imgHaut[0]->format, 222, 222, 98));
	SDL_SetColorKey(imgHaut[1], SDL_TRUE, SDL_MapRGB(imgHaut[1]->format, 222, 222, 98));
	SDL_SetColorKey(imgHaut[2], SDL_TRUE, SDL_MapRGB(imgHaut[2]->format, 222, 222, 98));

	
	// droite:

	imgDroit[0] = IMG_Load("image/vers_droit0.png");
	imgDroit[1] = IMG_Load("image/vers_droit1.png");
	imgDroit[2] = IMG_Load("image/vers_droit2.png");
	imgDroit[3] = IMG_Load("image/vers_droit3.png");
	imgDroit[4] = IMG_Load("image/vers_droit4.png");
	imgDroit[5] = IMG_Load("image/vers_droit5.png");
	imgDroit[6] = IMG_Load("image/vers_droit6.png");
	
	for(i=0;i<7;i++)
		if(imgDroit[i]==NULL)
		{	liberation_ressources(window,NULL,NULL, NULL);	message_erreurs("Chargement image : "); 
				printf(" \t imgDroit[%i] \n",i);
		}
			
	SDL_SetColorKey(imgDroit[0], SDL_TRUE, SDL_MapRGB(imgDroit[0]->format, 222, 222, 98));
	SDL_SetColorKey(imgDroit[1], SDL_TRUE, SDL_MapRGB(imgDroit[1]->format, 222, 222, 98));
	SDL_SetColorKey(imgDroit[2], SDL_TRUE, SDL_MapRGB(imgDroit[2]->format, 222, 222, 98));
	SDL_SetColorKey(imgDroit[3], SDL_TRUE, SDL_MapRGB(imgDroit[3]->format, 222, 222, 98));
	SDL_SetColorKey(imgDroit[4], SDL_TRUE, SDL_MapRGB(imgDroit[4]->format, 222, 222, 98));
	SDL_SetColorKey(imgDroit[5], SDL_TRUE, SDL_MapRGB(imgDroit[5]->format, 222, 222, 98));
	SDL_SetColorKey(imgDroit[6], SDL_TRUE, SDL_MapRGB(imgDroit[6]->format, 222, 222, 98));
 	
 	// gauche 
 	
 	imgGauche[0] = IMG_Load("image/vers_gauche0.png");
 	imgGauche[1] = IMG_Load("image/vers_gauche1.png");
 	imgGauche[2] = IMG_Load("image/vers_gauche2.png");
 	imgGauche[3] = IMG_Load("image/vers_gauche3.png");
 	imgGauche[4] = IMG_Load("image/vers_gauche4.png");
 	imgGauche[5] = IMG_Load("image/vers_gauche5.png");
 	imgGauche[6] = IMG_Load("image/vers_gauche6.png");
 	
	for(i=0;i<7;i++)
		if(imgGauche[0]==NULL)
		{	liberation_ressources(window,NULL,NULL, NULL);	message_erreurs("Chargement image : ");
			printf(" \t imgGauche[%i] \n",i);
		}
			
	SDL_SetColorKey(imgGauche[0], SDL_TRUE, SDL_MapRGB(imgGauche[0]->format, 222, 222, 98));
	SDL_SetColorKey(imgGauche[1], SDL_TRUE, SDL_MapRGB(imgGauche[1]->format, 222, 222, 98));
	SDL_SetColorKey(imgGauche[2], SDL_TRUE, SDL_MapRGB(imgGauche[2]->format, 222, 222, 98));
	SDL_SetColorKey(imgGauche[3], SDL_TRUE, SDL_MapRGB(imgGauche[3]->format, 222, 222, 98));
	SDL_SetColorKey(imgGauche[4], SDL_TRUE, SDL_MapRGB(imgGauche[4]->format, 222, 222, 98));
	SDL_SetColorKey(imgGauche[5], SDL_TRUE, SDL_MapRGB(imgGauche[5]->format, 222, 222, 98));
	SDL_SetColorKey(imgGauche[6], SDL_TRUE, SDL_MapRGB(imgGauche[6]->format, 222, 222, 98));
	
  	win_surf=NULL;
	win_surf = SDL_GetWindowSurface(window);
 	
 	SDL_FillRect(win_surf, NULL, SDL_MapRGB(win_surf->format,0, 0, 0));/** actualisation du font(noir) **/
 	 
 	int saut=0;
 	int nb=0;
 	int l=0; //compteur de position chemin
    int g,d,h,b; // compteur defilement image direction
  	g = b = 1;
   	h = d = 0;
   	
   	continuer = FAUX;//0
   	temp=FAUX;
   	
	while (!continuer)
	{
		SDL_FillRect(win_surf, NULL, SDL_MapRGB(win_surf->format,0, 0, 0));//font noir
		/** temps **/
		temps+= (SDL_GetTicks()/1000) ;
		sprintf(c1, "%d" , temps);
		Stexte[0] = TTF_RenderText_Blended(police1, c1, couleurJaune);//init surface temps
		Stexte[1] = TTF_RenderText_Blended(police1, "temps : ", couleurJaune);
		SDL_BlitSurface(Stexte[0], NULL, win_surf, &positionTemps); // surface temps
		SDL_BlitSurface(Stexte[1], NULL, win_surf, &eTemps);
		
		/** points **/
		sprintf(c3, "%d" , scord);
		Stexte[3] = TTF_RenderText_Blended(police1,c3, couleurJaune); // init surface scord
		Stexte[4] = TTF_RenderText_Blended(police1, "scord : ", couleurJaune);
		SDL_BlitSurface(Stexte[3], NULL, win_surf, &pScord); // surface scord
		SDL_BlitSurface(Stexte[4], NULL, win_surf, &eScord); // surface scord
		
		/** arrière plans 1  **/
		
		SDL_BlitSurface (arrierePlan[pl], NULL,win_surf, &dest_rect); // arrière plan
			
		/** obstacle **/
		SDL_BlitSurface(imgObstacle[0], NULL, win_surf, &pSerp);// surface obstacle
		
		/** joueur **/
		SDL_BlitSurface (imgDroit[0], NULL, win_surf, &point);// surface joueur
		
		/** arrière plan quitter **/
		SDL_BlitSurface (arrierePlan[0], NULL,win_surf, &cQuit);//surface quitter (exit)
		
		//SDL_PollEvent(&event);
		SDL_WaitEvent(&event);
														 
		switch(event.type) 
		{
		    case SDL_QUIT:
		    	 printf(" arrêt inopiné : Page Jeu1...........\n");
		    	 temp=VRAI;
				 continuer = VRAI;
				 break;

			case SDL_MOUSEMOTION: /** gestion coordonnées de la souris **/
					//event.motion.xrel || yrel (position relative)
					printf(" %d | %d \n",event.motion.x,event.motion.y);
					break;
					
					//5 = largeur bouton = longueur bouton
				
			case SDL_MOUSEBUTTONUP: /** gestion menu **/
			
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					if(event.button.x > 700 && event.button.x < 
						800 && event.button.y > 720 && event.button.y < 770)/** joueur **/ 
					{
						menu(window,renderer);
					} 
				}
				break;
													
			case SDL_KEYDOWN:// entrée clavier

				switch (event.key.keysym.sym)
				{
					case SDLK_a:						
							continuer = VRAI;						
							break; 
							
					case SDLK_UP: /** mouvement vers le haut **/

						temp_actuel = SDL_GetTicks();

						/** gestion arrière plans **/ 
						
						SDL_BlitSurface (arrierePlan[pl], NULL,win_surf, &dest_rect); // arrière plan
							
						//..................................
						
						SDL_BlitSurface(Stexte[0], NULL, win_surf, &positionTemps);
						SDL_BlitSurface(Stexte[3], NULL, win_surf, &pScord); // surface scord
						
						SDL_BlitSurface(imgHaut[h], NULL, win_surf, &point);
						SDL_BlitSurface(imgObstacle[0], NULL, win_surf, &pSerp);// surface obstacle
						
						if(h<=2)
							h++;
						else
							h=0;

						printf("saut : s = %d chemin_aller_H (%i , %i ) \n",h,chemin_aller[l],point.y);

						//if(saut==0 ) // pour verouiller le nombre de saut
						//{
							point.y -=160;
							//saut++;

							nb++;
						//}

						if(nb==2)
						{
							point.y +=320;
							nb=0;
						}

						break;			
 
					case SDLK_DOWN:// mouvement vers le ******************** bas
					
						/** gestion arrière plans **/ 
						SDL_BlitSurface (arrierePlan[pl], NULL,win_surf, &dest_rect); // arrière plan
 
 						SDL_BlitSurface(Stexte[0], NULL, win_surf, &positionTemps);
						SDL_BlitSurface(Stexte[3], NULL, win_surf, &pScord); // surface scord
						
						SDL_BlitSurface(imgBas[1], NULL, win_surf, &point);
						SDL_BlitSurface(imgObstacle[0], NULL, win_surf, &pSerp);// surface obstacle
							
						break;
 
					case SDLK_LEFT: // // mouvement en arrière(gauche )

						if (point.y==515)
						{
							point.y +=20; saut=0;
						}	
						if(point.x==departX)

							point.x=departX;

						else
						{
							//on recuprère la position de X
							for( l=TAILLE; point.x != chemin_aller[l]; l-- );  

							printf("gauche : g = %d chemin_aller_H (%i , %i ) \n",g,chemin_aller[l],point.y);

							point.x = chemin_aller[--l];

							if(point.x == 640)

							point.y-= 35;

							if(point.x == 1300)

							point.y+= 35;
						}
						
						/** gestion arrière plans **/ 
						
						SDL_BlitSurface (arrierePlan[pl], NULL,win_surf, &dest_rect); // arrière plan
						
						SDL_BlitSurface(Stexte[0], NULL, win_surf, &positionTemps);
						SDL_BlitSurface(Stexte[3], NULL, win_surf, &pScord); // surface scord
 					 
						SDL_BlitSurface(imgGauche[g], NULL, win_surf, &point);
						SDL_BlitSurface(imgObstacle[0], NULL, win_surf, &pSerp);// surface obstacle
						
						if(g<=2)
							g++;
						else
							g=1;

						break;
					
					case SDLK_RIGHT: // ********************** droite 

						if(pl==1)
						{
							if (point.y==515)
							{
								point.y +=15;  saut=0;
							}
						}
						if(point.x==longueur_ecran)
						
							point.x=departX;
							
						for( l=0; point.x != chemin_aller[l]; l++ );  //on recuprère la position de X

						point.x = chemin_aller[++l];
						
						for( l=0; l<taillePoint && point.x != tabPoint[l]; l++ );/** géstion des points **/
						
							if(tabPoint[l] == point.x)
							{
								printf(" tabPoint[%i] = %i , point.x = %i \n",l,tabPoint[l],point.x);
								scord++;
							}
							
						/** gestion arrierePlan[1] **/
						
						if(pl==1)
						{
							if(point.x == 640) point.y+= 35;
							if(point.x == 1300) point.y-= 35;
						}
					 
						/** gestion arrierePlan[2] **/
						if(pl==2)
						{
							if(point.x == 1340) point.y+= 35;
						}
						/** gestion arrierePlan[3] **/
						
						if(pl==3)
						{	
							if(point.x == 560) point.y-= 40;
							if(point.x == 650) point.y-= 40;						
							if(point.x == 780) point.y+= 40;						
							if(point.x == 880) point.y+= 40;	
							if(point.x == 1070) point.y-= 40;		
							if(point.x == 1170) point.y-= 40;	
							if(point.x == 1300) point.y+= 40;	
							if(point.x == 1400) point.y+= 40;
							
						}
						/** gestion arrierePlan[4] **/
						
						if(pl==4)
						{		
							if(point.x == 900) point.y-= 40;		
							if(point.x == 1110) point.y-= 40;	
							if(point.x == 1330) point.y-= 40;	
							if(point.x == 1550) point.y-= 40;
						}
						
						printf(" point.x = %i, point.y = %i \n", point.x,point.y);
						/** gestion arrière plans **/ 
						
	 					if(point.x < 1600)
	 					{	printf("1- je suis la arrierePlan[%i]\n",pl);
							SDL_BlitSurface (arrierePlan[pl], NULL,win_surf, &dest_rect); // arrière plan	
						}
						else
							if(pl==1 )
								pl = 2;
							else 
								if(pl==2)
									pl=3;
								else
									if(pl==3)
										pl=4;
									else
									{
										pl=1;
										point.x=departX;
										point.y=departY;
									}

 						SDL_BlitSurface(Stexte[0], NULL, win_surf, &positionTemps);
 						SDL_BlitSurface(Stexte[3], NULL, win_surf, &pScord); // surface scord
 						/** affichage obstacle **/
						SDL_BlitSurface(imgObstacle[0], NULL, win_surf, &pSerp);
 						
 						if(d<7)//gestion du difilement d'images			
							SDL_BlitSurface(imgDroit[d++], NULL, win_surf, &point);	
						else
							d=0;/** remise à zéro du compteur d'images **/
							
						break;	
				}	
				
			default:
					break;
		}
		 
		SDL_UpdateWindowSurface(window);//actualisation de la page.	
    }
    
    if(temp==FAUX)
    
		continuer=FAUX;
  
    liberation_ressourcesSurface(imgBas);/** libération des surfaces  **/
    liberation_ressourcesSurface(imgHaut);
    liberation_ressourcesSurface(imgGauche);
    liberation_ressourcesSurface(imgDroit);
    liberation_ressourcesSurface(imgObstacle);
  
    liberation_ressourcesSurface(Stexte);
 
 	for(i=0;i<tailleSurface;i++)
 	 if( arrierePlan[i]!= NULL )
 	 	SDL_FreeSurface(arrierePlan[i]);

	SDL_FreeSurface(win_surf);
	
	TTF_Quit();
	
    return EXIT_SUCCESS;
}








