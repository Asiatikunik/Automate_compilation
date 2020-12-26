#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "automateFiniNonDeterministe.h"
#include "constante.h"


//Affiche un automate fini non déterministe
void affichage_AFND(AFND a){
	bool flag_accepteur = false;

	printf("Alphabet: ");
	if(a.taille_alphabet == false)
		printf("Vide");
	else{
		for(int s=0; s<a.taille_alphabet; s++){
			printf("%c ", a.alphabet[s]);
		}
	}
	printf("\n");

	printf("Nombre d'états: %d \n", a.nb_etats);
	printf("Etat d'initial: ");
	for(int s=0; s<a.nb_etats; s++){
		if(a.etat->initial == true)
			printf("%d ", a.etat->num);
	}
	printf("\n");

	printf("Etat accepteur: ");
	for(int s=0; s<a.nb_etats; s++){
		if(a.etat->accepteur == true){
			flag_accepteur = true;
			printf("%d ", a.etat->num);
		}
	}
	if(flag_accepteur == false)
		printf("Vide");
	printf("\n");

	printf("Liste des états: ");
	if(a.nb_etats == 0){
		printf("Vide");
	}else{
		for(int s=0; s<a.nb_etats; s++){
			printf("%d ", a.etat->num);
		}
	}
	printf("\n");

	printf("Transition: ");	
	if(a.etat->nb_transition == 0)
		printf("Vide");
	else{
		for(int s=0; s<a.nb_etats; s++)
			for(int k=0; k<a.etat->nb_transition; k++)
				printf("(%d, %c, %d) ", a.etat->num, a.etat[s].arrayTrans[k].caractere, a.etat[s].arrayTrans[k].arrivee);
	}
	printf("\n\n");


}

//Renvoie un automate fini non déterministe reconnaissant le langage vide
// Si le premier numero du caractère de l'alphabet est -1, alors il est vide
AFND langage_vide(){
	AFND automate; 

	automate.taille_alphabet = 0;
	automate.alphabet[0];

	automate.nb_etats = 1;
	automate.etat[1];

	automate.etat[0].num = 0;
	automate.etat[0].initial = true;
	automate.etat[0].accepteur = false;
	automate.etat[0].nb_transition = 0;

	return automate;

}

//Renvoie un automate fini non déterministe reconnaissant le mot vide
AFND mot_vide(){
	AFND automate; 

	automate.taille_alphabet = 0;
	automate.alphabet[0];

	automate.nb_etats = 1;
	automate.etat[1];

	automate.etat[0].num = 0;
	automate.etat[0].initial = true;
	automate.etat[0].accepteur = true;
	automate.etat[0].nb_transition = 0;

	return automate;
}

//Création d'une liste de caractères 
// Caractere* init_list_caractere(int taille) {
// 	Caractere* list_caractere = NULL;
// 	list_caractere = malloc(taille * sizeof(Caractere));
	
// 	for(int i=0;i<taille;i++)
// 		list_caractere[i] = NULL;
	
// 	return list_caractere;
// }

//Création d'une liste d'états
// Etat* init_list_etat(int taille) {
// 	Etat* list_etat = NULL;
// 	list_etat = malloc(taille * sizeof(Etat));

// 	for(int i=0;i<taille;i++)
// 		list_etat[i] = NULL;
	
// 	return list_etat;
// }

//Création d'un tableau de listes de transitions alloué dynamiquement
// Transition** init_tab_transition(int taille){
// 	Transition** tab_transition = NULL;
// 	int i;

// 	tab_transition = malloc(taille * sizeof(Transition*));
// 	for(i=0;i<taille;i++){
// 		tab_transition[i] = NULL;
// 	}

// 	return tab_transition;
// }

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
