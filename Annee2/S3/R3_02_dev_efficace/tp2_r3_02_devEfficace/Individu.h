#ifndef INDIVIDU_H
#define INDIVIDU_H

#include <iostream>
#include "Voiture.h"
using namespace std;

class Voiture;//permet de dire a cpp qu'il y a une classe voiture et eviter que gcc pete les couilles

class Individu{
    private:
        string _nom;
        string _prenom;
        Voiture* maVoiture;
    public:
        //CONSTRUCTOR
        Individu(string, string);   
        //ENCAPSULATION
        string getNom();
        void setNom(string);
        string getPrenom();
        void setPrenom(string);
        string getMaVoiture();
        void setMaVoiture(*);
        //METHODES USUELLES
        virtual string toString();
}
#endif //CLASSE INDIVIDU_H