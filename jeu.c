#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "jeu.h"


void initialise(char tableau[7][7]) {
    int lgn, col;
    for(lgn = 0; lgn < 7; ++lgn){
        for(col = 0; col < 7; col++){
            tableau[lgn][col] = ' ';
        }
    }
}

void affiche_tableau(char tableau[7][7]) {
   int lgn, col;
    printf("\n---------------\n");
    for(lgn = 0; lgn < 7; ++lgn){
        putchar('|');
        for(col = 0; col < 7; ++col){
            printf("%c|", tableau[lgn][col]);
        }
        printf("\n");
    }
    for (col = 1; col <= 7; col++)
        printf(" %d", col);
    printf("\n---------------\n");
}

int inserer_jeton (char tableau[7][7], int colonne, char jeton) {
    int i;
    for(i = 6; i >= 0; i--){
        if(tableau[i][colonne] == ' '){
            tableau[i][colonne] = jeton;
            return 0;
        }
    }
    printf("ERREUR: colonne pleine , selectionner une autre colonne. \n");
    return 1;
}

void tournergauche(char tableau[7][7]){
    int i, j, a = 0, b = 0;
    char nouveau_tableau[7][7];
    initialise(nouveau_tableau);

    for (j = 0; j < 7; j++){
        for (i = 0; i < 7; i++){
            if(tableau[i][j] != ' '){
                a = 6;
                while(nouveau_tableau[a][i] != ' ' && a > 0){
                    a--;
                }
                nouveau_tableau[a][i] = tableau[i][j];
            }
        }
    }

    for(i = 0; i < 7; i++){
        for (j = 0; j < 7; j++){
            tableau[i][j] = nouveau_tableau[i][j];
        }
    }
}

void tournerdroite(char tableau[7][7]){
    int i, j, a = 0, b = 0;
    char nouveau_tableau[7][7];
    initialise(nouveau_tableau);

    for (j = 6; j >= 0; j--){
        for (i = 0; i < 7; i++){
            if(tableau[i][j] != ' '){
                a = 6;
                while(nouveau_tableau[a][6-i] != ' ' && a > 0){
                    a--;
                }
                //printf("\n%c %d %d\n", nouveau_tableau[a][6-i], a, 6-i);
                nouveau_tableau[a][6-i] = tableau[i][j];
            }
        }
    }

    for(i = 0; i < 7; i++){
        for (j = 0; j < 7; j++){
            tableau[i][j] = nouveau_tableau[i][j];
        }
    }
}

void retourner(char tableau[7][7]){
    int i, j, a = 0, b = 0;
    char nouveau_tableau[7][7];
    initialise(nouveau_tableau);

    for (j = 6; j >= 0; j--){
        for (i = 0; i < 7; i++){
            if(tableau[i][j] != ' '){
                a = 6;
                while(nouveau_tableau[a][j] != ' ' && a > 0){
                    a--;
                }
                //printf("\n%c %d %d\n", nouveau_tableau[a][6-i], a, 6-i);
                nouveau_tableau[a][j] = tableau[i][j];
            }
        }
    }

    for(i = 0; i < 7; i++){
        for (j = 0; j < 7; j++){
            tableau[i][j] = nouveau_tableau[i][j];
        }
    }
}

int verifier_grille_complete(char tableau[7][7]){
    int i, j;

    for(i = 0; i < 7; i++){
        for(j = 0; j < 7; j++){
            if (tableau[i][j] == ' '){
                return 0;
            }
        }
    }

    return 1;
}

int statut_jeu(char tableau[7][7], char token){
    int i, j, s, z, n;
    int score;
    int gagnant = 0;


    //horizontal verification
    for( i = 0; i < 7; i++){
        score = 0;
        for( j = 0; j < 7; j++){
            if(tableau[i][j] == token){
                score++;
                if(score == 4){
                    return 1;
                }
            } else {
                score = 0;
            }
        }
    }
    //vertical verification
    for( j = 0; j < 7; j++){
        score = 0;
        for(i = 0; i < 7; i++){
            if(tableau[i][j] == token){
                score++;
                if(score == 4){
                    return 1;
                }
            } else {
                score = 0;
            }
        }
    }

    //verification diagonal
    for (s = 0; s < 2 * 7 - 1; ++s) {
        score = 0;
        z = (s < 7) ? 0 : s - 7 + 1;
        for (j = z; j <= s - z; ++j) {
            if(tableau[j][s - j] == token){
                score++;
                if(score == 4){
                    return 1;
                }
            } else {
                score = 0;
            }
        }
    }

    //verification inverse diagonal
    for (s = 0; s < 2 * 7 - 1; ++s) {
        score = 0;
        z = (s < 7) ? 0 : s - 7 + 1;
        for (j = z; j <= s - z; ++j) {
            if(tableau[j][6 - s - j] == token){
                score++;
                if(score == 4){
                    return 1;
                }
            } else {
                score = 0;
            }
        }
    }

    return 0;
}


