#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

int main() {
	Liste *l;
	l = initialisationListe(3);
	
	//ajout au debut de la liste
	ajout_deb(l,9);
	printf("%d\n", l->premier->nombre);
	return 0;
}
