#include <stdio.h>
#include <stdlib.h>

#include "automateFiniNonDeterministe.h"
#include "automateFiniDeterministe.h"
#include "constante.h"

//Affiche un automate fini non déterministe
void affichage_AFD(AFD a){
	bool flag_accepteur = false;
	bool flag_transition = false;

	printf("Alphabet: ");
	if(a.taille_alphabet == false)
		printf("Vide");
	else{
		for(int s=0; s<a.taille_alphabet; s++){
			printf("%c ", a.alphabet[s]);
		}
	}
	printf("\n");

	// printf("Nombre d'états: %d \n", a.nb_etats);

	printf("Liste des états: ");
	if(a.nb_etats == 0){
		printf("Vide");
	}else{
		for(int s=0; s<a.nb_etats; s++){
			printf("%d ", a.etat[s].num);
		}
	}
	printf("\n");

	printf("Etat d'initial: ");
	for(int s=0; s<a.nb_etats; s++){
		if(a.etat[s].initial == true)
			printf("%d ", a.etat[s].num);
	}
	printf("\n");

	printf("Etat accepteur: ");
	for(int s=0; s<a.nb_etats; s++){
		if(a.etat[s].accepteur == true){
			flag_accepteur = true;
			printf("%d ", a.etat[s].num);
		}
	}
	if(flag_accepteur == false)
		printf("Vide");
	printf("\n");

	printf("Transition: ");	
	for(int s=0; s<a.nb_etats; s++)
		for(int k=0; k<a.etat[s].nb_transition; k++){
			printf("(%d, %c, %d) ", a.etat[s].num, a.etat[s].arrayTrans[k].caractere, a.etat[s].arrayTrans[k].arrive);
			flag_transition = true;
		}
	if(flag_transition == false) 
		printf("Vide\n");
	printf("\n\n");


}


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


TabTrans2 recupere_tabTransition2(AFD a) {
	TabTrans2 tt;
	tt.taille_etat = a.nb_etats;
	tt.taille_alph = a.taille_alphabet;
	int test_array[a.nb_etats][a.taille_alphabet];

	for(int s=0; s<a.nb_etats; s++){
		for(int alph=0; alph < a.taille_alphabet; alph++){
			for(int k=0; k<a.etat[s].nb_transition; k++){
				if(a.alphabet[alph] ==  a.etat[s].arrayTrans[k].caractere){
					tt.array[s][alph] = a.etat[s].arrayTrans[k].arrive;
				}
			}
		}
	}

	return tt;
}

TabTrans recupere_tabTransitionBis(AFD a) {
	TabTrans tt;

	int count = 0;
	for(int s=0; s<a.nb_etats; s++)
		for(int k=0; k<a.etat[s].nb_transition; k++){
				tt.array[count].depart = a.etat[s].num;
				tt.array[count].caractere = a.etat[s].arrayTrans[k].caractere;
				tt.array[count].arrive = a.etat[s].arrayTrans[k].arrive;
			count++;
		}
	printf("\n");

	tt.taille = count;

	// afficher_tabTrans(tt);

	return tt;
}


// Permet de initialisé un etat de l'automate fini déterministe
AFD set_etat_AFD(AFD automate, int num_etat, int num, bool initial, bool accepteur, int nb_transition){
	automate.etat[num_etat].num = num;
	automate.etat[num_etat].initial = initial;
	automate.etat[num_etat].accepteur = accepteur;
	automate.etat[num_etat].nb_transition = nb_transition;

	return automate;
}

// Permet de initialisé un état UN transition d'un état de l'automate fini déterministe
AFD set_transition_AFD(AFD automate, int num_etat, int num_trans, int arrive, char caractere){
	automate.etat[num_etat].arrayTrans[num_trans].depart = num_etat;
	automate.etat[num_etat].arrayTrans[num_trans].caractere = caractere;
	automate.etat[num_etat].arrayTrans[num_trans].arrive = arrive;

	return automate;
}

// Regard le nombre de chiffre different dans un tab
// Fonction pour la minimisation
int groupe_different_tt(int* tab, int taille){
	int count=0;

	for(int i=0; i<taille; i++) {
		for(int j=0; j<taille; j++){
			if(tab[j] == i){
				// tab[i] = -1;
				count++;
				break;		
			}
		}
	}

	return count;
}

// Regard si la valeur existe dans le tab 0 1 2 2 1 3
// Fonction pour la minimisation
bool existe_tab(int* tab, int taille, int indice){
	for(int i=0; i<taille; i++)
		if(i != indice && tab[indice] == tab[i]) 
			return true;
			
	return false;		
}

