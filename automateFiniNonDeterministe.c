#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "automateFiniNonDeterministe.h"
#include "constante.h"

//Affiche un automate fini non déterministe
void affichage_AFND(AFND a){
	bool flag_accepteur = false;
	bool flag_transition = false;

	printf("Alphabet: ");
	if(a.taille_alphabet == false)
		printf("Vide");
	else{
		for(int s=0; s<a.taille_alphabet; s++){
			printf("%c ", a.alphabet[s]);
		}
	}
	printf("\n");

	// printf("Nombre d'états: %d \n", a.nb_etats);

	printf("Liste des états: ");
	if(a.nb_etats == 0){
		printf("Vide");
	}else{
		for(int s=0; s<a.nb_etats; s++){
			printf("%d ", a.etat[s].num);
		}
	}
	printf("\n");

	printf("Etat d'initial: ");
	for(int s=0; s<a.nb_etats; s++){
		if(a.etat[s].initial == true)
			printf("%d ", a.etat[s].num);
	}
	printf("\n");

	printf("Etat accepteur: ");
	for(int s=0; s<a.nb_etats; s++){
		if(a.etat[s].accepteur == true){
			flag_accepteur = true;
			printf("%d ", a.etat[s].num);
		}
	}
	if(flag_accepteur == false)
		printf("Vide");
	printf("\n");

	printf("Transition: ");	
	for(int s=0; s<a.nb_etats; s++)
		for(int k=0; k<a.etat[s].nb_transition; k++){
			printf("(%d, %c, %d) ", a.etat[s].num, a.etat[s].arrayTrans[k].caractere, a.etat[s].arrayTrans[k].arrive);
			flag_transition = true;
		}
	if(flag_transition == false) 
		printf("Vide\n");
	printf("\n\n");


}

// Permet de initialisé un etat de l'automate fini non déterministe
AFND set_etat_AFND(AFND automate, int num_etat, int num, bool initial, bool accepteur, int nb_transition){
	automate.etat[num_etat].num = num;
	automate.etat[num_etat].initial = initial;
	automate.etat[num_etat].accepteur = accepteur;
	automate.etat[num_etat].nb_transition = nb_transition;

	return automate;
}

// Permet de initialisé un état UN transition d'un état de l'automate fini non déterministe
AFND set_transition_AFND(AFND automate, int num_etat, int num_trans, int arrive, char caractere){
	automate.etat[num_etat].arrayTrans[num_trans].depart = num_etat;
	automate.etat[num_etat].arrayTrans[num_trans].caractere = caractere;
	automate.etat[num_etat].arrayTrans[num_trans].arrive = arrive;

	return automate;
}

void afficher_alphabet(AFND a){
	for(int i=0; i<a.taille_alphabet; i++){
		printf("%c ", a.alphabet[i]);
	}
	printf("\n");
}

//Initialise les numéros des états de départ de chaque transition à -1
AFND init_arrayTransition(AFND a) {
	for(int i=0; i<TAILLE_ETAT; i++)
		for(int j=0; j<TAILLE_TRANSITION; j++)
			a.etat[i].arrayTrans[j].arrive = -1;
		
	return a;
}

//Initialise les numéros des états à -1
AFND init_etat(AFND a) {
	for(int i=0; i<TAILLE_ETAT; i++){
		a.etat[i].num = -1;
		a.etat[i].initial = false;
		a.etat[i].accepteur = false;
		a.etat[i].nb_transition = 0;
	}
	
	return a;
}

//Renvoie un automate fini non déterministe reconnaissant le langage vide
// Si le premier numero du caractère de l'alphabet est -1, alors il est vide
AFND langage_vide(){
	AFND automate; 

	automate.taille_alphabet = 0;
	automate.alphabet[0];

	automate = init_etat(automate);
	automate.nb_etats = 1;

	automate = init_arrayTransition(automate);
		

	automate.etat[0].num = 0;
	automate.etat[0].initial = true;

	// On les remet pour que ce soit clair vu qu'elles sont déjà initialisée de base
	automate.etat[0].accepteur = false; 
	automate.etat[0].nb_transition = 0;

	return automate;

}

//Renvoie un automate fini non déterministe reconnaissant le mot vide
AFND mot_vide(){
	AFND automate; 

	automate.taille_alphabet = 0;
	automate.alphabet[0];

	automate = init_etat(automate);
	automate.nb_etats = 1;
	
	automate = init_arrayTransition(automate);

	automate.etat[0].num = 0;
	automate.etat[0].initial = true;
	automate.etat[0].accepteur = true;

	// On le remet pour que ce soit clair, parce qu'elle est déjà initialisé
	automate.etat[0].nb_transition = 0;

	return automate;
}

//Renvoie un automate fini non déterministe reconnaissant le language composé d'un mot d'un caractere passé en parametre
AFND un_mot(char mot) {
	AFND automate ;
	Etat etat_initial,etat_final;
	Transition transition;

	automate = init_etat(automate);
	
	automate.nb_etats = 1;
	etat_initial.num = 0;
	etat_initial.initial = true;
	etat_initial.accepteur = false;
	etat_initial.nb_transition = 1;
	
	etat_final.num = 1;
	etat_final.initial = false;
	etat_final.accepteur = true;
	etat_final.nb_transition = 1;

	transition.arrive = 0;
	transition.caractere = mot;

	automate = init_arrayTransition(automate);
	etat_initial.arrayTrans[0] = transition;

	automate.taille_alphabet = 1;
	automate.alphabet[0] = mot;
	automate.nb_etats = 2;
	automate.etat_init = etat_initial;
	automate.etat[0] = etat_initial;
	automate.etat[1] = etat_final;

	return automate;
}

