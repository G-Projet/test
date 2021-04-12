
/**
*\file affichage.c
*\brief Fichier contenant les fonctions utilisées dans le programme
*\author Belkadi Smail
*\version 2.0
*\date 07 avril 2021
**/

#include "fonction.h"

/** fonction qui affiche un mot de bienvenue **/

extern
void bienvenue()
{
	SDL_version nb;
	SDL_VERSION(&nb);
	
	system("clear");
	printf("\t********************************************************\n");
	printf("\t*    Bienvenus sur la platforme de jeux Duck_Tales     *  \n");
	printf("\t* \t \t SDL version : %d . %d . %d              *\n", nb.major, nb.minor, nb.patch );
	printf("\t********************************************************\n");	
	//sleep(1);
}

/**
*\brief La fonction qui renvoi un message d'erreurs
**/

extern
char message_erreurs(const char* message )
{
	fprintf(stderr, "ERREUR : %s >(%s)\n", message, SDL_GetError());
	SDL_Quit(); // On quitte la SDL
	return EXIT_FAILURE;
}
	
extern
void liberation_ressources(SDL_Window* w, SDL_Renderer *r,SDL_Surface* image, SDL_Texture *t) // libération des resources subsistantes
{
	if(w!=NULL) SDL_DestroyWindow(w);
		
	if(r!=NULL) SDL_DestroyRenderer(r);
		
	if(image!=NULL) SDL_FreeSurface(image); //permet de libérer la mémoire quand on n'a plus besoin d'une surface
		
	if(t!=NULL) SDL_DestroyTexture(t);
	
}
 
 
extern
void liberation_ressourcesTexture(SDL_Texture  *tabTexture[tailleTexture] )
{
	for (i=0;i<tailleTexture;i++)
	
		if(tabTexture[i]!= NULL ) 
			
			SDL_DestroyTexture(tabTexture[i]); 
}

extern
void liberation_ressourcesSurface( SDL_Surface  *tabSurface[tailleSurface] )
{
	for (i=0;i<tailleSurface;i++)
	
		if(tabSurface[i] != NULL) 
			
			SDL_FreeSurface(tabSurface[i]); 
}


extern
void liberation_ressourcesTTF( TTF_Font *p1, TTF_Font *p2 )
{
	if(p1!=NULL)TTF_CloseFont(p1);
	if(p2!=NULL)TTF_CloseFont(p2);
}

extern
void chargement_cheminA_1(int  *chemin_aller , int t)
{
		int l=0;

	for ( i=0;l< t; i+=10,l++ )
 
			chemin_aller[l]=i ;	
				
}
 

 /*   0,10,20,30,......,1680} */

 




