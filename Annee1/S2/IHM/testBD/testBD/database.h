#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>

#define DATABASE_NAME "nodenot_bd1"
#define CONNECT_TYPE "QODBC"


class DataBase
{

public:
    DataBase();
    bool openDataBase();
    void closeDataBase();
private:
    QSqlDatabase mydb;
};

#endif // DATABASE_H