bool isUnique(int* tab, int taille, int valeur){
	int count = 0;
	for(int i=0; i<taille; i++)
		if(tab[i] == valeur)
			count++;
		
			
			
	if(count == 1)
		return true;
	else
		return false;
		
}

AFD minimisation(AFD a){
	
	TabTrans2 tt = recupere_tabTransition2(a);
	int groupe2d[tt.taille_etat][tt.taille_alph];
	int groupe[tt.taille_etat];

	AFD returned;
// etape initial  
	for(int i=0; i<tt.taille_etat; i++) // Set le tableau en groupe
		if(a.etat[i].accepteur == false)
			groupe[i] = 0;
		else
			groupe[i] = 1;

// setup groupe2d
	for(int i=0; i<tt.taille_etat; i++)
		for(int j=0; j<tt.taille_alph; j++)
			groupe2d[i][j] = groupe[tt.array[i][j]];
		

// processing
	int currentGroups = groupe_different_tt(groupe,tt.taille_etat);
	int currentGroupsCopy = currentGroups;
	for(int n=0; n<5; n++){
		for(int cg = 0; cg < currentGroups; cg++){
			// only run on non-uniques
			if(isUnique(groupe,tt.taille_etat,cg))
				continue;

			for(int i=0; i<tt.taille_etat; i++){

				// we only run the logic on the same group (group by group)
				if(groupe[i] != cg) 
					continue;

				// a mettre dans une autre method: check si pour une lettre precise, les resultat sont les memes
				bool currentFlag = true;
				for(int j=0; j<tt.taille_alph; j++){

					// [START] check if has sameLogic
					bool hasSameLogic = true;
					int previousValue = -1;
					for(int _i=0; _i<tt.taille_etat; _i++){

						// we only run the logic on the same group (group by group)
						if(groupe[_i] != cg) 
							continue;

						if(previousValue == -1)
							previousValue = groupe2d[_i][j];
						else if(previousValue != groupe2d[_i][j])
							hasSameLogic = false;
					}
					// [END] check if has sameLogic

					// check si on change le groupe
					if(groupe2d[i][j] != cg && !hasSameLogic){
						//change de groupe
						currentFlag = false;
					}
				}

				// update groupe2D with new group number
				if(!currentFlag){
					for(int j=0; j<tt.taille_alph; j++)
						groupe[i] = currentGroupsCopy;		
					currentGroupsCopy++;
				}
			}
		}

		// [START] regenerate groupe2d
		for(int i=0; i<tt.taille_etat; i++)
			for(int j=0; j<tt.taille_alph; j++)
				groupe2d[i][j] = groupe[tt.array[i][j]];
		// [END] regenerate groupe2d

		currentGroups = groupe_different_tt(groupe,tt.taille_etat);
	}

	returned.nb_etats = groupe_different_tt(groupe, a.nb_etats);
	returned.taille_alphabet = a.taille_alphabet;
	for(int i=0; i<a.taille_alphabet; i++){
		returned.alphabet[i] = a.alphabet[i];
	}

	for(int i=0; i<a.nb_etats; i++) // cherche état initial
		if(a.etat[i].initial == true){
			returned = set_etat_AFD(returned, 0, 0, true, false, a.etat[i].nb_transition);
			for(int j=0; j<a.etat[i].nb_transition; j++){
				returned = set_transition_AFD(returned, i, j, a.etat[i].arrayTrans[j].arrive, a.etat[i].arrayTrans[j].caractere);
			}
		}
		
	for(int i=0; i<a.nb_etats; i++){
		if(a.etat[i].initial == false)
			if(a.etat[i].accepteur == true)
				returned = set_etat_AFD(returned, i, i, false, true, a.etat[i].nb_transition);
			else
				returned = set_etat_AFD(returned, i, i, false, false, a.etat[i].nb_transition);
			for(int j=0; j<a.etat[i].nb_transition; j++)
				returned = set_transition_AFD(returned, i, j, a.etat[i].arrayTrans[j].arrive, a.etat[i].arrayTrans[j].caractere);
			
	}

	return returned;

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
AFD set_transition_afd(AFD automate, int num_etat, int num_trans, int arrive, char caractere){
	automate.etat[num_etat].arrayTrans[num_trans].arrive = arrive;
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

Transition getTransition(TabTrans tabTrans, Etat etat, char lettre) {
	Transition transition;
	for(int i=0; i<TAILLE_TRANSITION; i++) {
		if(tabTrans.array[i].depart == etat.num && tabTrans.array[i].caractere == lettre) {
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
	Transition transition;
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