#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->bConnexion,SIGNAL(clicked()),this,SLOT(demandeConnexion()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::demandeConnexion()
{
    QString utilisateur = ui->eUser->text();
    QString mdP = ui->eMdp->text();
    if ((utilisateur == "moi") && (mdP == "moi"))
    {
        QMessageBox::information(this, "Connexion", "Connexion réussie");
        maDlg = new Dialog(this);
        this-> hide();
        maDlg->exec();
        this->show();
    }
    else
    {
        QMessageBox::information(this, "Connexion", "Connexion erronée");
    }
}
