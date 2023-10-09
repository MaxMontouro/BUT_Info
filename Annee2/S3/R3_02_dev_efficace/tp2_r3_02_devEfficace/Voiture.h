#ifndef VOITURE_H
#define VOITURE_H

#include <iostream>
#include "Individu.h"
using namespace std;

class Voiture{
    private:
        string _marque;
        string _plaqueImat;
        Individu* monPilote;
    public:
        //CONSTRUCTOR
        Voiture(string, string);   
        //ENCAPSULATION
        string getMarque();
        void setMarque(string);
        string getPlaqueImat();
        void setPlaqueImat(string);
        string getMonPilote();
        void setMonPilote(Individu*);
        //METHODES USUELLES
        virtual string toString();
}
#endif // CLASSE VOITURE_H