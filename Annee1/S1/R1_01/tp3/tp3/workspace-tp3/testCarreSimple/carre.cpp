#include "carre.h"
#include <iostream>

using namespace std;

void init(Carre& pCarre, int pAbscisse, int pCote, int pOrdonne)
{
    pCarre.abscisse = pAbscisse;
    pCarre.ordonnee = pOrdonne;
    pCarre.cote = pCote;

}

void init(Carre& pCarre, Carre& pCarreModule)
{
    pCarreModule.abscisse = pCarre.abscisse;
    pCarreModule.ordonnee = pCarre.ordonnee;
    pCarreModule.cote = pCarre.cote;
}

bool estEgal(Carre pCarre1, Carre pCarre2)
{
    return (pCarre1.abscisse == pCarre2.abscisse && pCarre1.ordonnee == pCarre2.ordonnee && pCarre1.cote == pCarre2.cote);
}

 bool toucher(Carre pCarre1, Carre pCarre2)
 {
    return (pCarre1.abscisse == pCarre2.abscisse || pCarre1.ordonnee == pCarre2.ordonnee || pCarre1.cote == pCarre2.cote);
 }

 void afficher(const Carre& pCarre)
 {
    cout << pCarre.abscisse << "    " << pCarre.cote << "    " <<pCarre.ordonnee;
    
 }

 void redimensionner(Carre& pCarre, float coeffModif)
 {
    pCarre.abscisse = pCarre.abscisse*static_cast<int>(coeffModif);
    pCarre.ordonnee = pCarre.ordonnee*static_cast<int>(coeffModif);
    pCarre.cote = pCarre.cote*static_cast<int>(coeffModif);
 }

 void deplacerVers(Carre& pCarre, int pAbscisse, int pOrdonnee)
 {
    pCarre.abscisse = pAbscisse;
    pCarre.ordonnee = pOrdonnee;
 }

 void decalerDe(Carre& pCarre,int pAbscisse, int pCote)
 {
    pCarre.abscisse = pAbscisse;
    pCarre.cote = pCote;
 }

 void getAbscisse(Carre& pCarre)
 {
    cout <<"\n";
    cout << "L'abscisse du carre est : " << pCarre.abscisse << endl;
 }

void getOrdonnee(Carre& pCarre)
{
    cout <<"\n";
    cout << "L'ordonnee du carre est : " << pCarre.ordonnee << endl;
}

void getCote(Carre& pCarre)
{
    cout <<"\n";
    cout << "La cote du carre est : " << pCarre.cote << endl;
}