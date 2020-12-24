#ifndef AUTOMATEFININONDETERMINISTE
#define AUTOMATEFININONDETERMINISTE


// type caractère défini par un symbole, un numéro et le caractere suivant dans la liste
typedef struct Caractere Caractere;
struct Caractere {
	char symbole;
	int numero;
	//Caractere* caractere_suivant;
};

//type état défini par un numéro, s'il est accepteur (1) ou non (0) et l'état suivant dans la liste
typedef struct Etat Etat;
struct Etat {
	int num;
	int accepteur;
	//Etat* etat_suivant;
};

/* type transition défini par un état de départ, un état d'arrivée, un
 * caractère de transition.
 * liste chaînée
 */
typedef struct Transition Transition;
struct Transition{
	Etat* depart;
	Etat* arrivee;
	Caractere* caractere;
	Transition* transitionSuivante;
};

/* type automate fini non déterministe défini par
 * un alphabet (liste chainée de caractères)
 * un nombre d'états
 * une liste chainée d'états (les états accepteurs en premier)
 * un état initial
 * un tableau de listes chainées de transitions avec l'indice de la ligne représentant l'état de départ
 */
typedef struct AFND AFND;
struct AFND {
	Caractere* alphabet;
	int nombreEtats;
	Etat* liste_etat;
	Etat* etat_initial;
	Transition** tab_transition;
	//AFND* automate_suivant;
};

//Renvoie un automate non déterministe reconnaissant le langage vide
AFND* langage_vide();

//Renvoie un automate non déterministe reconnaissant le mot vide
AFND* mot_vide();

//Création d'un tableau de listes de transitions alloué dynamiquement
Transition** init_tab_transition(int taille);

//Création de la liste des caracteres allouée dynamiquement
Caractere* init_list_caractere(int taille);

//Création de la liste des états allouée dynamiquement
Etat* init_list_etat(int taille);

/*Transition* init_list_transition(int taille)
{
	Transition* list_transition = NULL;
	list_transition = malloc(taille * sizeof(Transition));

	for(int i=0;i<taille;i++)
		list_transition[i] = NULL;

	return list_transition;
}*/
#endif