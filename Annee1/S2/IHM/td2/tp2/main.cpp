#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);// creation du processe
    ConvertisseurTemp w;// creation de la fenetre
    w.show();//affichage de la fenetre
    return a.exec();//l appli se met en attente des msgs
}
