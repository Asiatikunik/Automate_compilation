#ifndef AUTOMATEFINIDETERMINISTE
#define AUTOMATEFINIDETERMINISTE

#include "automateFiniNonDeterministe.h"
#include "automateFiniDeterministe.h"
#include "constante.h"

// Structure pour faire un tableau de transition
// Une aide pour la partie deterministe
typedef struct Trans{
	int depart;
	char caractere;
	int arrive;
} Trans;

typedef struct TabTrans{
	int taille;
	Trans array[TAILLE_TRANSITION];
} TabTrans;

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

// Permet de initialisé UN etat de l'automate
AFD set_etat_afd(AFD automate, int num_etat, int num, bool initial, bool accepteur, int nb_transition);

// Permet de initialisé un état UN transition d'un état de l'automate
AFD set_transition_afd(AFD automate, int num_etat, int num_trans, int arrivee, char caractere);

TabTrans init_tabTrans(TabTrans tt);
void afficher_tabTrans(TabTrans tt);
TabTrans recupere_tabTransitionBis(AFD a);
Etat find_etat(AFD automate, int num);
Trans getTransition(TabTrans tabTrans, Etat etat, char lettre);
void execution_afd(AFD automate, char* mot);

#endif