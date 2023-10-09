#ifndef CARRE_H
#define CARRE_H
#include "point.h"

struct Carre
{
    Point origine;
    unsigned int cote ; // dimension des cotes du carre
};

/* -------------------------------------------------------------------------
 Getters et setters (accès et modification) des champs de l'enregistrement
 ------------------------------------------------------------------------*/

int getAbscisse(const Carre& pCarre);
 //Obtenir l’abscisse du carré passé en paramètre

int getOrdonnee(const Carre& pCarre);
 //Obtenir l'ordonnee du carré passé en paramètre

unsigned int getCote(const Carre& pCarre);
 //Obtenir la cote du carré passé en paramètre
/* --------------------------
 Primitives de comparaison
 -------------------------*/
 bool estEgal(Carre pCarre1, Carre pCarre2);
 //Renvoie True si les deux carres entrée en parametre on est les meme coordonnes, False sinon

 bool toucher(Carre pCarre1, Carre pCarre2);
 //Renvoie True si les 2 carres entree en parametre se touche, retourne False sinon

/* --------------------------
 Modificateurs
 -------------------------*/
 void init(Carre& pCarre, int pAbscisse, int pCote, int pOrdonnee);
 //initialisation d'un carre pCarre avec son abscisse, son ordonnee, sa cote

 void init(Carre& pCarre, const Carre& pCarreModele);
 //initalise un carre a partir d un autre carre creer precedemment 

void redimensionner( Carre& pCarre, float coeffModif);

void deplacerVers(Carre& pCarre, int pNouvelleAbscisse, int pNouvelleOrdonne);
//affecte au premier paramètre carré l’abscisse et ordonnée du second paramètre carré 

void decalerDe( Carre& pCarre, int pDecalerAbscisse, int pDecalerOrdonnee);
// déplace l’origine du carré de la distance passée en second paramètre

/* --------------------------------
 Entrées / Sorties / Exportations
 -------------------------------*/ 
void afficher(const Carre& pCarre);
//Affiche les parametres du carre

#endif