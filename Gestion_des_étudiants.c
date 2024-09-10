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
void ajouter_etudiant(int n) {
    if (count + n > MAX_ETUDIANTS) {
        printf("Le carnet d'etudiants est plein.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        int numero;
        char nom[15];
        char prenom[20];
        char date_de_naissance[50];
        char departement[20];
        double note_generale;

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
void Afficher_etudiant(){
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
void recherche_etudiant()
{
    char Nom[15];
    char nom_departement[50];
    int choix;
    printf("donner votre choix");
    scanf("%d",&choix);
    switch (choix)
    {
    case 1:
        printf("Entrez le nom d'Etudiant pour rechercher: ");
              scanf(" %s", Nom);
             for (int i = 0; i < count; i++) {
               
               if (strcmp(etudiants[i].nom,Nom)==0) {
               printf("les informations de %s est :\n",Nom);
               printf("Numero unique : %d\n", etudiants[i].numero);
               printf("Nom : %s\n", etudiants[i].nom);
               printf("Prenom : %s\n", etudiants[i].prenom);
               printf("Date de naissance : %s\n", etudiants[i].date_de_naissance);
               printf("Departement : %s\n", etudiants[i].departement);
               printf("Note generale : %.2f\n\n", etudiants[i].note_generale);

                return;
                
                }
             }
             break;
    case 2:
    printf("Entrez le nom de departemen d'Etudiant pour rechercher: ");
              scanf(" %s", nom_departement);
              
              for (int i = 0; i < count; i++) {
               
               if (strcmp(etudiants[i].departement,nom_departement)==0) {
               printf("les informations de %s est :\n",Nom);
               printf("Numero unique : %d\n", etudiants[i].numero);
               printf("Nom : %s\n", etudiants[i].nom);
               printf("Prenom : %s\n", etudiants[i].prenom);
               printf("Date de naissance : %s\n", etudiants[i].date_de_naissance);
               printf("Departement : %s\n", etudiants[i].departement);
               printf("Note generale : %.2f\n\n", etudiants[i].note_generale);
                }
                }
               break;
    default:
    printf("choix invalide. .\n");
        break;
    
              
            
        }
}

int main() {
    int n;
    printf("Combien d'etudiants voulez-vous ajouter ? ");
    scanf("%d", &n);

    ajouter_etudiant(n);
    Afficher_etudiant();
    recherche_etudiant();

   

    return 0;
}
