#include <iostream>
#include <list>
#include <map>
#include "ListePair.h"
#include "ListeSimple.h"
using namespace std;



int main(void)
{
    //pour oneshot
    pair<string,string> laPair("listeA","listeB");
    // OU
    //pour pls
    typedef pair<string,string> pairDeString;
    pairDeString jeSuisTonPair;
    jeSuisTonPair.first = "partieA";
    jeSuisTonPair.second = "partieB";

    

    return 0;
}