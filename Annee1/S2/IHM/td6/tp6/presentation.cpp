#include "presentation.h"
#include "ampoulevue.h"
#include <QDebug>

Presentation::Presentation(QObject *parent)
    : QObject{parent}
{

}

Modele *Presentation::getModele()
{
    return _leModele;
}

AmpouleVue *Presentation::getVue()
{
    return _laVue;
}
