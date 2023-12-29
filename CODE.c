#include <stdio.h>
#include <string.h>

#define MAX_Voyageurs 100
#define MAX_Reservations 100
#define MAX_Bus 10

struct Voyageur {
    int id;
    char nom[50];
    char prenom[50];
};

struct Reservation {
    int id;
    int idVoyageur;
    int idBus;
 
};

struct Bus {
    int id;
    char nom[50];
};

struct Voyageur voyageurs[MAX_Voyageurs];
struct Reservation reservations[MAX_Reservations];
struct Bus bus[MAX_Bus];

int nombreVoyageurs = 0;
int nombreReservations = 0;
int nombreBus = 0;

void creerNouveauVoyageur(char nom[], char prenom[]) {
    if (nombreVoyageurs < MAX_Voyageurs) {
        struct Voyageur nouveauVoyageur;
        nouveauVoyageur.id = nombreVoyageurs + 1;
        strcpy(nouveauVoyageur.nom, nom);
        strcpy(nouveauVoyageur.prenom, prenom);
        voyageurs[nombreVoyageurs++] = nouveauVoyageur;
        printf("Nouveau compte voyageur créé avec l'ID : %d\n", nouveauVoyageur.id);
    } else {
        printf("Nombre maximal de voyageurs atteint. Impossible de créer un nouveau compte.\n");
    }
}

void creerNouvelleReservation(int idVoyageur, int idBus) {
    if (nombreReservations < MAX_Reservations) {
        struct Reservation nouvelleReservation;
        nouvelleReservation.id = nombreReservations + 1;
        nouvelleReservation.idVoyageur = idVoyageur;
        nouvelleReservation.idBus = idBus;
        reservations[nombreReservations++] = nouvelleReservation;
        printf("Nouvelle réservation créée avec l'ID : %d\n", nouvelleReservation.id);
    } else {
        printf("Nombre maximal de réservations atteint. Impossible de créer une nouvelle réservation.\n");
    }
}

void afficherDetailsBus() {
    printf("Liste des bus :\n");
    for (int i = 0; i < nombreBus; i++) {
        printf("Bus %d - Nom : %s\n", bus[i].id, bus[i].nom);
    }
}

void afficherEtModifierDetailsReservation(int idReservation) {
    for (int i = 0; i < nombreReservations; i++) {
        if (reservations[i].id == idReservation) {
            printf("Détails de la réservation %d :\n", reservations[i].id);
            printf("Voyageur ID : %d\n", reservations[i].idVoyageur);
            printf("Bus ID : %d\n", reservations[i].idBus);

            return;
        }
    }
    printf("Aucune réservation trouvée avec l'ID : %d\n", idReservation);
}
void rechercherVoyageurParNom(char nom[]) {
    printf("Résultats de la recherche pour le voyageur avec le nom '%s':\n", nom);
    for (int i = 0; i < nombreVoyageurs; i++) {
        if (strcmp(voyageurs[i].nom, nom) == 0) {
            printf("Voyageur ID : %d, Nom : %s, Prénom : %s\n", voyageurs[i].id, voyageurs[i].nom, voyageurs[i].prenom);
        }
    }
}

void rechercherReservationsParVoyageur(int idVoyageur) {
    printf("Résultats de la recherche pour les réservations du voyageur ID %d:\n", idVoyageur);
    for (int i = 0; i < nombreReservations; i++) {
        if (reservations[i].idVoyageur == idVoyageur) {
            printf("Réservation ID : %d, Bus ID : %d\n", reservations[i].id, reservations[i].idBus);
        }
    }
}


int main() {
    creerNouveauVoyageur("Khalifa", "Manar");

    char nomRecherche[50];
    printf("Entrez le nom du voyageur à rechercher : ");
    scanf("%s", nomRecherche);
    rechercherVoyageurParNom(nomRecherche);

    creerNouvelleReservation(1, 1);
    afficherDetailsBus();
    afficherEtModifierDetailsReservation(1);

    return 0;
}
