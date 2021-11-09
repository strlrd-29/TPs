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
	
	printf("\n L'afficage de la liste des element est : \n");
	afficheListe(l);
	
	supp_deb(l);
	printf("\n L'afficage apres suppression du premier element est : \n");
	afficheListe(l);

	//ajout a la fin de la liste
	ajout_fin(l,999);
	ajout_fin(l,99);
	ajout_fin(l,959);
	ajout_fin(l,13);
	ajout_fin(l,743);
	
	printf("\n L'afficage apres plusieurs ajout d'element a la fin de la liste est : \n");
	afficheListe(l);
	
	supp_fin(l);
	printf("\n L'afficage apres suppression du dernier element est : \n");
	afficheListe(l);
	//fonction d'affichage	
	
	ajout_milieu(l,4,27);
	printf("\nL'affichage apres ajout d'un element a la position 4 est : \n");
	afficheListe(l);


	printf("\nL'affichage apres suppression d'un element a la position 7 est : \n");
	supp_milieu(l,7);
	afficheListe(l);

	supp_val(l, 27);
	printf("\nl'affichage apres suppression de la valeur 27 est : \n");
	afficheListe(l);
	//vous trouverz tous les autres fonctions dans le fichier functions.c si vous voulez les essayer
	return 0;
}
