#include <stdio.h>
#include <stdlib.h>

#include "automateFiniNonDeterministe.h"
#include "automateFiniDeterministe.h"
#include "constante.h"

TabTrans init_tabTrans(TabTrans tt) {
	for(int i=0; i<TAILLE_TRANSITION; i++) {
		tt.array[i].depart = -1;
		tt.array[i].caractere = '.';
		tt.array[i].arrive = -1;
	}
}

void afficher_tabTrans(TabTrans tt){
	for(int i=0; i<tt.taille; i++) 
		printf("(%d, %c, %d) \n", tt.array[i].depart, tt.array[i].caractere, tt.array[i].arrive);
}

TabTrans recupere_tabTransitionBis(AFND a) {
	TabTrans tt;

	int count = 0;
	for(int s=0; s<a.nb_etats; s++)
		for(int k=0; k<a.etat[s].nb_transition; k++){
				tt.array[count].depart = a.etat[s].num;
				tt.array[count].caractere = a.etat[s].arrayTrans[k].caractere;
				tt.array[count].arrive = a.etat[s].arrayTrans[k].arrivee;
			count++;
		}
	printf("\n");

	tt.taille = count;

	// afficher_tabTrans(tt);

	return tt;

}
