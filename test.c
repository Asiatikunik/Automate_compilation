
// Reunion_alphabet
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

// Concat 
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

// Concat 2
	AFND a1;
	a1.nb_etats = 2;
	a1.taille_alphabet = 1;
	a1.alphabet[0] = 'a';

	a1 = set_etat(a1, 0, 0, true, false, 1);
	a1 = set_etat(a1, 1, 1, false, true, 0);
	a1 = set_transition(a1, 0, 0, 1, 'a');
	affichage_AFND(a1);


	AFND a2;
	a2.nb_etats = 3;
	a2.taille_alphabet = 2;
	a2.alphabet[0] = 'b';
	a2.alphabet[1] = 'c';
	a2 = set_etat(a2, 0, 0, true, false, 2);
	a2 = set_etat(a2, 1, 1, false, false, 1);
	a2 = set_etat(a2, 2, 2, false, true, 0);
	a2 = set_transition(a2, 0, 0, 1, 'b');
	a2 = set_transition(a2, 0, 1, 1, 'c');
	a2 = set_transition(a2, 1, 0, 2, 'b');
	affichage_AFND(a2);


	printf("\n");

	a1 = concatenation_AFND(a1, a2);
	affichage_AFND(a1);

// Concat 3
	AFND a1;
	a1.nb_etats = 2;
	a1.taille_alphabet = 1;
	a1.alphabet[0] = 'a';

	a1 = set_etat(a1, 0, 0, true, false, 1);
	a1 = set_etat(a1, 1, 1, false, true, 0);
	a1 = set_transition(a1, 0, 0, 1, 'a');
	affichage_AFND(a1);


	AFND a2;
	a2.nb_etats = 4;
	a2.taille_alphabet = 2;
	a2.alphabet[0] = 'b';
	a2.alphabet[1] = 'c';
	a2 = set_etat(a2, 0, 0, true, false, 2);
	a2 = set_etat(a2, 1, 1, false, false, 1);
	a2 = set_etat(a2, 2, 2, false, false, 1);
	a2 = set_etat(a2, 3, 3, false, true, 0);
	a2 = set_transition(a2, 0, 0, 1, 'b');
	a2 = set_transition(a2, 0, 1, 1, 'c');
	a2 = set_transition(a2, 1, 0, 2, 'b');
	a2 = set_transition(a2, 2, 0, 3, 'b');
	affichage_AFND(a2);


	printf("\n");

	a1 = concatenation_AFND(a1, a2);
	affichage_AFND(a1);

// minimisation
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

// Lire un automate 
	AFD a;
	char mot[10];

	a.nb_etats = 2;
	a.taille_alphabet = 3;
	a.alphabet[0] = 'a';
	a.alphabet[1] = 'b';
	a = set_etat_afd(a, 0, 0, true, false, 2);
	a = set_etat_afd(a, 1, 1, false, true, 2);
	a = set_etat_afd(a, 2, 2, false, true, 2);
	a = set_transition_afd(a, 0, 0, 1, 'a');
	a = set_transition_afd(a, 0, 1, 1, 'b');
	a = set_transition_afd(a, 1, 1, 2, 'b');
	//affichage_AFND(a);

	printf("Entrez le mot : ");
	fgets(mot, 10, stdin);

	execution_afd(a, mot);

	/*TabTrans tt;
	tt = recupere_tabTransitionBis(a);*/

// Réunion 
	AFND a1;
	a1.nb_etats = 2;
	a1.taille_alphabet = 1;
	a1.alphabet[0] = 'a';

	a1 = set_etat(a1, 0, 0, true, false, 1);
	a1 = set_etat(a1, 1, 1, false, true, 0);
	a1 = set_transition(a1, 0, 0, 1, 'a');
	affichage_AFND(a1);


	AFND a2;
	a2.nb_etats = 4;
	a2.taille_alphabet = 2;
	a2.alphabet[0] = 'b';
	a2.alphabet[1] = 'c';
	a2 = set_etat(a2, 0, 0, true, false, 2);
	a2 = set_etat(a2, 1, 1, false, false, 1);
	a2 = set_etat(a2, 2, 2, false, false, 1);
	a2 = set_etat(a2, 3, 3, false, true, 0);
	a2 = set_transition(a2, 0, 0, 1, 'b');
	a2 = set_transition(a2, 0, 1, 1, 'c');
	a2 = set_transition(a2, 1, 0, 2, 'b');
	a2 = set_transition(a2, 2, 0, 3, 'b');
	affichage_AFND(a2);


	printf("\n");

	a1= reunion_automate(a1, a2);
	affichage_AFND(a1);

// Minimisation

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