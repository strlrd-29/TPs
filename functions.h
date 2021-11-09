#include <stdio.h>
#include <stdlib.h>
typedef  struct Element Element;
struct Element {
	int nombre;
	Element *suivant;
};

typedef struct Liste Liste;
struct Liste{
	Element *premier;
	Element *dernier;
};


Liste *initialisationListe(int val);
void ajout_deb(Liste *l, int val);
void supp_deb(Liste *l);
