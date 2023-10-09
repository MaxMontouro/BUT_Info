/* afficherInverseFichierTexte
   But : afficher à l'écran le contenu d'une liste d'entiers. 
         Tester le parcours complet de liste en utilisant les primitives d'accès séquetiel et direct. 
   Date : 14/01/2023
   Auteur : Pantxika Dagorret
   Remarque : Codage exercice 1 de la feuille de  TD n°7 - R1.01 
*/
#include <iostream>
#include "liste.h" // configurée pour manipuler des listes d'entiers (int)
using namespace std;

/* Déclaration des sous-programmes */

void afficherSequentiel(UneListe& pListe);
/* affiche le contenu de la liste pListe, et la laisse la liste dans l'état initial
   Utilise les primitives d'accès séquentiel */

void afficherDirect(UneListe& pListe);
/* affiche le contenu de la liste pListe, et la laisse la liste dans l'état initial
   Utilise les primitives d'accès direct */


/* MAIN 
   -------------------------*/

int main()
{
    // Déclaration et initialiatin d'un élément de type UneListe
    UneListe maListe; 
    initialiser(maListe); 

    // Ajout d'éléments dans la liste
    insererFin(maListe, 10);    insererFin(maListe, 20);
    insererFin(maListe, 30);    insererFin(maListe, 40);
    insererFin(maListe, 50);    insererFin(maListe, 60);
    insererFin(maListe, 70);    insererFin(maListe, 80);

    /* AfficherAvant - séquentiel */
    cout << "Affichage liste - utilisation primitives d'acces sequentiel " << endl;
    afficherSequentiel(maListe);
    
    cout << endl; 

    /* AfficherAvant - direct */
    cout << "Affichage liste - utilisation primitives d'acces direct " << endl;
    afficherDirect(maListe);
   
    return 0;
}

/* Corps des sous-programmes 
   -------------------------*/

void afficherSequentiel(UneListe& pListe)
{
   int tailleListe = taille(pListe);

   allerDebut(pListe);
   for(unsigned short int indiceParcours = 1; indiceParcours <= tailleListe; indiceParcours++)
   {
     cout << elementCourant(pListe) << "  ";
     avancer(pListe);
   }
}

void afficherDirect(UneListe& pListe)
{
   int rangElementCourant = 0;
   int tailleListe;
   
   if(parcoursEnCours(pListe) == true)
   {
      rangElementCourant = positionCourante(pListe);
   }

   //calculer taille de la liste
   tailleListe = taille(pListe);

   //parcours commplet
   for(unsigned short int indiceParcours = 1; indiceParcours < tailleListe; indiceParcours++)
   {
      cout << elementEn(pListe, indiceParcours);
   }
   
   //positionner element courant 
   if(rangElementCourant > 0);
   {
      allerEn(pListe, rangElementCourant);
   }
}