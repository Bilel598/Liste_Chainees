#include <stdio.h>
#include <stdlib.h>
#include "ListeChainee.h"

Liste *initialisation(){
	/* Création de la liste */
    Liste *liste = malloc(sizeof(*liste));
	
	/* Création du premier élément */
    Element *element = malloc(sizeof(*element));

	/*Traitement des éventuelles erreurs*/
    if (liste == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }
	
    element->nombre = 0;
    element->suivant = NULL;
    liste->premier = element;

    return liste;
}


void insertion(Liste *liste, int nvNombre){
    /* Création du nouvel élément */
    Element *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->nombre = nvNombre;

    /* Insertion de l'élément au début de la liste */
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}

void append(Liste *liste, int nvNombre){
    /* Création du nouvel élément */
	Element *nouveau = malloc(sizeof(*nouveau));
	nouveau->nombre = nvNombre;
	nouveau->suivant= NULL;
	/* Sauvegarde du premier élément actuel*/
	if (liste == NULL || nouveau == NULL){
		
        exit(EXIT_FAILURE);
    }
	/* Insertion du nouvel élément en fin de liste*/
	Element *element = liste->premier;
	while(element->suivant != NULL){
	element=element->suivant;
	}
	element->suivant= nouveau;
	
	
}

void afficherListe(Liste *liste){
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel = liste->premier;
	/* Parcours de la liste*/
    while (actuel != NULL)
    {
        printf("%d -> ", actuel->nombre);
        actuel = actuel->suivant;
    }
}

void occurence(Liste *liste,int occurence){
	int count=0;
    if (liste == NULL){
        printf("Liste vide!");
    }
	/* Element parcourant la liste*/
	Element *compare = liste->premier;
	
	while(compare != NULL){
		/* Comparaison des nombres */
		if(occurence == compare->nombre)
			count++;
		compare=compare->suivant;
	}
	printf("Nombre d'occurence pour %d : %d\n",occurence,count);
}

void suppression(Liste *liste, Element *aSuppr){
	/* Sauvegarde de l'élément précedent */
	Element *precedent = liste-> premier;
	/* Cas où l'élément à supprimer est le 1er*/
	if(aSuppr==liste->premier){
		liste->premier = aSuppr->suivant;
	}
	else{
		while(precedent->suivant != aSuppr){
			precedent = precedent->suivant;
		}
		/* Suppression */
		precedent->suivant = aSuppr->suivant;
	}

	free(aSuppr);
	free(precedent);
	}



void supprOcuurence(Liste *liste,int occurence, int multiSuppr){
//0=true; 1=false
	if (liste == NULL){
        printf("Liste vide!");
    }
	else{
		Element *aSuppr = liste-> premier;
		Element *element = liste->premier;
		while(element != NULL){
			if(occurence == element->nombre){
				while(aSuppr !=element){
					aSuppr=aSuppr->suivant;
				}
				element=element->suivant;
				suppression(liste,aSuppr);
				if( multiSuppr == 0)
					break;
			}	
			element=element->suivant;
		}
	}
}

int taille(Liste *liste){
	Element *element = liste->premier;
	int taille;
	/* Parcours de la liste*/
	while(element != NULL){
		/* Incrementation de la variable*/
		taille++;
		element= element->suivant;
	}
	return taille;
}