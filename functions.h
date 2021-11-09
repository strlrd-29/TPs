#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int jour;
	int mois;
	int annee;
} Date;

typedef struct {
	int Code;
	char Nom[100];
	char Dpt[100];
} Specialite;

typedef struct {
	int Matricule;
	char Nom[100];
	char Prenom[100];
	Date Date_naissance;
	int Age;
	char Adresse[100];
	char Specialite[100];
	int Niveau;
} Etudiant;

Specialite ajout_specialite();
Etudiant ajout_etudiant();
void affichage(Etudiant listeEtudiant[], int n);
