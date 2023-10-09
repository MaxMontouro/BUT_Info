/**
 * Fichier : main.cpp
 * But : Programme de test du module Carre 
 * Auteur : Pantxika Dagorret
 * date : 20-11-2023
 * Référence : feuille de TD n°3, exercice 2
 */
#include "carre.h"
#include <iostream>
using namespace std;


void afficherEtatApresAction(string pLibelleAction, const Carre& pCarre1, const Carre& pCarre2);
// But : affiche les champs abscisse, ordonnee, cote des pCarre1 et pCarre2 passés en paramètre,
//       puis indique si les 2 carrés sont égaux et s'ils se touchent ou pas

int main(void)
{
	
	Carre carre1; 
	Carre carre2;
	

	
	// 0,0,1, 20,20,10 >> init >> carre1, carre2
	init (carre1, 0, 0, 10);
	init (carre2, carre1);
	afficherEtatApresAction("init (carre1, 0, 0, 10); init (carre2, carre1); ", carre1, carre2);
	cout <<"\n";

	// 18,18,10 >> init >> carre2
	init (carre2, 18, 18, 10);
	afficherEtatApresAction("init (carre2, 18, 18, 10); ", carre1, carre2);
	cout << "\n";
	

	
	// carre1, 11 >> decaler >> carre1
	decalerDe(carre1, 11, 11);
	afficherEtatApresAction( "decalerDe (carre1, 11, 11);" , carre1, carre2);
	

	
	// carre1, 0.8 >> redimensionner >> carre1
	redimensionner (carre1, 0.5);
	afficherEtatApresAction( "redimensionner (carre1, 0.5);" , carre1, carre2);
	

	
	// carre1, 13,13 >> deplacerVers >> carre1
	deplacerVers(carre1, 13, 13);
	afficherEtatApresAction("deplacerVers (carre1, 13, 13);", carre1, carre2);


	//carre >> afficher(carre.abscisse)
	getAbscisse(carre1);
	getAbscisse(carre2);


	//carre >> afficher(carre.ordonnee)
	getOrdonnee(carre1);
	getOrdonnee(carre2);


	//carre >> afficher(carre.cote)
	getCote(carre1);
	getCote(carre2);
	
	return 0;
}


void afficherEtatApresAction(string pLibelleAction,const Carre& pCarre1,const Carre& pCarre2)
{
	cout << endl;
	cout << pLibelleAction << endl; 
	cout << "carre1 : " ;  afficher(pCarre1);
	cout << "\n";
	cout << "carre2 : " ;  afficher(pCarre2);
	cout << "\n";

	if (estEgal(pCarre1, pCarre2))
	{
		 cout << "Les 2 carres sont egaux " << endl;   
	}
	else 
	{
		cout << "Les 2 carres sont differents" << endl;
	};
	if (toucher(pCarre1, pCarre2))
	{
		cout << "Les 2 carres se touchent " << endl;
	}
	else 
	{
		cout << "Les 2 carres NE se touchent PAS" << endl;
	};

}

