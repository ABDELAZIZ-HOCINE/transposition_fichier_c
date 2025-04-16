#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fonction pour afficher un tableau de caractères (tableau 2D)
void print_mat(char** tab, int nb_lignes, int nb_columns) {
    for (int i = 0; i < nb_lignes; i++) {
        printf("|");
        for (int j = 0; j < nb_columns; j++) {
            printf("%c|", tab[i][j]);
        }
        printf("\n");
    }
}

// Fonction pour diviser le fichier sur des fichiers
void transpose(char * file, int k) {

    FILE* my_file = fopen(file, "r");
    if (!my_file) {
        printf("Error opening file!\n");
        return;
    }

    // Calculer la taille du fichier
    int nb_char = 0;
    while (fgetc(my_file) != EOF) {
        nb_char++;
    }

    rewind(my_file);

    // Calculer le nombre de lignes nécessaires
    int nb_colonnes = k;
    int nb_lignes = nb_char / k;
    if (nb_char % k != 0) {
        nb_lignes++;
    }

    // Allocation mémoire pour le tableau transposé
    char **tab_transpose = (char**)malloc(nb_lignes * sizeof(char*));
    for (int i = 0; i < nb_lignes; i++) {
        tab_transpose[i] = (char*)malloc(nb_colonnes * sizeof(char));
    }

    int cpt = 0;

    // Remplir le tableau transposé avec les caractères du fichier
    for (int i = 0; i < nb_lignes; i++) {
        for (int j = 0; j < nb_colonnes; j++) {
            if (cpt < nb_char) {
                tab_transpose[i][j] = fgetc(my_file);
                if (tab_transpose[i][j] == '\n') tab_transpose[i][j] = ' ';  // Remplacer '\n' par un espace
                cpt++;
            } else {
                tab_transpose[i][j] = ' ';  // Remplir avec des espaces si nécessaire
            }
        }
    }
    rewind(my_file);

    //Fermer le fichier
    fclose(my_file);

    //Débogage (optionnel, à activer si nécessaire)----------
    //Afficher le tableau transposé
    print_mat(tab_transpose, nb_lignes, nb_colonnes);


    char* filename=(char*)malloc(20*sizeof(char));
    int num_file = 1;

    for (int i = 0; i < nb_colonnes; i++) {
        sprintf(filename, "fichier_%d", num_file);
        FILE* file = fopen(filename, "w");
        if (!file) {
            perror("Erreur lors de l'ouverture du fichier");
            exit(EXIT_FAILURE);
        }
        for (int j = 0; j < nb_lignes; j++) {
            fputc(tab_transpose[j][i], file);
        }
        fclose(file);
        num_file++;
    }

    printf("Transposition effectuée avec succès avec un ordre de %d\n", k);

    // Libérer la mémoire
    for (size_t i = 0; i < nb_lignes; i++) {
        free(tab_transpose[i]);
    }
    free(tab_transpose);
    free(filename);

}

int main(int argc, char* argv[]) {

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file> <k>\n", argv[0]);
        return 0;
    }

    char* file_name = argv[1]; 

    //Convertir l'argument en entier
    int k = atoi(argv[2]);

    if (k <= 0) {
        fprintf(stderr, "Usage: %s <file> <k>\n", argv[0]);
        fprintf(stderr, "Erreur : k doit être un entier positif.\n");
        return 0;
    }

    transpose(file_name, k);
    return 0;
}