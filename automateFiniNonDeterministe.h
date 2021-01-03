#ifndef AUTOMATEFININONDETERMINISTE
#define AUTOMATEFININONDETERMINISTE

#include "automateFiniNonDeterministe.h"
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
	int arrive;
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
	Transition arrayTrans[TAILLE_TRANSITION];
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
	Etat etat[TAILLE_ETAT];
} AFND;

//Affiche un automate fini non déterministe
void affichage_AFND(AFND a);

// Permet de initialisé UN etat de l'automate
AFND set_etat_AFND(AFND automate, int num_etat, int num, bool initial, bool accepteur, int nb_transition);

// Permet de initialisé un état UN transition d'un état de l'automate
AFND set_transition_AFND(AFND automate, int num_etat, int num_trans, int arrive, char caractere);

void afficher_alphabet(AFND a);

//Initialise les numéros des états de départ de chaque transition à -1
AFND init_arrayTransition(AFND a);

//Initialise les numéros des états à -1
AFND init_etat(AFND a);

//Renvoie un automate non déterministe reconnaissant le langage vide
AFND langage_vide();

//Renvoie un automate non déterministe reconnaissant le mot vide
AFND mot_vide();

//Renvoie un automate fini non déterministe reconnaissant le language composé d'un mot d'un caractere passé en parametre
AFND un_mot(char mot);

// Fait la réunion de deux automates et le met dans a1
AFND reunion_automate(AFND a1, AFND a2);

// Ajoute l'alphaber de a2 dans a1
AFND reunion_alphabet(AFND a1, AFND a2);

// Concatenation de a2 dans a1
AFND concatenation_AFND(AFND a1, AFND a2);

// Ajouter transition
Transition* add_transition(Transition transition, Transition* arrayTrans);

// Fermeture iterative de Kleene
AFND kleene(AFND automate);

#endif