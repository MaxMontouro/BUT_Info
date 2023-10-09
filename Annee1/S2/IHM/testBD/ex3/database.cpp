#include "database.h"
#include "ui_database.h"

DataBase::DataBase(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DataBase)
{
    ui->setupUi(this);
    connect(ui->bQuitter, SIGNAL(clicked), this, SLOT(close()));
}

DataBase::~DataBase()
{
    delete ui;
}


bool DataBase::openDataBase()
{
    mydb = QSqlDatabase::addDatabase(CONNECT_TYPE);
    mydb.setDatabaseName(DATABASE_NAME);
    if(mydb.open())
    {
        return true;
    }
    else
    {
        return false;
    }
}
void DataBase::closeDataBase()
{
    mydb.close();
}

bool DataBase::restoreDataBase()
{
    if(this->openDataBase())
    {
        QSqlQuery query;
        if(query.exec("SELECT * FROM Villes"))
        {
            qDebug("Table Ville déjà existant");
            return true;
       }
       else
       {
            qDebug("Création de la Table Villes avec le Code Postal, le Nom et le Nombre d'habitants");
            query.exec("create table Villes (codepostal varchar(5) primary key, nomVille varchar(30), nbHabitants int(10))");
            this->insertVilles();
            return true;
        }
    }
    else
    {
        qDebug("Pas de BD... DSN Mauvais");
        return false;
    }
}

bool DataBase::insertVilles()
{
    QSqlQuery query;
    if (!query.exec("insert into Villes values('64000', 'Pau', 70000);"))
        return false;

    QString insertions="insert into Villes values(?, ?, ?);";
     query.prepare(insertions);
    QVariantList codesPostaux;
    codesPostaux << "33000" << "32000" ;
    query.addBindValue(codesPostaux);

     QVariantList nomsVilles;
     nomsVilles << "Bordeaux" << "Auch";
    query.addBindValue(nomsVilles);

    QVariantList nbHabitants;
    nbHabitants << 300000 << 25000;
    query.addBindValue(nbHabitants);

    if (!query.execBatch())
        return false;
    return true;

    //affichage dans le tableWidget

    for(int i = 0; query.next(); i++)
    {
        //on insere la ligne

        ui->tableWidget->insertRow(i);
        qDebug() << query.value(0) << query.value(1) << query.value(2) << Qt::endl;

        //insertion des donnees dans les différentes colonnes

        ui->tableWidget->setItem(i,0,new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(query.value(3).toString()));
    }
}
