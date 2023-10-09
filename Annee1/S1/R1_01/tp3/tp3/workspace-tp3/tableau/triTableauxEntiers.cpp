#include "triTableauxEntiers.h"
#include <iostream>

using namespace std;

void remplirTab(int tab[4][4], int lgTab, int lgLigne)
{
    int somme = 0;
    
    for(unsigned short int indice = 0; indice < lgTab; indice++)
    {
        for(unsigned short int indiceCourant = 0; indiceCourant < lgLigne; indiceCourant++)
        {
            tab[indice][indiceCourant]= somme;
            somme++;
        }       
    }
}

void afficherTab(int tab[4][4], int lgTab, int lgLigne)
{
    for(unsigned short int indiceParcours = 0; indiceParcours < lgTab; indiceParcours++)
    {
        for(unsigned short int indice = 0; indice < lgLigne; indice++)
        {
            cout << tab[indiceParcours] << "   "; 
        }
    }
}