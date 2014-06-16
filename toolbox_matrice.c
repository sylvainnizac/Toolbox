#include "toolbox_matrice.h"

/**
* afficher une matrice d'int
*/

void affiche_matrice_int (int hauteur_matrice, int largeur_matrice, int** matrice)
{
	int i = 0;
	int j = 0;
	while ( i < hauteur_matrice )
	{
		while ( j < largeur_matrice )
		{
			printf("%i ", matrice[i][j]);
			j++;
		}
		printf("\n");
		i++;
		j = 0;
	}
}

/**
* initialiser une matrice d'int
*/

void init_matrice_int (int hauteur_matrice, int largeur_matrice, int** matrice)
{
	int i = 0;
	int j = 0;
	while ( i < hauteur_matrice )
	{
		while ( j < largeur_matrice )
		{
			matrice[i][j] = 0;
			j++;
		}
		i++;
		j = 0;
	}
}

/**
* afficher une matrice de struct
*/

void affiche_matrice_str (int hauteur_matrice, int largeur_matrice, struct matrice** matrice)
{
	int i = 0;
	int j = 0;
	while ( i < hauteur_matrice )
	{
		while ( j < largeur_matrice )
		{
			printf("%i ", matrice[i][j].data1);
			j++;
		}
		printf("\n");
		i++;
		j = 0;
	}
}

/**
* parcourir une matrice et exécuter une fonction sur chacune de ses cases
*/
void parcour_matrice_appelfonc ( unsigned int H, unsigned int L, void* world, void (*fonction)(unsigned int, unsigned int, void*))
{
	unsigned int h = H;
	unsigned int l = L;
	for(h = 0; h < H; h++)
	{		
		for(l = 0; l < L; l++)
		{
			(*fonction)(h, l, world); //\brief fonction à exécuter
		}
	}
}




