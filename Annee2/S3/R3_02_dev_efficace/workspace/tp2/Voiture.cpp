#include "Voiture.h"

Individu::Individu(string maMarque, string maPlaque)
{
    this->_marque = maMarque;
    this->_plaqueImat = maPlaque;
}

string Individu::getMarque(){
    return this->_marque;
}

void Individu::setMarque(string uneMarque){
    this->_marque = uneMarque;
}

string Individu::getPlaqueImat(){
    return this->_plaqueImat;
}

void setPlaqueImat(string maPlaque){
    this->_plaqueImat = maPlaque;
}

void Individu::getMonPilote(){
    return monPilote.toString();
}
void setMonPilote(){}
