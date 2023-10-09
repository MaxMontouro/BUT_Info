#ifndef SOUSPROGRAMMES_H
#define SOUSPROGRAMMES_H
#include "pile.h"
// contient la définition du type File implémentée àl'aide de 2 piles d'entiers non signés
// ainsi que les déclarations des primitives habituelles de gestion de cette file

struct File
{
    UnePile pile1;//pile tete
    UnePile pile2;//pile queue
};

// Primitives de gestion d'une telle File 

void enfiler(UnePile& piletete, UnePile& pileQueue, UnElement& element);
//But: enfile l'élément passer en paramètre au bout de la file pieQueue

#endif
