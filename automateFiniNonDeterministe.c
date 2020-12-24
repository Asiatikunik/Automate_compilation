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
	
	//etat->etat_suivant = NULL;

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
	
	//etat->etat_suivant = NULL;

	automate->alphabet = NULL;
	automate->nombreEtats = 1;
	automate->liste_etat = etat;
	automate->etat_initial = etat;
	automate->tab_transition = init_tab_transition(1);
	automate->automate_suivant = NULL;

	return automate;
}

//Création d'une liste de caractères 
Caractere* init_list_caractere(int taille)
{
	Caractere* list_caractere = NULL;
	list_caractere = malloc(taille * sizeof(Caractere));
	
	for(int i=0;i<taille;i++)
		list_caractere[i] = NULL;
	
	return list_caractere;
}

//Création d'une liste d'états
Etat* init_list_etat(int taille)
{
	Etat* list_etat = NULL;
	list_etat = malloc(taille * sizeof(Etat));

	for(int i=0;i<taille;i++)
		list_etat[i] = NULL;
	
	return list_etat;
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

/* Transition -> tab dynamique
//Création d'une liste de transitions
Transition* init_list_transition(int taille)
{
	Transition* list_transition = NULL;
	list_transition = malloc(taille * sizeof(Transition));

	for(int i=0;i<taille;i++)
		list_transition[i] = NULL;

	return list_transition;
}

//Création d'un tableau de listes de transitions alloué dynamiquement
Transition** init_tab_transition(int taille_tab, int taille_transition){
	Transition** tab_transition = NULL;

	tab_transition = malloc(taille * sizeof(Transition*));
	
	for(int i=0;i<taille;i++){
		tab_transition[i] = init_list_transition(taille_transition);
	}

	return tab_transition;
}*/
