/*#include <iostream>
#include <algorithm>
#include <list>
#include <map>

using namespace std;

#ifndef PRODUIT_H
#define PRODUIT_H

typedef string Libelle;
typedef string Reference;
typedef int Prix;
typedef int Poids;

//fonction globale
void exempleFind();
void exempleFindIf();

class Produit {
    public:

    //ATTRIBUTS
        Reference _reference;
        Libelle _libelle;
        Prix _prix;

    //CONSTRUCTEUR 

        Produit(Reference laRef = "",Libelle lib="",Prix p=0);

        //METHODES USUELLES
        string toString(string message = "");

};

#endif //PRODUIT_H*/