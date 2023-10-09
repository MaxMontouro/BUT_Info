#ifndef SPORTIF_H
#define SPORTIF_H


#include <iostream>
using namespace std;

class Sportif{
private:
        string _nom, _prenom;
        short int _anneeNaissance;
public:
        Sportif(string, string, short int);
        string getNom();
        void setNom(string);
        string getPrenom();
        void setPrenom(string);
        short int getAnneeNaissance();
        void setAnneeNaissance(short int);
        virtual void toString(); // définition de la fonction 
        virtual short int getAge();
};

#endif