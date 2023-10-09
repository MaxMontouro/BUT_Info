#include "ampoulevue.h"
#include "ui_ampoulevue.h"

AmpouleVue::AmpouleVue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AmpouleVue)
{
    ui->setupUi(this);
    connect(ui->bAllumer, SIGNAL(clicked()), this, SLOT(demandeAllumer()));
    connect(ui->bEteindre, SIGNAL(clicked()), this, SLOT(demandeEteindre()));
}

AmpouleVue::~AmpouleVue()
{
    delete ui;
}

void AmpouleVue::demandeAllumer()
{

}

void AmpouleVue::demandeEteindre()
{

}
