//PERRIN Ewan
//LABORDE Antoine

#ifndef BC_H
#define BC_H

#include "header_structures.h"

/**
* Permet de créer un proposition
* @param c : chaine de caractères à ajouter dans la proposition
* @param n : état de la proposition
* @return la proposition créée
*/
proposition create_prop(char c[],bool n);

/**
* Creer une règle vide
* @return un pointeur sur NULL
*/
regle create_empty_regle(void);

/**
* Ajout en queue d'une proposition à une premisse d'une règle
* @param r une règle
* @param p une proposition
* @return une nouvelle règle contenant la proposition p
*/
regle add_prop(regle r, proposition p);

/**
* Permet de créer la conclusion d'une règle
* @param r une règle
* @param c chaine de caractères qui servira de conclusion
* @return une règle contenant la conclusion c
*/
regle create_conclu(regle r, char c[]);

/**
* Test si un caractère appartient à une premisse ou non
* @param p premisse d'une règle
* @param prop proposition à chercher
* @return True la proposition appartient à la premisse, False si elle n'appartient pas
*/
bool contains (premisse p, char prop[]);

/**
* Change l'etat d'une proposition appartenant à la premisse d'une regle
* @param r une règle
* @param prop proposition à changer d'état (supprimer) dans la premisse
* @return une regle dont l'une des proposition de la premisse à été modifié suivant l'appartenance de la proposition
*/
premisse change_etat_p(regle r, char prop[]);

/**
* Fonction qui permet de déterminer si la premisse d'une regle est vide
* @param r regle (on utilise la premisse de cette regle)
* @return True(ou 1) si elle est vide sinon False(ou 0)
*/
bool is_empty_prem(regle r);

/**
* Fonction qui permet de déterminer si chaque état d'une proposition appartenant à la premisse d'une règle est égale à 1
* @param r regle (on utilise la premisse de cette regle)
* @return True si chaque proposition de la premisse possède un état égale à 1 (autrement dit si la premisse est vide), False si l'une des proposition possède un état égale à 0
*/
bool test_pre (regle r);

/**
* Permet d'accéder à la propisition en tête d'une premisse
* @param p premisse d'une regle
* @return la proposition en tête de la premisse p
*/
proposition head_value_p(premisse p);

/**
* Permet d'accéder à la conclusion d'une règle
* @param r règle
* @return le caractère (le mot) contenu dans la conclusion d'une règle
*/
char conclu_regle(regle r);

/**
* Permet de créer une base de connaissance vide
* @return un pointeur sur NULL
*/
BC create_empty_BC(void);

/**
* Insère en queue une règle à une base de connaissance
* @param b : base de connaissance de départ
* @param r : règle à ajouter à la base de connaissance b
* @return la base de connaissance b avec l'ajout de la règle r
*/
BC insert_tail_BC(BC base, regle r);

/**
* Retourne la regle en tete de la base de connaissance
* @param base : base de connaissance
* @return règle en tete de la base de connaissance "base"
*/
regle head_regle_BC(BC base);



/**
* Definition d'un element de la base de fait (liste chainée de caractère)
*/
typedef struct base{char fait[100];
                    struct base *next;}basef;

/**
* Definition du type BF (base de fait)
*/
typedef basef *BF;

/**
* Fonction qui permet de savoir si une conclusion est vrai à partie de fait et de règle
* @param base : base de fait comportant des faits vrai
* @param baseC : base de connaissance comportant les différentes règles à tester
* Cette fonction ne retourne rien elle ajoute simplement à la base de fait des conclusions (si on peut en trouver) et test à nouveau à partir des conclusions trouver si l'on peut tirer d'autre conlusion
* Elle affiche les conclusions trouvées
*/
void moteur_inference(BF base, BC baseC);

/**
* Insère en queue un nouveau fait à la base de fait "base"
* @param baseF : base de fait
* @param c caractère (fait) à ajouter à la base de fait
* @return la base de fait avec un nouveau caractère
*/
BF insert_tail_BF(BF base, char *c);

#endif

