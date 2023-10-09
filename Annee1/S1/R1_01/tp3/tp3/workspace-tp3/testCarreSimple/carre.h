#ifndef CARRE_H
#define CARRE_H

struct Carre
{
 int abscisse ; // abscisse du point Origine du carre, axe horizontal
 int ordonnee ; // ordonnee du point Origine du carre, axe vertical
 unsigned cote ; // dimension des cotes du carre
};

/* -------------------------------------------------------------------------
 Getters et setters (accès et modification) des champs de l'enregistrement
 ------------------------------------------------------------------------*/

 void getAbscisse(Carre& pCarre);
 //Obtenir l’abscisse du carré passé en paramètre

 void getOrdonnee(Carre& pCarre);
 //Obtenir l'ordonnee du carré passé en paramètre

 void getCote(Carre& pCarre);
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

 void init(Carre& pCarre, Carre& pCarreModule);
 //initalise un carre a partir d un autre carre creer precedemment 

void redimensionner( Carre& pCarre, float coeffModif);

void deplacerVers(Carre& pCarre, int pAbscisse, int pOrdonne);
//affecte au premier paramètre carré l’abscisse et ordonnée du second paramètre carré 

void decalerDe( Carre& pCarre, int pAbscisse, int pCote);
// déplace l’origine du carré de la distance passée en second paramètre

/* --------------------------------
 Entrées / Sorties / Exportations
 -------------------------------*/ 
void afficher(const Carre& pCarre);
//Affiche les parametres du carre

#endif