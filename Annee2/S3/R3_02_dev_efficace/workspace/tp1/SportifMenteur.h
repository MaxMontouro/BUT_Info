#ifndef SPORTIFMENTEUR_H
#define SPORTIFMENTEUR_H

#include "Sportif.h"
#include <iostream>
using namespace std;

class SportifMenteur: Sportif{
private:
        string _tuteur;
public:
        SportifMenteur(string, string, short int, string);
        string getTuteur();
        void setTuteur(string);
        virtual void toString(); // définition de la fonction 
        virtual short int getAge();
};

#endif