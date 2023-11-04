#include "Chambre.h"

Chambre::Chambre(string numero, string etage, unsigned short int prix){
    numero = _numero;
    etage = _etage;
    prix = _prix;
}

Chambre::~Chambre(){}
string Chambre::toString (string message) {
    string resultat = message;
    resultat += _numero + " / " + _etage + " / " + to_string(_prix) + " euros";
    return resultat;
}
