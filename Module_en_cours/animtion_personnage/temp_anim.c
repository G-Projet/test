
#include <unistd.h> 
#include "init.h"
 
int main (int argc, char *argv[])
{

    SDL_Window *window = NULL;
    SDL_Surface *win_surf;
    SDL_Surface *arrierePlan1=NULL,*arrierePlan2=NULL,*arrierePlan3=NULL;
    SDL_Event event;
    
    SDL_Surface *bas[4];
    SDL_Surface *haut[4];
    SDL_Surface *gauche[4];
    SDL_Surface *droite[4];
    SDL_Surface* texte1=NULL;
    
    SDL_Rect point, position, positionTemps;
    
    int quit = 0;
    int i = 1;
    int l = 0 ;
    int j = 1;
    int k = 1;

    int temp_actuel = 0;
    int temp_precedent = 0;
    
    point.x = 0;  
    point.y = 535;

    int chemin_aller[TAILLE];

    cheminA_1(chemin_aller,TAILLE);
    	 
    int saut=0;

    // **** affichage 
    TTF_Font *police1 = NULL;
    SDL_Color couleurJaune = {250,234,115};
    TTF_Init();
    police1 = TTF_OpenFont("JMH Typewriter.ttf", 30);// police et taille de la police
    
    int temps=0;
    char c1[10];

    positionTemps.x =100; 
    positionTemps.y = 30;
 	
 	SDL_Rect r;
    r.x = 600; 
    r.y = 300; 
    r.w = 60;
    r.h = 60;

    
    window = SDL_CreateWindow
    (
        "DuckTales", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        1600,// taille horizontale
        800,// taille verticale
        SDL_WINDOW_SHOWN
    );
      
	arrierePlan1 = IMG_Load("image/paysage_dem.png");
	arrierePlan2 = IMG_Load("image/paysage_dem.png");
	arrierePlan3 = IMG_Load("image/paysage_dem.png");

	//SDL_PixelFormat* SDL_AllocFormat(Uint32 pixel_format)

	bas[1] =IMG_Load("image/duck.png"); 
	bas[2] = IMG_Load("image/duck.png");
	bas[3] = IMG_Load("image/duck.png");

	haut[1] = IMG_Load("image/duck.png");
	haut[2] = IMG_Load("image/duck.png");
	haut[3] = IMG_Load("image/duck.png");

	droite[1] = IMG_Load("image/duck.png");
	droite[2] = IMG_Load("image/duck.png");
	droite[3] = IMG_Load("image/duck.png");

	gauche[1] = IMG_Load("image/duck.png");
	gauche[2] = IMG_Load("image/duck.png");
	gauche[3] = IMG_Load("image/duck.png");
  
	win_surf = SDL_GetWindowSurface(window);

	
	SDL_BlitSurface (arrierePlan1, NULL,win_surf, &dest_rect ); // arrière plan = copie la photo sur l'ecran
	SDL_BlitSurface(texte1, NULL, win_surf, &positionTemps);
	SDL_BlitSurface (bas[1], NULL, win_surf, &point);// position de duck
 	
	while (!quit)
	{
		temps+= (SDL_GetTicks()/1000) ;
		sprintf(c1, "%d ." , temps);
		texte1= TTF_RenderText_Blended(police1, c1, couleurJaune);

		SDL_BlitSurface(texte1, NULL, win_surf, &positionTemps);
		

		//SDL_PollEvent(&event);
		SDL_WaitEvent(&event);
		
		switch(event.type)
		{
		    case SDL_QUIT:
		    quit = 1;
		    break;

				// gestion de la souris 

				printf(" %d | %d \n",event.motion.x,event.motion.y);
				break;
				
			case SDL_MOUSEBUTTONDOWN: // gestion coordonnées de la souris 
 
				if(event.button.button==SDL_BUTTON_RIGHT)//SDL_BUTTON_LEFT|MIDOLE
					printf("Clic droit \n");
				printf(" clic en %d | %d \n",event.button.x,event.button.y);
				break;
					

			case SDL_KEYDOWN:// entrée clavier

				switch (event.key.keysym.sym)
				{
					case SDLK_UP:// sauter *******************************

						 	temp_actuel = SDL_GetTicks();

							if (temp_actuel - temp_precedent > 35)// /1000(millième de secondes)
							{
								SDL_BlitSurface (arrierePlan1, NULL,win_surf, &dest_rect); // arrière plan
							
								SDL_BlitSurface(haut[j], NULL, win_surf, &point);
								j++;
								if(j<4)
									j = 1;
								temp_precedent = temp_actuel;

							}

							printf(" chemin_aller_H (%i , %i ) \n",chemin_aller[l],point.y);

							if(saut==0) // pour verouiller le nombre de saut
							{
								point.y -=20;
								saut++;
							}
							break;
							
					/*case SDLK_DOWN:// mouvement  en bas
					
						for(i = 1; i<4; i++)
						{
							temp_actuel = SDL_GetTicks();

							if (temp_actuel - temp_precedent > 35)
							{
								SDL_BlitSurface (arrirePlan1, NULL,win_surf, &dest_rect); // arrière plan
								SDL_BlitSurface(bas[i], NULL, win_surf, &point);
								i++;
								if(i<4)
									i = 1;
								temp_precedent = temp_actuel;
							}
							point.y+=5;
						}
						break;
					*/
					case SDLK_LEFT: // // mouvement en arrière(gauche )
						 
						 if (point.y==515)

						 	point.y +=20;

						 for( l=TAILLE; point.x != chemin_aller[l]; l-- );  //on recuprère la position de X

							temp_actuel = SDL_GetTicks();

							if (temp_actuel - temp_precedent > 65)
							{
								k++;
								if(k<4)
									k = 1;
									SDL_BlitSurface (arrierePlan1, NULL,win_surf, &dest_rect); // arrière plan
									
									SDL_BlitSurface(gauche[k], NULL, win_surf, &point);
									temp_precedent = temp_actuel;
							}

							printf(" chemin_aller_H (%i , %i ) \n",chemin_aller[l],point.y);

							point.x = chemin_aller[--l];

							if(point.x == 640)

								point.y-= 35;

							if(point.x == 1300)

								point.y+= 35;

							saut=0;

						break;
				
					case SDLK_RIGHT: // droite 

						if (point.y==515)

						 	point.y +=20;

						for( l=0; point.x != chemin_aller[l]; l++ );  //on recuprère la position de X
						 
							 i=1;
							temp_actuel = SDL_GetTicks();
							
							if (temp_actuel - temp_precedent > 35)
							{
								SDL_BlitSurface (arrierePlan1, NULL,win_surf, &dest_rect); // arrière plan
								
								SDL_BlitSurface(droite[i++], NULL, win_surf, &point);

								if(i<4)
									i = 1;
								temp_precedent = temp_actuel;
							}

							printf(" chemin_aller_H (%i , %i ) \n",chemin_aller[l],point.y);

								point.x = chemin_aller[++l];

								if(point.x == 640)

									point.y+= 35;

								if(point.x == 1300)

									point.y-= 35;
							saut=0;
						break;
					}	
			}
		 
			SDL_UpdateWindowSurface(window);//actualisation de la page.
    	}

    SDL_FreeSurface(texte1);

    SDL_FreeSurface(arrierePlan1);
    SDL_FreeSurface(arrierePlan2);
    SDL_FreeSurface(arrierePlan3);

    SDL_FreeSurface(bas[1]); SDL_FreeSurface(bas[2]); SDL_FreeSurface(bas[3]);
    SDL_FreeSurface(haut[1]);SDL_FreeSurface(haut[2]);SDL_FreeSurface(haut[3]);
    SDL_FreeSurface(gauche[1]);SDL_FreeSurface(gauche[2]);SDL_FreeSurface(gauche[3]);
    SDL_FreeSurface(droite[1]);SDL_FreeSurface(droite[2]);SDL_FreeSurface(droite[3]);
    
    SDL_DestroyWindow(window);
 
    SDL_Quit();
    return (0);
}







