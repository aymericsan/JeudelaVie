#include <stdio.h>

// Définition de la taille de la grille
#define LARGEUR 20
#define HAUTEUR 10

int main() {
    // 1. Déclaration du tableau (0 = mort, 1 = vivant)
    int grille[HAUTEUR][LARGEUR] = {0};

    // 2. On place manuellement quelques cellules vivantes (un "Glider")
    grille[1][2] = 1;
    grille[2][3] = 1;
    grille[3][1] = 1;
    grille[3][2] = 1;
    grille[3][3] = 1;

    // 3. Affichage de la grille
    for (int i = 0; i < HAUTEUR; i++) {       // Pour chaque ligne
        for (int j = 0; j < LARGEUR; j++) {   // Pour chaque colonne
            if (grille[i][j] == 1) {
                printf("# "); // Cellule vivante
            } else {
                printf(". "); // Cellule morte
            }
        }
        printf("\n"); // Retour à la ligne après chaque ligne de la grille
    }

    return 0;
}