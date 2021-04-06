
 
#include "fonction.h"

int jeu1(SDL_Window * window,SDL_Renderer *renderer)
{
	SDL_Rect dest_rect     = {0,200,1500,600};

    SDL_Surface *bas[4];
    SDL_Surface *haut[4];
    SDL_Surface *gauche[4];
    SDL_Surface *droite[4];
    
    SDL_Surface* texte1=NULL;
    
    int l=0; //compteur de position chemin
    int g,d,h,b; // compteur defilement image direction
   		g = d = h = b = 1;
	
    int temp_actuel = 0;
    int temp_precedent = 0;
    
    point.x = departX;  //0
    point.y = departY; //535;
    
    SDL_Rect pSerp;
    pSerp.x=  100;
    pSerp.y=  580;

    int chemin_aller[TAILLE];

    chargement_cheminA_1(chemin_aller,TAILLE);

    // **** affichage 
    
    SDL_Color couleurJaune = {250,234,115};
    TTF_Init();
    police1 = NULL;
    police1 = TTF_OpenFont("image/JMH Typewriter.ttf", 30);// police et taille de la police
    
    int temps=0;
    char c1[10];

    positionTemps.x =100; 
    positionTemps.y = 30;
    
    arrierePlan1 = arrierePlan2 = arrierePlan3 = NULL;
    
	arrierePlan1 = IMG_Load("image/paysage_dem.png");
	if(arrierePlan1==NULL)
	{	liberation_ressources(window,NULL,NULL, NULL);	message_erreurs("Chargement image [arrierePlan1]"); }
	
	arrierePlan2 = IMG_Load("image/paysage_dem.png");
	arrierePlan3 = IMG_Load("image/paysage_dem.png");
	 
	bas[1] =IMG_Load("image/duck.png"); 
	if(bas[1]==NULL)
	{	liberation_ressources(window,NULL,NULL, NULL);	message_erreurs("Chargement image [ bas[1] ]"); }
		
	bas[2] = IMG_Load("image/S2.png");
	if(bas[2]==NULL)
	{	liberation_ressources(window,NULL,NULL, NULL);message_erreurs("Chargement image [bas[2]]"); }
	
	bas[3] = IMG_Load("image/duck.png");

	haut[1] = IMG_Load("image/duck.png");
	if(haut[1]==NULL)
	{	liberation_ressources(window,NULL,NULL, NULL);	message_erreurs("Chargement image [ haut[1] ]"); }
	
	haut[2] = IMG_Load("image/duck.png");
	haut[3] = IMG_Load("image/duck.png");

	droite[1] = IMG_Load("image/duck.png");
	if(droite[1]==NULL)
	{	liberation_ressources(window,NULL,NULL, NULL);	message_erreurs("Chargement image [ droite[1] ]"); }
	
	droite[2] = IMG_Load("image/duck.png");
	droite[3] = IMG_Load("image/duck.png");

	gauche[1] = IMG_Load("image/duck.png");
	if(gauche[1]==NULL)
	{	liberation_ressources(window,NULL,NULL, NULL);	message_erreurs("Chargement image [ gauche[1] ]"); }
	gauche[2] = IMG_Load("image/duck.png");
	gauche[3] = IMG_Load("image/duck.png");
  
  	win_surf=NULL;
	win_surf = SDL_GetWindowSurface(window);
 	
 	continuer = FAUX;//0
 	int saut=0;
 	int nb=0;
 	
	while (!continuer)
	{
		temps+= (SDL_GetTicks()/1000) ;
		sprintf(c1, "%d" , temps);
		texte1 = TTF_RenderText_Blended(police1, c1, couleurJaune);
		
		SDL_FillRect(win_surf, NULL, SDL_MapRGB(win_surf->format,0, 0, 0));//font noir
		
		SDL_BlitSurface(texte1, NULL, win_surf, &positionTemps);
		SDL_BlitSurface (arrierePlan1, NULL,win_surf, &dest_rect );
		
		SDL_BlitSurface (bas[1], NULL, win_surf, &point);
		SDL_BlitSurface(bas[2], NULL, win_surf, &pSerp);
		
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
					case SDLK_UP:					// sauter *******************************

						temp_actuel = SDL_GetTicks();

						SDL_BlitSurface (arrierePlan1, NULL,win_surf, &dest_rect); // arrière plan
						SDL_BlitSurface(texte1, NULL, win_surf, &positionTemps);
 	
						SDL_BlitSurface(haut[h], NULL, win_surf, &point);
						if(h<=2)
							h++;
						else
							h=1;

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
/*
					case SDLK_DOWN:// mouvement  en bas

						for(i = 1; i<4; i++)
						{
							temp_actuel = SDL_GetTicks();

							if (temp_actuel - temp_precedent > 35)
							{
								SDL_BlitSurface (arrirePlan1, NULL,win_surf, &dest_rect); // arrière plan
								SDL_BlitSurface(bas[b], NULL, win_surf, &point);
								i++;
								if(b<4)
								b = 1;
								temp_precedent = temp_actuel;
							}
							point.y+=5;
						}
						texture
						break;
*/
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
					
					case SDLK_RIGHT: // droite 

						if (point.y==515)
						{
							point.y +=20;  saut=0;
						}
						if(point.x==longueur_ecran)
						
							point.x=departX;
							
						for( l=0; point.x != chemin_aller[l]; l++ );  //on recuprère la position de X
						
						printf("droite : d= %i l= %i, chemin_aller_H (%i , %i ) \n",d,l,chemin_aller[l],point.y);

						point.x = chemin_aller[++l];

						if(point.x == 640)

							point.y+= 35;

						if(point.x == 1300)

							point.y-= 35;
	 
						SDL_BlitSurface (arrierePlan1, NULL,win_surf, &dest_rect); // arrière plan
						SDL_BlitSurface(texte1, NULL, win_surf, &positionTemps);
 
						SDL_BlitSurface(droite[d], NULL, win_surf, &point);
						
						if(d<=2) //gestion du difilement d'images
							d ++;
						else
							d=1;
						
						SDL_BlitSurface(bas[2], NULL, win_surf, &pSerp);// à revoir

						break;	
				}	
		}
		 
		SDL_UpdateWindowSurface(window);//actualisation de la page.
    }

	// liberer uniquement les surfaces ouvertes dans la fonction 
	
	liberation_ressourcesSurface(arrierePlan1,arrierePlan2,arrierePlan3,bas[1],bas[2],bas[3]);
	liberation_ressourcesSurface(haut[1],haut[2],haut[3],gauche[1],gauche[2],gauche[3]);
 	liberation_ressourcesSurface(droite[1],droite[2],droite[3],texte1,NULL,NULL);
 
    return EXIT_SUCCESS;
}








