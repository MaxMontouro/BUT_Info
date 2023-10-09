#include "carre.h"
#include <iostream>

using namespace std;

void init(Carre& pCarre, int pAbscisse, int pCote, int pOrdonne)
{
    pCarre.origine.abscisse = pAbscisse;
    pCarre.origine.ordonnee = pOrdonne;
    pCarre.cote = pCote;

}

void init(Carre& pCarre, const Carre& pCarreModele)
{
    pCarreModele.origine.abscisse = pCarre.origine.abscisse;
    pCarreModele.origine.ordonnee = pCarre.origine.ordonnee;
    pCarreModele.cote = pCarre.cote;
}

bool estEgal(Carre pCarre1, Carre pCarre2)
{
    return (pCarre1.origine.abscisse == pCarre2.origine.abscisse && pCarre1.origine.ordonnee == pCarre2.origine.ordonnee && pCarre1.cote == pCarre2.cote);
}

 bool toucher(Carre pCarre1, Carre pCarre2)
 {
    return (pCarre1.origine.abscisse == pCarre2.origine.abscisse || pCarre1.origine.ordonnee == pCarre2.origine.ordonnee || pCarre1.cote == pCarre2.cote);
 }

 void afficher(const Carre& pCarre)
 {
    cout << pCarre.origine.abscisse << "    " << pCarre.cote << "    " <<pCarre.origine.ordonnee;
    
 }

 void redimensionner(Carre& pCarre, float coeffModif)
 {
    pCarre.origine.abscisse = pCarre.origine.abscisse*static_cast<int>(coeffModif);
    pCarre.origine.ordonnee = pCarre.origine.ordonnee*static_cast<int>(coeffModif);
    pCarre.cote = pCarre.cote*static_cast<int>(coeffModif);
 }

 void deplacerVers(Carre& pCarre, int pNouvelleAbscisse, int pNouvelleOrdonnee)
 {
    pCarre.origine.abscisse = pNouvelleAbscisse;
    pCarre.origine.ordonnee = pNouvelleOrdonnee;
 }

 void decalerDe(Carre& pCarre,int pDecalerAbscisse, int pDecalerOrdonnee)
 {
    pCarre.origine.abscisse = pDecalerAbscisse;
    pCarre.origine.ordonnee = pDecalerOrdonnee;
 }

int getAbscisse(const Carre& pCarre)
 {
    return getAbscisse(pCarre.origine);
 }

int getOrdonnee(const Carre& pCarre)
{
   return getOrdonnee(pCarre.origine);// Appel du ss prgrm getOrdonne du champ pCarre.origine en faisant appel a la fct getOrdonnee du module point.h 
}

unsigned int getCote(const Carre& pCarre)
{
    return getCote(pCarre.origine);
}