#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "jeu.c"




}
int main(void){
    char tableau[7][7];

    srand(time(NULL));
    initialise(tableau);
    affiche_tableau(tableau);

    jeu(tableau);

    return 0;
}

