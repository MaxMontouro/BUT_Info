#include <iostream>
#include <list>
#include <map>
#include "ListePair.h"
#include "ListeSimple.h"
using namespace std;



void listPair(){
    typedef pair<string,string> pairDeString;
    typedef list<pair<string,string>> listeP;       // ou list<PairDeString>
    listeP uneListeP;
    uneListeP.push_back(listeP::value_type("Pantxika","06.01.01.01.01"));
    uneListeP.push_back(listeP::value_type("Yann","06.02.02.02.02"));
    uneListeP.push_back(listeP::value_type("Philippe","06.03.03.03.03"));
    uneListeP.push_back(listeP::value_type("Patrick","06.04.04.04.04"));

    listeP::iterator iteListP;
    iteListP = uneListeP.begin();
    while (iteListP!= uneListeP.end())
    {
        cout << iteListP->first << "    " <<iteListP->second << endl;
        iteListP ++;
    }
    
}


