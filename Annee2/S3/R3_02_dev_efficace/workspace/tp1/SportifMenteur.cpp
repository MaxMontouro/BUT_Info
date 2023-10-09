#include "SportifMenteur.h"
#include "Outils.h"

SportifMenteur::SportifMenteur(string nom, string prenom, short int anneeNaissance, string tuteur):
    Sportif(nom, prenom, anneeNaissance)
{
    this->_tuteur = tuteur;
}

string SportifMenteur::getTuteur(){
    return this->_tuteur;
}

void SportifMenteur::setTuteur(string unTuteur){
    this->_tuteur = unTuteur;
}

void SportifMenteur::toString(){
    cout << "Je suis " << this->getPrenom() << "  " << this->getNom() << " et je suis né en " << this->getAnneeNaissance() << " et mon tuteur est " << this->getTuteur();
}

short int SportifMenteur::getAge(){
    Outils *outil = new Outils();
    short int anneeActuelle = outil->anneeActuelle();
    short int anneeNaissance = this->getAnneeNaissance();
    if(static_cast<short int>(anneeActuelle - anneeNaissance) < 18)
    {
        return 18;
    }
    else{
        return static_cast<short int>(anneeActuelle - anneeNaissance);
    }
}