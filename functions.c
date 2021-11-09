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


void supp_deb(Liste *l) {
	char res;
	Element *supp;
	if(l == NULL) {
		printf("La liste ne contiet aucun element!!\n");
		exit(-1);
	}
	if(l->premier == l->dernier) {
		printf("La liste chainee contiet un seul element voulez vous vraiment supprimer ?(y/n)\n");
		scanf("%c",&res);
		switch (res) {
			case 'y':
				printf("OK !!\n");
				break;
			case 'n':
				exit(-1);
				break;
		}
	}
		supp = l->premier;
		l->premier = l->premier->suivant;
		free(supp);
}


void afficheListe(Liste *l) {
	Element *p;
	int i = 0;
	
	if(l == NULL) {
		printf("La liste est vide\n");
		exit(1);
	}
	for(p = l->premier; p!=NULL; p = p->suivant) {
		printf("\n valeur %d : %d ---- son adresse : %p\n",i+1,p->nombre,p);
        i++;
	}
}
