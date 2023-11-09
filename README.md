# Puissance4
Le jeu de Puissance 4 est un jeu à 2 joueurs ayant pour but d'aligner 4 jetons de la même couleur.
À chaque tour, chaque joueur peut ajouter un jeton de sa couleur dans une colonne, ce jeton ira à la position la plus basse dans cette colonne.
Si toutes les cases de la grille sont remplies et qu'aucun joueur n'a réussi à aligner 4 jetons, la partie est déclarée nulle.

Le projet
Vous devez implémenter en C le jeu du puissance 4.

Quelques modifications
La grille de jeu aura 7 lignes et 7 colonnes.
Un joueur peut soit :
placer une jeton dans une colonne,
tourner le plateau de 90 degrés sur la gauche,
tourner le plateau de 90 degrés sur la droite,
ou retourner le plateau.
Quelques obligations
On doit pouvoir jouer en mode console.
Seulement trois fichiers peuvent être utilisés: jeu.c, jeu.h et main.c.
Vous devez écrire un rapport expliquant ce que vous avez fait. Le rapport doit être en pdf et à votre nom.
Un joueur autonome doit être utilisable. Il doit pouvoir prendre des decisions tout seul. Tout joueur doit pouvoir être remplacé par ce joueur autonome au début du jeu.
Un bonus sera obtenu si vous implémentez une sauvegarde d'une partie en cours, ainsi qu'une lecture d'un fichier de sauvegarde.
Merci de bien vouloir tester que votre solution fonctionne.
Vous devez rendre un fichier zip portant votre nom et contenant les 3 fichiers sources et votre rapport.

```
Exemple
On commence avec une grille vide
_______________
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
———————————————
 1 2 3 4 5 6 7  
le joueur 1 joue dans la colonne 3
_______________
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | |O| | | | |
———————————————
 1 2 3 4 5 6 7 
le joueur 2 joue dans la colonne 4
_______________
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | |O|X| | | |
———————————————
 1 2 3 4 5 6 7 
le joueur 1 tourne le plateau de 90 degrés à gauche
_______________
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | |X|
| | | | | | |O|
———————————————
 1 2 3 4 5 6 7 
le joueur 2 retourne le plateau
_______________
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | |O|
| | | | | | |X|
———————————————
 1 2 3 4 5 6 7
```
