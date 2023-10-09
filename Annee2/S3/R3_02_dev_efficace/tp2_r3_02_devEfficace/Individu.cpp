#include "Individu.h"


Individu::Individu(string monPrenom, string monNom)
{
    this->_prenom = monPrenom;
    this->_nom = monNom;
}

string Individu::getNom(){
    return this->_nom;
}

void Individu::setNom(string unNom){
    this->_nom = unNom;
}

string Individu::getPrenom(){
    return this->_prenom;
}

void Individu::setPrenom(string unPrenom){
    this->_prenom = unPrenom;
}

string Individu::getMaVoiture(){
    return maVoiture->toString();
}

string setMonPilote(*);