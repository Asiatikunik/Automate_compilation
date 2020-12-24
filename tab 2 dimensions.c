#include <stdio.h>
#include <stdlib.h>

#define TAILLE_TAB 5
#define VIDE '.'

void initTab(char ***tab, int taille){
	int i,j;
	*tab = (char**) calloc (taille, sizeof(char*));
	for(i=0; i<taille; i++) {
		(*tab)[i] = (char*)calloc(taille, sizeof(char));
		for(j=0;j<taille;j++) {
			(*tab)[i][j] = VIDE;
		}
	}
}

void affTab(char **tab, int taille){
	int i,j;
	char car;
	for(i=0;i<taille;i++) {
		for(j=0;j<taille;j++) {
			car = tab[i][j];
			printf("%c",car);
		}
    printf("\n");
	}
}

int main(){
	char **transition;

	initTab(&transition, TAILLE_TAB);	
	affTab(transition, TAILLE_TAB);

	for(int i=0; i<TAILLE_TAB; i++)
		free(transition[i]);
	free(transition);

	return 0;
}