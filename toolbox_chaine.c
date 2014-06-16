#include <stdio.h>
#include <stdlib.h>
#include "toolbox_chaine.h"

/**
 * Fonction permettant d'ajouter un maillon en fin de chaine
 * */

struct maille *ajout_fin (struct maille *ptr_debut, int valeur) /**La fonction d'ajout prend en donnée le pointeur sur la première maille  et la valeur stockée dans la nouvelle maille*/
{
	struct maille *ptr_nouv = malloc (sizeof *ptr_nouv); /**On créé la nouvelle maille avec une taille suffisante pour contenir la structure, l'utilisation de malloc permet de pouvoir modifier la structure sans affecter la fonction*/

	/**On initialise la maille avant de l'ajouter*/
	ptr_nouv->data = valeur; /**ajout de la valeur dans la maille*/
	ptr_nouv->ptr_next = NULL; /**next pointe sur NULL car on veut ajouter la maille en fin de chaine*/

	if (ptr_debut == NULL) /**on vérifie si le premier maillon est déjà défini ou non*/
	{
		ptr_debut = ptr_nouv; /**debut devient un maillon avec une valeur*/
	}
	else /**on cherche la dernière maille de la chaine*/
	{
		struct maille *ptr = ptr_debut; /** ptr est une variable de transition qui sert à parcourir la chaine en commençant par la maille de tête*/

		while (ptr->ptr_next != NULL) /**on cherche la maille ne pointant sur rien*/
		{
			ptr = ptr->ptr_next; /**l'adresse de ptr est incrémentée pour vérifier la maille suivante*/
		}

		ptr->ptr_next = ptr_nouv; /**on donne à la dernière maille l'adresse de la suivante*/
	}
	return ptr_debut; 
}

/**
 * Fonction d'affichage de la chaine
 * */

void affiche_chaine (struct maille *ptr_debut) /**La fonction n'a besoin que de la première maille pour retrouver toute la chaine*/
{
	struct maille *temp = ptr_debut;

	while (temp != NULL)
	{
		printf ("%i -> ", temp->data);
		temp = temp->ptr_next; /**permet arrivé à la derière maille de faire pointer temp non plus sur une truct mais sur NULL*/
	}

	printf ("FIN\n");
}

/**
 * Fonction permettant d'ajouter un maillon en fin de chaine
 * */

struct maille *ajout_debut (struct maille *ptr_debut, int valeur)
{
	struct maille *ptr_nouv = malloc (sizeof *ptr_nouv); /**On créé la nouvelle maille avec une taille suffisante pour contenir la structure, l'utilisation de malloc permet de pouvoir modifier la structure sans affecter la fonction*/

	/**On initialise la maille avant de l'ajouter*/
	ptr_nouv->data = valeur; /**ajout de la valeur dans la maille*/
	ptr_nouv->ptr_next = NULL; /**initialisation de la donnée de pointeur sur le suivant*/

	if (ptr_debut == NULL) /**on vérifie si le premier maillon est déjà défini ou non*/
	{
		ptr_debut = ptr_nouv; /**debut devient un maillon avec une valeur*/
	}
	else
	{
		struct maille *ptr_temp = malloc (sizeof *ptr_temp);

		ptr_temp = ptr_debut; /**on transfère les données de la première maille dans une maille temporaire*/
		ptr_debut = ptr_nouv; /**on réaffecte les données au nouveau pointeur de début*/
		ptr_debut->ptr_next = ptr_temp; /**le pointeur de début reçoit l'adresse de la maille suivante dans la chaine*/
	}
	
	return ptr_debut;
}

/**
 * Fonction permettant d'ajouter une maille en milieu de chaine, en donnant le rang surlequel la placer
 * */

struct maille *ajout_milieu (struct maille *ptr_debut, int valeur, int nouv_rang)
{
	struct maille *ptr_nouv = malloc (sizeof *ptr_nouv); /**On créé la nouvelle maille avec une taille suffisante pour contenir la structure, l'utilisation de malloc permet de pouvoir modifier la structure sans affecter la fonction*/

	/**On initialise la maille avant de l'ajouter*/
	ptr_nouv->data = valeur; /**ajout de la valeur dans la maille*/
	ptr_nouv->ptr_next = NULL; /**initialisation de la donnée de pointeur sur le suivant*/

	if (ptr_debut == NULL) /**on vérifie si le premier maillon est déjà défini ou non*/
	{
		ptr_debut = ptr_nouv; /**debut devient un maillon avec une valeur*/
	}
	else
	{
		struct maille *ptr1 = ptr_debut; /** ptr est une variable de transition qui sert à parcourir la chaine en commençant par la maille de tête*/
		struct maille *ptr2 = ptr_debut->ptr_next;
		int i = 1;
		
		while (i != (nouv_rang-1)) /**on cherche la position où placer la nouvelle maille*/
		{
			/**bascule entre les adresse pour progresser de rang en rang dans la chaine*/
			ptr1 = ptr2; 
			ptr2 = ptr1->ptr_next;
			i++;
		}

		ptr_nouv->ptr_next = ptr1->ptr_next;
		ptr1->ptr_next = ptr_nouv;

	}
	
	return ptr_debut;
}

/**
 * Fonction permettant de transformer un tableau d'int en liste chainée
 * */

struct maille *tranfo_tab_chaine (struct maille *ptr_debut, int tab_int[], int long_tab)
{
	int i = 0;
	
	while (i < long_tab)
	{
	ptr_debut = ajout_fin (ptr_debut, tab_int[i]);
	i++;
	}
	
	return ptr_debut;

}

/**
 * Fonction permettant de transformer une liste chainée en un tableau
 * */
