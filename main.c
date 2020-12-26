#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "automateFiniNonDeterministe.h"

int main(){
	
	AFND automate = langage_vide();
	affichage_AFND(automate);

	AFND automate2 = mot_vide();
	affichage_AFND(automate2);
	
	return 0;
}