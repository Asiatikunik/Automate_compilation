#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "automateFiniNonDeterministe.h"

//Renvoie un automate non déterministe reconnaissant le langage vide
AFND* langage_vide(){
	AFND* automate = malloc(sizeof(AFND));
	Etat* etat = malloc(sizeof(Etat));

	etat->num = 0;
	etat->accepteur = 0;
	
	etat->etat_suivant = NULL;

	automate->alphabet = NULL;
	automate->nombreEtats = 1;
	automate->liste_etat = etat;
	automate->etat_initial = etat;
	automate->tab_transition = init_tab_transition(1);
	automate->automate_suivant = NULL;

	return automate;

}

//Renvoie un automate non déterministe reconnaissant le mot vide
AFND* mot_vide(){
	AFND* automate = malloc(sizeof(AFND));
	Etat* etat = malloc(sizeof(Etat));

	etat->num = 0;
	etat->accepteur = 1;
	etat->etat_suivant = NULL;

	automate->alphabet = NULL;
	automate->nombreEtats = 1;
	automate->liste_etat = etat;
	automate->etat_initial = etat;
	automate->tab_transition = init_tab_transition(1);
	automate->automate_suivant = NULL;

	return automate;
}

//Création d'un tableau de listes de transitions alloué dynamiquement
Transition** init_tab_transition(int taille){
	Transition** tab_transition = NULL;
	int i;

	tab_transition = malloc(taille * sizeof(Transition*));
	for(i=0;i<taille;i++){
		tab_transition[i] = NULL;
	}

	return tab_transition;
}