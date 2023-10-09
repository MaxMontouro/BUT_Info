#ifndef AMPOULEVUE_H
#define AMPOULEVUE_H

#include <QMainWindow>
#include "modele.h"

QT_BEGIN_NAMESPACE
namespace Ui { class AmpouleVue; }
QT_END_NAMESPACE

class Presentation;
class AmpouleVue : public QMainWindow
{
    Q_OBJECT

public:
    AmpouleVue(QWidget *parent = nullptr);
    ~AmpouleVue();

private:
    Ui::AmpouleVue *ui;
    Presentation *_laPresentation;

public slots:
    void demandeAllumer();
    void demandeEteindre();
};
#endif // AMPOULEVUE_H
