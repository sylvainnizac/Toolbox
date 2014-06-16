#include "toolbox.h"
#include <time.h> //pour utiliser time()


/**
 * afficher le contenu d'un tableau de chaines de caractères dans l'ordre
 * void affichtab (chartab, tablength)
 * prérequis :
 * chartab : non null
 * tablelength : égal nombre ligne de chartab, strictement positif ou nul
*/
void affichtab ( char* chartab[], unsigned int tablength)
{
	unsigned int i = 0; //\brief déclaration de la variable i qui est un entier positif (unsigned int) et initialisation de la variable à 0
 	for (i = 0; i < tablength; i++) //\brief boucle for entre i=0 et i=argc-1
	{
		printf("chartab[%d]:%s\n", i, chartab[i]); //\brief écrit sur la sortie standard (console) la valeur de argv à la "ligne" i
	}	
}

/**
* appel une fonction comptage de longueur de chaine de caractère qui va inscrire directement son résultat dans le ctr
*/
int lenghtStr (char* Str)
{
	int ctr = 0;
	if (lenghtStrPtr(Str, &ctr)) //\brief si la fonction lenghtStrPtr renvoi 0 retourner -1, sinon retourner la valeur du compteur (ctr), &ctr est l'adresse de la variable ctr
	{
		return ctr;
	}
	return -1;
}

/**
* définir la longueur d'une chaine de caractère, et via un pointeur écrire la longueur dans un int extérieur
*/

int lenghtStrPtr (char* Str, int * length) //\brief paramètres pointeur sur la chaine de carac et pointeur sur la longueur de la chaine, en elle même cette fonction est juste un booléen
{
	if (!Str) //\brief si la chaine est nulle retourner 0
	{
		return 0;
	}

	*length = 0; //\brief on initialise la valeur de la longueur de chaine via le pointeur
	int lenghtStr = 0;
	while (*Str) //\brief tant que Str non nul on boucle et incrémente
	{
		lenghtStr++;
		Str++;
	}

	*length = lenghtStr; //\brief on copie la longueur de chaine sur la variable ext via le pointeur
	return 1;
}

/**
* transformer une chaine de caracère issue d'un char en int à partir de la fin de la chaine
*/

int convStrIntfin (char* Nbr, unsigned int lenghtNbr)
{
	int temp = 0;
	int nbr = -1;
	int multipl = 1;
	int i = lenghtNbr - 1;
	while (i >= 0)
	{
		if ('0' <= Nbr[i] && Nbr[i] <= '9')	
		{		
			temp = (Nbr[i] - '0') * multipl;
			nbr = nbr + temp;
			multipl = multipl * 10;
			i--;
		}
		else
		{		
			//\brief fonction erreur
			break;
		}
	}
	return nbr == -1 ? -1 : nbr + 1;
}

/**
* transformer une chaine de caracère issue d'un char en int à partir du début avec séparateur
*/

int convStrIntdebut (char* Nbr)
{
	int temp = 0;
	int nbr = -1;
	int multipl = 1;
	int i = 0;
	int lenght_interne = 0;

	while ('0' <= Nbr[i] && Nbr[i] <= '9')
	{
		lenght_interne++;
		Nbr++;
	}

	Nbr = Nbr - lenght_interne;

	multipl = pow(10, lenght_interne - 1);

	i = 0;
	while (i <= lenght_interne)
	{
		if ('0' <= Nbr[i] && Nbr[i] <= '9')	
		{		
			temp = (Nbr[i] - '0') * multipl;
			nbr = nbr + temp;
			multipl = multipl / 10;
			i++;
		}
		else
		{		
			//\brief fonction erreur
			break;
		}
	}
	return nbr == -1 ? -1 : nbr + 1;
}

/**
* vérification qu'un paramètre ne soit pas en erreur
*/

void param_check (int param)
{
	assert(param != -1);
}

/**
* générateur de nombre aléatoire avec nouvelle graine de random
*/
int nbr_alea (int init)
{
	if (init)
	{
	srand(time (NULL));
	}
	return random();
}
