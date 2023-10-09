#include "ampoulevue.h"
#include "modele.h"
#include "presentation.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // créer le modèle
    Modele *m = new Modele();
    // créer la présentation
    Presentation *p = new Presentation();
    // créer la vue
    AmpouleVue w;
    // faire pointer la présentation vers la vue et le modèle
    p->setVue(&w);
    p->setModele(m);
    // faire pointer la vue vers la présentation
    w.setPresentation(p);
    // initialiser la vue en conformité avec l'état initial du modèle
    w.majInterface(m->getEtat()); // ou p->getVue()->majInterface(m->getEtat());
    // afficher la vue et démarrer la boucle d'attente des messages
    w.show();
    return a.exec();
}
