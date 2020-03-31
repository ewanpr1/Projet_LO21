//PERRIN Ewan
//LABORDE Antoine

/**
 * Ce fichier regroupe toutes les fonctions qui gèrent la base de connaissance, la base de fait et le moteur d'inférence
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "header_structures.h"
#include "bc.h"

/**
 * Partie liée aux fonctions de la question 2.2.1 qui permet de gérer une règle
 */

proposition create_prop(char *c,bool n)
{
    proposition p;

    strcpy(p.prop,c);
    p.etat = n;

    return p;
}

regle create_empty_regle(void)
{
    regle temp;

    temp.prem = NULL; //initialise la premisse de temp à NULL
    temp = create_conclu(temp,""); // on créer une conclusion vide

    return temp;
}

regle add_prop(regle r, proposition p)
{
    premisse temp,i;

    temp = (premisse)malloc(sizeof(prem));
	temp->proposit = p;
	temp->suivant = NULL;

	if (is_empty_prem(r))
	{
	    r.prem = temp;
		return r;
	}
	else
	{
		i = r.prem;
		while (i->suivant != NULL)
			{
				i = i->suivant;
			}
		i->suivant = temp;

		return r;
	}
}

regle create_conclu(regle r, char *c)
{
   strcpy(r.conclu.prop, c);
   r.conclu.etat = 0;

    return r;
}

bool contains(premisse p , char *prop)
{
    if (p == NULL)
        {return 0;}
    else
    {
        if ( strcmp(p->proposit.prop,prop)==0) //utilisation fonction strcmp pour comparer deux chaine de caractère
            {return 1;}
        else
            {return contains(p->suivant,prop);}
    }
}

premisse change_etat_p(regle r, char *prop) // cette fonction ne supprime pas réellement une proposition mais change son état
{
    bool test = 0;

    if (is_empty_prem(r))
        return NULL;
    else
    {

        if (contains(r.prem,prop))
        {
            premisse j = r.prem;
            while (j != NULL && test == 0)
            {
                char temp[100];
                strcpy(temp, prop);
                if (strcmp(j->proposit.prop,temp) == 0)
                {
                    j->proposit.etat = 1;
                    test = 1;
                }
                j = j->suivant;
            }
        }
        return r.prem;
    }
}

bool is_empty_prem(regle r)
{
    if (r.prem == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool test_pre (regle r) // Test si l'etat de chaque propsition est à 1 ou non
{
    if (is_empty_prem(r))
        return 1;
    else
    {
        premisse j = r.prem;
        while(j != NULL && j->proposit.etat == 1)
        {
            j = j->suivant;
        }
        if (j == NULL)
        {
            return 1;
        }
        else
            return 0;
    }
}

proposition head_value_p(premisse p)
{
    return p->proposit;
}

char conclu_regle(regle r)
{
     return *r.conclu.prop;
}


/**
 * Partie liée aux fonctions de la base de connaissance (question 2.2.2)
 */


BC create_empty_BC(void)
{
    return NULL;
}

regle head_regle_BC(BC base)
{
    return base->reg;
}

BC insert_tail_BC(BC b, regle r)
{
    BC temp = (BC)malloc(sizeof(base));
    temp->reg = r;
    temp->suivant = NULL;
    if (b == NULL)
        return temp;
    else
    {
        BC i = b;
        while (i->suivant != NULL)
        {
            i = i->suivant;
        }
        i->suivant = temp;
        return b;
    }
}


/**
 * Partie liée aux fonctions du moteur d'inférence (question 2.2.3)
 */


void moteur_inference(BF base, BC baseC)
{

    BF tempf = base;
    BC tempc = baseC;

    bool test = 0;

    while (tempf != NULL)
    {
        tempc = baseC;

        while (tempc != NULL)
        {
            tempc->reg.prem = change_etat_p(tempc->reg, tempf->fait); //on modifie la premisse ("supprime" une proposition en fonction du fait vrai)

            if (test_pre(tempc->reg) && tempc->reg.conclu.etat == 0) // on test si chaque membre de la prémisse est vrai (si la prémisse est vide) et si la conclusio n'a pas déjà été trouvé
            {
                test = 1;
                insert_tail_BF(tempf, tempc->reg.conclu.prop); // on insert donc notre conclusion à notre base de fait afin de pouvoir tester si la conclusion nous apporte pas d'autre information
                tempc->reg.conclu.etat = 1;
                printf("    - %s\n",tempc->reg.conclu.prop);
            }

            tempc = tempc->suivant;
        }
        tempf = tempf->next;
    }
    if (test == 0)
    {
        system("cls");
        printf("On ne peut tirer aucune conclusion\n\n");
    }
}

BF insert_tail_BF(BF base, char *c )
{
    BF temp = (BF)malloc(sizeof(basef));
    strcpy(temp->fait, c);
    temp->next = NULL;

    if (base == NULL)
        return temp;
    else
    {
        BF i = base;
        while (i->next != NULL)
        {
            i = i->next;
        }
        i->next = temp;
        return base;
    }
}
