/* afficherLexicographiqueCroissantAVECDoublons
   But : A partir d'un fichier texte contennat des mots de la langue français, affiche ces mots triés par 
         ordre lexicographique croissant.   
         Toutes les occurrences d'un même mot dans le fichier sont aussi affichées à l'écran.
   Date : 14/01/2023
   Auteur : Pantxika Dagorret
   Remarque : Codage exercice 2 de la feuille de  TD n°7 - R1.01 
*/
#include <iostream>
using namespace std;
#include "fichierTexte.h"
#include "liste.h"

/* Déclaration des sous-programmes 
    -------------------------------*/
void afficherOrdreLexicoCroissantAvecDoublons (string nomSys);
/* Etant donné un fichier texte composé de mots de la langue française, et dont le
   nom système est fourni par le paramètre nomSys. 
   Les propriétés di fichier sont les suivantes : il peut être vide, ses mots sont 
   séparés par des séparateurs tels que espace – tabulations - sauts de ligne et de 
   page, un même mot peut apparaître plusieurs fois dans le fichier.
   
   Ce sous-programme affiche à l’écran les mots du fichier, par ordre lexicographique
   croissant(= ordre du dictionnaire), et à raison de 1 par ligne. 
   Un mot répété plusieurs fois dans le fichier est affiché autant de fois à l’écran.
*/

void afficherSequentiel(UneListe& pListe);



int main()
{
    // Déclaration et initialisation des éléments servant à la manipulation de fichiers
    string nomSysEntree = "data"; 

    afficherOrdreLexicoCroissantAvecDoublons(nomSysEntree);
    cout << endl;
    
    return 0;
}

    /* Définitions des sous-programmes 
    -------------------------------*/

void afficherOrdreLexicoCroissantAvecDoublons (string nomSys)
{
    //INITIALISATION
    UneListe maListe;
    bool trouve = false;
    bool finFichier = false;
    string mot;
    initialiser(maListe);

    //Charger avec doublons
    //preapration fichier
    UnFichierTexte fichier;
    associer(fichier, nomSys);
    ouvrir(fichier, consultation);
    
    //parcours du fichier
    while (true)
    {
       lireMot(fichier, mot, finFichier);
       if(finFichier == true)
       {
            break;
       } 
       //chercher place du mot dans maListe
       allerDebut(maListe);
        while(true)
        {
            if(parcoursEnCours(maListe) == false)
            {
                break;
            }
            else if(elementCourant(maListe) >= mot)
            {
                trouve = true;
                break;
            }
            avancer(maListe);
        }
        //Inserer mot a sa palce
        if(trouve == true)
        {
            insererDevantCourant(maListe, mot);
        }
        else
        {
            insererFin(maListe, mot);
        }
    }
    fermer(fichier);
    afficherSequentiel(maListe);
}

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