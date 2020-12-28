#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "automateFiniNonDeterministe.h"

int main(){
	
	AFND a1;
	a1.nb_etats = 1;
	a1.taille_alphabet = 1;
	a1.alphabet[0] = 'a';

	AFND a2;
	a2.nb_etats = 2;
	a2.taille_alphabet = 1;
	a2.alphabet[0] = 'a';
	// a2.etat = malloc(a2.nb_etats * sizeof(Etat));
	// a2.etat[0].nb_transition = 1;
	// a2.etat[0].arrayTrans.


	printf("\n");

	// a1 = reunion_alphabet(a1, a2);
	// printf("new alphabet: \n");
	// afficher_alphabet(a1);
	// printf("%d \n", a1.taille_alphabet);
	
	return 0;
}