int *transfo_chaine_tab (struct maille *ptr_debut, int tab_int[])
{
	int long_chaine = 0;
	int i = 0;
	struct maille *temp = ptr_debut;
	
	mesure_long_chaine (ptr_debut, &long_chaine);

	tab_int = calloc(long_chaine, sizeof(int));
	

	while (temp != NULL)
	{
		tab_int[i] = temp->data;
		temp = temp->ptr_next;
		i++;
	}
	
/**
 * 	i = 0;
 * for (i = 0; i < long_chaine; i++)
 * {
 * 		printf("%i\n", tab[i]);
 * }
*/
	
	return tab_int;
}


/**
 * Fonction permettant de supprimer la dernière maille d'une chaine
 * */

struct maille *suppr_fin (struct maille *ptr_debut)
{
		if(ptr_debut == NULL)
		{
			printf("pas de maille à supprimer, la chaine est vide");		
		}
		else
		{
			struct maille *ptr_der = ptr_debut; /** ptr est une variable de transition qui sert à parcourir la chaine en commençant par la maille de tête*/
			struct maille *ptr_avder = ptr_debut;

			while (ptr_der->ptr_next != NULL) /**on cherche la maille ne pointant sur rien*/
			{
				ptr_avder = ptr_der; /**ptr_avder reste un cran en retrait car on veut que l'avant dernière maille devienne la dernière*/
				ptr_der = ptr_der->ptr_next; /**l'adresse de ptr_der est incrémentée pour vérifier la maille suivante*/
			}

			ptr_avder->ptr_next = NULL; /**on donne à l'avant dernière maille l'adresse NULL pour supprimer la dernière*/
		}
	return ptr_debut; 
}

/**
 * Fonction permettant de supprimer la première maille d'une chaine
 * */

struct maille *suppr_debut (struct maille *ptr_debut)
{
		if(ptr_debut == NULL)
		{
			printf("pas de maille à supprimer, la chaine est vide");		
		}
		else
		{
			struct maille *ptr = ptr_debut->ptr_next; /**on initialise ptr comme étant la deuxième maille de la chaine*/
			ptr_debut = ptr; /**on modifie ptr_debut pour que la deuxième maille devienne la première*/
		}
	return ptr_debut; 
}

/**
 * Fonction permettant de supprimer une maille en milieu de chaine, en donnant le rang à supprimer
 * */

struct maille *suppr_milieu (struct maille *ptr_debut, int rang_suppr)
{
	if(ptr_debut == NULL)
	{
		printf("pas de maille à supprimer, la chaine est vide");		
	}
	else
	{

		struct maille *ptr1 = ptr_debut; /** ptr est une variable de transition qui sert à parcourir la chaine en commençant par la maille de tête*/
		struct maille *ptr2 = ptr_debut->ptr_next;
		int i = 1;
		
		while (i != (rang_suppr-1)) /**on cherche la position où placer la nouvelle maille*/
		{
			/**bascule entre les adresse pour progresser de rang en rang dans la chaine*/
			ptr1 = ptr2; 
			ptr2 = ptr1->ptr_next;
			i++;
		}

		ptr1->ptr_next = ptr2->ptr_next;

	}
	
	return ptr_debut;
}

/**
 * Fonction permettant de supprimer un groupe de mailles en milieu de chaine, en donnant le premier et le dernier rang à supprimer
 * */

struct maille *suppr_portion (struct maille *ptr_debut, int rang_suppr1, int rang_suppr2)
{
	if(ptr_debut == NULL)
	{
		printf("pas de maille à supprimer, la chaine est vide");		
	}
	else
	{

		struct maille *ptr1 = ptr_debut;
		struct maille *ptr2 = ptr_debut->ptr_next;
		struct maille *ptr3 = ptr_debut;
		struct maille *ptr4 = ptr_debut->ptr_next;
		int i = 1;
		
		while (i != (rang_suppr1-1)) /**on cherche la position où placer la nouvelle maille*/
		{
			/**bascule entre les adresse pour progresser de rang en rang dans la chaine*/
			ptr1 = ptr2; 
			ptr2 = ptr1->ptr_next;
			i++;
		}

		i = 1;
		while (i != (rang_suppr2-1)) /**on cherche la position où placer la nouvelle maille*/
		{
			/**bascule entre les adresse pour progresser de rang en rang dans la chaine*/
			ptr3 = ptr4; 
			ptr4 = ptr3->ptr_next;
			i++;
		}

		ptr1->ptr_next = ptr4->ptr_next;

	}
	
	return ptr_debut;
}

/**
 * Fonction permettant de concaténer 2 chaines
 * */

struct maille *concat_chaine (struct maille *ptr_debut, struct maille *ptr_debut2)
{
		if(ptr_debut == NULL || ptr_debut2 == NULL)
		{
			printf("pas de concaténation possible, l'une des chaines est vide");		
		}
		else
		{
			struct maille *ptr_der = ptr_debut; /** ptr est une variable de transition qui sert à parcourir la chaine en commençant par la maille de tête*/

			while (ptr_der->ptr_next != NULL) /**on cherche la maille ne pointant sur rien*/
			{
				ptr_der = ptr_der->ptr_next; /**l'adresse de ptr_der est incrémentée pour vérifier la maille suivante*/
			}

			ptr_der->ptr_next = ptr_debut2;
		}
		
	return ptr_debut;
}

/**
 * Fonction permettant de mesurer la longueur d'une liste chainée
 * */
 
int mesure_long_chaine (struct maille *ptr_debut, int * long_chaine)
{
	struct maille *temp = ptr_debut;
	int i = 0;
	*long_chaine = 0;
	
	while (temp != NULL)
	{
		temp = temp->ptr_next;
		i++;
	}

	printf ("la longueur de la chaine est de %i mailles\n", i);

	*long_chaine = i;

	return 1;
}

