#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "automateFiniNonDeterministe.h"
#include "automateFiniDeterministe.h"
#include "constante.h"

int main(){

	AFND a;
	a.nb_etats = 2;
	a.taille_alphabet = 2;
	a.alphabet[0] = 'a';
	a.alphabet[1] = 'b';
	a = set_etat(a, 0, 0, true, false, 2);
	a = set_etat(a, 1, 1, false, true, 0);
	a = set_transition(a, 0, 0, 1, 'a');
	a = set_transition(a, 0, 1, 1, 'b');
	// affichage_AFND(a);


	TabTrans tt;
	tt = recupere_tabTransitionBis(a);

	
	return 0;
}