
#ifndef INTERFACE_H
#define INTERFACE_H

#include "header_structures.h"

/**
* Permet de transformer un caractère compris entre '0' et '9' en un entier correspondant compris entre 0 et 9
* @param charChoice : numero du menu acquis grace a la fonction getch()
* @param nbMenu : entier correspondant au nombre de proposition dans le menu
* @return un entier correspondant au numero du menu acquis
*/
int menuManager(char charChoice, int nbMenu);

/**
* Permet de tester le numéro demandé par l'utilisateur convient
*/
int testMenu(int,int);

/**
* Fonction qui permet d'afficher le menu principal
* @param baseF : base de faits
* @param baseC : base de connaissance
* Cette fonction ne retourne rien elle affiche simplement le menu principal
*/
void mainMenu(BC baseC, BF baseF);

/**
* Fonction qui permet d'executer le projet
* @param baseF : base de fait comportant des faits vrai
* @param baseC : base de connaissance
* Cette fonction ne retourne rien elle execute simplement le projet
*/
void run_project(BF baseF, BC baseC);

/**
* Fonction qui permet d'ajouter une ou plusieur règle(s) à la base de connaissance
* @param baseC : base de connaissance
* @return la base de connaissance
*/
BC Add_regle(BC baseC);

/**
* Fonction qui permet de créer la base de fait en y ajoutant les faits de l'utilisateur
* @param baseF : base de faits vide
* @param baseC : base de connaissance
* @return la base de fait avec les faits de l'utilisateur
*/
BF Affichage_choix_faits(BF baseF, BC baseC);

/**
* Fonction qui permet de vérifier si une chaine de caractères appartient à une conclusion d'une des règles de la base de connaissance
* @param baseC : base de faits vide
* @param c : chaine de caractères
* @return un booleen
*/
bool conclu_contains(BC baseC, char *c);

/**
* Fonction qui permet de vérifier si un caractère appartient à la base de faits
* @param baseF : base de faits
* @param c : caractère à tester
* @return un booleen indiquant si la base de fait contient le caractere ou non
*/
bool BF_contains(BF baseF, char *c);

/**
* Permet d'initialiser la base de connaissance
* @return la base de connaissance initialisée
*/
BC initial_BC(void);


#endif
