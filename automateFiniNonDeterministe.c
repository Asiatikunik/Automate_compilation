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
				printf("(%d, %c, %d) ", a.etat->num, a.etat[s].arrayTrans[k].caractere, a.etat[s].arrayTrans[k].depart);
	}
	printf("\n\n");


}

Transition* init_arrayTransition()
{
	static Transition arrayTrans[TAILLE_TRANSITION];
	for(int i=0; i<TAILLE_TRANSITION; i++)
		arrayTrans[i].depart = -1;
	return arrayTrans;
}

Etat* init_etat()
{
	static Etat etat[TAILLE_ETAT];
	
	for(int i=0; i<TAILLE_ETAT; i++)
		etat->num = -1;
	
	return etat;
}
//Renvoie un automate fini non déterministe reconnaissant le langage vide
// Si le premier numero du caractère de l'alphabet est -1, alors il est vide
AFND langage_vide(){
	AFND automate; 

	automate.taille_alphabet = 0;
	automate.alphabet[0];

	for(int i=0; i<TAILLE_ETAT;i++)
	{
		automate.etat = init_etat();
	}
	automate.nb_etats = 1;

	for(int i=0; i<TAILLE_ETAT;i++)
	{
		automate.etat[i].arrayTrans = init_arrayTransition();
	}

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

	for(int i=0; i<TAILLE_ETAT;i++)
	{
		automate.etat = init_etat();
	}
	automate.nb_etats = 1;
	
	for(int i=0; i<TAILLE_ETAT;i++)
	{
		automate.etat[i].arrayTrans = init_arrayTransition();
	}
	//automate.etat[1];

	automate.etat[0].num = 0;
	automate.etat[0].initial = true;
	automate.etat[0].accepteur = true;
	automate.etat[0].nb_transition = 0;

	return automate;
}

//Renvoie un automate fini non déterministe reconnaissant le language composé d'un mot d'un caractere passé en parametre
AFND un_mot(char mot)
{
	AFND automate ;
	Etat etat_initial,etat_final;
	Transition transition;

	for(int i=0; i<TAILLE_ETAT;i++)
	{
		automate.etat = init_etat();
	}
	
	automate.nb_etats = 1;
	etat_initial.num = 0;
	etat_initial.initial = true;
	etat_initial.accepteur = false;
	etat_initial.nb_transition = 1;
	
	etat_final.num = 1;
	etat_final.initial = false;
	etat_final.accepteur = true;
	etat_final.nb_transition = 1;

	transition.depart = 0;
	transition.caractere = mot;

	for(int i=0; i<TAILLE_ETAT;i++)
	{
		automate.etat[i].arrayTrans = init_arrayTransition();
	}
	etat_initial.arrayTrans[0] = transition;

	automate.taille_alphabet = 1;
	automate.alphabet[0] = mot;
	automate.nb_etats = 2;
	automate.etat_init = etat_initial;
	automate.etat[0] = etat_initial;
	automate.etat[1] = etat_final;

	return automate;
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
	// reunion_alphabet(a1, a2);

	//Renvoie a1 s'il n'y a pas d'état accepteur dans a1
	bool flag = false;
	for(int i=0; i<a1.nb_etats; i++){
		if( a1.etat[i].accepteur == true ){
			flag = true;
			break;
		}
	}
}
// Ajouter transition
Transition* add_transition(Transition transition, Transition* arrayTrans)
{
	for(int i=0; i<TAILLE_TRANSITION; i++)
	{
		while(arrayTrans[i].depart != -1)
			continue;
		arrayTrans[i].depart = transition.depart;
		arrayTrans[i].caractere = transition.caractere;
		return arrayTrans;
	}
}
// Fermeture iterative de Kleene
AFND kleene(AFND automate)
{
	Transition transition;
	int j;

	for(int i=0; i< TAILLE_ETAT; i++)
	{
		if(automate.etat[i].accepteur == true)
		{
			if(automate.etat[i].initial == false)
			{
				for(j=0; j<TAILLE_TRANSITION; j++)
				{
					while(j < automate.etat_init.num)
						continue;
					transition.depart = automate.etat[i].num;
					transition.caractere = automate.etat[i].arrayTrans[j].caractere;
					automate.etat[i].arrayTrans = add_transition(transition, automate.etat[i].arrayTrans);
				}
				
			}
		}
	}

	return automate;
}
//Retourne l'automate 1 avec son alphabet = reunion des alphabets des 2 automates en parametre
/*AFND reunion_language(AFND automate1, AFND automate2)
{
	if(automate1.taille_alphabet == 0)
	{
		for(int i=0; i<TAILLE_ALPHABET; i++)
			automate1.alphabet[i] = automate2.alphabet[i];
		return automate1;
	}
	else if(automate2.taille_alphabet == 0)
		return automate1;
	
		
}*/
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
