/**
 * Fichier : main.cpp
 * But : Programme de prise en main de la notion de module
 * v0 : le programme complet (sous-programme et main) implanté dans 1 seul fichier
 * Auteur : Pantxika Dagorret
 * date : 20-11-2023
 * Référence : feuille de TD n°3
 */

#include "triTableauxEntiers.h"
using namespace std;

int main(void)
{
    //VARIABLES
    const int NB_CASES = 4;//Lgr tab$
    const int NB_COLONNE = 4;//
    int tab[NB_CASES][NB_COLONNE];//tab de lgr NB_CASES

    //REMPLIR TAB
    remplirTab(tab, NB_COLONNE, NB_CASES);
    afficherTab(tab,NB_COLONNE, NB_CASES);
    return 0;
}
