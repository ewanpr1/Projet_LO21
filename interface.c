//PERRIN Ewan
//LABORDE Antoine


/**
* Ce fichier gère les fonctions liées à l'interface
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "bc.h"
#include "interface.h"
#include "header_structures.h"

BC initial_BC(void)
{
    BC tempC = NULL;

    regle r1,r2,r3,r4,r5;

    /**
    *Initialisation de la règle 1
    */
    r1 = create_empty_regle();

    r1 = add_prop(r1, create_prop("Toux", 0));
    r1 = add_prop(r1, create_prop("Ecoulement nasal", 0));
    r1 = create_conclu(r1, "Rhume");

    /**
    *Initialisation de la règle 2
    */
    r2 = create_empty_regle();

    r2 = add_prop(r2, create_prop("Sueurs chaudes ou froides", 0));
    r2 = add_prop(r2, create_prop("Vomissements", 0));
    r2 = add_prop(r2, create_prop("Diarrhee", 0));
    r2 = create_conclu(r2, "Gastro-enterite");

    /**
    *Initialisation de la règle 3
    */
    r3 = create_empty_regle();

    r3 = add_prop(r3, create_prop("Mal de gorge", 0));
    r3 = add_prop(r3, create_prop("Fievre", 0));
    r3 = create_conclu(r3, "Angine");

    /**
    *Initialisation de la règle 4
    */
    r4 = create_empty_regle();

    r4 = add_prop(r4, create_prop("Angine", 0));
    r4 = add_prop(r4, create_prop("Amygdales rouges", 0));
    r4 = create_conclu(r4, "Angine rouge");

    /**
    *Initialisation de la règle 5
    */
    r5 = create_empty_regle();

    r5 = add_prop(r5, create_prop("Angine", 0));
    r5 = add_prop(r5, create_prop("Amygdales blanches", 0));
    r5 = create_conclu(r5, "Angine blanche");


    tempC = insert_tail_BC(tempC, r1);
    tempC = insert_tail_BC(tempC, r2);
    tempC = insert_tail_BC(tempC, r3);
    tempC = insert_tail_BC(tempC, r4);
    tempC = insert_tail_BC(tempC, r5);

    return tempC;
}

void mainMenu(BC baseC, BF baseF)
{
    int intChoice=0;

    do
    {
        printf("\n***Menu Principal***\n\n");

        printf( "1/ Tester le projet                                (saisir 1)\n"
                "2/ Ajouter une regle a la base de connaissance     (saisir 2)\n"
                "3/ Quitter                                         (saisir 3)\n");

        intChoice=menuManager(getch(),3);

        while(intChoice==10)
        {
            printf("\n>> Erreur: Veuillez saisir une valeur proposee dans le menu\n");
            intChoice=menuManager(getch(),3);
        }

        switch (intChoice)
        {
            case 1: system("cls"); /* Execute le projet*/
                    baseF = NULL;
                    run_project(baseF, baseC);
                    exit(EXIT_SUCCESS);
                    break;

            case 2: system("cls"); /* Propose à l'utilisateur d'ajouter un ou plusieur règle(s) à la base de connaissance*/
                    baseC = Add_regle(baseC);
                    break;

            case 3: system("cls"); /* Permet de quitter le programme*/
                    break;

            default:    //system("cls");
                        printf("\n\n>> erreur: probleme switch menu principal");

        }

    }
    while(intChoice!=3);
}

int testMenu(int numeroMenu,int nbMenu)
{
    if(numeroMenu>nbMenu)
    {
        printf("\n\n>>erreur: le menu demande n'existe pas");
        return 10;
    }
    else
    {
        return numeroMenu;
    }
}

int menuManager(char charChoice, int nbMenu)
{
    switch (charChoice)
    {
        case '1':   return testMenu(1,nbMenu);
                    break;

        case '2':   return testMenu(2,nbMenu);
                    break;

        case '3':   return testMenu(3,nbMenu);
                    break;

        case '4':   return testMenu(4,nbMenu);
                    break;

        case '5':   return testMenu(5,nbMenu);
                    break;

        case '6':   return testMenu(6,nbMenu);
                    break;

        case '7':   return testMenu(7,nbMenu);
                    break;

        case '8':   return testMenu(8,nbMenu);
                    break;

        case '9':   return testMenu(9,nbMenu);
                    break;

        default:    return 10;
    }
}

