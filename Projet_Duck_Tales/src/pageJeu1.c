

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
int jeu1(SDL_Window * window,SDL_Renderer *renderer)
{
	SDL_Rect dest_rect = {0,200,1500,600};
 
    SDL_Surface *bas[tailleS]  ; /** tableau de surface comptenant les photos du joueur **/
	SDL_Surface *haut[tailleS]  ;
	SDL_Surface *gauche[tailleS];
	SDL_Surface *droite[tailleS];
	
    int i=0;
    for(i=0;i<tailleS;i++)
    {
		bas[i]=NULL;
		haut[i]=NULL;
		gauche[i]=NULL;
		droite[i]=NULL;	
    }
 
    SDL_Surface *texte1 = NULL,*texte2 = NULL;
 	
    int temp_actuel = 0; /** initialisation des variables de la gestion **/
    int temp_precedent = 0;
    
    point.x = departX; /** initialisation des coordonnées de départ du joueur **/
    point.y = departY; //535;
    
    SDL_Rect pSerp,pScord, eScord,eTemps;
    
    pSerp.x=  300; /** initialisation des coordonnées du serpent **/
    pSerp.y=  535;
    
    int scord= 0;
    pScord.x=  1500;
    pScord.y=  30;
    
    eScord.x = 1400;
    eScord.y = 30;

    int chemin_aller[TAILLE];

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
    
    arrierePlan1 = arrierePlan2 = arrierePlan3 = NULL;
    
	//arrierePlan1 = IMG_Load("image/paysage_dem.png");
	arrierePlan1 = IMG_Load("image/paysage11.png");
	
	if(arrierePlan1==NULL)
	{	liberation_ressources(window,NULL,NULL, NULL);	message_erreurs("Chargement image [arrierePlan1]"); }
	
	arrierePlan2 = IMG_Load("image/paysage_dem.png");
	arrierePlan3 = IMG_Load("image/paysage_dem.png");
	
	// bas 
	
	bas[0] = IMG_Load("image/duck.png"); 
	if(bas[0]==NULL)
	{	liberation_ressources(window,NULL,NULL, NULL);	message_erreurs("Chargement image [ bas[1] ]"); }
	//Mettre en transeparent le fond de personnage
	SDL_SetColorKey(bas[0], SDL_TRUE, SDL_MapRGB(bas[0]->format, 222, 222, 98));
	
	bas[1] = IMG_Load("image/bas1.png");
	SDL_SetColorKey(bas[1], SDL_TRUE, SDL_MapRGB(bas[1]->format, 222, 222, 98));
	
	bas[2] = IMG_Load("image/arbre.png");
	SDL_SetColorKey(bas[2], SDL_TRUE, SDL_MapRGB(bas[2]->format, 80, 240, 240));
	
	// haut 
	
	haut[0] = IMG_Load("image/duck.png");
	if(haut[0]==NULL)
	{	liberation_ressources(window,NULL,NULL, NULL);	message_erreurs("Chargement image [ haut[1] ]"); }
	SDL_SetColorKey(haut[0], SDL_TRUE, SDL_MapRGB(haut[0]->format, 222, 222, 98));
	
	haut[1] = IMG_Load("image/duck.png");
	SDL_SetColorKey(haut[1], SDL_TRUE, SDL_MapRGB(haut[1]->format, 222, 222, 98));
	
	haut[2] = IMG_Load("image/duck.png");
	SDL_SetColorKey(haut[2], SDL_TRUE, SDL_MapRGB(haut[2]->format, 222, 222, 98));

	
	// droite:

	droite[0] = IMG_Load("image/vers_droit0.png");
	if(droite[0]==NULL)
	{	liberation_ressources(window,NULL,NULL, NULL);	message_erreurs("Chargement image [ droite[1] ]"); }
	SDL_SetColorKey(droite[0], SDL_TRUE, SDL_MapRGB(droite[0]->format, 222, 222, 98));

	droite[1] = IMG_Load("image/vers_droit1.png");
	SDL_SetColorKey(droite[1], SDL_TRUE, SDL_MapRGB(droite[1]->format, 222, 222, 98));
	 
	droite[2] = IMG_Load("image/vers_droit2.png");
	SDL_SetColorKey(droite[2], SDL_TRUE, SDL_MapRGB(droite[2]->format, 222, 222, 98));
	
	droite[3] = IMG_Load("image/vers_droit3.png");
	SDL_SetColorKey(droite[3], SDL_TRUE, SDL_MapRGB(droite[3]->format, 222, 222, 98));
	
	droite[4] = IMG_Load("image/vers_droit4.png");
	SDL_SetColorKey(droite[4], SDL_TRUE, SDL_MapRGB(droite[4]->format, 222, 222, 98));
	
	droite[5] = IMG_Load("image/vers_droit5.png");
	SDL_SetColorKey(droite[5], SDL_TRUE, SDL_MapRGB(droite[5]->format, 222, 222, 98));
 
	
	droite[6] = IMG_Load("image/vers_droit6.png");
	SDL_SetColorKey(droite[6], SDL_TRUE, SDL_MapRGB(droite[6]->format, 222, 222, 98));
 	
 	// gauche 
 	
	gauche[0] = IMG_Load("image/vers_gauche0.png");
	if(gauche[0]==NULL)
	{	liberation_ressources(window,NULL,NULL, NULL);	message_erreurs("Chargement image [ gauche[1] ]"); }
	SDL_SetColorKey(gauche[0], SDL_TRUE, SDL_MapRGB(gauche[0]->format, 222, 222, 98));
 
	gauche[1] = IMG_Load("image/vers_gauche1.png");
	SDL_SetColorKey(gauche[1], SDL_TRUE, SDL_MapRGB(gauche[1]->format, 222, 222, 98));
	 
	gauche[2] = IMG_Load("image/vers_gauche2.png");
	SDL_SetColorKey(gauche[2], SDL_TRUE, SDL_MapRGB(gauche[2]->format, 222, 222, 98));
	
	gauche[3] = IMG_Load("image/vers_gauche3.png");
	SDL_SetColorKey(gauche[3], SDL_TRUE, SDL_MapRGB(gauche[3]->format, 222, 222, 98));
	
	gauche[4] = IMG_Load("image/vers_gauche4.png");
	SDL_SetColorKey(gauche[4], SDL_TRUE, SDL_MapRGB(gauche[4]->format, 222, 222, 98));
	
 	gauche[5] = IMG_Load("image/vers_gauche5.png");
	SDL_SetColorKey(gauche[5], SDL_TRUE, SDL_MapRGB(gauche[5]->format, 222, 222, 98));
  	
  	gauche[6] = IMG_Load("image/vers_gauche6.png");
	SDL_SetColorKey(gauche[6], SDL_TRUE, SDL_MapRGB(gauche[6]->format, 222, 222, 98));
	
  	win_surf=NULL;
  	
	win_surf = SDL_GetWindowSurface(window);
 	
 	continuer = FAUX;//0
 	
 	int saut=0;
 	int nb=0;
 	int l=0; //compteur de position chemin
    int g,d,h,b; // compteur defilement image direction
  	g = b = 1;
   	h = d = 0;
   		
	while (!continuer)
	{
		temps+= (SDL_GetTicks()/1000) ;
		sprintf(c1, "%d" , temps);
		texte1 = TTF_RenderText_Blended(police1, c1, couleurJaune);//init surface temps
		texte2 = TTF_RenderText_Blended(police1, "temps : ", couleurJaune);
		
		sprintf(c3, "%d" , scord);
		texte3 = TTF_RenderText_Blended(police1,c3, couleurJaune); // init surface scord
		texte4 = TTF_RenderText_Blended(police1, "scord : ", couleurJaune);
		
		SDL_FillRect(win_surf, NULL, SDL_MapRGB(win_surf->format,0, 0, 0));//font noir
		
		SDL_BlitSurface(texte1, NULL, win_surf, &positionTemps); // surface temps
		SDL_BlitSurface(texte2, NULL, win_surf, &eTemps);
		
		SDL_BlitSurface(texte3, NULL, win_surf, &pScord); // surface scord
		SDL_BlitSurface(texte4, NULL, win_surf, &eScord); // surface scord
		
		
		SDL_BlitSurface (arrierePlan1, NULL,win_surf, &dest_rect );//surface arrière plan
		
		SDL_BlitSurface (droite[0], NULL, win_surf, &point);// surface joueur
		
		SDL_BlitSurface(bas[2], NULL, win_surf, &pSerp);// surface serpend
		
		//SDL_PollEvent(&event);
		SDL_WaitEvent(&event);
		
		switch(event.type)
		{
		    case SDL_QUIT:
				continuer = VRAI;
				break;

				/*
			case SDL_MOUSEBUTTONDOWN: // gestion coordonnées de la souris 
 
				if(event.button.button==SDL_BUTTON_RIGHT)//SDL_BUTTON_LEFT|MIDOLE
					printf("Clic droit \n");
					printf(" %d | %d \n",event.motion.x,event.motion.y);
				printf(" clic en %d | %d \n",event.button.x,event.button.y);
				break;*/
 
			case SDL_KEYDOWN:// entrée clavier

				switch (event.key.keysym.sym)
				{
					case SDLK_UP: // mouvement vers le ******************************* haut

						temp_actuel = SDL_GetTicks();

						SDL_BlitSurface (arrierePlan1, NULL,win_surf, &dest_rect); // arrière plan
						SDL_BlitSurface(texte1, NULL, win_surf, &positionTemps);
 	
						SDL_BlitSurface(haut[h], NULL, win_surf, &point);
						
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
					
						SDL_BlitSurface (arrierePlan1, NULL,win_surf, &dest_rect); // arrière plan
 
						SDL_BlitSurface(bas[1], NULL, win_surf, &point);
							
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

						SDL_BlitSurface (arrierePlan1, NULL,win_surf, &dest_rect); // arrière plan
						SDL_BlitSurface(texte1, NULL, win_surf, &positionTemps);
 
						SDL_BlitSurface(gauche[g], NULL, win_surf, &point);
						
						if(g<=2)
							g++;
						else
							g=1;

						break;
					
					case SDLK_RIGHT: // ********************** droite 

						if (point.y==515)
						{
							point.y +=20;  saut=0;
						}
						if(point.x==longueur_ecran)
						
							point.x=departX;
							
						for( l=0; point.x != chemin_aller[l]; l++ );  //on recuprère la position de X

						point.x = chemin_aller[++l];

						if(point.x == 640)

							point.y+= 35;

						if(point.x == 1300)

							point.y-= 35;
	 
						SDL_BlitSurface (arrierePlan1, NULL,win_surf, &dest_rect); // arrière plan
						SDL_BlitSurface(texte1, NULL, win_surf, &positionTemps);
 
 						if(d<tailleS)//gestion du difilement d'images
 						{
 							printf("droite : d= %i l= %i, chemin_aller_H (%i , %i ) \n",d,l,chemin_aller[l],point.y);
							SDL_BlitSurface(droite[d++], NULL, win_surf, &point);
						}
						else
							d=0;
						
						SDL_BlitSurface(bas[2], NULL, win_surf, &pSerp);// à revoir

						break;	
				}	
				
			default:
					break;
		}
		 
		SDL_UpdateWindowSurface(window);//actualisation de la page.
    }

	// liberer uniquement les surfaces ouvertes dans la fonction 
	
	for(i=0;i<tailleS;i++)
    {
		SDL_FreeSurface(bas[i]);
		SDL_FreeSurface(haut[i]);
		SDL_FreeSurface(gauche[i]);
		SDL_FreeSurface(droite[i]);	
    }
    
    SDL_FreeSurface(texte1);
 	 
	liberation_ressourcesSurface(arrierePlan1,arrierePlan2,arrierePlan3,NULL,NULL,NULL);

    return EXIT_SUCCESS;
}








