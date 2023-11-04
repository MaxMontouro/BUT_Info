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


#ifndef ADMINISTRATEUR_H
#define ADMINISTRATEUR_H

class Administrateur{
    //ATTRIBUTS
    public:
        string _identite;
        string _fonction;

    //CONSTRUCTEUR
    public:
        Administrateur(string="", string="");
        ~Administrateur();
        string toString(string);
    //METHODES
};
#endif //HOTEL_H