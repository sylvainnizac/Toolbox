#ifndef TOOLBOX_CHAINE_H__
#define TOOLBOX_CHAINE_H__

#include <stdio.h>
#include <stdlib.h>

/**
 * structure composant la chaine
 */

struct maille
{
int data; // données contenues dans la maille
struct maille *ptr_next; // pointeur sur la maille suivante de la chaine, la dernière maille pointe sur NULL
};

struct maille *ajout_debut (struct maille *ptr_debut, int valeur);

struct maille *ajout_milieu (struct maille *ptr_debut, int valeur, int nouv_rang);

struct maille *ajout_fin (struct maille *ptr_debut, int valeur);

struct maille *suppr_fin (struct maille *ptr_debut);

struct maille *suppr_milieu (struct maille *ptr_debut, int rang_suppr);

struct maille *suppr_debut (struct maille *ptr_debut);

struct maille *suppr_portion (struct maille *ptr_debut, int rang_suppr1, int rang_suppr2);

void affiche_chaine (struct maille *ptr_debut);

struct maille *tranfo_tab_chaine (struct maille *ptr_debut, int tab_int[], int long_tab);

int *transfo_chaine_tab (struct maille *ptr_debut, int tab_int[]);

struct maille *concat_chaine (struct maille *ptr_debut, struct maille *ptr_debut2);

int mesure_long_chaine (struct maille *ptr_debut, int *long_chaine);

#endif
