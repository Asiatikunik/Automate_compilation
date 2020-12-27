#ifndef AUTOMATEFININONDETERMINISTE
#define AUTOMATEFININONDETERMINISTE

#include "constante.h"


/* 
type transition défini par un état de départ 
L'état qui possède la transition est la transition de départ
un état d'arrivée,
un caractère de transition.
 */
typedef struct Transition{
	int depart;
	char caractere;
} Transition;

/*
type état défini par un numéro
S'il est initial et accepteur
Et ses transitions
	Le départ des transitions est l'état sur lequel il est rattraché.
*/
typedef struct Etat {
	int num;
	bool initial;
	bool accepteur;
	int nb_transition;
	Transition* arrayTrans;
} Etat;



/* type automate fini non déterministe défini par
 * un alphabet (liste chainée de caractères)
 * un nombre d'états
 * une tableau d'états (les états accepteurs en premier)
 * un état initial
 * un tableau de listes chainées de transitions avec l'indice de la ligne représentant l'état de départ
 */
typedef struct AFND {
	int taille_alphabet;
	char alphabet[TAILLE_ALPHABET];
	int nb_etats;
	Etat etat_init;
	Etat* etat;
} AFND;

//Initialise les numéros des états de départ de chaque transition à -1
Transition* init_arrayTransition();

//Initialise les numéros des états à -1
Etat* init_etat();
//Renvoie un automate non déterministe reconnaissant le langage vide
AFND langage_vide();

//Renvoie un automate non déterministe reconnaissant le mot vide
AFND mot_vide();

//Renvoie un automate fini non déterministe reconnaissant le language composé d'un mot d'un caractere passé en parametre
AFND un_mot(char mot);

//Reunion des languages de 2 automates
void reunion_language(AFND automate1, AFND automate2);

// Concatenation de a2 dans a1
AFND concatenation_AFND(AFND a1, AFND a2);
//Création d'un tableau de listes de transitions alloué dynamiquement
// Transition** init_tab_transition(int taille);

//Création de la liste des caracteres allouée dynamiquement
// Caractere* init_list_caractere(int taille);

//Création de la liste des états allouée dynamiquement
// Etat* init_list_etat(int taille);

/*Transition* init_list_transition(int taille)
{
	Transition* list_transition = NULL;
	list_transition = malloc(taille * sizeof(Transition));

	for(int i=0;i<taille;i++)
		list_transition[i] = NULL;

	return list_transition;
}*/
#endif