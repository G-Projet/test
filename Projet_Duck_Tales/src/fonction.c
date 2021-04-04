 
#include "fonction.h"
 
void bienvenus()
{
	SDL_version nb;
	SDL_VERSION(&nb);
	
	system("clear");
	printf("\t********************************************************\n");
	printf("\t*    Bienvenus sur la platforme de jeux Duck_Tales     *  \n");
	printf("\t* \t \t SDL version : %d . %d . %d              *\n", nb.major, nb.minor, nb.patch );
	printf("\t********************************************************\n");	
	sleep(1);
}
 
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
	if(w!=NULL)
		SDL_DestroyWindow(w);
	if(r!=NULL)
		SDL_DestroyRenderer(r);
	if(image!=NULL)
		SDL_FreeSurface(image); //permet de libérer la mémoire quand on n'a plus besoin d'une surface
	if(t!=NULL)
		SDL_DestroyTexture(t);
}

extern
void liberation_ressourcesSurface(SDL_Surface* s1,SDL_Surface* s2,SDL_Surface* s3,
							SDL_Surface* s4,SDL_Surface* s5,SDL_Surface* s6) // libération des resources subsistantes
{
	if(s1!=NULL)SDL_FreeSurface(s1);
	if(s2!=NULL)SDL_FreeSurface(s2);
	if(s3!=NULL)SDL_FreeSurface(s3);
	if(s4!=NULL)SDL_FreeSurface(s4);
	if(s5!=NULL)SDL_FreeSurface(s5);
	if(s6!=NULL)SDL_FreeSurface(s6);	 
}
 
extern
void liberation_ressourcesTTF( TTF_Font *p1, TTF_Font *p2 )
{
	if(p1!=NULL)TTF_CloseFont(p1);
	if(p2!=NULL)TTF_CloseFont(p2);
}
 
void chargement_cheminA_1(int  *chemin_aller , int t)
{
		int i=0, l=0;

	for ( ;l< t; i+=10,l++ )
 
			chemin_aller[l]=i ;	
				
}

extern 
int  cheminV_1 ( int val )
{
		 	return ( val < TAILLE ) ;
}

 /*   0,10,20,30,......,1680} */

 




