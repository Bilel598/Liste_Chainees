
typedef struct Element Element;
typedef struct Liste Liste;


struct Element
{
    int nombre;
    Element *suivant;
};

struct Liste{
    Element *premier;
};

Liste *initialisation();
void insertion(Liste *liste, int nvNombre);
void append(Liste *liste, int nvNombre);
void suppression(Liste *liste, Element *element);
void afficherListe(Liste *liste);
void occurence(Liste *liste,int occurence);
void supprOcuurence(Liste *liste,int occurence, int delete);
int taille(Liste *liste);
