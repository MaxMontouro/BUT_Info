#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDebug>

#define DATABASE_NAME "mmontouro_bd"
#define CONNECT_TYPE "QODBC"


class DataBase
{

public:
    DataBase();
    bool openDataBase();
    void closeDataBase();
    bool restoreDataBase();
    bool insertVilles();
private:
    QSqlDatabase mydb;
};

#endif // DATABASE_H