void run_project(BF baseF, BC baseC)
{
    baseF = NULL;

    printf("Veuillez ajouter vos symptomes a la base de fait");

    baseF = Affichage_choix_faits(baseF,baseC);

    system("cls");

    printf("Nous pouvons conclure que vous avez  : \n\n");

    moteur_inference(baseF, baseC);

    printf("\n\n>> Appuyez sur une touche pour quitter le programme");
    getch();
    system("cls");
}

BF Affichage_choix_faits(BF baseF, BC baseC)
{
    BC tempC = baseC;


    while(tempC != NULL)
    {
        premisse tempP = tempC->reg.prem;

        while(tempP != NULL)
        {
            char rep;

            if(BF_contains(baseF, tempP->proposit.prop) == 0 && conclu_contains(baseC, tempP->proposit.prop) == 0)
            {
                printf("\n\nAvez vous ce fait? : %s\n\nY = Oui\nN = Non\n",tempP->proposit.prop);
                rep = getch();
                system("cls");

                while(!(rep == 'Y' || rep == 'N'))
                {
                    printf(">> Erreur : Veuillez repondre avec 'Y' ou 'N'");
                    printf("\n\nAvez vous ce fait? : %s\n\nY = Oui\nN = Non\n",tempP->proposit.prop);
                    rep = getch();
                    system("cls");
                }

                if (rep == 'Y')
                {
                    baseF = insert_tail_BF(baseF, tempP->proposit.prop);
                }

                tempP = tempP->suivant;
            }
            else
            {
                tempP = tempP->suivant;
            }

        }
        tempC = tempC->suivant;
    }

    return baseF;
}

bool conclu_contains(BC baseC, char *c)
{
    BC tempC = baseC;
    bool test = 0;
    char temp2[100];

    strcpy(temp2,c);

    while ((tempC != NULL) && (test != 1))
    {
        char temp1[100];
        strcpy(temp1,tempC->reg.conclu.prop);
        if (strcmp(strlwr(temp1),strlwr(temp2)) == 0)
        {
            test = 1;
        }
        tempC = tempC->suivant;
    }
    return test;
}

bool BF_contains(BF baseF, char *c)
{
    bool test = 0;
    BF tempF = baseF;

    char temp1[100];
    strcpy(temp1,c);

    while ((tempF != NULL) && (test != 1))
    {
        char temp2[100];
        strcpy(temp2,tempF->fait);

        if (strcmp(strlwr(temp1),strlwr(temp2)) == 0)
        {
            test = 1;
        }
        tempF = tempF->next;
    }
    return test;
}

BC Add_regle(BC baseC)
{
    char rep;
    char rep_char[100];
    char rep_reg;
    regle test;

    do
    {
        int i=0;
        printf("Voulez-vous ajouter une regle a la base de connaissance?\n\nY = Oui\nN = Non\n");
        rep_reg = getch();
        system("cls");

        while(!(rep_reg == 'Y' || rep_reg == 'N'))
        {
            printf(">> Erreur : Veuillez repondre avec 'Y' ou 'N'");
            printf("\n\nVoulez-vous ajouter une regle a la base de connaissance?\n\nY = Oui\nN = Non\n");
            rep_reg = getch();
            system("cls");
        }

        if (rep_reg == 'Y')
        {
            test = create_empty_regle();

            for(i=0;i<=1;i++)
            {
                printf("Veuillez entrer la proposition %d\n",i+1);
                        fgets(rep_char, sizeof rep_char, stdin);
                        test = add_prop(test,create_prop(rep_char,0));
                        system("cls");
            }

            do
            {
                printf("Voulez-vous ajouter une autre proposition a la premisse de la regle?\n\nY = Oui\nN = Non\n");
                        rep = getch();
                        system("cls");

                while(!(rep == 'Y' || rep == 'N'))
                {
                    printf(">> Erreur : Veuillez repondre avec 'Y' ou 'N'");
                    printf("\n\nVoulez-vous ajouter une autre proposition a la premisse de la regle?\n\nY = Oui\nN = Non\n");
                    rep = getch();
                    system("cls");
                }

                if(rep == 'Y')
                {
                    printf("Veuillez entre la proposition %d\n",i+1);
                    i = i+1;
                    fgets(rep_char, sizeof rep_char, stdin);
                    test = add_prop(test,create_prop(rep_char,0));
                    system("cls");
                }

            }while(rep == 'Y');

            printf("\nVeuillez entre la conclusion : ");
                    fgets(rep_char, sizeof rep_char, stdin);
                    strcpy(test.conclu.prop, rep_char);
                    test.conclu.etat = 0;
                    system("cls");

            baseC = insert_tail_BC(baseC, test);
        }
    }while (rep_reg == 'Y');

    return baseC;
}
