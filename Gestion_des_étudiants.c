#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ETUDIANTS 100

typedef struct {
    int numero;
    char nom[15];
    char prenom[20];
    char date_de_naissance[50];
    char departement[20];
    double note_generale;
} Etudiant;

Etudiant etudiants[MAX_ETUDIANTS];
int count = 0;

// Fonction d'ajout d'étudiants
void ajouter_etudiant() {
    int n;
    int numero;
    char nom[15];
    char prenom[20];
    char date_de_naissance[50];
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
            etudiants[count].numero = count+1;
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

void supprimer_etudiant() {
    int num;
    printf("Entrez le numero de l'etudiant pour supprimer: ");
    scanf("%d", &num);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (etudiants[i].numero == num) {
            // Décalage des éléments
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
void modifier_etudiant() {
    int NUM;
    printf("Entrez le numéro de l'étudiant à modifier : ");
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
            printf("etudiant modifie.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("etudiant non trouve.\n");
    }
}


int main() {
    int choix;
    while (1) {
        printf("\nMenu :\n");
        printf("1. Ajouter des etudiants\n");
        printf("2. Afficher les etudiants\n");
        printf("3. Rechercher un etudiant\n");
        printf("4. Supprimer un etudiant\n");
        printf("5. modifier un etudiant\n");
        printf("6. Quitter\n");
        printf("Choisissez une option (1-6) : ");
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
                printf("Quitter le programme.\n");
                exit(0);
            default:
                printf("Choix invalide. Veuillez choisir une option entre 1 et 5.\n");
                break;
        }
    }

    return 0;
}
