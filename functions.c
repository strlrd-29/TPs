#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"

Specialite ajout_specialite() {
	Specialite nouv_spec;
	printf("Entrez le code de la specilite : ");
	scanf("%d",&nouv_spec.Code);
	printf("Entrez le nom de la specilite : ");
	scanf("%s", nouv_spec.Nom);
	printf("Entrez le departement de la specilite : ");
	scanf("%s", nouv_spec.Dpt);

	return nouv_spec;
}

Etudiant ajout_etudiant(int niveau, char specialite[]) {
	Etudiant nouv_etud;
	nouv_etud.Niveau = niveau;
	strcpy(specialite, nouv_etud.Specialite);
	printf("\nEntrez le matricule de l'etudiant : ");
	scanf("%d",&nouv_etud.Matricule);
	printf("Entrez le nom de l'etudiant : ");
	scanf("%s", nouv_etud.Nom);
	printf("Entrez le prenom de l'etudiant : ");
	scanf("%s", nouv_etud.Prenom);
	printf("Date De Naissance: \n");
	printf("Jour : ");
	scanf("%d", &nouv_etud.Date_naissance.jour);
	printf("Mois : ");
	scanf("%d", &nouv_etud.Date_naissance.mois);
	printf("Annee : ");
	scanf("%d", &nouv_etud.Date_naissance.annee);
	printf("Donner l'age de l'etudiant : ");
	scanf("%d", &nouv_etud.Age);
	printf("Donner l'adresse de l'etudiant : ");
	scanf("%s", nouv_etud.Adresse);

	return nouv_etud;
}

void affichage(Etudiant listeEtudiants[], int n) {
	int i;
	for(i=0 ;i<n; i++) {
		printf("|   %9d   |  %7s %7s  |         %2d/%2d/%2d        |   %2d   |%13s|\n",listeEtudiants[i].Matricule,listeEtudiants[i].Nom,listeEtudiants[i].Prenom,listeEtudiants[i].Date_naissance.jour,listeEtudiants[i].Date_naissance.mois,listeEtudiants[i].Date_naissance.annee,listeEtudiants[i].Age,listeEtudiants[i].Adresse);
	}
}
