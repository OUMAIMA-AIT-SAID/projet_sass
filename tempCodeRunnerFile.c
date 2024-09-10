
    int n;
    printf("Combien d'etudiants voulez-vous ajouter ? ");
    scanf("%d", &n);

    ajouter_etudiant(n);
    Afficher_etudiant();
    recherche_etudiant();

   

    return 0;