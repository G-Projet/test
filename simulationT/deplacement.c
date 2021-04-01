

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 

#include "chemin.h"
#define TAILLE 151


typedef enum dep{DROIT,GAUCHE,HAUT,BAS}t_direction;


 
void tableau (int  *chemin_aller ,int t)
{
		int i,l=0;

	for (i=0,l;l< t; i+=10,l++)
 
			chemin_aller[l]=i;		
  
}


int main()
{
	system("clear");

	 //int val = 0;

 
	int i;

	int chemin_aller[TAILLE];

	tableau (chemin_aller,TAILLE);

	for ( i=0;i<TAILLE;i++)
 
		printf("chemin_aller[%d] = %d \n",i, chemin_aller[i]);
 
 
	return 0; 
}


 