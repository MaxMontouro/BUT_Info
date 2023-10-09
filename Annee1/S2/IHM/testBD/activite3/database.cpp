#include "database.h"

DataBase::DataBase()
{
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
            return false;
        }
        else
        {
            qDebug("Création de la Table Villes avec le Code Postal, le Nom et le Nombre d'habitants");
            query.exec("create table Villes (codepostal varchar(5) primary key, nomVille varchar(30), nbHabitants int(10))");
            return true;
        }
    }
    else
    {
        qDebug("Pas de BD... DSN Mauvais");
        return false;
    }
}


