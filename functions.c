#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

Liste *initialisationListe(int val) {
	Liste *l;
	Element *element;
	l = (Liste*)malloc(sizeof(Liste));
	element = (Element*)malloc(sizeof(Element));

	if(l == NULL || element == NULL) {
		exit(-1);
	}

	element->nombre = val;
	element->suivant = NULL;
	l->premier = element;
	l->dernier = element;

	return l;
}


void ajout_deb(Liste *l, int val) {
	Element *nouveau;
	nouveau = (Element*)malloc(sizeof(Element));
	if(!nouveau) {
		exit(-1);
	}
	nouveau->nombre = val;
	nouveau->suivant = l->premier;
	l->premier = nouveau;
}
