#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->bDemarrer, SIGNAL(clicked()), this, SLOT(demandeInitial()));

    this->hide();
    //int reponse = maDlg->exec();

    //effacer le contenue
    ui->lMonNom->clear();
    ui->lMonPrenom->clear();
    ui->lEtreMajeur->clear();
    ui->lEnfant->clear();
    ui->lAfficherEnfant->clear();
    ui->lAfficherMajeur->clear();
    ui->lAfficherNom->clear();
    ui->lAfficherPrenom->clear();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::demandeInitial()
{
    maDlg = new Dialog(this);
    if((maDlg->majeur())&&(maDlg->getNom()!=""))
    {
        ui->lAfficherNom->setText(maDlg->getNom());
        ui->lAfficherPrenom->setText(maDlg->getPrenom());
        ui->lAfficherMajeur->setText(tr("Majeur"));

    }
    this->show();

}

void MainWindow::cacherLesWidgets()
{
    ui->lMonNom->setVisible(false);
    ui->lAfficherNom->setVisible(false);
    ui->lMonPrenom->setVisible(false);
    ui->lAfficherPrenom->setVisible(false);
    ui->lAfficherMajeur->setVisible(false);
    ui->lEtreMajeur->setVisible(false);
    ui->lEnfant->setVisible(false);
    ui->lAfficherEnfant->setVisible(false);
}
