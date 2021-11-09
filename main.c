#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"


int main() {
	int niveau,n,i;

	//declaration d'une variable de type specialite pour enregistrer les donnees sur la specialite
	Specialite specialite;

	//declaration d'une table de type Etudiant pour l'affichage
	Etudiant Liste_Etudiants[100];

	//ajout de la specialite
	printf("Veuillez introduire la specialite :\n");
	printf("----------------\n");
	specialite = ajout_specialite();
	
	//demande du niveau des etudiant
	printf("Introduisez le niveau des etudiants : ");
	scanf("%d", &niveau);
	
	//demande du nombre d'etudiants
	printf("Introduisez le nombre d'etudiants : ");
	scanf("%d", &n);
	
	//L'ajout des etudiant selon le nombre entree par l'utilisateur
	for(i=0; i<n; i++) {
		printf("Etudiant n.%d", i+1);
		Liste_Etudiants[i] = ajout_etudiant(niveau,specialite.Nom);
	}


	//affichage de la liste des etudiants
	printf("La liste des Etudiants est : \n " );
	printf("---------------------------------------------------------------------------------------------------\n");
	affichage(Liste_Etudiants, n);
	return 0;
}
