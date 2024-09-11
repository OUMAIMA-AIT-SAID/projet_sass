#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ETUDIANTS 100
#define DATE_MAX 15
#define MAX_DEPT 20

typedef struct {
    int numero;
    char nom[15];
    char prenom[20];
    char date_de_naissance[DATE_MAX];
    char departement[20];
    double note_generale;
} Etudiant;

Etudiant etudiants[MAX_ETUDIANTS];
int count = 10;

// Fonction d'ajout d'etudiants ---------------------------------------------------------
void ajouter_etudiant() {
    int n;
    int numero;
    char nom[15];
    char prenom[20];
    char date_de_naissance[DATE_MAX];
    char departement[20];
    double note_generale;

    printf("Combien d'etudiants voulez-vous ajouter ? ");
    scanf("%d", &n);

    if (count + n > MAX_ETUDIANTS) {
        printf("Le carnet d'etudiants est plein.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("Entrez le numero de l'etudiant: ");
        scanf("%d", &numero);

        int exist = 0;
        for (int j = 0; j < count; j++) {
            if (etudiants[j].numero == numero) {
                printf("Cet etudiant est deja inscrit.\n");
                exist = 1;
                break;
            }
        }

        if (!exist) {
            etudiants[count].numero = numero;
            printf("Entrez le nom de l'etudiant: ");
            scanf("%s", etudiants[count].nom);
            printf("Entrez le prenom de l'etudiant: ");
            scanf("%s", etudiants[count].prenom);
            printf("Entrez la date de naissance de l'etudiant (JJ/MM/AAAA): ");
            scanf("%s", etudiants[count].date_de_naissance);
            printf("Entrez le departement de l'etudiant: ");
            scanf("%s", etudiants[count].departement);
            printf("Entrez la note generale de l'etudiant: ");
            scanf("%lf", &etudiants[count].note_generale);
            count++;
            printf("Etudiant ajoute.\n");
        }
    }
}

// Fonction d'affichage d'etudiants -------------------------------------------------------------------------------
void Afficher_etudiant() {
    printf("\nListe des etudiants :\n");
    for (int i = 0; i < count; i++) {
        printf("Numero unique : %d\n", etudiants[i].numero);
        printf("Nom : %s\n", etudiants[i].nom);
        printf("Prenom : %s\n", etudiants[i].prenom);
        printf("Date de naissance : %s\n", etudiants[i].date_de_naissance);
        printf("Departement : %s\n", etudiants[i].departement);
        printf("Note generale : %.2f\n\n", etudiants[i].note_generale);
    }
}

// Fonction de recherche ---------------------------------------------------------------------------
void recherche_etudiant() {
    char nom[15];
    char nom_departement[20];
    int choix;
    printf("Donner votre choix (1 pour nom, 2 pour departement) : ");
    scanf("%d", &choix);

    switch (choix) {
        case 1:
            printf("Entrez le nom de l'etudiant pour rechercher: ");
            scanf("%s", nom);
            int found = 0;
            for (int i = 0; i < count; i++) {
                if (strcmp(etudiants[i].nom, nom) == 0) {
                    printf("Les informations de %s sont :\n", nom);
                    printf("Numero unique : %d\n", etudiants[i].numero);
                    printf("Nom : %s\n", etudiants[i].nom);
                    printf("Prenom : %s\n", etudiants[i].prenom);
                    printf("Date de naissance : %s\n", etudiants[i].date_de_naissance);
                    printf("Departement : %s\n", etudiants[i].departement);
                    printf("Note generale : %.2f\n\n", etudiants[i].note_generale);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Etudiant non trouve.\n");
            }
            break;
        case 2:
            printf("Entrez le nom du departement pour rechercher: ");
            scanf("%s", nom_departement);
            found = 0;
            for (int i = 0; i < count; i++) {
                if (strcmp(etudiants[i].departement, nom_departement) == 0) {
                    printf("Les informations de l'etudiant dans le departement %s sont :\n", nom_departement);
                    printf("Numero unique : %d\n", etudiants[i].numero);
                    printf("Nom : %s\n", etudiants[i].nom);
                    printf("Prenom : %s\n", etudiants[i].prenom);
                    printf("Date de naissance : %s\n", etudiants[i].date_de_naissance);
                    printf("Departement : %s\n", etudiants[i].departement);
                    printf("Note generale : %.2f\n\n", etudiants[i].note_generale);
                    found = 1;
                }
            }
            if (!found) {
                printf("Aucun etudiant trouve dans le departement %s.\n", nom_departement);
            }
            break;
        default:
            printf("Choix invalide.\n");
            break;
    }
}

// Fonction de suppression----------------------------------------------------------------------
void supprimer_etudiant() {
    int num;
    printf("Entrez le numero de l'etudiant pour supprimer: ");
    scanf("%d", &num);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (etudiants[i].numero == num) {
            // Decalage des elements
            for (int j = i; j < count - 1; j++) {
                etudiants[j] = etudiants[j + 1];
            }
            count--;
            printf("Etudiant supprime.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Etudiant non trouve.\n");
    }
}

// Fonction de modification ----------------------------------------------------
void modifier_etudiant() {
    int NUM;
    printf("Entrez le numero de l'etudiant a modifier : ");
    scanf("%d", &NUM);
    int found = 0;

    for (int i = 0; i < count; i++) {
        if (etudiants[i].numero == NUM) {
            printf("Veuillez entrer les nouvelles informations :\n");
            printf("Nom : ");
            scanf("%s", etudiants[i].nom);
            printf("Prenom : ");
            scanf("%s", etudiants[i].prenom);
            printf("Date de naissance (JJ/MM/AAAA) : ");
            scanf("%s", etudiants[i].date_de_naissance);
            printf("Departement : ");
            scanf("%s", etudiants[i].departement);
            printf("Note generale : ");
            scanf("%lf", &etudiants[i].note_generale);
            printf("Etudiant modifie.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Etudiant non trouve.\n");
    }
}

// Fonction de calcul de moyenne generale-------------------------------------------------
void calculer_moyenne_generale() {
    double somme_notes_universite = 0;
    int count_nombre_etudiant = 0;
    char departements[MAX_DEPT][20];
    double somme_dept[MAX_DEPT] = {0};
    int count_dept[MAX_DEPT] = {0};
    int dept_count = 0;

    for (int i = 0; i < count; i++) {
        int dept_found = 0;
        for (int j = 0; j < dept_count; j++) {
            if (strcmp(etudiants[i].departement, departements[j]) == 0) {
                somme_dept[j] += etudiants[i].note_generale;
                count_dept[j]++;
                dept_found = 1;
                break;
            }
        }

        if (!dept_found) {
            strcpy(departements[dept_count], etudiants[i].departement);
            somme_dept[dept_count] = etudiants[i].note_generale;
            count_dept[dept_count] = 1;
            dept_count++;
        }
        somme_notes_universite += etudiants[i].note_generale;
        count_nombre_etudiant++;
    }

    printf("\nMoyenne generale de chaque departement :\n");
    for (int i = 0; i < dept_count; i++) {
        printf("Departement %s : %.2f\n", departements[i], somme_dept[i] / count_dept[i]);
    }

    if (count_nombre_etudiant > 0) {
        printf("Moyenne generale de l'universite : %.2f\n", somme_notes_universite / count_nombre_etudiant);
    } else {
        printf("Aucun etudiant pour calculer la moyenne.\n");
    }
}

// Fonction de statistiques----------------------------------------------------
void statistiques() {
    int choix;
    printf("Choisissez les statistiques que vous souhaitez :\n");
    printf("1. Afficher le nombre total d'etudiants inscrits\n");
    printf("2. Afficher le nombre d'etudiants dans chaque departement\n");
    printf("3. Afficher les etudiants ayant une moyenne generale superieure a un certain seuil\n");
    printf("4. Afficher les 3 etudiants ayant les meilleures notes\n");
    printf("5. Afficher le nombre d'etudiants ayant reussi dans chaque departement\n");
    scanf("%d", &choix);

    switch (choix) {
        case 1:
            printf("Le nombre total d'etudiants inscrit est : %d\n", count);
            break;
        case 2: {
            int compte_nombreE[MAX_DEPT] = {0};
            char departements[MAX_DEPT][20];
            int compte_depar = 0;

            for (int i = 0; i < count; i++) {
                int trouve_departement = 0;
                for (int j = 0; j < compte_depar; j++) {
                    if (strcmp(etudiants[i].departement, departements[j]) == 0) {
                        compte_nombreE[j]++;
                        trouve_departement = 1;
                        break;
                    }
                }
                if (!trouve_departement) {
                    strcpy(departements[compte_depar], etudiants[i].departement);
                    compte_nombreE[compte_depar] = 1;
                    compte_depar++;
                }
            }

            printf("Nombre d'etudiants dans chaque departement :\n");
            for (int i = 0; i < compte_depar; i++) {
                printf("Departement %s : %d etudiants\n", departements[i], compte_nombreE[i]);
            }
            break;
        }
        case 3: {
            double seuil;
            printf("Entrez le seuil de la moyenne generale : ");
            scanf("%lf", &seuil);

            printf("Les etudiants ayant une moyenne generale superieure a %.2f sont :\n", seuil);
            for (int i = 0; i < count; i++) {
                if (etudiants[i].note_generale > seuil) {
                    printf("Numero unique : %d\n", etudiants[i].numero);
                    printf("Nom : %s\n", etudiants[i].nom);
                    printf("Prenom : %s\n", etudiants[i].prenom);
                    printf("Date de naissance : %s\n", etudiants[i].date_de_naissance);
                    printf("Departement : %s\n", etudiants[i].departement);
                    printf("Note generale : %.2f\n\n", etudiants[i].note_generale);
                }
            }
            break;
        }
        case 4: {
            // Tri des etudiants par note generale
            for (int i = 0; i < count - 1; i++) {
                for (int j = i + 1; j < count; j++) {
                    if (etudiants[i].note_generale < etudiants[j].note_generale) {
                        Etudiant temp = etudiants[i];
                        etudiants[i] = etudiants[j];
                        etudiants[j] = temp;
                    }
                }
            }

            printf("Les 3 etudiants ayant les meilleures notes sont :\n");
            for (int i = 0; i < 3 && i < count; i++) {
                printf("Numero unique : %d\n", etudiants[i].numero);
                printf("Nom : %s\n", etudiants[i].nom);
                printf("Prenom : %s\n", etudiants[i].prenom);
                printf("Date de naissance : %s\n", etudiants[i].date_de_naissance);
                printf("Departement : %s\n", etudiants[i].departement);
                printf("Note generale : %.2f\n\n", etudiants[i].note_generale);
            }
            break;
        }
        case 5: {
            // Suppose qu'une note >= 10 est une reussite
            printf("Nombre d'etudiants ayant reussi dans chaque departement :\n");
            int compte_nombreE[MAX_DEPT] = {0};
            char departements[MAX_DEPT][20];
            int compte_depar = 0;

            for (int i = 0; i < count; i++) {
                if (etudiants[i].note_generale >= 10) {
                    int trouve_departement = 0;
                    for (int j = 0; j < compte_depar; j++) {
                        if (strcmp(etudiants[i].departement, departements[j]) == 0) {
                            compte_nombreE[j]++;
                            trouve_departement = 1;
                            break;
                        }
                    }
                    if (!trouve_departement) {
                        strcpy(departements[compte_depar], etudiants[i].departement);
                        compte_nombreE[compte_depar] = 1;
                        compte_depar++;
                    }
                }
            }

            for (int i = 0; i < compte_depar; i++) {
                printf("Departement %s : %d etudiant(s)\n", departements[i], compte_nombreE[i]);
            }
            break;
        }
        default:
            printf("Choix invalide.\n");
            break;
    }
}

// Fonction de main --------------------------------------------------------
int main() {
    // Ajout d'étudiants par défaut pour test
    count = 5; // nombre d'étudiants par défaut

    etudiants[0] = (Etudiant){1, "Dupont", "Jean", "15/05/2000", "Informatique", 12.5};
    etudiants[1] = (Etudiant){2, "Durand", "Marie", "22/03/1999", "Mathematiques", 14.0};
    etudiants[2] = (Etudiant){3, "Lefebvre", "Paul", "01/11/1998", "Physique", 9.0};
    etudiants[3] = (Etudiant){4, "Moreau", "Sophie", "30/08/2001", "Chimie", 15.5};
    etudiants[4] = (Etudiant){5, "Petit", "Luc", "17/12/2000", "Informatique", 11.0};
    int choix;
    while (1) {
        printf("\nMenu :\n");
        printf("1. Ajouter des etudiants\n");
        printf("2. Afficher les etudiants\n");
        printf("3. Rechercher un etudiant\n");
        printf("4. Supprimer un etudiant\n");
        printf("5. Modifier un etudiant\n");
        printf("6. Calculer la moyenne generale\n");
        printf("7. Statistiques\n");
        printf("8. Quitter\n");
        printf("Choisissez une option (1-8) : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouter_etudiant();
                break;
            case 2:
                Afficher_etudiant();
                break;
            case 3:
                recherche_etudiant();
                break;
            case 4:
                supprimer_etudiant();
                break;
            case 5:
                modifier_etudiant();
                break;
            case 6:
                calculer_moyenne_generale();
                break;
            case 7:
                statistiques();
                break;
            case 8:
                printf("Quitter le programme.\n");
                exit(0);
            default:
                printf("Choix invalide. Veuillez choisir une option entre 1 et 8.\n");
                break;
        }
    }

    return 0;
}
