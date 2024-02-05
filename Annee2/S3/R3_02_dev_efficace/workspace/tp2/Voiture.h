#ifndef VOITURE_H
#define VOITURE_H

#include <iostream>
#include "Individu.h"
using namespace std;

class Individu{
    private:
        string _marque;
        string _plaqueImat;
        Individu* monPilote;
    public:
        //CONSTRUCTOR
        Individu(string, string);   
        //ENCAPSULATION
        string getMarque();
        void setMarque(string);
        string getPlaqueImat();
        void setPlaqueImat(string);
        string getMonPilote();
        void setMonPilote();
        //METHODES USUELLES
        virtual string toString();
};
#endif // CLASSE VOITURE_H