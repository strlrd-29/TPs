#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

int main() {
	Liste *l;
	l = initialisationListe(3);
	//ajout au debut de la liste
	ajout_deb(l,9);
	ajout_deb(l,1);
	ajout_deb(l,54);
	ajout_deb(l,230);
	ajout_deb(l,4987);
	//fonction d'affichage
	afficheListe(l);
	return 0;
}
