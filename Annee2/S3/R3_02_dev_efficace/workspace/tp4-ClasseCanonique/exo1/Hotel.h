/**
 * @file Hotel.h
 * @author MaxMontouro
 * @brief 
 * @version 0.1
 * @date 2023-10-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
using namespace std;
#include "Administrateur.h"
#include "Chambre.h"
#include <set>
#include <algorithm>

#ifndef HOTEL_H
#define HOTEL_H

class Hotel{
    
    //ATTRIBUTS
    public:
        string _nom;
        string _adresse;
        set<Chambre*> mesChambres;
        set<Administrateur*> lesAdministrateurs;
    //CONSTRUCTEUR & DESTRUCTEUR
    public:
        Hotel(string = "", string = "");
        Hotel(const Hotel&);
        ~Hotel();

    //METHODES USUELLES
    public:
        Hotel& operator= (const Hotel&);
    
    //METHODES SPECIFIQUES
    public:
        string toString(string);
        bool administrerPar(Administrateur* admin);
        bool ajouterChambre(string, string, unsigned short int);
        bool modifierPrixChambre(string, unsigned short int);
};
#endif //HOTEL_H