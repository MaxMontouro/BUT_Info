#include "Sportif.h"
#include "Outils.h"

Sportif::Sportif(string nom, string prenom, short int anneeNaissance)
{
    this->_nom = nom;
    this->_prenom = prenom;
    this->_anneeNaissance = anneeNaissance;
}

string Sportif::getNom(){
    return this->_nom;
}

void Sportif::setNom(string unNom){
    this->_nom = unNom;
}

string Sportif::getPrenom(){
    return this->_prenom;
}

void Sportif::setPrenom(string unPrenom){
    this->_prenom = unPrenom;
}

short int Sportif::getAnneeNaissance(){
    return this->_anneeNaissance;
}

void Sportif::setAnneeNaissance(short int uneAnneeDeNaissance){
    this->_anneeNaissance = uneAnneeDeNaissance;
}

void Sportif::toString(){
    cout << "Je suis " << this->getPrenom() << "  " << this->getNom() << " et je suis né en " << this->getAnneeNaissance();
}

short int Sportif::getAge(){
    Outils *outil = new Outils();
    short int anneeActuelle = outil->anneeActuelle();
    short int anneeNaissance = this->getAnneeNaissance();
    return static_cast<short int>(anneeActuelle - anneeNaissance);
}