// Fait la réunion de deux automates et le met dans a1
// L'état initial est forcement 0
AFND reunion_automate(AFND a1, AFND a2) {
	a1 = reunion_alphabet(a1, a2);

	int num_etat = a1.nb_etats;

	for(int i=1; i<a2.nb_etats; i++) {
		a1 = set_etat_AFND(a1, num_etat+i-1, num_etat+i-1, a2.etat[i].initial, a2.etat[i].accepteur, a2.etat[i].nb_transition);
	}

	for(int i=0; i<a2.nb_etats; i++){
		for(int j=0; j<a2.etat[i].nb_transition; j++){
			if(i == 0){
				a1 = set_transition_AFND(a1, 0, a1.etat[i].nb_transition+j, num_etat+i, a2.etat[i].arrayTrans[j].caractere);
			}else{
				a1 = set_transition_AFND(a1, num_etat+j-1, j, num_etat, a2.etat[i].arrayTrans[j].caractere);
			}
		}	
		if(i == 0) 
			a1.etat[0].nb_transition += a2.etat[0].nb_transition;
		else
			a1.etat[0].nb_transition += a2.etat[num_etat].nb_transition;
		num_etat++;
	}	

	a1.nb_etats += a2.nb_etats -1;

	return a1;
}

// Ajoute l'alphaber de a2 dans a1
AFND reunion_alphabet(AFND a1, AFND a2) {
	// Recherche pour avoir la taille du tableau
	// et Ajoute au tableau
	int count = a1.taille_alphabet;
	bool flag = false;
	for(int j=0; j<a2.taille_alphabet; j++) {
		for(int i=0; i<a1.taille_alphabet; i++) {
			if(a1.alphabet[i] == a2.alphabet[j]){
				flag = true;
				break;
			}
		}
		if(flag == false){
			a1.alphabet[count]=a2.alphabet[j];
			count++;
		}
		flag = false;
	}

	a1.taille_alphabet = count;

	return a1;
}

// Concatenation de a2 dans a1
AFND concatenation_AFND(AFND a1, AFND a2){

	int etatF_a1;
	int etatI_a2;

	// Renvoie a1 s'il n'y a pas d'état accepteur dans a1
	bool flag = false;
	for(int i=0; i<a1.nb_etats; i++){ // Cherche s'il a un etat accepteur
		if( a1.etat[i].accepteur == true ){
			flag = true;
			etatF_a1 = i;
			break;
		}
	}
	if(flag == false)
		return a1;


	// Recherche l'état initial de a2 pour ses transitions
	for(int i=0; i<a1.nb_etats; i++){ // Cherche s'il a un etat initial
		if( a2.etat[i].initial == true ){
			flag = true;
			etatI_a2 = i;
			break;
		}
	}
	if(flag == false)
		return a1;

	// Retire l'état initial de a2
	a2 .etat[etatI_a2].initial = false;

	// Retire l'état accepteur de a1
	a1.etat[etatF_a1].accepteur = false;

	a1 = reunion_alphabet(a1, a2);
	
	// Réunion des états
	int count_etat = a1.nb_etats -1;
	int count_trans;
	int count = 0;
	for(int i=0; i<a2.nb_etats; i++) {
		a1 = set_etat_AFND(a1, count_etat, count_etat, a2.etat[i].initial, a2.etat[i].accepteur, a2.etat[i].nb_transition);
		for(int j=0; j<a2.etat[i].nb_transition; j++) {
			a1 = set_transition_AFND(a1, count_etat, j, count_etat+a2.etat[i].arrayTrans[j].arrive - count, a2.etat[i].arrayTrans[j].caractere);
		}
		count_etat++;
		count++;
	}
	a1.nb_etats += a2.nb_etats;
	a1.nb_etats--;

	// Rajouter les transitions de a2 initial à a1 final
	// for(int i=0; i<a1.etat[etatI_a2].nb_transition; i++) {
	// 	a1 = set_transition_AFND(a1, etatF_a1, a2.etat[etatI_a2].nb_transition, a2.etat[etatI_a2].arrayTrans[i].arrivee, a2.etat[etatI_a2].arrayTrans[i].caractere);		
	// }
	// a1.etat[etatF_a1].nb_transition += a2.etat[etatI_a2].nb_transition;


	return a1;

}

// // Ajouter transition
// Transition* add_transition(Transition transition, Transition* arrayTrans)
// {
// 	for(int i=0; i<TAILLE_TRANSITION; i++)
// 	{
// 		while(arrayTrans[i].arrive != -1)
// 			continue;
// 		arrayTrans[i].arrive = transition.arrive;
// 		arrayTrans[i].caractere = transition.caractere;
// 		return arrayTrans;
// 	}
// }


// // Fermeture iterative de Kleene
// AFND kleene(AFND automate)
// {
// 	Transition transition;
// 	int j;

// 	for(int i=0; i< TAILLE_ETAT; i++)
// 	{
// 		if(automate.etat[i].accepteur == true)
// 		{
// 			if(automate.etat[i].initial == false)
// 			{
// 				for(j=0; j<TAILLE_TRANSITION; j++)
// 				{
// 					while(j < automate.etat_init.num)
// 						continue;
// 					transition.arrive = automate.etat[i].num;
// 					transition.caractere = automate.etat[i].arrayTrans[j].caractere;
// 					automate.etat[i].arrayTrans = add_transition(transition, automate.etat[i].arrayTrans);
// 				}
				
// 			}
// 		}
// 	}

// 	return automate;
// }

