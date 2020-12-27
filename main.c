#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "automateFiniNonDeterministe.h"

int main(){
	
	AFND a1;
	a1.taille_alphabet = 3;
	a1.alphabet[0] = 'a';
	a1.alphabet[1] = 'b';
	a1.alphabet[2] = 'c';
	// affichage_AFND(a);
	afficher_alphabet(a1);

	AFND a2 = mot_vide();
	a2.taille_alphabet = 4;
	a2.alphabet[0] = 'a';
	a2.alphabet[1] = 'd';
	a2.alphabet[2] = 'e';
	a2.alphabet[3] = 'f';
	// affichage_AFND(a2);
	afficher_alphabet(a2);

	printf("\n");

	a1 = reunion_alphabet(a1, a2);
	printf("new alphabet: \n");
	afficher_alphabet(a1);
	printf("%d \n", a1.taille_alphabet);
	
	return 0;
}