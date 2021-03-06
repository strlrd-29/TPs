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


//--- fonctions demandees ---

Liste *initialisationListe(int val);
void ajout_deb(Liste *l, int val);
void supp_deb(Liste *l);
void afficheListe(Liste *l);

//--- fonctions en plus ---

void ajout_fin(Liste *l, int val);
void supp_fin(Liste *l);

void ajout_milieu(Liste *l, int rang, int val);
void supp_milieu(Liste *l, int rang);
void supp_val(Liste *l, int val);
