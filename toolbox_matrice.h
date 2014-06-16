#ifndef TOOLBOX_MATRICE_H__
#define TOOLBOX_MATRICE_H__

#include <stdio.h>
#include <stdlib.h>

struct matrice
{
int data1;
};

/**
* afficher une matrice d'int
*/
void affiche_matrice_int (int hauteur_matrice, int largeur_matrice, int** matrice);

/**
* initialiser une matrice d'int
*/
void init_matrice_int (int hauteur_matrice, int largeur_matrice, int** matrice);

/**
* afficher une matrice de str
*/
void affiche_matrice_str (int hauteur_matrice, int largeur_matrice, struct matrice** matrice);

/**
* parcourir une matrice et exécuter une fonction sur chacune de ses cases
*/
void parcour_matrice_appelfonc ( unsigned int H, unsigned int L, void* world, void (*fonction)(unsigned int, unsigned int, void*));

#endif
