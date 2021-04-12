

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
int jeu4(SDL_Window * window, SDL_Renderer *renderer)
{
	SDL_Surface *pSurf;
	
	SDL_Rect dest_rect;
	
	 	dest_rect.x=0;
	 	dest_rect.y=200;
	 	dest_rect.h=1600;
	 	dest_rect.w=0;
 	
    SDL_Surface *imagebas[tailleSurface]  ; /** tableau de surface comptenant les photos du joueur **/
	SDL_Surface *imagehaut[tailleSurface]  ;
	SDL_Surface *imagegauche[tailleSurface];
	SDL_Surface *imagedroite[tailleSurface];
	
    int i=0;
    for(i=0;i<tailleSurface;i++)
    {
		imagebas[i]=NULL;
		imagehaut[i]=NULL;
		imagegauche[i]=NULL;
		imagedroite[i]=NULL;	
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
    
    int scord= 0;/** initialisation des coordonnées du temps **/
    pScord.x=  1500;
    pScord.y=  30;
    
    eScord.x = 1400; /** initialisation des coordonnées du scord **/
    eScord.y = 30;
    
    cQuit.x=700;
    cQuit.y=720;

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
    
    arrierePlan1 = arrierePlanQ = NULL;
    
	//arrierePlan1 = IMG_Load("image/paysage_dem.png");
	//arrierePlan1 = IMG_Load("image/paysage11.png"); imag_F3.png
	
	arrierePlan1 = IMG_Load("image/imag_F12.png");
	if(arrierePlan1==NULL)
	{	liberation_ressources(window,NULL,NULL, NULL);	message_erreurs("Chargement image [arrierePlan1]"); }
	
	//arrierePlan2 = IMG_Load("image/paysage_dem.png");
	//arrierePlan3 = IMG_Load("image/paysage_dem.png");
	arrierePlanQ = IMG_Load("image/exit1.jpg");
	if(arrierePlanQ==NULL)
	{	liberation_ressources(window,NULL,NULL, NULL);	message_erreurs("Chargement image [arrierePlanQ]"); }
	
	// bas 
	
	imagebas[0] = IMG_Load("image/duck.png"); 
	if(imagebas[0]==NULL)
	{	liberation_ressources(window,NULL,NULL, NULL);	message_erreurs("Chargement image [ bas[1] ]"); }
	//Mettre en transeparent le fond de personnage
	SDL_SetColorKey(imagebas[0], SDL_TRUE, SDL_MapRGB(imagebas[0]->format, 222, 222, 98));
	
	imagebas[1] = IMG_Load("image/bas1.png");
	SDL_SetColorKey(imagebas[1], SDL_TRUE, SDL_MapRGB(imagebas[1]->format, 222, 222, 98));
	
	imagebas[2] = IMG_Load("image/arbre.png");
	SDL_SetColorKey(imagebas[2], SDL_TRUE, SDL_MapRGB(imagebas[2]->format, 80, 240, 240));
	
	// haut 
	
	imagehaut[0] = IMG_Load("image/duck.png");
	if(imagehaut[0]==NULL)
	{	liberation_ressources(window,NULL,NULL, NULL);	message_erreurs("Chargement image [ haut[1] ]"); }
	SDL_SetColorKey(imagehaut[0], SDL_TRUE, SDL_MapRGB(imagehaut[0]->format, 222, 222, 98));
	
	imagehaut[1] = IMG_Load("image/duck.png");
	SDL_SetColorKey(imagehaut[1], SDL_TRUE, SDL_MapRGB(imagehaut[1]->format, 222, 222, 98));
	
	imagehaut[2] = IMG_Load("image/duck.png");
	SDL_SetColorKey(imagehaut[2], SDL_TRUE, SDL_MapRGB(imagehaut[2]->format, 222, 222, 98));

	
	// droite:

	imagedroite[0] = IMG_Load("image/vers_droit0.png");
	if(imagedroite[0]==NULL)
	{	liberation_ressources(window,NULL,NULL, NULL);	message_erreurs("Chargement image [ droite[1] ]"); }
	SDL_SetColorKey(imagedroite[0], SDL_TRUE, SDL_MapRGB(imagedroite[0]->format, 222, 222, 98));

	imagedroite[1] = IMG_Load("image/vers_droit1.png");
	SDL_SetColorKey(imagedroite[1], SDL_TRUE, SDL_MapRGB(imagedroite[1]->format, 222, 222, 98));
	 
	imagedroite[2] = IMG_Load("image/vers_droit2.png");
	SDL_SetColorKey(imagedroite[2], SDL_TRUE, SDL_MapRGB(imagedroite[2]->format, 222, 222, 98));
	
	imagedroite[3] = IMG_Load("image/vers_droit3.png");
	SDL_SetColorKey(imagedroite[3], SDL_TRUE, SDL_MapRGB(imagedroite[3]->format, 222, 222, 98));
	
	imagedroite[4] = IMG_Load("image/vers_droit4.png");
	SDL_SetColorKey(imagedroite[4], SDL_TRUE, SDL_MapRGB(imagedroite[4]->format, 222, 222, 98));
	
	imagedroite[5] = IMG_Load("image/vers_droit5.png");
	SDL_SetColorKey(imagedroite[5], SDL_TRUE, SDL_MapRGB(imagedroite[5]->format, 222, 222, 98));
 
	
	imagedroite[6] = IMG_Load("image/vers_droit6.png");
	SDL_SetColorKey(imagedroite[6], SDL_TRUE, SDL_MapRGB(imagedroite[6]->format, 222, 222, 98));
 	
 	// gauche 
 	
	imagegauche[0] = IMG_Load("image/vers_gauche0.png");
	if(imagegauche[0]==NULL)
	{	liberation_ressources(window,NULL,NULL, NULL);	message_erreurs("Chargement image [ gauche[1] ]"); }
	SDL_SetColorKey(imagegauche[0], SDL_TRUE, SDL_MapRGB(imagegauche[0]->format, 222, 222, 98));
 
	imagegauche[1] = IMG_Load("image/vers_gauche1.png");
	SDL_SetColorKey(imagegauche[1], SDL_TRUE, SDL_MapRGB(imagegauche[1]->format, 222, 222, 98));
	 
	imagegauche[2] = IMG_Load("image/vers_gauche2.png");
	SDL_SetColorKey(imagegauche[2], SDL_TRUE, SDL_MapRGB(imagegauche[2]->format, 222, 222, 98));
	
	imagegauche[3] = IMG_Load("image/vers_gauche3.png");
	SDL_SetColorKey(imagegauche[3], SDL_TRUE, SDL_MapRGB(imagegauche[3]->format, 222, 222, 98));
	
	imagegauche[4] = IMG_Load("image/vers_gauche4.png");
	SDL_SetColorKey(imagegauche[4], SDL_TRUE, SDL_MapRGB(imagegauche[4]->format, 222, 222, 98));
	
 	imagegauche[5] = IMG_Load("image/vers_gauche5.png");
	SDL_SetColorKey(imagegauche[5], SDL_TRUE, SDL_MapRGB(imagegauche[5]->format, 222, 222, 98));
  	
  imagegauche[6] = IMG_Load("image/vers_gauche6.png");
	SDL_SetColorKey(imagegauche[6], SDL_TRUE, SDL_MapRGB(imagegauche[6]->format, 222, 222, 98));
	
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
		temps+= (SDL_GetTicks()/1000) ;
		sprintf(c1, "%d" , temps);
		Stexte[0] = TTF_RenderText_Blended(police1, c1, couleurJaune);//init surface temps
		Stexte[1] = TTF_RenderText_Blended(police1, "temps : ", couleurJaune);
		
		sprintf(c3, "%d" , scord);
		Stexte[3] = TTF_RenderText_Blended(police1,c3, couleurJaune); // init surface scord
		Stexte[4] = TTF_RenderText_Blended(police1, "scord : ", couleurJaune);
		
		SDL_FillRect(win_surf, NULL, SDL_MapRGB(win_surf->format,0, 0, 0));//font noir
		
		SDL_BlitSurface(Stexte[0], NULL, win_surf, &positionTemps); // surface temps
		SDL_BlitSurface(Stexte[2], NULL, win_surf, &eTemps);
		
		SDL_BlitSurface(Stexte[3], NULL, win_surf, &pScord); // surface scord
		SDL_BlitSurface(Stexte[4], NULL, win_surf, &eScord); // surface scord
		
		
		SDL_BlitSurface (arrierePlan1, NULL,win_surf, &dest_rect );//surface arrière plan
		
		SDL_BlitSurface (arrierePlanQ, NULL,win_surf, &cQuit);//surface arrière plan
		
		
		SDL_BlitSurface (imagedroite[0], NULL, win_surf, &point);// surface joueur
		SDL_BlitSurface(imagebas[2], NULL, win_surf, &pSerp);// surface serpend
		
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
							
					case SDLK_UP: // mouvement vers le ******************************* haut

						temp_actuel = SDL_GetTicks();

						SDL_BlitSurface (arrierePlan1, NULL,win_surf, &dest_rect); // arrière plan
						SDL_BlitSurface(Stexte[0], NULL, win_surf, &positionTemps);
 	
						SDL_BlitSurface(imagehaut[h], NULL, win_surf, &point);
						
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
 
						SDL_BlitSurface(imagebas[1], NULL, win_surf, &point);
							
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
						SDL_BlitSurface(Stexte[0], NULL, win_surf, &positionTemps);
 
						SDL_BlitSurface(imagegauche[g], NULL, win_surf, &point);
						
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
						SDL_BlitSurface(Stexte[0], NULL, win_surf, &positionTemps);
 
 						if(d<7)//gestion du difilement d'images
 						{
 							printf("droite : d= %i l= %i, chemin_aller_H (%i , %i )\n",d,l,chemin_aller[l],point.y);
 										
							SDL_BlitSurface(imagedroite[d++], NULL, win_surf, &point);
						}
						else
							d=0;
						
						SDL_BlitSurface(imagebas[2], NULL, win_surf, &pSerp);// à revoir

						break;	
				}	
				
			default:
					break;
		}
		
		printf(" je passe par la ................... \n");
		 
		SDL_UpdateWindowSurface(window);//actualisation de la page.	
    }
    
    if(temp==FAUX)
    
		continuer=FAUX;
  
    liberation_ressourcesSurface(imagebas);/** libération des surfaces  **/
    liberation_ressourcesSurface(imagehaut);
    liberation_ressourcesSurface(imagegauche);
    liberation_ressourcesSurface(imagedroite);
    
    liberation_ressourcesSurface(Stexte);
 
 	SDL_FreeSurface(arrierePlan1);
 	 
 	SDL_FreeSurface(arrierePlanQ); 
	SDL_FreeSurface(win_surf);
	
	TTF_Quit();
	
    return EXIT_SUCCESS;
}








