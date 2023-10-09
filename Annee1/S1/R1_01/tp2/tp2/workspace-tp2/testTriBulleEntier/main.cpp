/*
 Programme : testTriBulle_entiers
 But :  Tester le sous-programme triBulle qui trie un tableau d'entiers par ordre croissant de valeurs 
 Date de dernière modification : 19/11/2022
 Auteur : Pantxika Dagorret
 Référence : R1.01-partie2 - feuille de TD n°2
*/

#include <iostream>
using namespace std;

/*---------------------------------------------------------*/
/*  Déclarations des sous-programmes servant à faire les tests
  ---------------------------------------------------------*/

void testTriBulle_entiers();
// test du triBulle croissant d'un tableau d'entiers

void afficher (const int tab[], unsigned short int lgTab);
/* But : affiche à l'écran le contenu d'aun tableau tab contenant lgTab > 0 éléments
         si lgTab = 0, affiche un message indiquant que le tableau n'a pas de valeur 
         significative (tableau 'vide') */

/*----------------------------------------*/
/* Déclarations des  sous-programmes testés 
----------------------------------------- */
void   triBulle (int tab[], unsigned int nbTab);
/* But : tri CROISSANT du tableau tab, contenant nbTab éléments entiers, selon la méthode
         du tri BULLE */

void faireMonterLaBulleIci (int tab[] , unsigned int bDeb, unsigned int ici, unsigned int& nbAcces);
/* Fait remonter le plus grand élément de la tranche tab(0..ici] à l'indice ici
 par échanges successifs.
 nbAcces précise le nombre d'accès au tableau réalisés dans le sous-programme*/ 

void echangerDeuxCasesTab(int tab[], int nb1, int nb2);
//But: Echanger les deux cases d'un tableau 

/*---------------------------*/
/* MAIN
---------------------------*/
int main()
{
    
    testTriBulle_entiers();
    return 0;
}

/*  ---------------------------------------------------*/
 /* Corps des sous-programmes servant à faire les tests
  -----------------------------------------------------*/

void testTriBulle_entiers()
{
    const unsigned int TAILLE = 10 ;

   int tableau1 [TAILLE] = {7, -6, 8, 10, 2, -3, 6, 9, 0, 2}; // non trié, valeurs au hasard


   cout << " ------------------   TRI BULLE croissant - tableau d'ENTIERS --------------" << endl << endl;

    // ---------tableau 1
    // afficher monTab avant le tri
    cout << "Avant tri BULLE croissant, tableau = ";
    afficher (tableau1, TAILLE);

    // monTab1, TAILLE >> triBulle >> monTab
    triBulle(tableau1, TAILLE);

    // afficher monTab après le tri
    cout << "Apres tri BULLE croissant, tableau = " ;
    afficher (tableau1, TAILLE);
    cout << endl;
}

void afficher (const int tab[],
               unsigned short int lgTab)
{
    if (lgTab > 0)
    {
        cout << "{";
        for (unsigned short int i = 0; i<lgTab-1; i++)
        {
            cout << tab[i] << ", " ;

        };
        cout << tab[lgTab-1] << "} "<< endl;
    }
    else
    {
        cout << "tableau vide " << endl;
    }
}

/*-----------------------------------*/
/* Corps des sous-programmes à tester 
-------------------------------------*/
void   triBulle (int tab[], unsigned int nbTab)
{
    unsigned int nbAcces;// Nombre acces 
    nbAcces = 0;

    for(unsigned short int indiceCourant = 0; indiceCourant<nbTab; indiceCourant++)
    {
        faireMonterLaBulleIci(tab, indiceCourant, nbTab, nbAcces);
    }
}

void faireMonterLaBulleIci (int tab[] , unsigned int bDeb, unsigned int ici, unsigned int& nbAcces)
{
    for(unsigned int i = bDeb; i < ici; i++)
    {
        if(tab[i]>tab[i+1])
        {
            echangerDeuxCasesTab(tab, tab[i], tab[i+1]);
            nbAcces++;
        }
    }
}

void echangerDeuxCasesTab(int tab[], int nb1, int nb2)
{
    int copieNb1 = tab[nb1];
    tab[nb2] = tab[nb1];
    tab[nb1] = copieNb1;
}

