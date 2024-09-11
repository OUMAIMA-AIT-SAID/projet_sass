#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ETUDIANTS 100



#define DATE_MAX 50
#define DEPT_MAX 20

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

// Fonction d'ajout d'étudiants ---------------------------------------------------------
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
//affichage d'étudiant -------------------------------------------------------------------------------

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
//fonction de la recherche ---------------------------------------------------------------------------

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
//fonction de supprission----------------------------------------------------------------------
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
//fonction des modifications ----------------------------------------------------
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
//fonction de Moyenne génèrale-------------------------------------------------
void calculer_moyenne_generale() {
    double somme_notes_université = 0;
    int count_nombre_etudiant = 0;
    char departements[MAX_ETUDIANTS][DEPT_MAX];
    double somme_dept[MAX_ETUDIANTS] = {0};
    int count_dept[MAX_ETUDIANTS] = {0};
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
        somme_notes_université += etudiants[i].note_generale;
        count_nombre_etudiant++;
    }

    printf("\nMoyenne générale de chaque département :\n");
    for (int i = 0; i < dept_count; i++) {
        printf("Département %s : %.2f\n", departements[i], somme_dept[i] / count_dept[i]);
    }

    if (count_nombre_etudiant> 0) {
        printf("Moyenne générale de l'université : %.2f\n", somme_notes_université / count_nombre_etudiant);
    } else {
        printf("Aucun étudiant pour calculer la moyenne.\n");
    }
}
//fonction de main --------------------------------------------------------
int main() {
    int choix;
    while (choix<8) {
        printf("\nMenu :\n");
        printf("1. Ajouter des etudiants\n");
        printf("2. Afficher les etudiants\n");
        printf("3. Rechercher un etudiant\n");
        printf("4. Supprimer un etudiant\n");
        printf("5. modifier un etudiant\n");
        printf("6. calculer le moyenne génèrale \n");
        printf("7. Quitter\n");
        printf("Choisissez une option (1-7) : ");
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
                printf("Quitter le programme.\n");
                exit(0);
            default:
                printf("Choix invalide. Veuillez choisir une option entre 1 et 7.\n");
                break;
        }
    }

    return 0;
}
