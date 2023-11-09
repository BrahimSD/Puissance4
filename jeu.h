#ifndef JEU_H
#define JEU_H

void initialise(char tableau[7][7]);
void affiche_tableau(char tableau[7][7]);
int inserer_jeton (char tableau[7][7], int colonne, char jeton);
void tournergauche(char tableau[7][7]);
void tournerdroite(char tableau[7][7]);
void retourner(char tableau[7][7]);
int statut_jeu(char tableau[7][7], char token);
int verifier_grille_complete(char tableau[7][7]);
void sauvgarde_partie(char tableau[7][7], int tour);
void restauration_partie(char tableau[7][7], int *tour);
void jeu(char tableau[7][7]);

#endif
