#include <stdio.h>
#include <stdlib.h>

#include "functions.h"


void verifieListe(Liste *l, char res) {
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
}


/*
 1-fonction d'initialisation
 2-fonction d'ajout au debut
 3-fonction de suppresssion au debut
 4-fonction d'affichage de la liste
 5-fonction d'ajout a la fin de la liste
 6-fonction de suppresssion de la fin
 7-fonction d'ajout dans un certain rang
 8-fonction de suppression dans un certain rang
 9-fonction de suppression d'une certaine valeur
 */


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
	verifieListe(l,res);

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



void ajout_fin(Liste *l, int val) {
	Element *nouveau;
	nouveau = (Element*)malloc(sizeof(Element));
	if(!nouveau) {
		exit(-1);
	}
	nouveau->suivant= NULL;
	nouveau->nombre = val;
	l->dernier->suivant = nouveau;
	l->dernier = nouveau;
}


void supp_fin(Liste *l) {
	Element *courant;
	Element *precedent;
	char res;
	verifieListe(l,res);		

	courant = l->premier;
	while(courant->suivant) {
		precedent = courant;
		courant = courant->suivant;		
	}
	precedent->suivant = NULL;
	l->dernier = precedent;
	free(courant);
}


void ajout_milieu(Liste *l, int rang, int val){
	int taille = 0,i = 1;
	Element *nouveau;
	Element *courant;
	Element *precedent;
	Element *p;

	nouveau = (Element*)malloc(sizeof(Element));
	if(!nouveau) {
		exit(-1);
	}
	//calcul de la taille de la liste chainne
	for(p = l->premier; p!=NULL; p = p->suivant) {
		taille++;
	}
	

	//verifier si le rang depace la taille du tableau
	if(rang > taille+1) {
		printf("Ce rang n'existe pas \n");
		exit(-1);
	}

	if(rang == 1) {
		ajout_deb(l, val);
	}else if(rang == taille+1) {
		ajout_fin(l, val);
	}else {
		courant = l->premier;
		while(i<rang) {
			precedent = courant;
			courant = courant->suivant;
			i++;
		}
		nouveau->nombre = val;
		precedent->suivant = nouveau;
		nouveau->suivant = courant;
	}
}


void supp_milieu(Liste *l, int rang) {
	int taille=0, i=1;
	Element *courant;
	Element *precedent;
	Element *p;
	
	for(p = l->premier; p!=NULL; p = p->suivant) {
		taille++;
	}


	if(rang == 1) {
		supp_deb(l);
	}else if(rang == taille) {
		supp_fin(l);
	}else {
		courant = l->premier;
		while(i<rang) {
			precedent = courant;
			courant = courant->suivant;
			i++;
		}
		precedent->suivant = courant->suivant;
		free(courant);
	}
}


void supp_val(Liste *l, int val) {
	int existe,i=1,rang;
	Element *p;

	for(p = l->premier; p!=NULL; p=p->suivant) {
		if(p->nombre == val) {
			existe = 1;
			rang=i;
			break;
		}else {
			existe = 0;
			i++;
		}
	}
	if(existe) {
		supp_milieu(l, rang);
	}else {
		printf("La valeur que vous chercher n'existe pas :(\n");
		exit(-1);
	}
}
