#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "automateFiniNonDeterministe.h"
#include "automateFiniDeterministe.h"
#include "constante.h"

int main(){
	system("clear");
	int choix = 0;
	AFD a;
	AFND a1;
	AFND a2;

	printf("****Dans un souci de simplification de la correction, nous avons déjà préprogrammer les automates ****\n");
	printf("**Seul les chiffres qui sont proposer afficherons quelque chose.**\n\n");
	printf("Veillez choisir une option.\n");
	printf("1) Renvoie un Automate Standard du langage vide\n");
	printf("2) Renvoie un Automate Standard du mot vide\n");
	printf("3) Renvoie un Automate composé d'un mot passer en paramètre\n");
	printf("4) Renvoie un Automate qui fait la réunion de deux automates\n");
	printf("5) Renvoie la concaténation de deux automates\n");
	printf("6) Renvoie un automate mit a l'étoile\n");
	printf("7) Renvoie un automate minimisé\n");
	printf("8) Renvoie la lecture de l'automate\n\n");
	scanf("%d", &choix);

	switch(choix){
		case 1:
			printf("\n**Le langage vide**\n");
			a1 = langage_vide();
			affichage_AFND(a1);
			break;
		case 2:	
			printf("\n****Le mot vide****\n");
			a1 = mot_vide();
			affichage_AFND(a1);
			break;
		case 3:	
			printf("\n****Le mot****\n");
			// a1 = un_mot();
			/*
		Il faut que tu faces ton exemple !!!!!!!!!!!!!!!!
			*/
			// affichage_AFND(a1);
			break;
		case 4:	
			printf("\n****La réunion****\n");
			a1.nb_etats = 2;
			a1.taille_alphabet = 1;
			a1.alphabet[0] = 'a';

			a1 = set_etat_AFND(a1, 0, 0, true, false, 1);
			a1 = set_etat_AFND(a1, 1, 1, false, true, 0);
			a1 = set_transition_AFND(a1, 0, 0, 1, 'a');
			printf("**Automate 1**\n");
			affichage_AFND(a1);


			a2.nb_etats = 4;
			a2.taille_alphabet = 2;
			a2.alphabet[0] = 'b';
			a2.alphabet[1] = 'c';
			a2 = set_etat_AFND(a2, 0, 0, true, false, 2);
			a2 = set_etat_AFND(a2, 1, 1, false, false, 1);
			a2 = set_etat_AFND(a2, 2, 2, false, false, 1);
			a2 = set_etat_AFND(a2, 3, 3, false, true, 0);
			a2 = set_transition_AFND(a2, 0, 0, 1, 'b');
			a2 = set_transition_AFND(a2, 0, 1, 1, 'c');
			a2 = set_transition_AFND(a2, 1, 0, 2, 'b');
			a2 = set_transition_AFND(a2, 2, 0, 3, 'b');
			printf("**Automate 2**\n");
			affichage_AFND(a2);

			printf("\n");

			a1= reunion_automate(a1, a2);
			printf("**Automate Final**\n");
			affichage_AFND(a1);
			break;
		case 5:
			printf("\n****La concaténation****\n");
			a1.nb_etats = 2;
			a1.taille_alphabet = 1;
			a1.alphabet[0] = 'a';

			a1 = set_etat_AFND(a1, 0, 0, true, false, 1);
			a1 = set_etat_AFND(a1, 1, 1, false, true, 0);
			a1 = set_transition_AFND(a1, 0, 0, 1, 'a');
			printf("**Automate 1**\n");
			affichage_AFND(a1);

			a2.nb_etats = 4;
			a2.taille_alphabet = 2;
			a2.alphabet[0] = 'b';
			a2.alphabet[1] = 'c';
			a2 = set_etat_AFND(a2, 0, 0, true, false, 2);
			a2 = set_etat_AFND(a2, 1, 1, false, false, 1);
			a2 = set_etat_AFND(a2, 2, 2, false, false, 1);
			a2 = set_etat_AFND(a2, 3, 3, false, true, 0);
			a2 = set_transition_AFND(a2, 0, 0, 1, 'b');
			a2 = set_transition_AFND(a2, 0, 1, 1, 'c');
			a2 = set_transition_AFND(a2, 1, 0, 2, 'b');
			a2 = set_transition_AFND(a2, 2, 0, 3, 'b');
			printf("**Automate 2**\n");
			affichage_AFND(a2);


			printf("\n");

			a1 = concatenation_AFND(a1, a2);
			printf("**Automate Final**\n");
			affichage_AFND(a1);
			break;
		case 6:
			printf("\n****Mise a l'étoile****\n");
			/*
		Ton truc a l'étoile
			*/
			break;
		case 7:
			printf("\n****La minimisation****\n");
			a.nb_etats = 8;
			a.taille_alphabet = 2;
			a.alphabet[0] = 'a';
			a.alphabet[1] = 'b';

			a = set_etat_AFD(a, 0, 0, true, false, 2);
			a = set_transition_AFD(a, 0, 0, 0, 'a');
			a = set_transition_AFD(a, 0, 1, 4, 'b');

			a = set_etat_AFD(a, 1, 1, false, false, 2);
			a = set_transition_AFD(a, 1, 0, 1, 'a');
			a = set_transition_AFD(a, 1, 1, 4, 'b');

			a = set_etat_AFD(a, 2, 2, false, false, 2);
			a = set_transition_AFD(a, 2, 0, 3, 'a');
			a = set_transition_AFD(a, 2, 1, 5, 'b');
			
			a = set_etat_AFD(a, 3, 3, false, false, 2);
			a = set_transition_AFD(a, 3, 0, 2, 'a');
			a = set_transition_AFD(a, 3, 1, 7, 'b');

			a = set_etat_AFD(a, 4, 4, false, false, 2);
			a = set_transition_AFD(a, 4, 0, 1, 'a');
			a = set_transition_AFD(a, 4, 1, 3, 'b');

			a = set_etat_AFD(a, 5, 5, false, true, 2);
			a = set_transition_AFD(a, 5, 0, 2, 'a');
			a = set_transition_AFD(a, 5, 1, 6, 'b');

			a = set_etat_AFD(a, 6, 6, false, true, 2);
			a = set_transition_AFD(a, 6, 0, 7, 'a');
			a = set_transition_AFD(a, 6, 1, 6, 'b');

			a = set_etat_AFD(a, 7, 7, false, true, 2);
			a = set_transition_AFD(a, 7, 0, 6, 'a');
			a = set_transition_AFD(a, 7, 1, 6, 'b');

			printf("**Automate**\n");
			affichage_AFD(a);

			a=minimisation(a);

			printf("\n\n**Automate Minimisé**\n");
			affichage_AFD(a);
			break;
		default:
			printf("Erreur.\n");
	}



	return 0;
}