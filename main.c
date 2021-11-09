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

	supp_deb(l);

	//ajout a la fin de la liste
	ajout_fin(l,999);
	ajout_fin(l,99);
	ajout_fin(l,959);
	ajout_fin(l,3);
	ajout_fin(l,743);
	
	supp_fin(l);

	//fonction d'affichage	
	afficheListe(l);

	//ajout milieu de la liste
	ajout_milieu(l, 6, 100);
	supp_milieu(l,3);
	printf("Le nouveau affichage : \n");
	afficheListe(l);
	
	return 0;
}
