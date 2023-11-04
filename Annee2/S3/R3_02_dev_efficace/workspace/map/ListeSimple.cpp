#include <iostream>
#include <list>
#include <map>
#include "ListePair.h"
#include "ListeSimple.h"
using namespace std;


void listSimple(){
    typedef list<string> listS;
    listS uneListeS;                                        //peut être a remplacer par listeS uneListeS()
    uneListeS.push_back(listS::value_type("Pantxika"));     //pour donner objet dans le type qu'il demande
    uneListeS.push_back(listS::value_type("Patrick")); 
    uneListeS.push_back(listS::value_type("Yann")); 
    uneListeS.push_back(listS::value_type("Philippe")); 

    listS::iterator iteListeS;
    iteListeS = uneListeS.begin();                          //pour le placer au début
    //parcours
    while (iteListeS != uneListeS.end()) 
    {   //affichage de l'élément de la liste
        cout << *iteListeS << endl;
        iteListeS ++;
    }
}


