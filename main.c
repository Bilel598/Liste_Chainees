#include <stdio.h>
#include <stdlib.h>
#include "ListeChainee.h"

int main(int argc, char *argv[])
{
 Liste *maListe = initialisation();

    insertion(maListe, 4);
    insertion(maListe, 7);
    append(maListe, 8);
    append(maListe, 9);
    append(maListe, 8);
    append(maListe, 9);

    afficherListe(maListe);
	supprOcuurence(maListe,8,1);
	afficherListe(maListe);
	printf("%d", taille(maListe));

    return 0;
}