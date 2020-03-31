//PERRIN Ewan
//LABORDE Antoine

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "header_structures.h"
#include "bc.h"
#include "interface.h"

int main(int argc, char* argv[])
{

    BC baseC = initial_BC(); //permet de créer notre base de connaissance

    BF baseF = NULL; //initialise notre base de fait

    mainMenu(baseC, baseF);

    return EXIT_SUCCESS;
}
