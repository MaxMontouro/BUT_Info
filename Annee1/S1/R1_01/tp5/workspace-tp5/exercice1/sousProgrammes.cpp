#include "sousProgrammes.h"
#include "fichierTexte.h"
#include <iostream>
using namespace std;

void afficherFichierTexte(string nomSysFic)
{
	//VARIABLES
	bool finFichier = false;
	string chaine;
	UnFichierTexte nomFichier;

	//SS PRGM

	associer(nomFichier, nomSysFic);
	ouvrir(nomFichier, consultation);
	
	while(finFichier == false)
	{
		lireLigne(nomFichier, chaine, finFichier);
		cout << chaine << endl;
	}
	fermer(nomFichier);
}

void etendreFichierTexte (string nomSysFicSource, string nomSysFicCible)

{
	//VARIABLES 
	UnFichierTexte nomFichier1;
	UnFichierTexte nomFichier2;
	string chaine;
	bool finFichier = false;

	//SS PRGM
	associer(nomFichier1, nomSysFicCible);
	associer(nomFichier2, nomSysFicSource);
	ouvrir(nomFichier1, extension);
	ouvrir(nomFichier2, consultation);

	while(true)
	{
		lireLigne(nomFichier2, chaine, finFichier);
		if(finFichier == true)
		{
			break;
		}
		ecrire(nomFichier1, chaine);
		chaine += "  ";
	}
	fermer(nomFichier2);
	fermer(nomFichier1);
}

void viderFichierTexte(string nomSysFic)
{
      // Exemple du cours
	UnFichierTexte nomFichier1;
	string lecture;
	bool finFichier = false;

	associer(nomFichier1, nomSysFic);
	ouvrir(nomFichier1, creation);
	fermer(nomFichier1);
	ouvrir(nomFichier1, consultation);

	while(finFichier !=true)
	{
		lireLigne(nomFichier1, lecture, finFichier);
	}

	fermer(nomFichier1);

}