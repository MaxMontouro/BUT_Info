/**
 * @file main.cpp
 * @author MaxMontouro
 * @brief 
 * @version 0.1
 * @date 2023-10-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <algorithm>
#include <list>
#include <map>

using namespace std;

typedef string Libelle;
typedef string Reference;
typedef int Prix;
typedef int Poids;

//classe 
class Produit {
    public:
    //ATTRIBUTS
        Reference _reference;
        Libelle _libelle;
        Prix _prix;

    //CONSTRUCTEUR 

    Produit(Reference laRef = "",Libelle lib="",Prix p=0){
        _reference = laRef;
        _libelle = lib;
        _prix = p;
    }

        //METHODES USUELLES
    string toString(string message = ""){
        string resultat = message;
        resultat += "Reference : " + _reference + " Libelle : " + _libelle;
        resultat += " Prix : " + to_string(_prix);
        return resultat;
    }
};

//fonction globale

void exempleFind(){
    //DEFINITION DE MAP DANS LEQUEL ON VA CHERCHER
    //CREATION DE LA CLASSE MapProduit
    typedef map<Reference, pair<Libelle,Prix> > MapProduit;

    //DECALRATION D UN OBJET MapProduit
    MapProduit unMapProduit;

    //PREPARATION DES VALEURS A PEUPLER
    pair<Libelle,Prix> p1 ("Canape", 10);
    pair<Libelle, Prix> p2("Fauteuil", 200);
}

//variable globale qui represente une refernce chercher
Reference referenceChercher;

//FONCTION BOOLENNE qui invoque depuis find_if pour chacun des produits sa sequence
bool memeReference(Produit produit){
    return(produit._reference == referenceChercher);
}

void exempleFindIf(){
    //PREPARATION DES 3 PRODUITS
    Produit produit1("P001", "Tabouret",10);
    Produit produit2("P002", "Chaise",20);
    Produit produit3("P003", "Table",30);

    typedef list<Produit> listProd;
    listProd uneListeProduit;

    /* TESTER VALIDER !!!
    cout << produit1.toString() << endl;
    cout << produit2.toString() << endl;
    cout << produit3.toString() << endl;*/ 

    uneListeProduit.push_back(listProd::value_type(produit1));
    uneListeProduit.push_back(listProd::value_type(produit2));
    uneListeProduit.push_back(listProd::value_type(produit3));

    //DECALRATION D'UN POINTEUR
    listProd::iterator existe = find_if(uneListeProduit.begin(), uneListeProduit.end(), memeReference);

    //DECLARATION D UNE RECHERCHE FRUCTUEURSE
    referenceChercher = "P002";

    if(existe != uneListeProduit.end()){
        cout << "Le premier objet produit avec la reference " << referenceChercher << " est : " << existe->toString() << endl; 
    }
    else{
        cout << "Aucune reference ne correspond";
    }
}




int main(){

    exempleFind();
    exempleFindIf();
    return 0;
}