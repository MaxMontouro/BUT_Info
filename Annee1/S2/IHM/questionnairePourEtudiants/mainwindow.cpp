#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QInputDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    cacherLesWidgets();
    connect (ui->btnDialogue, SIGNAL(clicked()), this, SLOT(ouvrirDialogue()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::cacherLesWidgets()
{
    ui->labelValeurNomSaisi->setVisible(false);
    ui->labelValeurPrenomSaisi->setVisible(false);
    ui->labelNomSaisi->setVisible(false);
    ui->labelPrenomSaisi->setVisible(false);
    ui->labelValeurMajeur->setVisible(false);
    ui->labelMajeur->setVisible(false);
    ui->labelEnfants->setVisible(false);
    ui->labelValeurEnfants->setVisible(false);
}

void MainWindow::montrerLesWidgets(bool dialNPOk, bool majeur)
{
}

void MainWindow::ouvrirDialogue()
{
    Dialog maDlg(this);

    // 1.- Ouverture de DalogueNom : demandant nom, prénom, majeur
    this->hide();
    int reponse = maDlg.exec();


    // 2.- Récupération et traitement des réponses (nom, prenom, majeur) lorsque le dialogue (DialogueNom) a été validé

    // Effacer les contenus des widgets d'affichage avant de les repeupler

    // 3.- S'occuper du dialogue enfants si le 1er Dialogue est correct


    // 4.- Les réponses aux dialogues ne sont affichées que si le dialogue principal (DialogueNom) a été validé

}




