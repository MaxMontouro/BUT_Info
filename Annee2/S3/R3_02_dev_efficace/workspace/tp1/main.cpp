#include <iostream>
using namespace std;
#include "SportifMenteur.h"

//DECLARATION FONCTIONS GLOBALES 

int main()
{
    Sportif sportif1("Jean Paul" , "Lafayette", 2007);
    Sportif sportif2("Michel", "Fugain" , 2000);
    SportifMenteur sportif3("Alexandre", "Picoulet", 2010, "Abdoul");
    
    cout << sportif1.getAge();
    cout << endl;
    sportif1.toString();
    cout << endl;
    cout << sportif2.getAge();
    cout << endl;
    sportif2.toString();
    cout << endl;
    cout << sportif3.getAge();
    cout << endl;
    sportif3.toString();
    cout << endl;
    return 0;
}

//FONCTIONS GLOBALES 