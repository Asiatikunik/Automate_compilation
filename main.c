#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "automateFiniNonDeterministe.h"
#include "automateFiniDeterministe.h"
#include "constante.h"

int main(){

	AFD a;
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

	// affichage_AFD(a);

	// a = minimisation(a);
	a=minimisation2(a);
	affichage_AFD(a);
	
	return 0;
}