#include <iostream>
#include <list>
#include <map>
#include "map.h"
#include "ListePair.h"
#include "ListeSimple.h"
using namespace std;

void leMap(){
    typedef map<string, string> Annuaire; // créer un type MapDeString
    Annuaire unAnnuaire; // créer un objet annuaire
    
    // Etablit le type iterateurAnnuaire
    typedef Annuaire::iterator iterateurAnnuaire;

    // Crée resultatInsert une paire de valeurs qui récupere le résultat d'une insertion
    pair<iterateurAnnuaire,bool> resultatInsert;

    // TRAITEMENTS

    // Alimente l'annuaire et teste le résultat
    resultatInsert = unAnnuaire.insert(Annuaire::value_type("Pantxika","06.01.01.01.01"));

    if (resultatInsert.second)// si false rajouter ! devant      si true ne rien mettre apres  
    {
        cout << "insertion" << resultatInsert.first->first << "Bien réalisée" << endl;
    }
    else
        cout << "insertion Mal réalisée" << endl;
    
    // Réalimente l'annuaire et teste le résultat
    resultatInsert = unAnnuaire.insert(Annuaire::value_type("Pantxika","06.01.01.01.01"));
    if (resultatInsert.second)
    {
        cout << "insertion" << resultatInsert.first->first << "Bien réalisée" << endl;
    }
    else
        cout << "insertion Mal réalisée" << endl;
    // avec map on ne peut pas inserer un elem avec la même clé
    
    // alimente un annuaire
    resultatInsert = unAnnuaire.insert(Annuaire::value_type("Yann","06.02.02.02.02"));
    resultatInsert = unAnnuaire.insert(Annuaire::value_type("Philippe","06.03.03.03.03"));
    resultatInsert = unAnnuaire.insert(Annuaire::value_type("Patrick","06.04.04.04.04"));

    // créer un iterateur pour parcourir les objets de annuaire
    iterateurAnnuaire unIterateur;

    // initialise l'iterateur au premier élément de unAnnuaire
    unIterateur = unAnnuaire.begin();

    // parcours complet de la liste et affiche le second composant de chaque élément
    while (unIterateur!= unAnnuaire.end())
    {
        cout << unIterateur->second << endl;
        unIterateur ++;
    }
    
    // la methode find() retourne un iterateur sur la paire de clefRecherhee ou bien sur end()
    string clefRecherchee = "Philippe";
    unIterateur = unAnnuaire.find(clefRecherchee);

    // affiche le numéro de téléphone ou bien : Philippe - clef inconnue
    if (unIterateur!= unAnnuaire.end())
    {
        cout << clefRecherchee << " -telephone : " << unIterateur->second << endl;
    }
    else
        cout << clefRecherchee << "clef inconnue " << endl;  
}
