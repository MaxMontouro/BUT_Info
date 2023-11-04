#include "Administrateur.h"

Administrateur::Administrateur(string identite, string fonction){
    identite = _identite;
    fonction = _fonction;
}

Administrateur::~Administrateur(){}

string Administrateur::toString (string message) {
    string resultat = message;
    resultat += _identite + " (" + _fonction +")";
    return resultat;
}