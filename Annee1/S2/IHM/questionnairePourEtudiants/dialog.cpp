#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->btnOk, SIGNAL(clicked()), this, SLOT(accept()));
    connect(ui->btnAnnuler, SIGNAL(clicked()), this, SLOT(reject()));

    // effacer les champs de saisie
    ui->RdBtnMajeur->setChecked(false);
    ui->nomLineEdit->clear();
    ui->prenomLineEdit->clear();
}

Dialog::~Dialog()
{
    delete ui;
}

QString Dialog::getNom()
{
    return ui->nomLineEdit->text();
}
QString Dialog::getPrenom()
{
    return ui->prenomLineEdit->text();
}

bool Dialog::getMajeur()
{
    return ui->RdBtnMajeur->isChecked();
}
