/**
 * @file Chambre.h
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

#ifndef CHAMBRE_H
#define CHAMBRE_H

class Chambre{
    //ATTRIBUTS
    public:
        string _numero;
        string _etage;
        unsigned short int _prix;
    
    //CONSTRUCTEUR
    public:
        Chambre(string ="", string="", unsigned short int=0);
        ~Chambre();
        string toString(string message="");
};
#endif //HOTEL_H