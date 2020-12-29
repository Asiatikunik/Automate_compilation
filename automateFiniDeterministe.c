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

TabTrans recupere_tabTransitionBis(AFD a) {
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

	afficher_tabTrans(tt);

	return tt;

}

// Permet de initialisé un etat de l'automate
AFD set_etat_afd(AFD automate, int num_etat, int num, bool initial, bool accepteur, int nb_transition){
	automate.etat[num_etat].num = num;
	automate.etat[num_etat].initial = initial;
	automate.etat[num_etat].accepteur = accepteur;
	automate.etat[num_etat].nb_transition = nb_transition;

	return automate;
}

// Permet de initialisé un état UN transition d'un état de l'automate
AFD set_transition_afd(AFD automate, int num_etat, int num_trans, int arrivee, char caractere){
	automate.etat[num_etat].arrayTrans[num_trans].arrivee = arrivee;
	automate.etat[num_etat].arrayTrans[num_trans].caractere = caractere;

	return automate;
}

Etat find_etat(AFD automate, int num)
{
	Etat etat;
	etat.num = num;
	etat.initial = automate.etat[num].initial;
	etat.accepteur = automate.etat[num].accepteur;
	etat.nb_transition = automate.etat[num].nb_transition;
	
	for(int i=0; i<TAILLE_TRANSITION; i++)
	{
		etat.arrayTrans[i] = automate.etat[num].arrayTrans[i];
	}

	return etat;
}

Trans getTransition(TabTrans tabTrans, Etat etat, char lettre)
{
	Trans transition;
	for(int i=0; i<TAILLE_TRANSITION; i++)
	{
		if(tabTrans.array[i].depart == etat.num && tabTrans.array[i].caractere == lettre)
		{
			transition.depart = etat.num;
			transition.caractere = lettre;
			transition.arrive = tabTrans.array[i].arrive;
			break;
		}
	}

	return transition;
}
//Executer afd sur un mot en parametre
void execution_afd(AFD automate, char* mot)
{
	int i=0;
	int taille_mot = 0;
	bool found = false;
	TabTrans tabTrans;
	Trans transition;
	Etat etat = automate.etat_init;
	while(mot[i] != '\n' && mot[i] != '\n')
	{
		taille_mot++;
		i++;
	}
	
	for(i=0; i<taille_mot; i++)
	{
		for(int j=0; j<TAILLE_ALPHABET; j++)
		{
			if(mot[i] == automate.alphabet[j])
				{
					found = true;
					break;
				}
		}

		if(found == true)
		{
			tabTrans = recupere_tabTransitionBis(automate);
			transition = getTransition(tabTrans, etat, mot[i]);
			etat = find_etat(automate, transition.arrive);
		}
	}

	if(etat.accepteur == true)
	{
		printf("L'automate a reconnu le mot!! \n");
	}
	else
	{
		printf("L'automate n'a pas pu reconnaître le mot!\n");
	}
	
	
}