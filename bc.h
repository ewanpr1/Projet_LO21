//PERRIN Ewan
//LABORDE Antoine

#ifndef BC_H
#define BC_H

#include "header_structures.h"

/**
* Permet de cr�er un proposition
* @param c : chaine de caract�res � ajouter dans la proposition
* @param n : �tat de la proposition
* @return la proposition cr��e
*/
proposition create_prop(char c[],bool n);

/**
* Creer une r�gle vide
* @return un pointeur sur NULL
*/
regle create_empty_regle(void);

/**
* Ajout en queue d'une proposition � une premisse d'une r�gle
* @param r une r�gle
* @param p une proposition
* @return une nouvelle r�gle contenant la proposition p
*/
regle add_prop(regle r, proposition p);

/**
* Permet de cr�er la conclusion d'une r�gle
* @param r une r�gle
* @param c chaine de caract�res qui servira de conclusion
* @return une r�gle contenant la conclusion c
*/
regle create_conclu(regle r, char c[]);

/**
* Test si un caract�re appartient � une premisse ou non
* @param p premisse d'une r�gle
* @param prop proposition � chercher
* @return True la proposition appartient � la premisse, False si elle n'appartient pas
*/
bool contains (premisse p, char prop[]);

/**
* Change l'etat d'une proposition appartenant � la premisse d'une regle
* @param r une r�gle
* @param prop proposition � changer d'�tat (supprimer) dans la premisse
* @return une regle dont l'une des proposition de la premisse � �t� modifi� suivant l'appartenance de la proposition
*/
premisse change_etat_p(regle r, char prop[]);

/**
* Fonction qui permet de d�terminer si la premisse d'une regle est vide
* @param r regle (on utilise la premisse de cette regle)
* @return True(ou 1) si elle est vide sinon False(ou 0)
*/
bool is_empty_prem(regle r);

/**
* Fonction qui permet de d�terminer si chaque �tat d'une proposition appartenant � la premisse d'une r�gle est �gale � 1
* @param r regle (on utilise la premisse de cette regle)
* @return True si chaque proposition de la premisse poss�de un �tat �gale � 1 (autrement dit si la premisse est vide), False si l'une des proposition poss�de un �tat �gale � 0
*/
bool test_pre (regle r);

/**
* Permet d'acc�der � la propisition en t�te d'une premisse
* @param p premisse d'une regle
* @return la proposition en t�te de la premisse p
*/
proposition head_value_p(premisse p);

/**
* Permet d'acc�der � la conclusion d'une r�gle
* @param r r�gle
* @return le caract�re (le mot) contenu dans la conclusion d'une r�gle
*/
char conclu_regle(regle r);

/**
* Permet de cr�er une base de connaissance vide
* @return un pointeur sur NULL
*/
BC create_empty_BC(void);

/**
* Ins�re en queue une r�gle � une base de connaissance
* @param b : base de connaissance de d�part
* @param r : r�gle � ajouter � la base de connaissance b
* @return la base de connaissance b avec l'ajout de la r�gle r
*/
BC insert_tail_BC(BC base, regle r);

/**
* Retourne la regle en tete de la base de connaissance
* @param base : base de connaissance
* @return r�gle en tete de la base de connaissance "base"
*/
regle head_regle_BC(BC base);



/**
* Definition d'un element de la base de fait (liste chain�e de caract�re)
*/
typedef struct base{char fait[100];
                    struct base *next;}basef;

/**
* Definition du type BF (base de fait)
*/
typedef basef *BF;

/**
* Fonction qui permet de savoir si une conclusion est vrai � partie de fait et de r�gle
* @param base : base de fait comportant des faits vrai
* @param baseC : base de connaissance comportant les diff�rentes r�gles � tester
* Cette fonction ne retourne rien elle ajoute simplement � la base de fait des conclusions (si on peut en trouver) et test � nouveau � partir des conclusions trouver si l'on peut tirer d'autre conlusion
* Elle affiche les conclusions trouv�es
*/
void moteur_inference(BF base, BC baseC);

/**
* Ins�re en queue un nouveau fait � la base de fait "base"
* @param baseF : base de fait
* @param c caract�re (fait) � ajouter � la base de fait
* @return la base de fait avec un nouveau caract�re
*/
BF insert_tail_BF(BF base, char *c);

#endif