void sauvegarde_partie(char tableau[7][7], int tour){
    FILE *fp;
    int i, j;

    fp = fopen("sauvegarde.txt", "w");

    if(fp == NULL){
        printf("\nSauvegarde échouée!!\n");
        return;
    }

    fprintf(fp, "%d", tour);

    for(i = 0; i < 7; i++){
        for (j = 0; j < 7; j++){
            fprintf(fp, "%c", tableau[i][j]);
        }
    }
}

void restauration_partie(char tableau[7][7], int *tour){
    FILE *fp;
    int i, j;

    fp = fopen("sauvegarde.txt", "r");


    if(fp == NULL){
        printf("\nLecture du fichier échouée!!\n");
        return;
    }

    fscanf(fp, "%d", tour);

    for(i = 0; i < 7; i++){
        for (j = 0; j < 7; j++){
            fscanf(fp, "%c", &tableau[i][j]);
        }
    }
}

void jeu(char tableau[7][7]){
    int n_joueurs, choix, colonne, return_status;
    int jeu_termine = 0, gagnant = 0, autonome = 0;
    int tour = 1;
    char jeton;

    printf("\n\nSalut !. Vous pouvez choisir le nombre de joueurs  . (1 ou 2):");
    scanf("%d", &n_joueurs);

    if(n_joueurs == 1){
        autonome = 1;
        printf("\nJoueur 1:vous jouez les X. Joueur 2 (Ordinateur): vous jouez les O");
    } else if(n_joueurs == 2) {
        printf("\nJoueur 1: vous jouez les X. Joueur 2: vous jouez les O");
    } else {
        printf("\nCHOIX INVALIDE, LE JEU VA QUITTER!!\n");
        return;
    }

    while(jeu_termine == 0){
        if(tour == 1){
           jeton = 'X';
        } else if (tour == 2){
            jeton = 'O';
        }

        CHOIX:

        affiche_tableau(tableau);


        printf("\nJoueur %d: c'est ton tour. Que voulez-vous faire?\n", tour);
        printf("1. inserer jeton.\n");
        printf("2. tourner le plateau a gauche.\n");
        printf("3. tourner le plateau a droite.\n");
        printf("4. retourner le plateau.\n");
        printf("5. sauvegarder la partie.\n");
        printf("6. charger la derniere partie sauvegardee.\n");
        printf("7. abandonner la partie.\n");


        if (tour == 2 && autonome == 1){
            choix = (rand() % (4 - 1 + 1) + 1);
            printf("\nl'Ordinateur choisit l'option: %d\n", choix);
        } else {
            scanf("%d", &choix);
        }

        switch(choix){
            case 1: printf("Choisissez une colonne (de 1 a 7):");
                    if (tour == 2 && autonome == 1){
                        colonne = (rand() % (7 - 1 + 1) + 1);
                        printf("\nl'Ordinateur choisit la colonne: %d\n", colonne);
                    } else {
                        scanf("%d", &colonne);
                    }
                    return_status = inserer_jeton(tableau, colonne-1, jeton);
                    break;
            case 2: tournergauche(tableau);
                    printf("\nplateau tourne a gauche.\n");
                    break;
            case 3: tournerdroite(tableau);
                    printf("\nplateau tourne a droite.\n");
                    break;
            case 4: retourner(tableau);
                    printf("\nplateau retourne.\n");
                    break;
            case 5: printf("\nSAUVEGARDE EN COURS.\n");
                    sauvegarde_partie(tableau, tour);
                    goto CHOIX;
                    break;
            case 6: printf("\nCHARGEMENT DE LA SAUVEGARDE EN COURS\n");
                    restauration_partie(tableau, &tour);
                    goto CHOIX;
                    break;
            case 7: printf("\nVous abandonnez la partie, joueur %d. \n", tour);
                    gagnant = tour == 1 ? 2 : 1;
                    jeu_termine = 1;
                    break;
            default: printf("\nCHOIX INVALIDE!\n");
                     break;
        }

        if(statut_jeu(tableau, 'X') == 1){
            gagnant = 1;
            jeu_termine = 1;
        } else if(statut_jeu(tableau, 'O') == 1){
            gagnant = 2;
            jeu_termine = 1;
        }

        if(verifier_grille_complete(tableau) == 1){
            jeu_termine = 1;
        }


        tour = tour == 1 ? 2 : 1;
    }

    if(jeu_termine == 1){
        affiche_tableau(tableau);
        if(gagnant != 0){
            printf("\nJOUEUR %d GAGNE :) \n", gagnant);
        } else {
            printf("\nMATCH NUL");
        }

        printf("\n\n====================\nPARTIE TERMINEE!\n");
    }


