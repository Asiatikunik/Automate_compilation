#ifndef AUTOMATEFINIDETERMINISTE
#define AUTOMATEFINIDETERMINISTE

#include "automateFiniNonDeterministe.h"
#include "automateFiniDeterministe.h"
#include "constante.h"


typedef struct TabTrans {
	int taille;
	Transition array[TAILLE_TRANSITION];
} TabTrans;

typedef struct TabTrans2 {
	int taille_etat;
	int taille_alph;
	int array[TAILLE_TRANSITION][TAILLE_TRANSITION];
} TabTrans2;

/* C'est la même chose que l'automate fini NON deterministe
 * type automate fini non déterministe défini par
 * un alphabet (liste chainée de caractères)
 * un nombre d'états
 * une tableau d'états (les états accepteurs en premier)
 * un état initial
 * un tableau de listes chainées de transitions avec l'indice de la ligne représentant l'état de départ
 */
typedef struct AFD {
	int taille_alphabet;
	char alphabet[TAILLE_ALPHABET];
	int nb_etats;
	Etat etat_init;
	Etat etat[TAILLE_ETAT];
} AFD;

TabTrans2 recupere_tabTransition2(AFD a);

// Permet d'afficher l'automate fini déterministe
void affichage_AFD(AFD a);

// Permet de initialisé UN etat de l'automate
AFD set_etat_afd(AFD automate, int num_etat, int num, bool initial, bool accepteur, int nb_transition);

// Permet de initialisé un état UN transition d'un état de l'automate
AFD set_transition_afd(AFD automate, int num_etat, int num_trans, int arrivee, char caractere);

// minimisation ld'un automate
AFD minimisation(AFD a);

// minimisation ld'un automate
AFD minimisation2(AFD a);

TabTrans init_tabTrans(TabTrans tt);

// Permet d'afficher un tableau de transition 
void afficher_tabTrans(TabTrans tt);

AFD set_transition_AFD(AFD automate, int num_etat, int num_trans, int arrive, char caractere);

AFD set_etat_AFD(AFD automate, int num_etat, int num, bool initial, bool accepteur, int nb_transition);

TabTrans recupere_tabTransitionBis(AFD a);

Etat find_etat(AFD automate, int num);

Transition getTransition(TabTrans tabTrans, Etat etat, char lettre);

void execution_afd(AFD automate, char* mot);

#endif