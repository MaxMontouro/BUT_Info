#include <iostream>
#include <sstream>
#include "sousProgrammes.h"
#include "fichierTexte.h"

using namespace std;

float moyennePluviometrique (string nomSysFic)
{
    UnFichierTexte nomFichier;
    associer(nomFichier, nomSysFic);
    ouvrir(nomFichier, consultation);
    float sommeValeur;
    float nbVal;
    float nombre;
    bool finFichier;

    while(true)
    {
        lireMot(nomFichier, nombre, finFichier);
        if(finFichier == true)
        {
            break;
        }
        sommeValeur += nombre;
        nbVal++;
    }
    fermer(nomFichier);
    return sommeValeur/nbVal;
}
