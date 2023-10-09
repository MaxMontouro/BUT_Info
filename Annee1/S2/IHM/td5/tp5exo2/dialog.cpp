#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->bAnnuler, SIGNAL(clicked()), this, SLOT(reject()));
    connect(ui->bOk, SIGNAL(clicked()), this, SLOT(accept()));

    //effacer les champs
    ui->radioButton->setChecked(false);
    ui->lNom->clear();
    ui->lPrenom->clear();
}

Dialog::~Dialog()
{
    delete ui;
}

bool Dialog::majeur()
{
    if(ui->radioButton->isChecked())
    {
        return true;
    }
    else
    {
        return false;
    }
}

QString Dialog::getNom()
{
    return ui->lNom->text();
}

QString Dialog::getPrenom()
{
    return ui->lPrenom->text();
}
