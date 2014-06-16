#ifndef TOOLBOX_H__
#define TOOLBOX_H__


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

/**
* afficher le contenu d'un tableau de chaines de caractères dans l'ordre 
*/
void affichtab ( char* chartab[], unsigned int tablength);

/**
* appel une fonction comptage de longueur de chaine de caractère qui va inscrire directement son résultat dans le ctr
*/
int lenghtStr (char* Str);

/**
* définir la longueur d'une chaine de caractère, et via un pointeur écrire la longueur dans un int extérieur
*/
int lenghtStrPtr (char* Str, int * length);

/**
* transformer une chaine de caracère issue d'un char en int à partir de la fin
*/
int convStrIntfin (char* Nbr, unsigned int lenghtNbr);

/**
* transformer une chaine de caracère issue d'un char en int à partir du début
*/
int convStrIntdebut (char* Nbr);

/**
* vérification qu'un paramètre ne soit pas en erreur
*/
void param_check (int param);

/**
* générateur de nombre aléatoire
*/
int nbr_alea (int init);

#endif
