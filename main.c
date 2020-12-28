#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "automateFiniNonDeterministe.h"

int main(){
	
	AFND a1;
	a1.nb_etats = 2;
	a1.taille_alphabet = 1;
	a1.alphabet[0] = 'a';

	a1 = set_etat(a1, 0, 0, true, false, 1);
	a1 = set_etat(a1, 1, 1, false, true, 0);
	a1 = set_transition(a1, 0, 0, 1, 'a');
	affichage_AFND(a1);


	AFND a2;
	a2.nb_etats = 2;
	a2.taille_alphabet = 2;
	a2.alphabet[0] = 'b';
	a2.alphabet[1] = 'c';
	a2 = set_etat(a2, 0, 0, true, false, 2);
	a2 = set_etat(a2, 1, 1, false, true, 0);
	a2 = set_transition(a2, 0, 0, 1, 'b');
	a2 = set_transition(a2, 0, 1, 1, 'c');
	affichage_AFND(a2);


	printf("\n");

	a1 = concatenation_AFND(a1, a2);
	affichage_AFND(a1);
	
	return 0;
}