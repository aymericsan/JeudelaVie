#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Pour usleep (pause)

#define LARGEUR 30
#define HAUTEUR 15

// Fonction pour compter les voisins
int compter_voisins(int grille[HAUTEUR][LARGEUR], int i, int j) {
    int total = 0;
    for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
            if (di == 0 && dj == 0) continue;
            int ni = i + di;
            int nj = j + dj;
            if (ni >= 0 && ni < HAUTEUR && nj >= 0 && nj < LARGEUR) {
                total += grille[ni][nj];
            }
        }
    }
    return total;
}

int main() {
    int grille[HAUTEUR][LARGEUR] = {0};
    int future[HAUTEUR][LARGEUR] = {0};

    // Initialisation : Un "Glider"
    grille[1][2] = 1; grille[2][3] = 1;
    grille[3][1] = 1; grille[3][2] = 1; grille[3][3] = 1;

    // Boucle infinie du jeu
    while (1) {
        // 1. Effacer le terminal
        // "clear" sur Mac/Linux, "cls" sur Windows
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        // 2. Affichage
        for (int i = 0; i < HAUTEUR; i++) {
            for (int j = 0; j < LARGEUR; j++) {
                printf(grille[i][j] ? "# " : ". ");
            }
            printf("\n");
        }

        // 3. Calcul de la génération suivante
        for (int i = 0; i < HAUTEUR; i++) {
            for (int j = 0; j < LARGEUR; j++) {
                int n = compter_voisins(grille, i, j);
                if (grille[i][j] == 1) {
                    future[i][j] = (n == 2 || n == 3) ? 1 : 0;
                } else {
                    future[i][j] = (n == 3) ? 1 : 0;
                }
            }
        }

        // 4. Mise à jour de la grille (Copie)
        for (int i = 0; i < HAUTEUR; i++) {
            for (int j = 0; j < LARGEUR; j++) {
                grille[i][j] = future[i][j];
            }
        }

        // 5. Petite pause (100 millisecondes = 100000 microsecondes)
        usleep(100000);
    }

    return 0;
}