//PERRIN Ewan
//LABORDE Antoine

#ifndef HEADER_STRUCTURES_H
#define HEADER_STRUCTURES_H

typedef int bool;

#define false 0
#define true 1


/**
* Definition d'une proposition
*/
typedef struct {    char prop[100];
                    bool etat;//L'état d'une proposition permet de déterminer si la proposition est vrai ou fausse.
                }proposition;

/**
* Definition d'un element d'une premisse (liste chainée de proposition)
*/
typedef struct elem {   proposition proposit;
                        struct elem *suivant;}prem;

/**
* Definition du type premisse
*/
typedef prem *premisse;

/**
* Definition d'une regle
*/
typedef struct {    premisse prem;
                    proposition conclu;}regle;

/**
* Definition d'un element de la base de connaissance(liste chainée de règle)
*/
typedef struct ba{  regle reg;
                    struct ba *suivant;}base;

/**
* Definition du type BC (représente une base de connaissance)
*/
typedef base *BC;



#endif
