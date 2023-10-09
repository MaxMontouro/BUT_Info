#include "testbd.h"
#include "ui_testbd.h"

TestBD::TestBD(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TestBD)
{
    ui->setupUi(this);
    db = new DataBase();


    if(db->openDataBase())
    {
       QSqlQuery query("SELECT Article.Reference, Article.Descriptif, Article.PrixHT, Categorie.Libelle, Categorie.CodeCategorie FROM Article JOIN Categorie ON Categorie.CodeCategorie = Article.CodeCategorie");
       for(int i = 0; query.next(); i++)
       {
           //on insere la ligne

           ui->tableWidget->insertRow(i);
           qDebug() << query.value(0) << query.value(1) << query.value(2) << Qt::endl;

           //insertion des donnees dans les différentes colonnes

           ui->tableWidget->setItem(i,0,new QTableWidgetItem(query.value(0).toString()));
           ui->tableWidget->setItem(i,1,new QTableWidgetItem(query.value(1).toString()));

           QTableWidgetItem *itemPrixHT = new QTableWidgetItem(query.value(2).toString());
           itemPrixHT->setTextAlignment(Qt::AlignRight | Qt::AlignCenter);

           ui->tableWidget->setItem(i,2,itemPrixHT);
           ui->tableWidget->setItem(i,3,new QTableWidgetItem(query.value(3).toString()));
       }

    }
}

TestBD::~TestBD()
{
    delete ui;
}

