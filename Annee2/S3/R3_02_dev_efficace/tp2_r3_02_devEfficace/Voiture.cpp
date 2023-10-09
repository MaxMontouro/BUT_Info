#include "Voiture.h"

Voiture::Voiture(string maMarque, string maPlaque)
{
    this->_marque = maMarque;
    this->_plaqueImat = maPlaque;
}

string Voiture::getMarque(){
    return this->_marque;
}

void Voiture::setMarque(string uneMarque){
    this->_marque = uneMarque;
}

string Voiture::getPlaqueImat(){
    return this->_plaqueImat;
}

void Voiture::setPlaqueImat(string maPlaque){
    this->_plaqueImat = maPlaque;
}

void Voiture::getMonPilote(){
    return monPilote->toString();
}
string setMonPilote(*);