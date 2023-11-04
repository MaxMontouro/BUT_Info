#include "Hotel.h"

Hotel::Hotel(string nom, string adresse){
    nom = _nom;
    adresse = _adresse;

    
}

Hotel::~Hotel(){}

Hotel::Hotel(const Hotel& hotelModeleACopier){
    _adresse = hotelModeleACopier._adresse;
    _nom = hotelModeleACopier._nom;

    lesAdministrateurs.insert(hotelModeleACopier.lesAdministrateurs.begin(), 
                              hotelModeleACopier.lesAdministrateurs.end());
    
    set<Chambre*>::iterator chambre = hotelModeleACopier.mesChambres.begin();
    
    for(chambre; chambre!=hotelModeleACopier.mesChambres.end(); chambre++){
        mesChambres.insert(new Chambre(**chambre));
    }
}

Hotel& Hotel::operator= (const Hotel& hotel){
    string nomHotel = hotel._nom;
    string adresseHotel = hotel._adresse;

    lesAdministrateurs.insert(hotel.lesAdministrateurs.begin(), hotel.lesAdministrateurs.end());

    set<Chambre*>::iterator chambre;
    for(chambre = hotel.mesChambres.begin(); chambre != hotel.mesChambres.end(); chambre++){
        mesChambres.insert(new Chambre(**chambre));//Ins�re une chambre sur le mod�le de la chambre courante
    }

    return *this;
}

bool Hotel::administrerPar(Administrateur* admin){
    return (lesAdministrateurs.insert(admin).second);
}

bool Hotel::ajouterChambre(string numero, string etage, unsigned short int prix){
    if(numero == "" || etage == "" || prix == 0){ return false;}

    Chambre* nouvelleChambre = new Chambre(numero,etage,prix);

    return(mesChambres.insert(nouvelleChambre).second);
}

bool Hotel::modifierPrixChambre(string numero, unsigned short int prix ){
    bool modification = false;

    set<Chambre*>::iterator chambre;
    for(chambre = mesChambres.begin(); chambre != mesChambres.end();  chambre++){
        if((*chambre)->_numero == numero){
            (*chambre)->_prix = prix;
            modification = true;
            break;
        }
    }
    return modification;
}
    
string Hotel::toString (string message){
    string resultat = message;

    /// Int�gre nom et adresse
    resultat += _nom + " : " + _adresse + "\n";

    /// Int�gre lesAdministrateurs
    set<Administrateur*>::iterator admin;
    for (admin = lesAdministrateurs.begin(); admin != lesAdministrateurs.end(); admin++) {
        resultat += (*admin)->toString ("ADMIN : ") + "\n";
    }
    /// Int�gre les chambres
    set<Chambre*>::iterator chambre;
    for (chambre = mesChambres.begin(); chambre != mesChambres.end() ; chambre++) {
        resultat += (*chambre)->toString ("CHAMBRE : ") + "\n";
    }
    return resultat;
}
